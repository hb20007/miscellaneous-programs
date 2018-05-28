/// <file>
/// <author>hb20007</author>
/// <datecreated>2016-11-07</datecreated>
/// <summary>
/// Countains the part of the class SeferBookstoreMainForm dealing with the behavior of the form and the components
/// </summary>
/// </file>

using System;
using System.Drawing;
using System.Windows.Forms;
using System.Threading;
using System.Linq;
using System.Collections.Generic; // For using a generic list.
using System.IO; // For StreamReader etc.
using System.Text.RegularExpressions;

namespace SeferBookstore
{
    partial class SeferBookstoreMainForm : Form
    {
        /// <summary>
        /// In this application, all books are sold at the same price
        /// </summary>
        internal const decimal PRICE_PER_BOOK = 10m;

        // The file books.csv was obtained from https://github.com/benoitvallon/100-best-books/blob/master/books.csv
        // It uses ; instead of the more common , to separate fields because some book titles contain the , character
        // It was edited as follows: Column titles were added, rows were sorted alphabetically by title, columns not relevant to my application were removed, some dates were reformatted
        internal static string BOOKS_FILE_NAME = "books.csv";

        /// <summary>
        /// All the book data
        /// </summary>
        internal List<string[]> bookData = new List<string[]>(); // A list is used instead of a 2D array because the array size is unknown

        /// <summary>
        /// The number of books in the current order
        /// </summary>
        public int NumberOfBooksOrdered { get; private set; } // The mutator is private since it needs to be read-only from outside the class

        /// <summary>
        /// The daily total sales. Initialized to <code>0m</code> by the C# default constructor
        /// </summary>
        public decimal DailyTotalSales { get; set; } // Along with DailyTotalItemsSold, it is public because it will be accessed from the summary form class as well as modified by the checkout form class 

        /// <summary>
        /// The daily total number of items sold. Initialized to <code>0m</code> by the C# default constructor
        /// </summary>
        public int DailyTotalItemsSold { get; set; }

        /// <summary>
        // To access Windows Forms controls from another thread, a dispatcher has to be used. Code obtained from this MSDN article: http://msdn.microsoft.com/en-us/library/ms171728.aspx
        /// </summary>
        /// <param name="text">The item that will be selected in the list box of all book titles</param>
        delegate void SetTextCallback(string text);
        private void ChangeAllTitlesListBoxSelectedItem(string text)
        {
            // InvokeRequired compares the thread ID of the calling thread to the thread ID of the creating thread. If these threads are different, it returns true.
            if (this.allTitlesListBox.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(ChangeAllTitlesListBoxSelectedItem);
                this.Invoke(d, new object[] { text });
            }
            else // On success
            {
                this.allTitlesListBox.SelectedItem = text;
            }
        }

        /// <summary>
        /// Used to allow the selected index in the all titles list box to be changed from the advanced search form
        /// </summary>
        private string allTitlesListBoxItemSelectedByAdvancedSearch;
        public string AllTitlesListBoxItemSelectedByAdvancedSearch
        {
            get
            {
                return allTitlesListBoxItemSelectedByAdvancedSearch;
            }
            set // The setter enables this property to change the list box selected item when it is set from the child form
            {
                this.allTitlesListBoxItemSelectedByAdvancedSearch = value;
                //this.allTitlesListBox.SelectedItem = this.allTitlesListBoxItemSelectedByAdvancedSearch; Doesn't work because this code will be accesssed from another thread.
                this.ChangeAllTitlesListBoxSelectedItem(this.allTitlesListBoxItemSelectedByAdvancedSearch); // Needed to make thread-safe calls to the windows forms control (the list box)
            }
        }

        /// <summary>
        /// Displays the splash screen, initialzes form components, font and font color, the total text box, the question mark tool tip, loads book data and then initializes the image list and the titles list box
        /// </summary>
        public SeferBookstoreMainForm()
        {
            // Displays the splash screen for a period of 2 seconds before we proceed with initializing the main form
            Thread splashScreenThread = new Thread(new ThreadStart(this.splashStart));
            splashScreenThread.Start();
            Thread.Sleep(2000);
            splashScreenThread.Abort();

            this.InitializeComponent();

            this.seferBookstoreFontDialog.Font = this.Font;
            this.seferBookstoreColorDialog.Color = this.ForeColor;

            this.totalTextBox.Text = 0m.ToString("c"); // Initialize to 0
            this.seferBookstoreMainFormToolTip.SetToolTip(this.questionMarkPictureBox, "Price per book: " + SeferBookstoreMainForm.PRICE_PER_BOOK.ToString("c"));

            this.loadBookData();
            this.initializeImageList();
            this.initializeTitlesListBox();
        }

        /// <summary>
        /// Loads data from <code>BOOKS_FILE_NAME</code> into the private field <code>bookData</code>
        /// </summary>
        private void loadBookData()
        {
            // I will create a new List (using the keyword new) and add all the data for a line into it then I will add it into the field list
            try
            {
                StreamReader reader = new StreamReader(File.OpenRead(SeferBookstoreMainForm.BOOKS_FILE_NAME));
                string line = reader.ReadLine(); // The first line is passed by because it has the column headings
                string[] values;
                while (!reader.EndOfStream)
                {
                    line = reader.ReadLine();
                    values = line.Split(';');
                    this.bookData.Add(values);
                }
                reader.Close();
            }
            catch(FileNotFoundException)
            {
                MessageBox.Show(String.Format("The file {0} was not found in {1}", SeferBookstoreMainForm.BOOKS_FILE_NAME, Directory.GetCurrentDirectory()), "Fatal error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Environment.Exit(1);
            }
        }
        
        /// <summary>
        /// Initializes the image list with all the book images
        /// </summary>
        private void initializeImageList()
        {
            this.seferBookstoreMainFormImageList.ImageSize = new Size(166, 256); // Setting ImageSize is mandatory. The numbers I chose are the largest possible with the same ratio as the images I have (256 is the highest width/height possible)
                foreach (string[] str in this.bookData)
                {
                    string relativePath = @"book-images\" + str[5]; // The 5th element in the array is the image name
                    try
                    {
                        this.seferBookstoreMainFormImageList.Images.Add(Image.FromFile(relativePath));
                    }
                    catch (FileNotFoundException)
                    {
                        MessageBox.Show(String.Format("The file {0} was not found in {1}\\book-images\\", str[5], Directory.GetCurrentDirectory()), "Fatal error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        Environment.Exit(1);
                    }
            }
        }

        /// <summary>
        /// Initializes the list box with all titles 
        /// </summary>
        private void initializeTitlesListBox()
        {
            foreach (string[] s in this.bookData)
                this.allTitlesListBox.Items.Add(s[0]);
        }

        /// <summary>
        /// Runs an anonymous instance of the splash screen class
        /// </summary>
        private void splashStart()
        {
            Application.Run(new SeferBookStoreSplashScreen());
        }

        /// <summary>
        /// Runs an anonymous instance of the summary form class
        /// </summary>
        private void summaryStart()
        {
            Application.Run(new SeferBookstoreSummaryForm(this)); // The parent form is passed into the child form via the constructor in order to have an accessible named instance of the main form in the summary form in order to access the main form's non-static members from there
        }

        /// <summary>
        /// Runs an anonymous instance of the advanced search form class
        /// </summary>
        private void advancedSearchStart()
        {
            Application.Run(new SeferBookstoreAdvancedSearchForm(this));
        }

        /// <summary>
        /// Animation when the mouse hovers over the question mark to indicate there is an important tool tip
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void questionMarkPictureBox_MouseHover(object sender, EventArgs e)
        {
            this.questionMarkPictureBox.BorderStyle = BorderStyle.Fixed3D;
        }

        /// <summary>
        /// Animation when the mouse hovers over the question mark to indicate there is an important tool tip
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void questionMarkPictureBox_MouseLeave(object sender, EventArgs e)
        {
            this.questionMarkPictureBox.BorderStyle = BorderStyle.FixedSingle;
        }

        /// <summary>
        /// Changes the font color of all read-only text boxes on the form and in the book information group box
        /// </summary>
        private void changeReadOnlyTextBoxFontColors()
        {
            this.totalTextBox.ReadOnly = false;
            this.totalTextBox.BackColor = Color.FromKnownColor(KnownColor.Control);
            this.totalTextBox.ForeColor = this.seferBookstoreColorDialog.Color;
            this.totalTextBox.ReadOnly = true;
            foreach (TextBox currentTextBox in this.bookInformationGroupBox.Controls.OfType<TextBox>())
            {
                currentTextBox.ReadOnly = false;
                currentTextBox.BackColor = Color.FromKnownColor(KnownColor.Control);
                currentTextBox.ForeColor = this.seferBookstoreColorDialog.Color;
                currentTextBox.ReadOnly = true; // ReadOnly text box text is gray. Therefore the color is changed before the text box is set to ReadOnly. BackColor must be changed too for this to work
            }
        }

        /// <summary>
        /// Changes the font color in all the submenu items in the menu strip
        /// </summary>
        private void changeMenuStripSubmenusFontColors()
        {
            foreach (ToolStripMenuItem currentSubmenuItem in this.fileToolStripMenuItem.DropDownItems.OfType<ToolStripMenuItem>()) // .OfType<>() needed due to the use/potential future use of a horizontal divider
            {
                currentSubmenuItem.ForeColor = this.seferBookstoreColorDialog.Color;
            }
            foreach (ToolStripMenuItem currentSubmenuItem in this.editToolStripMenuItem.DropDownItems.OfType<ToolStripMenuItem>())  // .OfType<>() needed due to the use/potential future use of a horizontal divider
            {
                currentSubmenuItem.ForeColor = this.seferBookstoreColorDialog.Color;
            }
            foreach (ToolStripMenuItem currentSubmenuItem in this.toolsToolStripMenuItem.DropDownItems.OfType<ToolStripMenuItem>()) // .OfType<>() needed due to the use/potential future use of a horizontal divider
            {
                currentSubmenuItem.ForeColor = this.seferBookstoreColorDialog.Color;
            }
            foreach (ToolStripMenuItem currentSubmenuItem in this.helpToolStripMenuItem.DropDownItems.OfType<ToolStripMenuItem>()) // .OfType<>() needed due to the use/potential future use of a horizontal divider
            {
                currentSubmenuItem.ForeColor = this.seferBookstoreColorDialog.Color;
            }
            foreach (ToolStripMenuItem currentSubSubmenuItem in this.customizeToolStripMenuItem.DropDownItems)
            {
                currentSubSubmenuItem.ForeColor = this.seferBookstoreColorDialog.Color;
            }
        }

        /// <summary>
        /// Displays a new form with the daily summary
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void dailySumarryToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Thread summaryFormThread = new Thread(new ThreadStart(this.summaryStart));
            summaryFormThread.Name = "Summary"; // To help keep track of the thread in the debugger
            summaryFormThread.Start();
        }

        /// <summary>
        /// Resets the daily summary
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void resetSumarryToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (DialogResult.Yes == MessageBox.Show("Are you sure you want to reset the daily summary?", "Confirmation", MessageBoxButtons.YesNo, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2))
            {
            this.DailyTotalSales = 0;
            this.DailyTotalItemsSold = 0;
            }
        }

        /// <summary>
        /// Quits the program
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        /// <summary>
        /// Performs the cut function
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void cutToolStripMenuItem_Click(object sender, EventArgs e) // The cut method, like the copy, paste and delete methods, are only implemented for text boxes in this application
        {
            if (this.ActiveControl is TextBox && this.ActiveControl.Text != String.Empty) // The check that the active control's text is not the empty string is important to avoid an exception
            {
                //if (((TextBox)this.ActiveControl).SelectedText != String.Empty) // If the user has selected some text
                //{
                //    Clipboard.SetText(((TextBox)this.ActiveControl).SelectedText); // The active control is downcasted to a text box in order to use the SelectedText property
                //    ((TextBox)this.ActiveControl).SelectedText = String.Empty;
                //}
                //else // If the user has not selected some text. This is needed otherwise an exception would occur on using the function
                //{
                //    Clipboard.SetText(this.ActiveControl.Text); // If the user has not selected any text in the text box, the whole text is cut with this functionality
                //    this.ActiveControl.Text = String.Empty;
                //}
                ((TextBox)this.ActiveControl).Cut(); // This line is an alternative to the commented code above without the feature of cutting unselected text if no text is selected
                this.pasteToolStripMenuItem.Enabled = true; // The paste function is now enabled
            }
        }

        /// <summary>
        /// Performs the copy function
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void copyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (this.ActiveControl is TextBox && this.ActiveControl.Text != String.Empty)
            {
                //if (((TextBox)this.ActiveControl).SelectedText != String.Empty)
                //    Clipboard.SetText(((TextBox)this.ActiveControl).SelectedText);
                //else
                //    Clipboard.SetText(this.ActiveControl.Text);
                ((TextBox)this.ActiveControl).Copy(); // This line is an alternative to the commented code above without the feature of copying unselected text if no text is selected
                this.pasteToolStripMenuItem.Enabled = true;
            }
        }

        /// <summary>
        /// Performs the paste function
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void pasteToolStripMenuItem_Click(object sender, EventArgs e) 
        {
            if (this.ActiveControl is TextBox)
            {
                ((TextBox)this.ActiveControl).Paste(Clipboard.GetText());
            }
        }

        /// <summary>
        /// Performs the select all function
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void selectAllToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (this.ActiveControl is TextBox)
            {
                ((TextBox)this.ActiveControl).SelectAll();
            }
        }

        /// <summary>
        /// Displays the Font dialog
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void changefontToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.seferBookstoreFontDialog.ShowDialog();
            this.Font = this.seferBookstoreFontDialog.Font;
            this.seferBookstoreMainFormMenuStrip.Font = this.seferBookstoreFontDialog.Font;
        }

        /// <summary>
        /// Displays the color dialog
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void changeFontcolorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.seferBookstoreColorDialog.ShowDialog();
            this.ForeColor = this.seferBookstoreColorDialog.Color;
            this.seferBookstoreMainFormMenuStrip.ForeColor = this.seferBookstoreColorDialog.Color;
            this.bookInformationGroupBox.ForeColor = this.seferBookstoreColorDialog.Color;
            // Changing the font color for read-only text boxes (default gray) is not straightforward
            this.changeReadOnlyTextBoxFontColors();
            // The colors for each submenu item must be changed separately for changing font color to work. This was not the case for changing the font
            this.changeMenuStripSubmenusFontColors();

            this.allTitlesListBox.ForeColor = this.seferBookstoreColorDialog.Color;
            this.shopListListBox.ForeColor = this.seferBookstoreColorDialog.Color;
        }

        /// <summary>
        /// Displays the about box
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new SeferBookstoreAboutBox(this.seferBookstoreFontDialog.Font, this.seferBookstoreColorDialog.Color).ShowDialog(); // As opposed to .Show(), .ShowDialog() disables the parent form so the user has to close the about box in order to continue using the program
        }

        /// <summary>
        /// Advanced book search feature from the context menu strip
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void advancedBookSearchToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.advancedSearchButton.PerformClick();
        }

        /// <summary>
        /// Clear feature from the context menu strip
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void clearToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.clearButton.PerformClick();
        }

        /// <summary>
        /// Reset shoplist feature from the context menu strip
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void resetShoplistToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.resetShoplistButton.PerformClick();
        }

        /// <summary>
        /// Displays the information corresponding to the selected book
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void allTitlesListBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            int bookIndex = this.allTitlesListBox.SelectedIndex;
            if (bookIndex != -1)
            {
                this.titleTextBox.Text = this.bookData[bookIndex][0];
                this.authorTextBox.Text = this.bookData[bookIndex][1];
                this.yearTextBox.Text = this.bookData[bookIndex][2];
                this.countryTextBox.Text = this.bookData[bookIndex][3];
                this.languageTextBox.Text = this.bookData[bookIndex][4];
                this.bookPictureBox.Image = this.seferBookstoreMainFormImageList.Images[bookIndex];
            }
        }

        /// <summary>
        /// Selects the appropriate book in the list box corresponding to the search (if any)
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void searchTextBox_TextChanged(object sender, EventArgs e)
        {
            string searchString = this.searchTextBox.Text.Trim().ToUpper(); // The search is case insensitive as it should be
            if (searchString != String.Empty)
            {
                bool foundFlag = false;
                for (int i = 0; i < this.allTitlesListBox.Items.Count; i++)
                {
                    string title = this.allTitlesListBox.Items[i].ToString().Trim().ToUpper(); // A foreach loop cannot be used because the titles is modified (eg. ToUpper() and then .SelectedItem cannot be used)
                    try
                    {
                        if (Regex.Match(title, searchString).Success) // The order of the arguments of Match() is important
                        {
                            this.allTitlesListBox.SelectedIndex = i;
                            foundFlag = true;
                            break;
                        }
                    }
                    catch (ArgumentException)
                    {
                        MessageBox.Show("The search term had invalid characters." + Environment.NewLine + Environment.NewLine + "The search box has been cleared.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                        this.searchTextBox.Clear();
                    }
                }
                if (!foundFlag)
                    this.searchTextBox.ForeColor = Color.Red;
                else
                    this.searchTextBox.ForeColor = this.ForeColor;
            }
        }

        /// <summary>
        /// Displays the advanced search form
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void advancedSearchButton_Click(object sender, EventArgs e)
        {
            Thread advancedSearchFormThread = new Thread(new ThreadStart(this.advancedSearchStart));
            advancedSearchFormThread.Name = "Advanced Search"; // To help keep track of the thread in the debugger
            advancedSearchFormThread.Start();
        }

        /// <summary>
        /// Adds selected item to the shoplist
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void addButton_Click(object sender, EventArgs e)
        {
            if (this.allTitlesListBox.SelectedIndex != -1)
            {
                this.shopListListBox.Items.Add(this.allTitlesListBox.SelectedItem);
                this.totalTextBox.Text = (this.shopListListBox.Items.Count * SeferBookstoreMainForm.PRICE_PER_BOOK).ToString("c");
            }
        }

        /// <summary>
        /// Double clicking can also be used to work with the list boxes
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void allTitlesListBox_DoubleClick(object sender, EventArgs e)
        {
            this.addButton.PerformClick();
        }

        /// <summary>
        /// Removes selected item from shoplist
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void removeButton_Click(object sender, EventArgs e)
        {
            int selectedIndex = this.shopListListBox.SelectedIndex;
            if (selectedIndex != -1)
            {
                this.shopListListBox.Items.RemoveAt(selectedIndex);
                // or this.shopListListBox.items.Remove(this.shopListListBox.SelectedItem);
                this.shopListListBox.SelectedIndex = selectedIndex - 1; // Overrides default behavior which is to unselect all elements and can be inconvenient
                if (this.shopListListBox.SelectedIndex == -1 && this.shopListListBox.Items.Count > 0)
                    this.shopListListBox.SelectedIndex = 0; // This if statement is an extra feature. If the user had removed the first element in the list box, instead of unselected everything if there are other elements in the list box, the selected index moves up this time
                this.totalTextBox.Text = (this.shopListListBox.Items.Count * SeferBookstoreMainForm.PRICE_PER_BOOK).ToString("c");
            }
        }

        /// <summary>
        /// Double clicking can also be used to work with the list boxes
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void shopListListBox_DoubleClick(object sender, EventArgs e)
        {
            this.removeButton.PerformClick();
        }

        /// <summary>
        /// Resets the shoplist
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void resetShoplistButton_Click(object sender, EventArgs e)
        {
            this.shopListListBox.Items.Clear();
            this.totalTextBox.Text = (this.shopListListBox.Items.Count * SeferBookstoreMainForm.PRICE_PER_BOOK).ToString("c");
        }

        /// <summary>
        /// Opens the Wikipedia page of the selected book in the default web browser
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void wikipediaPageButton_Click(object sender, EventArgs e)
        {
            int currentBookIndex = this.allTitlesListBox.SelectedIndex;
            if (currentBookIndex != -1)
                System.Diagnostics.Process.Start(this.bookData[currentBookIndex][6]); // 6 corresponds to the column with the wikipedia URLs
        }

        /// <summary>
        /// Clears the search box and the book information. Also unselects items in the list boxes
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void clearButton_Click(object sender, EventArgs e)
        {
            this.searchTextBox.Clear();
            foreach (TextBox t in this.bookInformationGroupBox.Controls.OfType<TextBox>())
                t.Clear();
            this.bookPictureBox.Image = null;
            this.allTitlesListBox.SelectedIndex = -1;
            this.shopListListBox.SelectedIndex = -1;
        }

        /// <summary>
        /// Proceeds the user to the checkout form. If the checkout form returns <code>DialogResult = OK</code> then the form is cleared in preparation for the next order
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void checkoutButton_Click(object sender, EventArgs e)
        {
            if (this.shopListListBox.Items.Count == 0)
                MessageBox.Show("There are no items in the shopping list.", "Cannot check out!", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            else
            {
                this.NumberOfBooksOrdered = this.shopListListBox.Items.Count;
                if (new SeferBookstoreCheckoutForm(this).ShowDialog() == DialogResult.OK) // A thread is not used for the checkout form because it needs to return a DialogResult
                {
                    this.clearButton.PerformClick();
                    this.resetShoplistButton.PerformClick();
                } 
            } 
        }
    }
}