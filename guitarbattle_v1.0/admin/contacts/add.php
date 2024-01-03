<?
include('gb.lib');

switch($action) {
case "add":
	vilw_query(vilw_sql_insert($contact_cols, "contacts"));
}

include('header.inc'); 

switch($action) {
case "add":
	print "Contact Added.<br>\n";
	print "<a href=\"" . $PHP_SELF . "\">Add Another</a><br>\n";
	print "<a href=\"index.php\">Contacts Main</a>\n";
	break;
default:
	$action = "add";
	include('./contact_form.inc');
}

include('footer.inc');
?>
