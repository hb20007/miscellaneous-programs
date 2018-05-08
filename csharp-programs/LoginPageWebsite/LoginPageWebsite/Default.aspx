<!--Created by Hanna Sababa on 24/11/16-->

<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="LoginPageWebsite.Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Login - Hanna Computer Store</title>
    <link rel="icon" type="image/x-icon" href="~/favicon.ico" />
    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
        .auto-style2 {
            font-size: x-large;
            text-align: right;
            width: 416px;
        }
        .auto-style3 {
            font-size: xx-large;
        }
        .auto-style4 {
            width: 416px;
        }
        .auto-style5 {
            width: 416px;
            text-align: center;
        }
        .auto-style6 {
            height: 26px;
        }
        .auto-style7 {
            width: 416px;
            text-align: center;
            height: 26px;
        }
        .auto-style8 {
            margin-left: 0px;
        }
    </style>
</head>
<body>
    <form id="DefaultPage" runat="server">
    <div>
    
        <table class="auto-style1" style ="table-layout:fixed">
            <tr>
                <td style="font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">&nbsp;</td>
                <td class="auto-style2" style="font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">
                    <asp:Image ID="logoImage" runat="server" Height="41px" ImageAlign="AbsBottom" ImageUrl="icon.png" Width="32px" />
&nbsp;<span class="auto-style3" style="vertical-align: top">Hanna Computer Store</span></td>
                <td style="font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">&nbsp;</td>
            </tr>
            <tr>
                <td style="font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">&nbsp;</td>
                <td class="auto-style4" style="font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">&nbsp;</td>
                <td style="font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style6" style="font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top"></td>
                <td class="auto-style7" style="font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">Username:
                    <asp:TextBox ID="usernameTextBox" runat="server" Font-Names="Lucida Sans Unicode" Height="16px" Width="121px"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="usernameRequiredValidator" runat="server" ControlToValidate="usernameTextBox" ErrorMessage="*" Font-Names="Hobo Std" ForeColor="Red" ToolTip="Enter username"></asp:RequiredFieldValidator>
                </td>
                <td class="auto-style6" style="font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top"></td>
            </tr>
            <tr>
                <td class="auto-style6" style="font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top"></td>
                <td class="auto-style7" style="font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">Password:&nbsp;
                    <asp:TextBox ID="passwordTextBox" runat="server" CssClass="auto-style8" Font-Names="Lucida Sans Unicode" Height="16px" TextMode="Password" Width="121px"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="passwordRequiredValidator" runat="server" ControlToValidate="passwordTextBox" ErrorMessage="*" Font-Names="Hobo Std" ForeColor="Red" ToolTip="Enter password"></asp:RequiredFieldValidator>
                </td>
                <td class="auto-style6" style="font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top"></td>
            </tr>
            <tr>
                <td style="font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">&nbsp;</td>
                <td class="auto-style4" style="font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">&nbsp;</td>
                <td style="font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">&nbsp;</td>
            </tr>
            <tr>
                <td style="font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">&nbsp;</td>
                <td class="auto-style5" style="font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">
                    <asp:Button ID="registerButton" runat="server" CausesValidation="False" Font-Names="Lucida Sans Unicode" OnClick="registerButton_Click" Text="Register" UseSubmitBehavior="False" Width="77px" />
                    <asp:Button ID="loginButton" runat="server" Font-Names="Lucida Sans Unicode" OnClick="loginButton_Click" Text="Login" Width="77px" Enabled="False" />
                </td>
                <td style="font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">&nbsp;</td>
            </tr>
        </table>
    
    </div>
    </form>
</body>
</html>