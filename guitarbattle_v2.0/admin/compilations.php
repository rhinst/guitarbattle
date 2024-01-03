<?
include('templates/general/header.inc');
switch($action) {
case "confirm_quantity":
	include('templates/compilations/confirm_quantity.inc');
	break;
case "confirm_amount_paid":
	$shipping_rate = ($country == "US")?($domestic_shipping_rate):($international_shipping_rate);
	$tax = ($state == "NY")?(round($compilation_cost * $tax_rate, 2)):(0);
	$amount_paid = $compilation_cost + $shipping_rate + $tax;
	$amount_paid *= $quantity;
	include('templates/compilations/confirm_amount_paid.inc');
	break;
case "confirm_transaction_id":
	include('templates/compilations/confirm_transaction_id.inc');
	break;
case "confirm":
	vilw_query("update " . $compilations_table . " set quantity='" . $quantity . "', amount_paid='" . $amount_paid . "', payment_date='" . date("Y-m-d H:i:s") . "', payment_confirmed_by='" . $REMOTE_USER . "', transaction_id='"  . $transaction_id . "', status='queued' where id='" . $id . "'");
	header("location: " . $PHP_SELF . "?updated=1&action=view&id=" . $id);
	exit;
	break;
case "begin_production":
	vilw_query("update " . $compilations_table . " set creation_date='" . date("Y-m-d H:i:s") . "', created_by='" . $REMOTE_USER . "', status='open' where id='" . $id . "'");
	header("location: " . $PHP_SELF . "?updated=1&action=view&id=" . $id);
	exit;
	break;
case "close_order":
	vilw_query("update " . $compilations_table . " set ship_date='" . date("Y-m-d H:i:s") . "', shipped_by='" . $REMOTE_USER . "', status='complete' where id='" . $id . "'");
	header("location: " . $PHP_SELF . "?updated=1&action=view&id=" . $id);
	exit;
	break;
case "update":
	vilw_query("update " . $compilations_table . " set fn='" . addslashes($fn) . "', ln='" . addslashes($ln) . "', address='" . addslashes($address) . "', city='" . addslashes($city) . "', state='" . addslashes($state) . "', province='" . addslashes($province) . "', zip='" . addslashes($zip) . "', country='" . addslashes($country) . "', phone='" . addslashes($phone) . "', email='" . addslashes($email) . "', notes='" . addslashes($notes) . "' where id='" . $id . "'");
	header("location: " . $PHP_SELF . "?updated=1&action=view&id=" . $id);
	exit;
	break;
case "cancel":
	vilw_query("update " . $compilations_table . " set status='cancelled' where id='" . $id . "'");
	header("location: " . $PHP_SELF);
	exit;
	break;
case "view":
	$res = vilw_query(vilw_sql_select($compilations_cols, $compilations_table, "where id='" . $id . "'"));
	$row = mysql_fetch_row($res);
	vilw_result_globalize($compilations_cols, $row);
	$track_list = vilw_result_array(vilw_query(vilw_sql_select($track_lists_cols, $track_lists_table, "where compilation_id='" . $id . "'")));
	include('templates/compilations/viewOrder.inc');
	break;
default:
	$orders = vilw_result_array(vilw_query(vilw_sql_select($compilations_cols, $compilations_table, "where status != '' order by status asc, order_date asc")));
	include('templates/compilations/printList.inc');
	break;
}
include('templates/general/footer.inc');
?>
