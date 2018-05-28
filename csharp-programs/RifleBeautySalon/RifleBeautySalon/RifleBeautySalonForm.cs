/// <file>
/// <author>hb20007</author>
/// <datecreated>2016-10-29</datecreated>
/// <summary>
/// Contains part of the class CrunchYourInvestmentForm dealing with the actions and events
/// </summary>
/// </file>

using System;
using System.Windows.Forms;

namespace RifleBeautySalon
{
    partial class RifleBeautySalonForm : Form
    {
        private const decimal MAKEOVER_PRICE = 125, HAIRSTYLING_PRICE = 60, MANICURE_PRICE = 35, PERMANENT_MAKEUP_PRICE = 200;

        /// <summary>
        /// The amount of disount as selected by the user
        /// </summary>
        private decimal discount; // Initialized to 0 by the C# default constructor Decimal()

        /// <summary>
        /// Price for makeover after the discount is applied
        /// </summary>
        private decimal makeoverPriceAfterDiscount;
        private decimal MakeoverPriceAfterDiscount // Private property used because setting the field needs to perform an extra action but it will not be called from another class
        { 
            get // get must be explicitly specified since I chose to define set
            {
                return this.makeoverPriceAfterDiscount;
            }
            set
            {
                this.makeoverPriceAfterDiscount = value;
                this.refreshPriceLabels(); // Every time the price is updated, the price labels are refreshed
            }
        }

        /// <summary>
        /// Price for hairstyling after the discount is applied
        /// </summary>
        private decimal hairstylingPriceAfterDiscount;
        private decimal HairstylingPriceAfterDiscount // Private property used because setting the field needs to perform an extra action but it will not be called from another class
        {
            get // get must be explicitly specified since I chose to define set
            {
                return this.hairstylingPriceAfterDiscount;
            }
            set
            {
                this.hairstylingPriceAfterDiscount = value;
                this.refreshPriceLabels(); // Every time the price is updated, the price labels are refreshed
            }
        }

        /// <summary>
        /// Price for manicure after the discount is applied
        /// </summary>
        private decimal manicurePriceAfterDiscount; 
        private decimal ManicurePriceAfterDiscount // Private property used because setting the field needs to perform an extra action but it will not be called from another class
        {
            get // get must be explicitly specified since I chose to define set
            {
                return this.manicurePriceAfterDiscount;
            }
            set
            {
                this.manicurePriceAfterDiscount = value;
                this.refreshPriceLabels(); // Every time the price is updated, the price labels are refreshed
            }
        }

        /// <summary>
        /// Price for permanent makeup after the discount is applied
        /// </summary>
        private decimal permanentMakeupPriceAfterDiscount;
        private decimal PermanentMakeupPriceAfterDiscount // Private property used because setting the field needs to perform an extra action but it will not be called from another class
        {
            get // get must be explicitly specified since I chose to define set
            {
                return this.permanentMakeupPriceAfterDiscount;
            }
            set
            {
                this.permanentMakeupPriceAfterDiscount = value;
                this.refreshPriceLabels(); // Every time the price is updated, the price labels are refreshed
            }
        }

        public RifleBeautySalonForm()
        {
            this.InitializeComponent();
            // Initializes the prices since discount begins as '0'
            this.updatePrices();
            // Initializes the price labels
            this.refreshPriceLabels();
        }

        /// <summary>
        /// Updates price properties with regards to the chosen discount
        /// </summary>
        private void updatePrices()
        {
            this.MakeoverPriceAfterDiscount = RifleBeautySalonForm.MAKEOVER_PRICE - this.discount * RifleBeautySalonForm.MAKEOVER_PRICE;
            this.HairstylingPriceAfterDiscount = RifleBeautySalonForm.HAIRSTYLING_PRICE - this.discount * RifleBeautySalonForm.HAIRSTYLING_PRICE;
            this.ManicurePriceAfterDiscount = RifleBeautySalonForm.MANICURE_PRICE - this.discount * RifleBeautySalonForm.MANICURE_PRICE;
            this.PermanentMakeupPriceAfterDiscount = RifleBeautySalonForm.PERMANENT_MAKEUP_PRICE - this.discount * RifleBeautySalonForm.PERMANENT_MAKEUP_PRICE;
        }

        /// <summary>
        /// Updates prices shown in the price labels to reflect new changes in prices
        /// </summary>
        private void refreshPriceLabels()
        {
            this.manicurePriceLabel.Text = "........................................................................ ($" + this.ManicurePriceAfterDiscount.ToString("0") + ")"; // All prices are rounded to the nearest whole number. Rounding away from zero is used by the "0" custom specifier
            this.permanentMakeupPriceLabel.Text = "...................................................... ($" + this.PermanentMakeupPriceAfterDiscount.ToString("0") + ")";
            this.hairstylingPriceLabel.Text = "...................................................................... ($" + this.HairstylingPriceAfterDiscount.ToString("0") + ")";
            this.makeoverPriceLabel.Text = ".................................................................... ($" + this.MakeoverPriceAfterDiscount.ToString("0") + ")";
        }

        /// <summary>
        /// Sets the discount field to 0 and updates the prices if the radio button is checked
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void noneRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (this.noneRadioButton.Checked)
            {
                this.discount = 0;
                this.updatePrices();
            }
            this.totalPriceTextBox.Clear(); // The total price text box which could have a previous total is cleared when the prices are changed in order to avoid confusion
        }

        /// <summary>
        /// Sets the discount field to 0.1 and updates the prices if the radio button is checked
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void tenPercentRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (this.tenPercentRadioButton.Checked)
            {
                this.discount = 0.1m;
                this.updatePrices();
            }
            this.totalPriceTextBox.Clear(); // The total price text box which could have a previous total is cleared when the prices are changed in order to avoid confusion
        }

        /// <summary>
        /// Sets the discount field to 0.2 and updates the prices if the radio button is checked
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void twentyPercentRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (this.twentyPercentRadioButton.Checked)
            {
                this.discount = 0.2m;
                this.updatePrices();
            }
            this.totalPriceTextBox.Clear(); // The total price text box which could have a previous total is cleared when the prices are changed in order to avoid confusion
        }

        /// <summary>
        /// Shows the corresponding price label if checked, hides it if unchecked
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void makeoverCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (this.makeoverCheckBox.Checked)
                this.makeoverPriceLabel.Show();
            else
                this.makeoverPriceLabel.Hide();
            this.totalPriceTextBox.Clear(); // The total price text box which could have a previous total is cleared when the prices are changed in order to avoid confusion
        }

        /// <summary>
        /// Shows the corresponding price label if checked, hides it if unchecked
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void hairstylingCheckbox_CheckedChanged(object sender, EventArgs e)
        {
            if (this.hairstylingCheckbox.Checked)
                this.hairstylingPriceLabel.Show();
            else
                this.hairstylingPriceLabel.Hide();
            this.totalPriceTextBox.Clear(); // The total price text box which could have a previous total is cleared when the prices are changed in order to avoid confusion
        }

        /// <summary>
        /// Shows the corresponding price label if checked, hides it if unchecked
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void manicureCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (this.manicureCheckBox.Checked)
                this.manicurePriceLabel.Show();
            else
                this.manicurePriceLabel.Hide();
            this.totalPriceTextBox.Clear(); // The total price text box which could have a previous total is cleared when the prices are changed in order to avoid confusion
        }

        /// <summary>
        /// Shows the corresponding price label if checked, hides it if unchecked
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void permanentMakeupCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (this.permanentMakeupCheckBox.Checked)
                this.permanentMakeupPriceLabel.Show();
            else
                this.permanentMakeupPriceLabel.Hide();
            this.totalPriceTextBox.Clear(); // The total price text box which could have a previous total is cleared when the prices are changed in order to avoid confusion
        }

        /// <summary>
        /// Resets form to its initial state
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void clearButton_Click(object sender, EventArgs e)
        {
            this.noneRadioButton.Checked = true;
            this.makeoverCheckBox.Checked = false;
            this.hairstylingCheckbox.Checked = false;
            this.manicureCheckBox.Checked = false;
            this.permanentMakeupCheckBox.Checked = false;
            this.totalPriceTextBox.Text = "";
        }

        /// <summary>
        /// Calculates the displays the total cost of all selected services
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void calculateButton_Click(object sender, EventArgs e)
        {
            decimal total = 0;
            if (this.makeoverCheckBox.Checked)
                total += this.MakeoverPriceAfterDiscount;
            if (this.hairstylingCheckbox.Checked)
                total += this.HairstylingPriceAfterDiscount;
            if (this.manicureCheckBox.Checked)
                total += this.ManicurePriceAfterDiscount;
            if (this.permanentMakeupCheckBox.Checked)
                total += this.PermanentMakeupPriceAfterDiscount;
            this.totalPriceTextBox.Text = "$" + String.Format("{0:0}", total); // Used String.Format instead of .ToString() for a change
        }

        /// <summary>
        /// Exits the program
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void exitButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}