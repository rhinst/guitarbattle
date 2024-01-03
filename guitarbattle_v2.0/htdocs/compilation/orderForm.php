<?
if(session_is_registered("compilation_id")) {
	$track_list = vilw_result_array(vilw_query(vilw_sql_select($track_lists_cols, $track_lists_table, "where compilation_id='" . $HTTP_SESSION_VARS["compilation_id"] . "'")));
	$total_time = 0;
	foreach($track_list as $track) {
		vilw_result_globalize($track_lists_cols, $track, "tl_");
		$total_time += $tl_track_length;	
	}
}
else {
	include('templates/general/header.inc');
	$err_msg = "Error finding compilation track list";
	include('templates/compilation/error.inc');
	include('templates/general/footer.inc');
	exit;
}

switch($action) {
case "complete":
	$id = $HTTP_SESSION_VARS["compilation_id"];
	$status = "unconfirmed";
	$order_date = date("Y-m-d H:i:s");
	vilw_query(vilw_sql_update($compilations_cols, $compilations_table, "where id='" . $id . "'"));
	$shipping_rate = (($country == "US")?($domestic_shipping_rate):($international_shipping_rate));
	$tax = ($state == "NY")?(round($compilation_cost * $tax_rate, 2)):(0);
	$total_amount = $compilation_cost + $shipping_rate + $tax;
 $paypal_checkout_link = "https://www.paypal.com/xclick/business=sales%40guitarbattle.com&undefined_quantity=1&item_name=GuitarBattle+Compilation+CD&item_number=" . zero_pad($id, 6) . "&amount=" . number_format($total_amount, 2) . "&image_url=http%3A//guitarbattle.com/images/paypal_logo.jpg&return=http%3A//www.guitarbattle.com/compilation/complete.php&cancel_return=http%3A//www.guitarbattle.com/compilation/cancel.php&no_shipping=1&no_note=1&currency_code=USD";
	header("location: " . $paypal_checkout_link);
	exit;
	break;
default:
	include('templates/general/header.inc');
	$mode = "order";
	include('templates/compilation/printList.inc');
	include('templates/compilation/orderForm.inc');
	include('templates/general/footer.inc');
}


?>
