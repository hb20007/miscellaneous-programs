/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-11-07</datecreated>
/// <summary>
/// Countains the part of the class SeferBookstoreSplashScreen with the constructor
/// </summary>
/// </file>

using System.Windows.Forms;

namespace SeferBookstore
{
    partial class SeferBookStoreSplashScreen : Form
    {
        public SeferBookStoreSplashScreen()
        {
            this.InitializeComponent();
            this.splashScreenMainLabel.Text = SeferBookstoreAboutBox.AssemblyTitle + " by " + SeferBookstoreAboutBox.AssemblyCompany;
            this.splashFormVersionLabel.Text = "v" + SeferBookstoreAboutBox.AssemblyVersion.Substring(0, 3); // I use the substring function because I want to display only the first 2 numbers of the version number
        }
    }
}