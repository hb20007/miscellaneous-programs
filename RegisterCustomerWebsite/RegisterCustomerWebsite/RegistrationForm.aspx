<!--File created by Hanna Sababa on 24/11/16-->

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
        }
        .auto-style3 {
            text-align: right;
            height: 22px;
        }
        .auto-style4 {
            height: 22px;
        }
        .auto-style5 {
            width: 169px;
        }
        .auto-style6 {
            height: 22px;
            width: 169px;
        }
        .auto-style7 {
            text-align: right;
            height: 26px;
        }
        .auto-style8 {
            width: 169px;
            height: 26px;
        }
        .auto-style9 {
            height: 26px;
        }
        .auto-style10 {
            text-align: right;
            height: 10px;
        }
        .auto-style11 {
            height: 10px;
        }
        .auto-style12 {
            text-align: right;
            height: 6px;
        }
        .auto-style13 {
            height: 6px;
        }
    </style>
</head>
<body>
    <form id="RegistrationForm" runat="server">
    <div>
    
        <table class="auto-style1" style ="table-layout:fixed; font-family: 'Courier New', Courier, monospace;">
            <tr>
                <td>&nbsp;</td>
                <td style="text-align: center; font-size: x-large;" class="auto-style5">Registration</td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td>&nbsp;</td>
                <td class="auto-style5">&nbsp;</td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style2">Name:</td>
                <td class="auto-style5">
                    <asp:TextBox ID="nameTextBox" runat="server"></asp:TextBox>
                </td>
                <td>
                    <asp:RequiredFieldValidator ID="nameRequiredValidator" runat="server" ControlToValidate="nameTextBox" ErrorMessage="*" ForeColor="Red" ToolTip="Required"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style3">E-mail:</td>
                <td class="auto-style6">
                    <asp:TextBox ID="emailTextBox" runat="server" TextMode="Email"></asp:TextBox>
                </td>
                <td class="auto-style4">
                    <asp:RequiredFieldValidator ID="emailRequiredValidator" runat="server" ControlToValidate="emailTextBox" ErrorMessage="*" ForeColor="Red" ToolTip="Required"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style2">Username:</td>
                <td class="auto-style5">
                    <asp:TextBox ID="usernameTextBox" runat="server"></asp:TextBox>
                </td>
                <td>
                    <asp:RequiredFieldValidator ID="usernameRequiredValidator" runat="server" ControlToValidate="usernameTextBox" ErrorMessage="*" ForeColor="Red" ToolTip="Required"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style2">Password:</td>
                <td class="auto-style5">
                    <asp:TextBox ID="passwordTextBox" runat="server" TextMode="Password"></asp:TextBox>
                </td>
                <td>
                    <asp:RequiredFieldValidator ID="passwordRequiredValidator" runat="server" ControlToValidate="passwordTextBox" ErrorMessage="*" ForeColor="Red" ToolTip="Required"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style7">Confirm password:</td>
                <td class="auto-style8">
                    <asp:TextBox ID="confirmPasswordTextBox" runat="server" TextMode="Password"></asp:TextBox>
                </td>
                <td class="auto-style9">
                    <asp:RequiredFieldValidator ID="confirmPasswordRequiredValidator" runat="server" ControlToValidate="confirmPasswordTextBox" ErrorMessage="*" ForeColor="Red" ToolTip="Required"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style10"></td>
                <td class="auto-style11" colspan="2">
                    <asp:CompareValidator ID="passwordCompaterValidator" runat="server" ControlToCompare="passwordTextBox" ControlToValidate="confirmPasswordTextBox" ErrorMessage="Passwords do not match" Font-Size="Small" ForeColor="Red"></asp:CompareValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style12"></td>
                <td class="auto-style13" colspan="2">
                    </td>
            </tr>
            <tr>
                <td class="auto-style2">&nbsp;</td>
                <td style ="text-align:center" class="auto-style5">
                    <asp:Button ID="submitButton" runat="server" style="text-align: center" Text="Submit" OnClick="submitButton_Click" />
                </td>
                <td>&nbsp;</td>
            </tr>
        </table>
    
    </div>
    </form>
</body>
</html>