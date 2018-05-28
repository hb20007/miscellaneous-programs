/// <file>
/// <author>hb20007</author>
/// <datecreated>2016-11-24</datecreated>
/// <summary>
///  Contains the part of the class Default with all code which is not automatically generated
/// </summary>
/// </file>

using System;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace LoginPageWebsite
{
    partial class Default : Page
    {
        /// <summary>
        /// Displays a success message if the user managed to get to this page from the Register page
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        protected void Page_Load(object sender, EventArgs e)
        {
            if (this.PreviousPage != null) // this.PreviousPage is null if there is no previous page
                if (this.PreviousPage.ToString() == "ASP.register_aspx") // If the user managed to get here from the registration page
                {
                    ScriptManager.RegisterClientScriptBlock(this.Page, this.GetType(), "SuccessMessage", "alert('Registration successful! You can login now.');", true);
                    this.loginButton.Enabled = true;
                }
        }

        /// <summary>
        /// Logs in the user
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        protected void loginButton_Click(object sender, EventArgs e)
        {
            if (this.usernameTextBox.Text.Trim() == Session["username"].ToString() && this.passwordTextBox.Text.Trim() == Session["password"].ToString())
                Server.Transfer("Welcome.aspx");
            else
                ScriptManager.RegisterClientScriptBlock(this.Page, this.GetType(), "WrongUsernameOrPasswordMessage", "alert('Incorrect username or password');", true);
        }

        /// <summary>
        /// Takes the user to the registration page
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        protected void registerButton_Click(object sender, EventArgs e)
        {
            Server.Transfer("Register.aspx");
        }
    }
}