/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-10-27</datecreated>
/// <summary>
/// Contains the Program static class with Main()
/// </summary>
/// </file>

using System;
using System.Windows.Forms;

namespace CrunchYourInvestment
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
            Application.Run(new CrunchYourInvestmentForm());
        }
    }
}
