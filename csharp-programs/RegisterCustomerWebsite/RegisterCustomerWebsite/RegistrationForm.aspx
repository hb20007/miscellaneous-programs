<!--File created by hb20007 on 24/11/16-->

<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="RegistrationForm.aspx.cs" Inherits="RegisterCustomerWebsite.RegistrationForm" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Register now</title>
    <link rel="icon" type="image/x-icon" href="~/favicon.ico" />
    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
        .auto-style2 {
            text-align: right;
            width: 299px;
        }
        .auto-style3 {
            text-align: right;
            height: 22px;
            width: 299px;
        }
        .auto-style4 {
            height: 22px;
        }
        .auto-style7 {
            text-align: right;
            height: 26px;
            width: 299px;
        }
        .auto-style9 {
            height: 26px;
        }
        .auto-style10 {
            text-align: right;
            height: 10px;
            width: 299px;
        }
        .auto-style11 {
            height: 10px;
        }
        .auto-style12 {
            text-align: right;
            height: 6px;
            width: 299px;
        }
        .auto-style13 {
            height: 6px;
        }
        .auto-style15 {
            font-size: xx-large;
        }
        .auto-style17 {
            width: 233px;
            text-align: left;
            height: 30px;
        }
        .auto-style18 {
            width: 233px;
        }
        .auto-style19 {
            height: 22px;
            width: 233px;
        }
        .auto-style20 {
            height: 26px;
            width: 233px;
        }
        .auto-style21 {
            font-size: xx-large;
            text-align: center;
        }
        .auto-style22 {
            width: 299px;
        }
        .auto-style23 {
            text-align: right;
            width: 299px;
            height: 30px;
        }
        .auto-style24 {
            height: 30px;
        }
    </style>
</head>
<body>
    <form id="RegistrationForm" runat="server">
    <div>
    
        <table class="auto-style1" style ="table-layout:fixed; font-family: 'Courier New', Courier, monospace;">
            <tr>
                <td class="auto-style21" colspan="2">&nbsp;&nbsp;&nbsp;&nbsp; Registration</td>
                <td class="auto-style15">&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style22">&nbsp;</td>
                <td class="auto-style18">&nbsp;</td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style2">Name:</td>
                <td class="auto-style18">
                    <asp:TextBox ID="nameTextBox" runat="server" Font-Names="Courier New"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="nameRequiredValidator" runat="server" ControlToValidate="nameTextBox" ErrorMessage="*" ForeColor="Red" ToolTip="Required"></asp:RequiredFieldValidator>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style3">E-mail:</td>
                <td class="auto-style19">
                    <asp:TextBox ID="emailTextBox" runat="server" TextMode="Email" Font-Names="Courier New"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="emailRequiredValidator" runat="server" ControlToValidate="emailTextBox" ErrorMessage="*" ForeColor="Red" ToolTip="Required"></asp:RequiredFieldValidator>
                </td>
                <td class="auto-style4">
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style2">Username:</td>
                <td class="auto-style18">
                    <asp:TextBox ID="usernameTextBox" runat="server" Font-Names="Courier New"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="usernameRequiredValidator" runat="server" ControlToValidate="usernameTextBox" ErrorMessage="*" ForeColor="Red" ToolTip="Required"></asp:RequiredFieldValidator>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style2">Password:</td>
                <td class="auto-style18">
                    <asp:TextBox ID="passwordTextBox" runat="server" TextMode="Password" Font-Names="Courier New"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="passwordRequiredValidator" runat="server" ControlToValidate="passwordTextBox" ErrorMessage="*" ForeColor="Red" ToolTip="Required"></asp:RequiredFieldValidator>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style7">Confirm password:</td>
                <td class="auto-style20">
                    <asp:TextBox ID="confirmPasswordTextBox" runat="server" TextMode="Password" Font-Names="Courier New"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="confirmPasswordRequiredValidator" runat="server" ControlToValidate="confirmPasswordTextBox" ErrorMessage="*" ForeColor="Red" ToolTip="Required"></asp:RequiredFieldValidator>
                </td>
                <td class="auto-style9">
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style10"></td>
                <td class="auto-style11" colspan="2">
                    <asp:CompareValidator ID="passwordCompaterValidator" runat="server" ControlToCompare="passwordTextBox" ControlToValidate="confirmPasswordTextBox" ErrorMessage="Passwords do not match" Font-Size="Small" ForeColor="Red" Font-Names="Courier New"></asp:CompareValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style12"></td>
                <td class="auto-style13" colspan="2">
                    </td>
            </tr>
            <tr>
                <td class="auto-style23"></td>
                <td style ="text-align:left" class="auto-style17">
                    <asp:Button ID="submitButton" runat="server" style="text-align: center" Text="Submit" OnClick="submitButton_Click" Font-Names="Courier New" Height="26px" Width="70px" />
                </td>
                <td class="auto-style24"></td>
            </tr>
        </table>
    
    </div>
    </form>
</body>
</html>