<br>
<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "mail"); ?>
<table class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title" colspan="2" align="left">
      Contact Us
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Your E-mail: 
    </td>
    <td align="left">
      <? vilw_input("email", 30); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Subject:
    </td>
    <td align="left">
      <? vilw_input("subject", 30); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Message:
    </td>
    <td align="left">
      <? vilw_textarea("message", 5, 45); ?>
    </td>
  </tr>
  <tr>
    <td colspan="2" align="center">
      <input class="button" type="submit" value="Send">
    </td>
  </tr>
</table>
</form>
