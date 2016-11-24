/// <file>
/// <author>Hanna Sababa</author>
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
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                string name = Session["name"].ToString();
                this.welcomeMessageLabel.Font.Name = "Courier New";
                this.welcomeMessageLabel.Text = "Welcome " + name + '!';
            }
        }
    }
}