/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-12-08</datecreated>
/// <summary>
///  Contains the part of the class CountriesForm responsible for actions
/// </summary>
/// </file>

using System;
using System.Windows.Forms;

namespace CountriesWindowsForm
{
    public partial class CountriesForm : Form
    {
        const string country1 = "Albania", country2 = "Bhutan", country3 = "Mexico";

        public CountriesForm()
        {
            this.InitializeComponent();
            // I could not place the following 3 lines of code within InitializeComponent() because Visual Studio would delete them every time the project is rebuilt
            this.country1RadioButton.Text = CountriesForm.country1;
            this.country2RadioButton.Text = CountriesForm.country2;
            this.country3RadioButton.Text = CountriesForm.country3;
        }

        /// <summary>
        /// Displays the flag of the first country in the picture box and the name of the country in the country label
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void country1RadioButton_CheckedChanged(object sender, EventArgs e)
        {
            this.flagPictureBox.Image = Properties.Resources.Flag_of_Albania;
            this.countryLabel.Text = "Country: " + CountriesForm.country1;
        }

        /// <summary>
        /// Displays the flag of the second country in the picture box and the name of the country in the country label
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void country2RadioButton_CheckedChanged(object sender, EventArgs e)
        {
            this.flagPictureBox.Image = Properties.Resources.Flag_of_Bhutan;
            this.countryLabel.Text = "Country: " + CountriesForm.country2;
        }

        /// <summary>
        /// Displays the flag of the third country in the picture box and the name of the country in the country label
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void country3RadioButton_CheckedChanged(object sender, EventArgs e)
        {
            this.flagPictureBox.Image = Properties.Resources.Flag_of_Mexico;
            this.countryLabel.Text = "Country: " + CountriesForm.country3;
        }

        /// <summary>
        /// Hides the country name label
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void hideCountryNameCheckbox_CheckedChanged(object sender, EventArgs e)
        {
            this.countryLabel.Visible = !this.hideCountryNameCheckbox.Checked;
        }

        /// <summary>
        /// Hides the programmer name label
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void hideProgrammerNameCheckbox_CheckedChanged(object sender, EventArgs e)
        {
            this.programmerLabel.Visible = !this.hideProgrammerNameCheckbox.Checked;
        }

        /// <summary>
        /// Hides the name of the form (ie. Form.Text). The only way possible to do this is to set Form.Text = ""
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void hideFormNameCheckbox_CheckedChanged(object sender, EventArgs e)
        {
            this.Text = this.hideFormNameCheckbox.Checked ? "" : this.Text = "Countries";
        }

        /// <summary>
        /// Closes the form
        /// </summary>
        /// <param name = "sender" ></ param >
        /// < param name="e"></param>
        private void exitButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
