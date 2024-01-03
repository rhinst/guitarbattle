<?
if(session_is_registered("compilation_id")) {
	$track_list = vilw_result_array(vilw_query(vilw_sql_select($track_lists_cols, $track_lists_table, "where compilation_id='" . $HTTP_SESSION_VARS["compilation_id"] . "'")));
}

include('templates/general/header.inc');
$message = "Thank you for placing your order with " . $sitename . ". Your order number is " . zero_pad($id, 6) . ". Keep this number for future correpondences about your order. Your CD will be created and shipped as soon as payment is approved. The contents of your order are as follows:\n\n";
foreach($track_list as $track) {
	vilw_result_globalize($track_lists_cols, $track, "tl_");
	$message .= $tl_track_number . ") " . $tl_song_name . " - " . $tl_username . (($tl_collab)?(" / " . $tl_collab):("")) . "\n";
}
mail($email, "Your " . $sitename . " Order", $message, "From: " . $sitename . " Sales Dept <" . $sales_email . ">");
$message = "An order has been placed for a compilation CD. Please visit the administration site to view this order.";
mail($sales_email, "An order has been placed", "From: Sales Notification <" . $sales_email . ">");
include('templates/compilation/complete.inc');
session_unregister("compilation_id");
include('templates/general/footer.inc');
?>
