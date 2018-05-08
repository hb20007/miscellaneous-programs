/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-11-07</datecreated>
/// <summary>
/// Countains the static class Program with Main()
/// </summary>
/// </file>

using System;
using System.Windows.Forms;

namespace SeferBookstore
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
            Application.Run(new SeferBookstoreMainForm());
        }
    }
}