/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-10-29</datecreated>
/// <summary>
/// Contains Main(). Launches an instance of RifleBeautySalonForm
/// </summary>
/// </file>

using System;
using System.Windows.Forms;

namespace RifleBeautySalon
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
            Application.Run(new RifleBeautySalonForm());
        }
    }
}