<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "send"); ?>
<table class="item" border="0" cellspacing="0" cellpadding="4">
 <tr>
  <th colspan="2" align="left">Mass Message:</th>
 </tr>
  <tr valign="top">
    <td align="right">
      From:
    </td>
    <td align="left">
      <? vilw_input("from", 30); ?>
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
      <? vilw_textarea("message", 10, 50); ?>
    </td>
  </tr>
  <tr>
    <td colspan="2" align="center">
      <input type="submit" value="Send">
    </td>
  </tr>
</table>
</form>
