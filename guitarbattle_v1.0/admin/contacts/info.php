<?
include('gb.lib');

switch($action) {
case "update":
	vilw_query(vilw_sql_update($contact_cols, "contacts", "where id=" . $id));
	break;
default:
	$contact_info = mysql_fetch_row(vilw_query(vilw_sql_select($contact_cols, "contacts", "where id=" . $id)));
	vilw_result_globalize($contact_cols, $contact_info);
}


include('header.inc');
switch($action) {
case "update":
	print "Contact Updated.<br>\n";
	print "<a href=\"list.php\">Back to Contact Listing</a><br>\n";
	print "<a href=\"index.php\">Contacts Main</a>\n";
	break;
default:
	$action = "update";
	include('./contact_form.inc');
}
include('footer.inc'); 
?>
