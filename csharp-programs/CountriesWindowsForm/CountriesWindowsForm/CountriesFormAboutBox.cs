/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-10-30</datecreated>
/// <summary>
///  Contains the part of the class CountriesFormAboutBox dealing with class members which are not controls and the methods acting on the controls
/// </summary>
/// </file>

using System;
using System.Reflection;
using System.Windows.Forms;

namespace CountriesWindowsForm
{
    partial class CountriesFormAboutBox : Form
    {
        public CountriesFormAboutBox()
        {
            this.InitializeComponent();
            this.Text = String.Format("About {0}", CountriesFormAboutBox.AssemblyTitle);
            this.productNameLabel.Text = CountriesFormAboutBox.AssemblyProduct; // Names for the labels have been changed to be more consistent with the styling used in this application
            this.versionLabel.Text = String.Format("Version {0}", CountriesFormAboutBox.AssemblyVersion);
            this.copyrightLabel.Text = CountriesFormAboutBox.AssemblyCopyright;
            this.companyNameLabel.Text = CountriesFormAboutBox.AssemblyCompany;
            this.descriptionTextBox.Text = CountriesFormAboutBox.AssemblyDescription;
        }

        #region Assembly Attribute Accessors

        private static string AssemblyTitle // I changed all the properties to static because they should be
        {
            get
            {
                object[] attributes = Assembly.GetExecutingAssembly().GetCustomAttributes(typeof(AssemblyTitleAttribute), false);
                if (attributes.Length > 0)
                {
                    AssemblyTitleAttribute titleAttribute = (AssemblyTitleAttribute)attributes[0];
                    if (titleAttribute.Title != "")
                    {
                        return titleAttribute.Title;
                    }
                }
                return System.IO.Path.GetFileNameWithoutExtension(Assembly.GetExecutingAssembly().CodeBase);
            }
        }

        public static string AssemblyVersion // I changed all properties to private except for this one because it will be accessed by the splash screen
        {
            get
            {
                return Assembly.GetExecutingAssembly().GetName().Version.ToString();
            }
        }

        private static string AssemblyDescription
        {
            get
            {
                object[] attributes = Assembly.GetExecutingAssembly().GetCustomAttributes(typeof(AssemblyDescriptionAttribute), false);
                if (attributes.Length == 0)
                {
                    return "";
                }
                return ((AssemblyDescriptionAttribute)attributes[0]).Description;
            }
        }

        private static string AssemblyProduct
        {
            get
            {
                object[] attributes = Assembly.GetExecutingAssembly().GetCustomAttributes(typeof(AssemblyProductAttribute), false);
                if (attributes.Length == 0)
                {
                    return "";
                }
                return ((AssemblyProductAttribute)attributes[0]).Product;
            }
        }

        private static string AssemblyCopyright
        {
            get
            {
                object[] attributes = Assembly.GetExecutingAssembly().GetCustomAttributes(typeof(AssemblyCopyrightAttribute), false);
                if (attributes.Length == 0)
                {
                    return "";
                }
                return ((AssemblyCopyrightAttribute)attributes[0]).Copyright;
            }
        }

        private static string AssemblyCompany
        {
            get
            {
                object[] attributes = Assembly.GetExecutingAssembly().GetCustomAttributes(typeof(AssemblyCompanyAttribute), false);
                if (attributes.Length == 0)
                {
                    return "";
                }
                return ((AssemblyCompanyAttribute)attributes[0]).Company;
            }
        }
        #endregion

        /// <summary>
        /// Closes the about box
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void okButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
