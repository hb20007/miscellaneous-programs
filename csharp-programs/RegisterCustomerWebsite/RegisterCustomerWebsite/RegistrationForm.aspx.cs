/// <file>
/// <author>Hanna Sababa</author>
/// <datecreated>2016-11-24</datecreated>
/// <summary>
///  Contains the part of the class RegistrationForm with all code not automatically generated
/// </summary>
/// </file>

using System;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace RegisterCustomerWebsite
{
    partial class RegistrationForm : Page
    {
        /// <summary>
        /// Takes the user to the page with the welcome message
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        protected void submitButton_Click(object sender, EventArgs e)
        {
            Session.Add("Name", nameTextBox.Text);
            Server.Transfer("WelcomePage.aspx");
        }
    }
}