/// <file>
/// <author>hb20007</author>
/// <datecreated>2016-11-19</datecreated>
/// <summary>
///  Contains the class Program with Main()
/// </summary>
/// </file>

using System;
using System.Windows.Forms;

namespace StudentData
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
            Application.Run(new StudentDataMainForm());
        }
    }
}