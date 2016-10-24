/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-10-24</datecreated>
/// <summary>
///  Contains the class Program with the Main() method
/// </summary>
/// </file>

using System;
using System.Windows.Forms;

namespace PamperYourSolesShoeCatalog
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
            Application.Run(new shoeCatalogForm());
        }
    }
}
