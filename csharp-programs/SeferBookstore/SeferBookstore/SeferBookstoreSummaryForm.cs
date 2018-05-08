/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-12-16</datecreated>
/// <summary>
/// Countains the part of the class SeferBookstoreSummaryForm with the constructor and the action of the OK button
/// </summary>
/// </file>

using System.Drawing;
using System.Windows.Forms;

namespace SeferBookstore
{
    partial class SeferBookstoreSummaryForm : Form
    {
        /// <summary>
        /// Initializes form components, sets font and font color based on parent form, initializes text boxes with default values
        /// </summary>
        /// <param name="parentForm">The parent form</param>
        public SeferBookstoreSummaryForm(SeferBookstoreMainForm parentForm)
        {
            this.InitializeComponent();
            this.Font = parentForm.Font;
            if (parentForm.ForeColor != this.ForeColor)
            {
                this.ForeColor = parentForm.ForeColor;
                this.totalSalesTextBox.BackColor = Color.FromKnownColor(KnownColor.Control);
                this.totalSalesTextBox.ForeColor = parentForm.ForeColor;
                this.totalItemsSoldTextBox.BackColor = Color.FromKnownColor(KnownColor.Control);
                this.totalItemsSoldTextBox.ForeColor = parentForm.ForeColor;
            }
            this.totalSalesTextBox.ReadOnly = true; // ReadOnly text box text is gray. Therefore the color is changed before the text box is set to ReadOnly. BackColor must be changed too for this to work
            this.totalItemsSoldTextBox.ReadOnly = true; 

            this.totalSalesTextBox.Text = parentForm.DailyTotalSales.ToString("c");
            this.totalItemsSoldTextBox.Text = parentForm.DailyTotalItemsSold.ToString();
        }

        /// <summary>
        /// Closes the summary form
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void okButton_Click(object sender, System.EventArgs e)
        {
            this.Close();
        }
    }
}