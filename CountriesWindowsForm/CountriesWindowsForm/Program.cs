/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-12-08</datecreated>
/// <summary>
///  Countains the class Program which has the Main() method
/// </summary>
/// </file>

using System;
using System.Windows.Forms;

namespace CountriesWindowsForm
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
            Application.Run(new CountriesForm());
        }
    }
}
