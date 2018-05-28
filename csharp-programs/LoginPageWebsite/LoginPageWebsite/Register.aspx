<!--Created by hb20007 on 24/11/16-->

<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Register.aspx.cs" Inherits="LoginPageWebsite.Register" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Register - Hanna Computer Store</title>
    <style type="text/css">
        .auto-style1 {
            width: 100%;
            table-layout: fixed;
        }
        .auto-style3 {
            font-size: xx-large;
        }
        .auto-style4 {
            text-align: center;
            width: 428px;
        }
        .auto-style5 {
            width: 428px;
        }
        .auto-style6 {
            width: 428px;
            font-size: x-large;
            text-align: center;
        }
        .auto-style7 {
            height: 24px;
        }
        .auto-style8 {
            width: 428px;
            height: 24px;
            text-align: left;
        }
        .auto-style9 {
            width: 428px;
            text-align: right;
        }
        .auto-style10 {
            width: 428px;
            height: 24px;
            text-align: right;
        }
        .auto-style11 {
            width: 428px;
            text-align: left;
        }
        .auto-style12 {
            text-align: right;
            height: 5px;
        }
        .auto-style13 {
            text-align: center;
        }
        .auto-style14 {
            text-align: center;
            height: 2px;
        }
        .auto-style15 {
            height: 2px;
        }
        .auto-style16 {
            height: 5px;
        }
    </style>
</head>
<body>
    <form id="RegistrationForm" runat="server">
    <div>
    
        <table class="auto-style1">
            <tr>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">&nbsp;</td>
                <td class="auto-style4" style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top; text-align: center;" colspan="2">
                    <asp:Image ID="logoImage" runat="server" Height="41px" ImageAlign="AbsBottom" ImageUrl="icon.png" Width="32px" />
&nbsp;<span class="auto-style3" style="vertical-align: top">Hanna Computer Store</span></td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top;">&nbsp;</td>
            </tr>
            <tr>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">&nbsp;</td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top; text-align: center;" class="auto-style5" colspan="2">&nbsp;</td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top;">&nbsp;</td>
            </tr>
            <tr>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">&nbsp;</td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top" class="auto-style6" colspan="2">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Register</td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top;">&nbsp;</td>
            </tr>
            <tr>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">&nbsp;</td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top; text-align: center;" class="auto-style5" colspan="2">&nbsp;</td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top;">&nbsp;</td>
            </tr>
            <tr>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">&nbsp;</td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top" class="auto-style9">Username:</td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top" class="auto-style11">
                    <asp:TextBox ID="usernameTextBox" runat="server" Font-Names="Lucida Sans Unicode" Width="147px"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="usernameRequiredValidator" runat="server" ControlToValidate="usernameTextBox" ErrorMessage="*" Font-Names="Hobo Std" ForeColor="Red" ToolTip="Required"></asp:RequiredFieldValidator>
                </td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top;">&nbsp;</td>
            </tr>
            <tr>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top" class="auto-style7"></td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top" class="auto-style10">Password: </td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top" class="auto-style8">
                    <asp:TextBox ID="passwordTextBox" runat="server" Font-Names="Lucida Sans Unicode" TextMode="Password" Width="147px"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="passwordRequiredValidator" runat="server" ControlToValidate="passwordTextBox" ErrorMessage="*" Font-Names="Hobo Std" ForeColor="Red" ToolTip="Required"></asp:RequiredFieldValidator>
                </td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top;" class="auto-style7"></td>
            </tr>
            <tr>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">&nbsp;</td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top" class="auto-style9">Confirm password:</td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top" class="auto-style11">
                    <asp:TextBox ID="confirmPasswordTextBox" runat="server" Font-Names="Lucida Sans Unicode" TextMode="Password" Width="147px"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="confirmPasswordRequiredValidator" runat="server" ControlToValidate="confirmPasswordTextBox" ErrorMessage="*" Font-Names="Hobo Std" ForeColor="Red" ToolTip="Required"></asp:RequiredFieldValidator>
                </td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top;">&nbsp;</td>
            </tr>
            <tr>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">&nbsp;</td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top" class="auto-style9">Year of birth:</td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top" class="auto-style11">
                    <asp:TextBox ID="yearOfBirthTextBox" runat="server" Font-Names="Lucida Sans Unicode" TextMode="Number" Width="147px"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="yearOfBirthRequiredValidator" runat="server" ControlToValidate="yearOfBirthTextBox" ErrorMessage="*" Font-Names="Hobo Std" ForeColor="Red" ToolTip="Required"></asp:RequiredFieldValidator>
                </td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top;">&nbsp;</td>
            </tr>
            <tr>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top" class="auto-style15"></td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top" class="auto-style14" colspan="2">
                    <asp:CompareValidator ID="passwordCompareValidator" runat="server" ControlToCompare="passwordTextBox" ControlToValidate="confirmPasswordTextBox" ErrorMessage="Passwords do not match" Font-Names="Lucida Sans Unicode" Font-Size="10pt" ForeColor="Red"></asp:CompareValidator>
                </td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top;" class="auto-style15"></td>
            </tr>
            <tr>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top" class="auto-style16"></td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top" class="auto-style12" colspan="2"></td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top;" class="auto-style16"></td>
            </tr>
            <tr>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top">&nbsp;</td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top" class="auto-style13" colspan="2">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;<asp:Button ID="submitButton" runat="server" Font-Names="Lucida Sans Unicode" OnClick="submitButton_Click" Text="Submit" />
                </td>
                <td style="font-family: 'lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; vertical-align: top;">&nbsp;</td>
            </tr>
        </table>
    
    </div>
    </form>
    <p>
        &nbsp;</p>
</body>
</html>