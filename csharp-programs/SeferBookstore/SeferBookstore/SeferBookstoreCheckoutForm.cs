/// <file>
/// <author>hb20007</author>
/// <datecreated>2016-12-23</datecreated>
/// <summary>
/// Countains the part of the class SeferBookstoreCheckoutForm with my code
/// </summary>
/// </file>

using System;
using System.IO;
using System.Drawing;
using System.Windows.Forms;

namespace SeferBookstore
{
    partial class SeferBookstoreCheckoutForm : Form
    {
        private SeferBookstoreMainForm parent;

        // The file countries.csv was obtained from http://blog.plsoucy.com/2012/04/iso-3166-country-code-list-csv-sql/
        // It was edited as follows: Some country names were simplified
        internal const string LIST_OF_COUNTRIES_FILE_NAME = "countries.csv";

        /// <summary>
        /// The price for priority delivery
        /// </summary>
        internal const decimal PRIORITY_DELIVERY_PRICE = 10m;

        /// <summary>
        /// The price for 24 hour delivery
        /// </summary>
        internal const decimal TWENTY_FOUR_HOUR_DELIVERY_PRICE = 20m;

        /// <summary>
        /// The price for gift wrapping
        /// </summary>
        internal const decimal GIFT_WRAPPING_PRICE = 1m;

        /// <summary>
        /// The price for making a book hardcover
        /// </summary>
        internal const decimal HARDCOVER_PRICE_PER_BOOK = 5m;

        /// <summary>
        /// The total price
        /// </summary>
        private decimal totalPrice;

        /// <summary>
        /// Calculates total price, initializes component, combo box, sets fonts and colors, appends dynamic information to labels, initialzes text boxes with default values determined at runtime
        /// </summary>
        /// <param name="parentForm">The parent form</param>
        public SeferBookstoreCheckoutForm(SeferBookstoreMainForm parentForm)
        {
            this.parent = parentForm;
            this.totalPrice = this.parent.NumberOfBooksOrdered * SeferBookstoreMainForm.PRICE_PER_BOOK;

            this.InitializeComponent();
            this.initializeComboBox();
            this.setFontAndColors();

            this.priorityDeliveryRadioButton.Text += " ( + " + SeferBookstoreCheckoutForm.PRIORITY_DELIVERY_PRICE.ToString("c") + " )";
            this.twentyFourHoursRadioButton.Text += " ( + " + SeferBookstoreCheckoutForm.TWENTY_FOUR_HOUR_DELIVERY_PRICE.ToString("c") + " )";
            this.giftWrappingCheckBox.Text += " ( + " + SeferBookstoreCheckoutForm.GIFT_WRAPPING_PRICE.ToString("c") + " )";
            this.hardcoverCheckBox.Text += " ( + " + SeferBookstoreCheckoutForm.HARDCOVER_PRICE_PER_BOOK.ToString("c") + " per book )";

            this.numberOfBooksTextBox.Text = this.parent.NumberOfBooksOrdered.ToString();
            this.totalPriceTextBox.Text = totalPrice.ToString("c");
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
                this.numberOfBooksTextBox.BackColor = Color.FromKnownColor(KnownColor.Control);
                this.numberOfBooksTextBox.ForeColor = this.parent.ForeColor;
                this.totalPriceTextBox.BackColor = Color.FromKnownColor(KnownColor.Control);
                this.totalPriceTextBox.ForeColor = this.parent.ForeColor;
                this.countriesComboBox.ForeColor = this.parent.ForeColor;
                this.shippingOptionsGroupBox.ForeColor = this.parent.ForeColor;
            }
            this.numberOfBooksTextBox.ReadOnly = true; // ReadOnly text box text is gray. Therefore the color is changed before the text box is set to ReadOnly. BackColor must be changed too for this to work
            this.totalPriceTextBox.ReadOnly = true;
        }

        /// <summary>
        /// Initializes the combo box with the names of all countries loaded from file
        /// </summary>
        private void initializeComboBox()
        {
            try
            {
                StreamReader reader = new StreamReader(File.OpenRead(SeferBookstoreCheckoutForm.LIST_OF_COUNTRIES_FILE_NAME));
                string line = reader.ReadLine(); // The first line is passed by because it has the column headings
                string[] values;
                while (!reader.EndOfStream)
                {
                    line = reader.ReadLine();
                    values = line.Split(',');
                    this.countriesComboBox.Items.Add(values[1]); // The second column in the .csv file has the country names 
                }
                reader.Close();
            }
            catch (FileNotFoundException)
            {
                MessageBox.Show(String.Format("The file {0} was not found in {1}", SeferBookstoreCheckoutForm.LIST_OF_COUNTRIES_FILE_NAME, Directory.GetCurrentDirectory()), "Fatal error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Environment.Exit(1);
            }
            this.countriesComboBox.Sorted = true; // The items in the .csv were sorted by a field other than country name so this is required
            this.countriesComboBox.SelectedIndex = 0; // The first country is displayed
            // NB: Some country names have special characters which may not be displayed properly in some fonts. Arial supports those characters which is why it's the default font (of the parent and carried over to child forms including this)
        }

        /// <summary>
        /// Modifies the total price to include priority delivery charges
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void priorityDeliveryRadioButton_CheckedChanged(object sender, System.EventArgs e)
        {
            if (this.priorityDeliveryRadioButton.Checked)
                this.totalPrice += SeferBookstoreCheckoutForm.PRIORITY_DELIVERY_PRICE;
            else
                this.totalPrice -= SeferBookstoreCheckoutForm.PRIORITY_DELIVERY_PRICE;
            this.totalPriceTextBox.Text = this.totalPrice.ToString("c");
        }

        /// <summary>
        /// Modifies the total price to include 24 hours delivery charges
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void twentyFourHoursRadioButton_CheckedChanged(object sender, System.EventArgs e)
        {
            if (this.twentyFourHoursRadioButton.Checked)
                this.totalPrice += SeferBookstoreCheckoutForm.TWENTY_FOUR_HOUR_DELIVERY_PRICE;
            else
                this.totalPrice -= SeferBookstoreCheckoutForm.TWENTY_FOUR_HOUR_DELIVERY_PRICE;
            this.totalPriceTextBox.Text = this.totalPrice.ToString("c");
        }

        /// <summary>
        /// Modifies the total price to include the gift wrapping charge
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void giftWrappingCheckBox_CheckedChanged(object sender, System.EventArgs e)
        {
            if (this.giftWrappingCheckBox.Checked)
                this.totalPrice += SeferBookstoreCheckoutForm.GIFT_WRAPPING_PRICE;
            else
                this.totalPrice -= SeferBookstoreCheckoutForm.GIFT_WRAPPING_PRICE;
            this.totalPriceTextBox.Text = this.totalPrice.ToString("c");
        }

        /// <summary>
        /// Modifies the total price to include the extra charges of ordering hardcover books
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void hardcoverCheckBox_CheckedChanged(object sender, System.EventArgs e)
        {
            if (this.hardcoverCheckBox.Checked)
                this.totalPrice += (SeferBookstoreCheckoutForm.HARDCOVER_PRICE_PER_BOOK * this.parent.NumberOfBooksOrdered);
            else
                this.totalPrice -= (SeferBookstoreCheckoutForm.HARDCOVER_PRICE_PER_BOOK * this.parent.NumberOfBooksOrdered);
            this.totalPriceTextBox.Text = this.totalPrice.ToString("c");
        }

        /// <summary>
        /// Closes the form
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void cancelButton_Click(object sender, System.EventArgs e)
        {
            this.Close();
        }

        /// <summary>
        /// Displays a thank you message, modifies the daily summary variables in the parent form
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void proceedButton_Click(object sender, System.EventArgs e)
        {
            this.Close();
            MessageBox.Show("Thank you for the purchase!", "Order successful");
            this.parent.DailyTotalItemsSold += parent.NumberOfBooksOrdered;
            this.parent.DailyTotalSales += this.totalPrice;
        }
    }
}