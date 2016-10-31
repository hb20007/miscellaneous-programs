/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-10-30</datecreated>
/// <summary>
///  Contains the part of the class PpVsAaSummaryForm dealing with the behavior of the form and its controls
/// </summary>
/// </file>

using System;
using System.Drawing; // To use Font and FontStyle
using System.Windows.Forms;

namespace PrunePunchVsAppleAde
{
    partial class PpVsAaSummaryForm : Form
    {
        /// <summary>
        /// The parent form
        /// </summary>
        private PpVsAaMainForm parent;
        public PpVsAaSummaryForm(PpVsAaMainForm parentForm) // An alternative to passing the parent form as an argument would have been to use the MdiParent and ParentForm properties
        {
            this.InitializeComponent();
            this.parent = parentForm;
            this.setTextBoxes();
        }

        /// <summary>
        /// Displays the right text in the text boxes based on information from the parent form
        /// </summary>
        private void setTextBoxes()
        {
            this.totalNumberOfVotesTextBox.Text = this.parent.NumberOfRatings.ToString();
            if (this.parent.NumberOfRatings == 0) // Avoids dividing by 0
            {
                this.meanRatingPrunePunchTextBox.Text = "No votes";
                this.meanRatingAppleAdeTextBox.Text = "No votes";
                this.winnerTextBox.Text = "No votes";
            }
            else
            { 
                this.meanRatingPrunePunchTextBox.Text = ((double)this.parent.PrunePunchTotal / this.parent.NumberOfRatings).ToString("0.#") + "/" + PpVsAaMainForm.MAXIMUM_RATING.ToString(); // The format specier used in this line and the one below it prints numbers to 1dp if they are not exact integers, in which case it does not show any decimal places
                this.meanRatingAppleAdeTextBox.Text = ((double)this.parent.AppleAdeTotal / this.parent.NumberOfRatings).ToString("0.#") + "/" + PpVsAaMainForm.MAXIMUM_RATING.ToString();
                this.winnerTextBox.Font = new Font(this.winnerTextBox.Font, FontStyle.Bold); // If the result is not the trivial "No votes" it will be printed in bold.
                this.winnerTextBox.Text = this.parent.evaluateAndReturnWinner(); 
            }
        }

        /// <summary>
        /// Closes the summary form
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void okButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
