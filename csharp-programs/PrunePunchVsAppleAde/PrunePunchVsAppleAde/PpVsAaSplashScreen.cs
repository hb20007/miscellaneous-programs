/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-10-31</datecreated>
/// <summary>
/// Part of the PpVsAaSpashScreen class with custom-written stuff
/// </summary>
/// </file>

using System.Windows.Forms;

namespace PrunePunchVsAppleAde
{
    partial class PpVsAaSplashScreen : Form
    {
        public PpVsAaSplashScreen() // In this as well as several other forms, I use a public constructor within an internal class. The internal class scope overrides the public constructor scope, making the constructor internal. The advantage of having the constructor public is that it would be easier to later update the class to public if needed
        {
            this.InitializeComponent();
        }
    }
}
