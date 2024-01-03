<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "confirm"); ?>
<? vilw_hidden("id"); ?>
<? vilw_hidden("quantity"); ?>
<? vilw_hidden("amount_paid"); ?>
<table border="0" class="item" width="250" cellspacing="0" cellpadding="2">
  <tr valign="top">
    <th colspan="2">
      Confirm Payment:
    </td> 
  </tr>
  <tr valign="top">
    <td align="right">
      PayPal Transaction ID:
    </td>
    <td align="left">
      <? vilw_input("transaction_id", 20); ?>
    </td>
  </tr>
  <tr valign="top">
    <td colspan="2" align="center">
      <input type="submit" value="Confirm Order">
    </td>
  </tr>
</table>
</form>
