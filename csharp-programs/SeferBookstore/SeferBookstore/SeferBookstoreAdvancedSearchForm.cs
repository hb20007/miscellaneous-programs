/// <file>
/// <author>hb20007</author>
/// <datecreated>2016-12-23</datecreated>
/// <summary>
/// Contains the part of the class SeferBookstoreAdvancedSearchForm with my code
/// </summary>
/// </file>

using System;
using System.IO;
using System.Drawing;
using System.Globalization;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace SeferBookstore
{
    partial class SeferBookstoreAdvancedSearchForm : Form
    {
        private SeferBookstoreMainForm parent;

        /// <summary>
        /// Initializes component, sets font and colors, initializes the combo box and gives it a default value
        /// </summary>
        /// <param name="parentForm">The parent form</param>
        public SeferBookstoreAdvancedSearchForm(SeferBookstoreMainForm parentForm)
        {
            this.parent = parentForm;
            this.InitializeComponent();
            this.setFontAndColors();
            this.initializeComboBox();
            this.searchByComboBox.SelectedIndex = 0; // Default value
        }

        /// <summary>
        /// Sets the font and colors to be the same as in the parent form
        /// </summary>
        private void setFontAndColors()
        {
            this.Font = this.parent.Font;
            if (this.parent.ForeColor != this.ForeColor)
            {
                this.ForeColor = this.parent.ForeColor;
                this.searchByComboBox.ForeColor = this.parent.ForeColor; // FlatStyle of the combo box was changed to flat for the color change to be possible
                this.resultsListBox.ForeColor = this.parent.ForeColor;
            }
        }
        
        /// <summary>
        /// Adds items to the combo box
        /// </summary>
        private void initializeComboBox()
        {
            try
            {
                StreamReader reader = new StreamReader(File.OpenRead(SeferBookstoreMainForm.BOOKS_FILE_NAME));
                string line = reader.ReadLine(); // The first line in the file contains the column headings
                reader.Close();
                string[] headings = line.Split(';');
                TextInfo textInfo = new CultureInfo("en-US", false).TextInfo; // For conversion to toMatch case
                for (int i = 0; i < headings.Length - 2; i++) // The last 2 elements in the string array are ignored because they cannot be used for search
                {
                    headings[i] = headings[i].ToLower(); // ToLower is needed before conversion to toMatch case
                    headings[i] = textInfo.ToTitleCase(headings[i]);
                    this.searchByComboBox.Items.Add(headings[i]);
                }
            }
            catch (FileNotFoundException)
            {
                MessageBox.Show(String.Format("The file {0} was not found in {1}", SeferBookstoreMainForm.BOOKS_FILE_NAME, Directory.GetCurrentDirectory()), "Fatal error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Environment.Exit(1);
            }
        }

        /// <summary>
        /// Updates the label based on the combo box selection
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void searchByComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            this.resultsLabel.Text = "Titles that match your search string for " + this.searchByComboBox.SelectedItem + ":";
            this.resultsListBox.Items.Clear(); // The results list box is cleared of any search results related to a previous search regarding a different option in the combo box
            this.searchTextBox.Clear(); // The text box is cleared to prepare for the new search by the item in the combo box
            this.searchTextBox.Focus();
        }

        /// <summary>
        /// Adds the item at the index where a match was found to the list box
        /// </summary>
        /// <param name="indexWhereMatchWasFound">The index where the regex match occured</param>
        private void addAppropriateItemToListBox(int indexWhereMatchWasFound)
        {
            string toBeAdded = this.parent.bookData[indexWhereMatchWasFound][0];
            switch(this.searchByComboBox.SelectedIndex)
            {
                // Case 0 is just search by Title and nothing needs to be added to the string
                case 1: // Author
                    toBeAdded += " (" + this.parent.bookData[indexWhereMatchWasFound][1] + ')';
                    break;
                case 2: // Year
                    toBeAdded += " (" + this.parent.bookData[indexWhereMatchWasFound][2] + ')';
                    break;
                case 3: // Country
                    toBeAdded += " (" + this.parent.bookData[indexWhereMatchWasFound][3] + ')';
                    break;
                case 4: // Language
                    toBeAdded += " (" + this.parent.bookData[indexWhereMatchWasFound][4] + ')';
                    break; // This break; is mandatory
            }
            this.resultsListBox.Items.Add(toBeAdded);
        }

        /// <summary>
        /// Performs the search functionality
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void searchTextBox_TextChanged(object sender, EventArgs e)
        {
            this.resultsListBox.Items.Clear(); // First the results list box is cleared of any previous search results

            string searchString = this.searchTextBox.Text.Trim().ToUpper(); // The search is case insensitive as it should be
            if (searchString != String.Empty && this.searchByComboBox.SelectedIndex != -1)
            {
                bool foundFlag = false;
                for (int i = 0; i < this.parent.bookData.Count; i++) // this.parent.bookData.Count is the number of books
                {
                    string toMatch = this.parent.bookData[i][this.searchByComboBox.SelectedIndex].ToString().Trim().ToUpper(); // All the entries in bookData in the appropriate column are examined
                    try
                    {
                        if (Regex.Match(toMatch, searchString).Success) // The order of the arguments of Match() is important
                        {
                            this.addAppropriateItemToListBox(i);  // If the string is matched the title of the corresponding book (as well as information related to the search) is added to the results combo box 
                            foundFlag = true;
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
        /// Closes the form without doing anything
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void cancelButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        /// <summary>
        /// Checks if the user has selected a search result. If they have, closes the form and displays it in the main form
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void okButton_Click(object sender, EventArgs e)
        {
            if (this.resultsListBox.SelectedIndex == -1)
            {
                MessageBox.Show("You have not selected any search result in the list box." + Environment.NewLine + Environment.NewLine + "If you would like to exit without selecting a search result, use the Cancel button.", "No search result selected!", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            //string selectedTitleWithoutTextInParentheses = this.resultsListBox.SelectedItem.ToString().Replace("(", "").Replace(")", ""); // Syntax of String.Replace: string Replace(string oldValue, string newValue)  << Doesn't work, removes only the parentheses themselves. This just calls string replace twice
            string selectedTitleWithoutTextInParentheses = Regex.Replace(this.resultsListBox.SelectedItem.ToString(), @" ?\(.*?\)", string.Empty); // Syntax of Regex.Replace: public string Replace(string input, string pattern, string replacement). Note the escaping of the ( and ) chars so that they aren't recognised as group markers.
            this.parent.AllTitlesListBoxItemSelectedByAdvancedSearch = selectedTitleWithoutTextInParentheses; // This works because objects are passed by reference
            this.Close();
        }

        /// <summary>
        /// Double clicking can also be used to make a selection
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void resultsListBox_DoubleClick(object sender, EventArgs e)
        {
            if (this.resultsListBox.SelectedIndex != -1) // If there is nothing selected, it is assumed the double click was aimless/accidental
                this.okButton.PerformClick();
        }
    }
}