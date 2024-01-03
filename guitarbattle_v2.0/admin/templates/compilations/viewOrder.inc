<table width="350" class="item" border="0" cellspacing="0" cellpadding="2">
  <tr valign="top">
<? if($status == 'unconfirmed') { ?>
    <td align="center">
      <form action="<? print $PHP_SELF; ?>" method="post">
      <? vilw_hidden("action", "confirm_quantity"); ?>
      <? vilw_hidden("id"); ?>
      <? vilw_hidden("state"); ?>
      <? vilw_hidden("country"); ?>
      <input type="submit" value="Confirm Payment">
      </form>
    </td>
<?
   }
   else if($status == 'queued') { 
?>
    <td align="center">
      <form action="<? print $PHP_SELF; ?>" method="post">
      <? vilw_hidden("action", "begin_production"); ?>
      <? vilw_hidden("id"); ?>
      <input type="submit" value="Begin Production">
      </form>
    </td>
<?
   }
   else if($status == 'open') { 
?>
    <td align="center">
      <form action="<? print $PHP_SELF; ?>" method="post">
      <? vilw_hidden("action", "close_order"); ?>
      <? vilw_hidden("id"); ?>
      <input type="submit" value="Close Order">
      </form>
    </td>
<?
   }
?>
    <td align="center">
      <form action="<? print $PHP_SELF; ?>" method="post">
      <? vilw_hidden("action", "cancel"); ?>
      <? vilw_hidden("id"); ?>
      <input type="submit" value="Cancel Order">
      </form>
    </td>
  </tr>
</table>
<br>
<?  if($updated) { ?>
<table class="item" width="350" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <th align="center">
	<i>Order Information Has Been Updated</i>
    </td>
  </tr>
</table>
<br>
<? } ?>

<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "update"); ?>
<? vilw_hidden("id"); ?>
<table width="350" class="item" border="0" cellspacing="0" cellpadding="2">
  <tr valign="top">
    <th colspan="2">
      Order Information 
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      First Name:
    </td>
    <td align="left">
      <? vilw_input("fn"); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Last Name:
    </td>
    <td align="left">
      <? vilw_input("ln"); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Street Address:
    </td>
    <td align="left">
      <? vilw_input("address"); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      City:
    </td>
    <td align="left">
      <? vilw_input("city"); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Province:
    </td>
    <td align="left">
      <? vilw_input("province"); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      State:
    </td>
    <td align="left">
      <? vilw_input("state"); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Zip:
    </td>
    <td align="left">
      <? vilw_input("zip"); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Country:
    </td>
    <td align="left">
      <? vilw_input("country"); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Phone:
    </td>
    <td align="left">
      <? vilw_input("phone"); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      E-mail:
    </td>
    <td align="left">
      <? vilw_input("email"); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Notes:
    </td>
    <td align="left">
      <? vilw_textarea("notes", 4, 30); ?>
    </td>
  </tr>
  <tr valign="top">
    <td colspan="2" align="center">
      <input type="submit" value="Update">
    </td>
  </tr>
</table>
</form>
<br>
<table width="350" class="item" border="0" cellspacing="0" cellpadding="2">
  <tr valign="top">
    <th colspan="2">
      Order Tracking Information
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Order Received:
    </td>
    <td align="left">
      <? print mysql_datetime_printable($order_date); ?>
    </td>
  </tr>
<? if($status != 'unconfirmed') { ?>
  <tr valign="top">
    <td align="right">
      Quantity Ordered:
    </td>
    <td align="left">
      <? print $quantity; ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Amount Paid:
    </td>
    <td align="left">
      $<? print number_format($amount_paid, 2); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Transaction ID:
    </td>
    <td align="left">
      <? print $transaction_id; ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Payment Date:
    </td>
    <td align="left">
      <? print mysql_datetime_printable($payment_date); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Confirmed By:
    </td>
    <td align="left">
      <? print $payment_confirmed_by; ?>
    </td>
  </tr>
<? if($status != 'queued') { ?>
  <tr valign="top">
    <td align="right">
      Began Creation:
    </td>
    <td align="left">
      <? print mysql_datetime_printable($creation_date); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Created By:
    </td>
    <td align="left">
      <? print $created_by; ?>
    </td>
  </tr>
<? if($status != 'open') { ?>
  <tr valign="top">
    <td align="right">
      Ship Date:
    </td>
    <td align="left">
      <? print mysql_datetime_printable($ship_date); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Closed By:
    </td>
    <td align="left">
      <? print $shipped_by; ?>
    </td>
  </tr>
<? } ?>
<? } ?>
<? } ?>
</table>
<br>
<table class="item" width="350" border="0" cellspacing="0" cellpadding="2">
  <tr>
    <th colspan="4">
      Track List
    </th>
  </tr>
  <tr>
    <th>#</th>
    <th>Song</th>
    <th>User</th>
    <th>Length</th>
  </tr>
<? 
$total_time = 0;
foreach($track_list as $track) { 
  vilw_result_globalize($track_lists_cols, $track, "track_");
  $total_time += $track_track_length;
?>
  <tr>
    <td><? print $track_track_number; ?></td>
    <td><? print $track_song_name; ?></td>
    <td><? print $track_username . (($track_collab)?(" / " . $track_collab):("")); ?></td>
    <td><? print readable_time($track_track_length); ?></td>
  </tr>
<? } ?>
  <tr>
    <th colspan="3">
      Total Time:
    </th>
    <td>
      <? print readable_time($total_time); ?>
    </td>
  </tr>
</table>
