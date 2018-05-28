/// <file>
/// <author>hb20007</author>
/// <datecreated>2016-11-24</datecreated>
/// <summary>
///  Contains the part of the class Welcome with all code which is not automatically generated
/// </summary>
/// </file>

using System;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace LoginPageWebsite
{
    partial class Welcome : Page
    {
        /// <summary>
        /// Displays the welcome message
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                string username = Session["username"].ToString();
                this.welcomeMessageLabel.Font.Name = "Lucida Sans Unicode";
                this.welcomeMessageLabel.Text = "Welcome " + username + '!'; // Note even if Trim() were not used in the program and the user entered a username iwith spaces, the spaces will not apear here somehow
            }
        }
    }
}