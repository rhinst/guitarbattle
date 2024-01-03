<?
include('templates/general/header.inc');
switch($action) {
case "delete":
	foreach($delete_judges as $judge) {
		vilw_query("update " . $users_table . " set judge='0' where username='" . $judge . "'");
	}
	break;
case "add":
		vilw_query("update " . $users_table . " set judge='1' where username='" . $username . "'");
	break;
case "delete_alt":
	foreach($delete_judges as $judge) {
		vilw_query("update " . $users_table . " set alt_judge='0' where username='" . $judge . "'");
	}
	break;
case "add_alt":
		vilw_query("update " . $users_table . " set alt_judge='1' where username='" . $username . "'");
	break;
}

$username = "";

$judges = vilw_result_array(vilw_query(vilw_sql_select($users_cols, $users_table, "where judge='1'")));
$alt_judges = vilw_result_array(vilw_query(vilw_sql_select($users_cols, $users_table, "where alt_judge='1'")));
include('templates/judges/printList.inc');
include('templates/judges/addForm.inc');
include('templates/judges/printAltList.inc');
include('templates/judges/addAltForm.inc');
include('templates/general/footer.inc');
?>
