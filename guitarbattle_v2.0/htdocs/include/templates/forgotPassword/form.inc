<br>
<table class="items" width="350" border="0" cellspacing="0" cellpadding="4">
<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "mail_pw"); ?>
  <tr>
    <td class="item_title" align="left">
      <b>Forgot Your Password?:</b>
    </td>
  </tr>
  <tr>
    <td align="left">
      Please enter the e-mail address you registered your account with and we will e-mail your password to you.
    </td>
  </tr>
  <tr>
    <td align="left">
      E-mail:&nbsp; <? vilw_input("email_addr", 25); ?>
    </td>
  </tr>
  <tr>
    <td align="center">
      <input class="button" type="submit" value="Submit">
    </td>
  </tr>
</form>
</table>
