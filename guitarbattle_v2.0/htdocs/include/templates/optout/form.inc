<br><br>
<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "optout"); ?>
<table width="350" class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td colspan="2" align="center">
      <? print $sitename; ?> will periodically send updates, exclusive offers, and news to our users. When users registered for our site or entered our competitions, they choose whether or not to receive such mail. You may choose not to receive these mailings from <? print $sitename; ?> by entering your email address in the form below.
    </td>
  </tr>
  <tr>
    <td align="right">
     Your E-mail Address:&nbsp;
    </td>
    <td align="left">
      <? vilw_input("email"); ?>
    </td>
  </tr>
  <tr>
    <td colspan="2" align="center">
      <input class="button" type="submit" value="Opt Out">
    </td>
  </tr>
</table>
</form>
