/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-11-19</datecreated>
/// <summary>
///  Contains the Student class
/// </summary>
/// </file>

namespace StudentData
{
    class Student
    {
        public string StudentID { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Major { get; set; }
        public string University { get; set; }
        public Utilities.Standings Standing { get; set; }
        public bool IsOnDeansList { get; set; }
        public Student(string ID, string firstName, string lastName, string major, string uni, Utilities.Standings year, bool isOnDeansList)
        {
            this.StudentID = ID;
            this.FirstName = firstName;
            this.LastName = lastName;
            this.Major = major;
            this.University = uni;
            this.Standing = year;
            this.IsOnDeansList = isOnDeansList;
        }
    }
}
