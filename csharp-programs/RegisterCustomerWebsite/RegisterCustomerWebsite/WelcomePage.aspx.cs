/// <file>
/// <author>hb20007</author>
/// <datecreated>2016-11-24</datecreated>
/// <summary>
///  Contains the part of the class WelcomePage with all code not automatically generated
/// </summary>
/// </file>

using System;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace RegisterCustomerWebsite
{
    partial class WelcomePage : Page
    {
        /// <summary>
        /// Loads and displays the username in the welcome message
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                string name = Session["Name"].ToString();
                this.welcomeMessageLabel.Font.Name = "Courier New";
                this.welcomeMessageLabel.Text = "Welcome " + name + '!';
            }
        }
    }
}