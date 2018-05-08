/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-11-07</datecreated>
/// <summary>
/// Countains the part of the class SeferStoreAboutBox with the constructor and the assembly attribute accessors
/// </summary>
/// </file>

using System;
using System.Reflection;
using System.Windows.Forms;
using System.Drawing;

namespace SeferBookstore
{
    partial class SeferBookstoreAboutBox : Form
    {
        /// <summary>
        /// SeferBookstoreAboutBox constructor which also sets the <code>Font</code> and <code>ForeColor</code> of the form to those of the parent form, passed in as arguments
        /// </summary>
        /// <param name="parentFont">The <code>Font</code> used in the parent form</param>
        /// <param name="parentFontColor">The <code>ForeColor</code> used in the parent form</param>
        public SeferBookstoreAboutBox(Font parentFont, Color parentFontColor)
        {
            this.InitializeComponent();
            this.Font = parentFont;
            if (parentFontColor != this.ForeColor)
            {
                this.ForeColor = parentFontColor;
                this.descriptionTextBox.BackColor = Color.FromKnownColor(KnownColor.Control);
                this.descriptionTextBox.ForeColor = parentFontColor;
            }
            this.descriptionTextBox.ReadOnly = true; // ReadOnly text box text is gray. Therefore the color is changed before the text box is set to ReadOnly. BackColor must be changed too for this to work
            this.Text = String.Format("About {0}", SeferBookstoreAboutBox.AssemblyTitle);
            this.productNameLabel.Text = SeferBookstoreAboutBox.AssemblyProduct;
            this.versionLabel.Text = String.Format("Version {0}", SeferBookstoreAboutBox.AssemblyVersion);
            this.copyrightLabel.Text = SeferBookstoreAboutBox.AssemblyCopyright;
            this.companyNameLabel.Text = SeferBookstoreAboutBox.AssemblyCompany;
            this.descriptionTextBox.Text = SeferBookstoreAboutBox.AssemblyDescription;
        }

        #region Assembly Attribute Accessors

        public static string AssemblyTitle // Will be accessed by the splash screen
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

        public static string AssemblyVersion // Will be accessed by the splash screen
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

        public static string AssemblyCompany // Will be accessed by the splash screen
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