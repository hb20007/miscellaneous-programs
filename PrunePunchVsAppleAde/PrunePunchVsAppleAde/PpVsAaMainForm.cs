/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-10-30</datecreated>
/// <summary>
///  Contains the part of the class PpVsAaMainForm dealing with the events
/// </summary>
/// </file>

using System;
using System.Windows.Forms;
using System.Threading;

namespace PrunePunchVsAppleAde
{
    partial class PpVsAaMainForm : Form
    {
        public const int MAXIMUM_RATING = 10;

        /// <summary>
        /// The total score for Prune Punch. Initialized to 0 by the c# default constructor
        /// </summary>
        public int PrunePunchTotal { get; private set; } = 0; // Along with the properties below, it is public because it will be accessed from the summary form class. However the mutator is private since it needs to be read only from outside the class

        /// <summary>
        /// The total score for Apple Ade. Initialized to 0 by the c# default constructor
        /// </summary>
        public int AppleAdeTotal { get; private set; } = 0;

        /// <summary>
        /// Number of ratings made so far (same number for both drinks). Initialized to 0 by the c# default constructor
        /// </summary>
        private int numberOfRatings;
        public int NumberOfRatings { get { return this.numberOfRatings; } } // There is no setter since this is effectively a counter and every time it is 'set' is will just be incremented by 1. This is taken care of by the private incrementNumberOfRatings() method
        public PpVsAaMainForm()
        {
            this.numberOfRatings = 0;
            Thread splashScreenThread = new Thread(new ThreadStart(splashStart));
            splashScreenThread.Start();
            Thread.Sleep(2000);
            splashScreenThread.Abort();
            this.InitializeComponent();
            // Initializing the labels with the initial rating of 1:
            this.refreshPrunePunchRatingLabel();
            this.refreshAppleAdeRatingLabel();
        }

        /// <summary>
        /// Returns the winner (ie. drink with higher average vote which is effectively a higher total score because both drinks have the same number of ratings)
        /// </summary>
        /// <returns>Returns <code>"Prune Punch™</code> if the total for Prune Punch™ is greater, <code>Apple Ade™</code> if the total for Apple Ade™ is the greater and <code>"Draw!"</code> if it is a draw</returns>
        public string evaluateAndReturnWinner()
        {
            if (this.PrunePunchTotal > this.AppleAdeTotal)
                return "Prune Punch™";
            if (this.PrunePunchTotal < this.AppleAdeTotal)
                return "Apple Ade™";
            return "Draw!";
        }

        /// <summary>
        /// Launches the splash screen
        /// </summary>
        private void splashStart()
        {
            Application.Run(new PpVsAaSplashScreen());
        }

        /// <summary>
        /// Launches the about box
        /// </summary>
        private void aboutStart()
        {
            Application.Run(new PpVsAaAboutBox());
        }

        /// <summary>
        /// Launches the summary form
        /// </summary>
        private void summaryStart() 
        {
            Application.Run(new PpVsAaSummaryForm(this)); // The parent form is passed into the child form via the constructor in order to have an accessible named instance of the main form in summary form in order to access main form's non-static members from there
        }

        /// <summary>
        /// Increments the numberOfRatings field
        /// </summary>
        private void incrementNumberOfRatings()
        {
            this.numberOfRatings++;
        }

        /// <summary>
        /// Refreshes the rating displayed in the Prune Prunch rating label
        /// </summary>
        private void refreshPrunePunchRatingLabel()
        {   
            this.prunePunchRatingLabel.Text = this.prunePunchTrackBar.Value.ToString() + "/" + PpVsAaMainForm.MAXIMUM_RATING; 
        }

        /// <summary>
        /// Refreshes the rating displayed in the Apple Ade rating label
        /// </summary>
        private void refreshAppleAdeRatingLabel()
        {
            this.appleAdeRatingLabel.Text = this.appleAdeTrackBar.Value.ToString() + "/" + PpVsAaMainForm.MAXIMUM_RATING;
        }

        /// <summary>
        /// Calls the method to refresh the Prune Punch rating label when Value is changed
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void prunePunchTrackBar_ValueChanged(object sender, EventArgs e) // This method is used instead of _Scroll because _Scroll will not fire when the Value is set to 1 when the rating is reset but this will
        {
            this.refreshPrunePunchRatingLabel();
        }

        /// <summary>
        /// Calls the method to refresh the Apple Ade rating label when Value is changed
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void appleAdeTrackBar_ValueChanged(object sender, EventArgs e) // This method is used instead of _Scroll because _Scroll will not fire when the Value is set to 1 when the rating is reset but this will
        {
            this.refreshAppleAdeRatingLabel();
        }

        /// <summary>
        /// Updates the totals for the 2 drinks, increments the number of ratings, resets the track bars and displays a message box to indicate the user that their ratings have successfully been registered
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void addYourScoresButton_Click(object sender, EventArgs e) // The actual ratings are not stored by the application since that is not necessary for the desired functionality
        {
            this.PrunePunchTotal += this.prunePunchTrackBar.Value;
            this.AppleAdeTotal += this.appleAdeTrackBar.Value;
            this.incrementNumberOfRatings();
            this.prunePunchTrackBar.Value = this.prunePunchTrackBar.Minimum;
            this.appleAdeTrackBar.Value = this.appleAdeTrackBar.Minimum;
            MessageBox.Show("Your ratings have been successfully registered!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        /// <summary>
        /// Closes the program
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        /// <summary>
        /// Another way to add the scores
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void addYourScoresToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.addYourScoresButton_Click(sender, e);
        }

        /// <summary>
        /// Displays the summary form
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void summaryToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Thread summaryFormThread = new Thread(new ThreadStart(summaryStart));
            summaryFormThread.Start();
        }

        /// <summary>
        /// Displays the about box
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Thread aboutBoxThread = new Thread(new ThreadStart(aboutStart));
            aboutBoxThread.Start();
        }
    }
}
