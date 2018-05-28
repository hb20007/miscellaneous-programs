/// <file>
/// <author>hb20007</author>
/// <datecreated>2016-10-30</datecreated>
/// <summary>
/// Contains the Program static class with Main()
/// </summary>
/// </file>

using System;
using System.Windows.Forms;

namespace PrunePunchVsAppleAde
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new PpVsAaMainForm());
        }
    }
}
