<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "confirm_amount_paid"); ?>
<? vilw_hidden("id"); ?>
<? vilw_hidden("state"); ?>
<? vilw_hidden("country"); ?>
<table border="0" class="item" width="250" cellspacing="0" cellpadding="2">
  <tr valign="top">
    <th colspan="2">
      Confirm Payment:
    </td> 
  </tr>
  <tr valign="top">
    <td align="right">
      Quantity Ordered:
    </td>
    <td align="left">
      <? vilw_input("quantity", 3); ?>
    </td>
  </tr>
  <tr valign="top">
    <td colspan="2" align="center">
      <input type="submit" value="Next">
    </td>
  </tr>
</table>
</form>
