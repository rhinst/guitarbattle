<?
switch($action) {
case "optout":
	vilw_query("update " . $users_table . " set public='0' where eml_addr='" . $email . "'");
	$success = 1;
	break;
}

include('templates/general/header.inc');
if(!$success) {
	include('templates/optout/form.inc');
}
else {
	print "<br><br>Your account information has been updated.";
}
include('templates/general/footer.inc');
?>
