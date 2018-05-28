/// <file>
/// <author>hb20007</author>
/// <datecreated>2016-11-19</datecreated>
/// <summary>
///  Contains the static class Utilities with useful methods
/// </summary>
/// </file>

using System;
using System.IO;
using System.Windows.Forms;

namespace StudentData
{
    static class Utilities
    {
        internal enum Standings { Freshman, Sophomore, Junior, Senior };

        /// <summary>
        /// string constants with the paths of the data files used in the application
        /// </summary>
        internal const string MAJORS_FILE_NAME = "listofmajors.csv", UNIVERSITIES_FILE_NAME = "listofunis.csv", STUDENTS_FILE_NAME = "listofstudents.csv";

        /// <summary>
        /// Checks if the student inserted as a parameter is new with regards to the .csv list of students
        /// </summary>
        /// <param name="studentID">The student's ID</param>
        /// <returns>Returns <code>true</code> if the university is not in the list, else <code>false</code></returns>
        internal static bool isStudentNew(string studentID)
        {
            try
            {
                StreamReader reader = new StreamReader(File.OpenRead(Utilities.STUDENTS_FILE_NAME));
                while (!reader.EndOfStream)
                {
                    string line = reader.ReadLine(); 
                    string[] values = line.Split(',');
                    if (values[0] == studentID.Trim())
                    {
                        reader.Close();
                        return false;
                    }
                }
                reader.Close(); //reader.Close() is needed twice
                return true;
            }
            catch
            {
                MessageBox.Show($"The file {Utilities.STUDENTS_FILE_NAME} was not found", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Environment.Exit(1); // Application.Exit() and this.Close() do not work here (because this code runs before this.InitializeComponent() probably)
            }
            return false;
        }

        /// <summary>
        /// Checks if the university inserted as a parameter is new with regards to the .csv list of universities file
        /// </summary>
        /// <param name="universityName">The name of the university</param>
        /// <returns>Returns <code>true</code> if the university is not in the list, else <code>false</code></returns>
        internal static bool isUniversityNew(string universityName)
        {
            try
            {
                StreamReader reader = new StreamReader(File.OpenRead(Utilities.UNIVERSITIES_FILE_NAME));
                string line = reader.ReadLine(); // All data in the .csv file is on 1 line so while (!reader.EndOfStream) is not required
                string[] values = line.Split(',');
                for (int i = 0; i < values.Length; i++)
                    if (values[i].ToUpper() == universityName.Trim().ToUpper()) // .ToUpper() needed for both string because University names are not formatted before being stored in the database for practical reasons
                    {
                        reader.Close();
                        return false;
                    }
                reader.Close(); //reader.Close() is needed twice
                return true;
            }
            catch
            {
                MessageBox.Show($"The file {Utilities.UNIVERSITIES_FILE_NAME} was not found", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Environment.Exit(1); // Application.Exit() and this.Close() do not work here (because this code runs before this.InitializeComponent() probably)
            }
            return false;
        }

        /// <summary>
        /// Appends the new university to the list of universities .csv file
        /// </summary>
        /// <param name="universityName">The name of the university to add to the list of universities</param>
        internal static void addUniversityToList(string universityName)
        {
            try
            {
                using (StreamWriter writer = File.AppendText(Utilities.UNIVERSITIES_FILE_NAME))
                {
                    writer.Write(',' + universityName.Trim());
                } // The using block calls Dispose() and cleans the StreamWriter so writer.Close() is not required
            }
            catch
            {
                MessageBox.Show($"The file {Utilities.UNIVERSITIES_FILE_NAME} was not found", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Environment.Exit(1); // Application.Exit() and this.Close() do not work here (because this code runs before this.InitializeComponent() probably)
            }
        }

        /// <summary>
        /// Adds the new student to the .csv list of students
        /// </summary>
        /// <param name="newStudent">The new student to add to the list</param>
        internal static void addStudentToList(Student newStudent)
        {
            try
            {
                using (StreamWriter writer = File.AppendText(Utilities.STUDENTS_FILE_NAME))
                {
                    writer.Write(Environment.NewLine + newStudent.StudentID); // Environment.NewLine is used in order to write on a new line
                    writer.Write(',' + newStudent.FirstName);
                    writer.Write(',' + newStudent.LastName);
                    writer.Write(',' + newStudent.Major);
                    writer.Write(',' + newStudent.University);
                    writer.Write(',' + newStudent.Standing.ToString());
                    writer.Write(',' + newStudent.IsOnDeansList.ToString());
                } // The using block calls Dispose() and cleans the StreamWriter so writer.Close() is not required
            }
            catch
            {
                MessageBox.Show($"The file { Utilities.STUDENTS_FILE_NAME} was not found", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Environment.Exit(1); // Application.Exit() and this.Close() do not work here (because this code runs before this.InitializeComponent() probably)
            }
        }
    }
}