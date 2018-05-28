/// <file>
/// <author>hb20007</author>
/// <datecreated>2016-11-24</datecreated>
/// <summary>
///  Contains the part of the class Register with all code which is not automatically generated
/// </summary>
/// </file>

using System;
using System.Drawing;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace LoginPageWebsite
{
    partial class Register : Page
    {
        /// <summary>
        /// Registers the user
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        protected void submitButton_Click(object sender, EventArgs e)
        {
            bool everythingOk = false;
            int currentYear = int.Parse(DateTime.Today.ToString("yyyy-MM-dd").Substring(0, 4));
            int yearOfBirth = int.Parse(this.yearOfBirthTextBox.Text);
            if (yearOfBirth > currentYear)
            {
                ScriptManager.RegisterClientScriptBlock(this.Page, this.GetType(), "FutureBirthMessage", "alert('You could not have been born in the future!');", true);
                this.yearOfBirthTextBox.Focus();
                this.yearOfBirthTextBox.BorderColor = Color.Red;
                everythingOk = false; // Using returns instead of a flag doesn't work
            }
            else if (currentYear - yearOfBirth < 18)
            {
                ScriptManager.RegisterClientScriptBlock(this.Page, this.GetType(), "UnderageMessage", "alert('You need to be at least 18 years old to register');", true);
                this.yearOfBirthTextBox.Focus();
                this.yearOfBirthTextBox.BorderColor = Color.Red;
                everythingOk = false;
            }
            else
                everythingOk = true;

            if (everythingOk == true)
            {
            // Cannot display a message at this point because the code doesn't pause and Server.Transfer() is executed
            //ScriptManager.RegisterClientScriptBlock(this.Page, this.GetType(), "SuccessMessage", "alert('Registration successful');", true);
            Session.Add("username", this.usernameTextBox.Text.Trim());
            Session.Add("password", this.passwordTextBox.Text.Trim());
            Server.Transfer("Default.aspx");
            }
            // Older code to display alert: (had problem cuz shouldn't use apostrophe in the alert text)
            //ClientScript.RegisterStartupScript(this.GetType(), "futurebirthalert", "alert('" + "You couldn't have been born in the future" + "');", true);
        }
    }
}