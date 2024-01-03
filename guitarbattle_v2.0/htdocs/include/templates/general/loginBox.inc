<!-- Start Login Box -->
<form action="<? print $PHP_SELF; ?>" method="post">
<input type="hidden" name="action" value="login">
<table width="150" border="0" cellspacing="0" cellpadding="0">
<? if($login_error) { ?>
  <tr valign="top">
    <td class="menu_text" align="center" colspan="2">
      <? print "<b>" . htmlspecialchars($login_error) . "</b><br><br>"; ?>
    </td>
  </tr>
<? } ?>
  <tr valign="top">
    <td class="menu_text" align="left">
      Username:&nbsp;
    </td>
    <td align="left">
      <input class="sleek" type="text" name="login_username" size="15">
    </td>
  </tr>
  <tr valign="top">
    <td class="menu_text" align="left">
      Password:&nbsp;
    </td>
    <td align="left">
      <input class="sleek" type="password" name="login_password" size="15">
    </td>
  </tr>
  <tr>
    <td colspan="2" align="center">
      <a class="menu_link" href="<? print $baseURL; ?>/forgotPassword.php">Forgot your password?</a><br><br>
    </td>
  </tr>
  <tr>
    <td align="center" colspan="2">
      <input class="button" type="submit" value="Login">
    </td>
  </tr>
  <tr>
    <td class="menu_text" align="center" colspan="2">
      <br>Don't have an account?<br>
      <a class="menu_link" href="<? print $baseURL; ?>/join.php">Join Now</a>
    </td>
  </tr>
</table>
</form>
<!-- End Login Box -->
