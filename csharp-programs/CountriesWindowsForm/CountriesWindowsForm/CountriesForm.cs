/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-12-08</datecreated>
/// <summary>
///  Contains the part of the class CountriesForm responsible for actions
/// </summary>
/// </file>

using System;
using System.Threading;
using System.Windows.Forms;

namespace CountriesWindowsForm
{
    partial class CountriesForm : Form
    {
        private const string ALBANIA_STRING = "Albania", BHUTAN_STRING = "Bhutan", MEXICO_STRING = "Mexico";

        public CountriesForm()
        {
            Thread splashScreenThread = new Thread(new ThreadStart(this.splashStart));
            splashScreenThread.Start();
            Thread.Sleep(2500);
            splashScreenThread.Abort();
            this.InitializeComponent();
            // I could not place the following 3 lines of code within InitializeComponent() because Visual Studio would delete them every time the project is rebuilt
            this.country1RadioButton.Text = CountriesForm.ALBANIA_STRING;
            this.country2RadioButton.Text = CountriesForm.BHUTAN_STRING;
            this.country3RadioButton.Text = CountriesForm.MEXICO_STRING;
        }

        /// <summary>
        /// Launches the splash screen
        /// </summary>
        private void splashStart()
        {
            Application.Run(new CountriesSplashScreenForm());
        }

        /// <summary>
        /// Displays the flag of the first country in the picture box and the name of the country in the country label
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void country1RadioButton_CheckedChanged(object sender, EventArgs e)
        {
            this.flagPictureBox.Image = Properties.Resources.Flag_of_Albania;
            this.countryLabel.Text = "Country: " + CountriesForm.ALBANIA_STRING;
        }

        /// <summary>
        /// Displays the flag of the second country in the picture box and the name of the country in the country label
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void country2RadioButton_CheckedChanged(object sender, EventArgs e)
        {
            this.flagPictureBox.Image = Properties.Resources.Flag_of_Bhutan;
            this.countryLabel.Text = "Country: " + CountriesForm.BHUTAN_STRING;
        }

        /// <summary>
        /// Displays the flag of the third country in the picture box and the name of the country in the country label
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void country3RadioButton_CheckedChanged(object sender, EventArgs e)
        {
            this.flagPictureBox.Image = Properties.Resources.Flag_of_Mexico;
            this.countryLabel.Text = "Country: " + CountriesForm.MEXICO_STRING;
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
        /// Displays the about box
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Thread aboutBoxThread = new Thread(new ThreadStart(() => Application.Run(new CountriesFormAboutBox()))); // Used the lamda expression syntax to create the aboutBoxThread for a change
            aboutBoxThread.Name = "About Form Thread"; // Used to identify the aboutBoxThread in the debugger
            aboutBoxThread.Start(); // A thread terminates when it no longer has code to execute. Therefore when the about box form is closed the aboutBoxThread will terminate and there is no need to explicitly abort it
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
