<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "confirm_transaction_id"); ?>
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
    <td colspan="2" align="center">
      Amount of payment should be <b>$<? print number_format($amount_paid, 2); ?></b>. Click 'Confirm Payment' if this is the amount recieved. If this is not the amount that has been paid, you must return the amount to the user and cancel this order.
    </td>
  </tr>
  <tr valign="top">
    <td colspan="2" align="center">
      <input type="submit" value="Confirm Payment">
    </td>
  </tr>
</table>
</form>
