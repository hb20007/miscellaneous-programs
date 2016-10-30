/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-10-27</datecreated>
/// <summary>
/// Contains part of the class CrunchYourInvestmentForm dealing with the actions and events
/// </summary>
/// </file>

using System;
using System.Windows.Forms;
using System.Globalization;

namespace CrunchYourInvestment
{
    partial class CrunchYourInvestmentForm : Form
    {
        /// <summary>
        /// Used to store the starting investment. It is necessary because the starting investment will be formatted to a currency and then it will be parsed again to a decimal to use it for the calculation. However, formatting to a currency does not allow the string to be parsed as a decimal.
        /// </summary>
        private decimal startingInvestment; // Initialized to 0 (C# default constructor)

        /// <summary>
        /// Becomes true if the value in the starting investment text box is correctly inserted
        /// </summary>
        private bool startingInvestmentEnteredCorrectly; // Initialized to false (C# default constructor)

        /// <summary>
        /// Becomes true if the value in the interest rate text box is correctly inserted
        /// </summary>
        private bool interestRateEnteredCorrectly; // Initialized to false (C# default constructor)

        /// <summary>
        /// Becomes true if the value in the number of years text box is correctly inserted
        /// </summary>
        private bool numberOfYearsEnteredCorrectly; // Initialized to false (C# default constructor)
  
        public CrunchYourInvestmentForm()
        {
            this.InitializeComponent();
            this.startingInvestmentTextBox.LostFocus += this.startingInvestmentTextBox_LostFocus; // Registering a function to an event in order to "use" the event. Alternative to making an event handler for this.startingInvestmentTextBox.LostFocus
            this.interestRateTextBox.LostFocus += this.interestRateTextBox_LostFocus;
            this.numberOfYearsTextBox.LostFocus += this.numberOfYearsTextBox_LostFocus;
        }

        /// <summary>
        /// This method is used because the same code will be needed several times
        /// </summary>
        /// <param name="errorString">A string representing the input error</param>
        /// <param name="wrongInputTextBox">The text box where the wrong input has been inserted</param>
        private void dealWithWrongInput(string errorString, TextBox wrongInputTextBox)
        {
                DialogResult result = MessageBox.Show(errorString, "Incorrect input", MessageBoxButtons.OKCancel, MessageBoxIcon.Asterisk);
                if (result == DialogResult.OK) // This is necessary because the user should have the option to choose Cancel in case they want to exit the form without being prompted to fix their entry in the field
                {
                    wrongInputTextBox.Focus();
                    wrongInputTextBox.SelectAll();
                }
        }

        /// <summary>
        /// This method is called when the user inputs in the 3 text fields are determined to be correct.
        /// </summary>
        private void actionOnAllInputsCorrect()
        {
            this.calculateButton.Enabled = true;
            this.calculateButton.Cursor = Cursors.Hand;
            //this.AcceptButton = calculateButton; This line doesn't change anything because focus will go to the calculate button and using tab before pressing it will only change the focus to other buttons while the AcceptButton is useful when pressing enter from a text field or radio button etc
            this.calculateButton.Focus(); // This line is essential because the focus goes to the Clear button. Even if the Calculate button were next in the tab order, the focus will still go to the other button because the Calculate button was disabled the moment the event was triggered
            this.startingInvestmentTextBox.Enabled = false;
            this.interestRateTextBox.Enabled = false;
            this.numberOfYearsTextBox.Enabled = false;
        }

        /// <summary>
        /// When the user is done typing into the startingInvestmentTextBox and the focus is lost, the field is formatted as a currency. For this to be possible, I also implement checking for the right input at this point
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void startingInvestmentTextBox_LostFocus(object sender, EventArgs e)
        {
            if (!this.startingInvestmentTextBox.Text.Equals("")) // The user may choose to leave the field empty for now
            {
                string currencySymbol = CultureInfo.CurrentCulture.NumberFormat.CurrencySymbol; // Retrieves appropriate currency symbol
                string errorMessage = ""; // Will be given a value depending on the error and will be printed in a MessageBox
                if (this.startingInvestmentTextBox.Text.StartsWith("-") || this.startingInvestmentTextBox.Text.StartsWith(currencySymbol + "-")) // The user may insert the currency symbol before the negative sign
                    errorMessage = "The value inserted should be a positive number.";
                try
                {
                    if (this.startingInvestmentTextBox.Text.StartsWith(currencySymbol)) // If the value has a currency symbol it is removed in order for parsing to proceed
                    {
                        string startingInvestmentWithoutCurrencySign = this.startingInvestmentTextBox.Text.Substring(1); // A substring from the 2nd character onwards
                        this.startingInvestment = decimal.Parse(startingInvestmentWithoutCurrencySign);
                    }
                    else
                        this.startingInvestment = decimal.Parse(this.startingInvestmentTextBox.Text);
                }
                catch (FormatException)
                {
                    errorMessage = "The value inserted should be a valid number."; // If the previous error message had been set, it will be replaced by this one because it would be more relevant
                }
                if (!errorMessage.Equals("")) // That is if there is an error 
                {
                    this.dealWithWrongInput(errorMessage, this.startingInvestmentTextBox);
                    this.startingInvestmentEnteredCorrectly = false; // Required in case the user inserts a correct input but later changes it to a wrong input
                }
                else
                {
                    this.startingInvestmentTextBox.Text = this.startingInvestment.ToString("c");
                    this.startingInvestmentEnteredCorrectly = true;
                    if (this.interestRateEnteredCorrectly && this.numberOfYearsEnteredCorrectly) // If there is no error and if the 2 other fields are inserted correctly the correct button is unlocked. The correct button must start in the disabled state because if the user chooses to calculate at the wrong value, both the lost focus error and the calculation error are triggered at the same time. Also the 3 fields will be disabled since leaving them enabled will result in yet another situation with an endless loop of message boxes
                        this.actionOnAllInputsCorrect();
                }
            }
        }

        /// <summary>
        /// If the user presses Enter, focus is taken to the next text box. This is a useful feature since the form has no AcceptButton
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void startingInvestmentTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
                //this.interestRateTextBox.Focus();
                SendKeys.Send("{TAB}"); // Same effect, less characters
        }

        /// <summary>
        /// When the user is done typing into the interestRateTextBox and the focus is lost, the field is formatted as a fixed-point number with 2 decimal places. For this to be possible, I also implement checking for the right input at this point
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void interestRateTextBox_LostFocus(object sender, EventArgs e)
        {
            if (!this.interestRateTextBox.Text.Equals("")) // The user may choose to leave the field empty for now
            {
                string errorMessage = ""; // Will be given a value depending on the error and will be printed in a MessageBox
                if (this.interestRateTextBox.Text.StartsWith("-"))
                    errorMessage = "The value inserted should be a positive number.";
                try
                {
                    decimal tempInterestRate = decimal.Parse(this.interestRateTextBox.Text);
                    this.interestRateTextBox.Text = tempInterestRate.ToString("f2");
                }
                catch (FormatException)
                {
                    errorMessage = "The value inserted should be a valid number."; // If the previous error message had been set, it will be replaced by this one because it would be more relevant
                }
                if (!errorMessage.Equals("")) // That is if there is an error
                { 
                    this.dealWithWrongInput(errorMessage, this.interestRateTextBox);
                    this.interestRateEnteredCorrectly= false; // Required in case the user inserts a correct input but later changes it to a wrong input
                }
                else
                {
                    this.interestRateEnteredCorrectly = true;
                    if (this.startingInvestmentEnteredCorrectly && this.numberOfYearsEnteredCorrectly) // If there is no error and if the 2 other fields are inserted correctly the correct button is unlocked. The correct button must start in the disabled state because if the user chooses to calculate at the wrong value, both the lost focus error and the calculation error are triggered at the same time. Also the 3 fields will be disabled since leaving them enabled will result in yet another situation with an endless loop of message boxes
                        this.actionOnAllInputsCorrect();
                }
            }
        }

        /// <summary>
        /// If the user presses Enter, focus is taken to the next text box. This is a useful feature since the form has no AcceptButton
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void interestRateTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
                //this.numberOfYearsTextBox.Focus();
                SendKeys.Send("{TAB}"); // Same effect, less characters
        }

        /// <summary>
        /// When the user is done typing into the numberOfYearsTextBox and the focus is lost, the field is checked for correct input since this check happens to the other fields as well
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void numberOfYearsTextBox_LostFocus(object sender, EventArgs e)
        {
            if (!this.numberOfYearsTextBox.Text.Equals("")) // The user may choose to leave the field empty for now
            {
                string errorMessage = ""; // Will be given a value depending on the error and will be printed in a MessageBox
                if (this.numberOfYearsTextBox.Text.StartsWith("-"))
                    errorMessage = "The value inserted should be a positive integer.";
                try
                {
                    int tempNumberOfYears = int.Parse(this.numberOfYearsTextBox.Text);
                    this.numberOfYearsTextBox.Text = tempNumberOfYears.ToString();
                }
                catch (FormatException)
                {
                    errorMessage = "The value inserted should be a valid integer."; // If the previous error message had been set, it will be replaced by this one because it would be more relevant
                }
                if (!errorMessage.Equals("")) // That is if there is an error
                {
                    this.dealWithWrongInput(errorMessage, this.numberOfYearsTextBox);
                    this.numberOfYearsEnteredCorrectly = false; // Required in case the user inserts a correct input but later changes it to a wrong input
                }
                else
                {
                    this.numberOfYearsEnteredCorrectly = true;
                    if (this.startingInvestmentEnteredCorrectly && this.interestRateEnteredCorrectly) // If there is no error and if the 2 other fields are inserted correctly the correct button is unlocked. The correct button must start in the disabled state because if the user chooses to calculate at the wrong value, both the lost focus error and the calculation error are triggered at the same time. Also the 3 fields will be disabled since leaving them enabled will result in yet another situation with an endless loop of message boxes
                        this.actionOnAllInputsCorrect();
                }
            }
        }

        /// <summary>
        /// Since this is the last text box, pressing enter will go ahead and perform the calculation. This is important so that the user doesn't need to remove focus from the text box in order for the Calculate button to appear
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void numberOfYearsTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                //SendKeys.Send("{TAB}"); // This line actually returns from the method. So the code below would not be executed. That's why I replaced it with the one below it.
                this.horizontalDividerLabel.Focus(); // We take the focus away from the text box in order to run the verification code in that event. Calling numberOfYearsTextBox_LostFocus() explicitly would be problematic since the code would have executed twice, once because of the explicit call and another because the focus would have been lost when the text box would appear on an invalid entry 
                if (startingInvestmentEnteredCorrectly && interestRateEnteredCorrectly && numberOfYearsEnteredCorrectly)
                    calculateButton_Click(sender, e);
            }
        }

        /// <summary>
        /// Clears all the text fields
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void clearButton_Click(object sender, EventArgs e)
        {
            this.startingInvestmentTextBox.Clear();
            this.interestRateTextBox.Clear();
            this.numberOfYearsTextBox.Clear();
            this.futureValueTextBox.Clear();
            this.startingInvestmentTextBox.Enabled = true;
            this.interestRateTextBox.Enabled = true;
            this.numberOfYearsTextBox.Enabled = true;
            this.futureValueTextBox.Enabled = false;
            this.calculateButton.Enabled = false;
            this.calculateButton.Cursor = Cursors.Arrow;
            this.startingInvestmentTextBox.Focus();
            // The 3 lines below are essential because these fields will remain true on form clear since they did not gain and lose focus for their respective _LostFocus() methods to run
            this.startingInvestmentEnteredCorrectly = false;
            this.interestRateEnteredCorrectly = false;
            this.numberOfYearsEnteredCorrectly = false;
        }
        
        /// <summary>
        /// Calculates the future value using the compound interest formula
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void calculateButton_Click(object sender, EventArgs e)
        {
            // The currency and rate values inserted by the user are decimal values since decimal is the most appropriate data type for financial quantities
            decimal amount_decimal = this.startingInvestment, rate_decimal = decimal.Parse(this.interestRateTextBox.Text); // in this method .Parse() is used without try catch since the input was verified to be correct before the Calculate button was enabled
            int years = int.Parse(this.numberOfYearsTextBox.Text);
            // amount and rate are converted to doubles. rate is converted to double because Math.Pow() is not defined for a decimal. As for amount, it is converted to double because the * operator cannot take a decimal and a double
            double amount_double = Convert.ToDouble(amount_decimal), rate_double = Convert.ToDouble(rate_decimal);
            // rateCalculation refers to the part of the formula involving the term with the indice
            double rateCalculation_double = Math.Pow((1 + rate_double), years);
            // The futureValue is calculated as a double
            double futureValue_double = amount_double * rateCalculation_double;
            // futureValue is converted to a decimal with 2 dps. This is achieved by multiplying by 100, rounding to the nearest integer and then dividing by 100 since the Math.Round() function rounds to the nearest integer
            futureValue_double *= 100;
            futureValue_double = Math.Round(futureValue_double, MidpointRounding.AwayFromZero); // Rounding away from zero at the midpoint is preferable over the default banker's rouding since there aren't repeat calculations
            try
            {
                decimal futureValue_decimal = Convert.ToDecimal(futureValue_double);
                futureValue_decimal /= 100;
                this.futureValueTextBox.Enabled = true;
                this.futureValueTextBox.Text = futureValue_decimal.ToString("c");
            }
            catch (OverflowException)
            {
                DialogResult result = MessageBox.Show("The numbers entered were too large.\nAll fields have been cleared.\nEnter realistic numbers!", "Overflow", MessageBoxButtons.OK, MessageBoxIcon.Error);
                clearButton_Click(sender, e);
            }
        }

        /// <summary>
        /// Exits the form
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void exitButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}