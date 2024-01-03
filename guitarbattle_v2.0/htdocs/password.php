<?
switch($action) {
case "change_pw":

	if($new_pass != $new_pass2) {
		$err_msg = "Your new passwords don't match. Please type them again";
	}
	else {
		$res = vilw_query(vilw_sql_select($users_cols, $users_table, "where username like binary '" . $authenticated_user . "' and password like binary '" . base64_encode($old_pass) . "'"));
        	if(mysql_num_rows($res) == 1) {
			vilw_query("update " . $users_table . " set password='" . base64_encode($new_pass) . "' where username='" . $authenticated_user . "'");
			$success = 1;
		}
		else {
			$err_msg = "Invalid password. Please re-type your old password";
		}
	}

		
	break;
}

if(!session_is_registered("authenticated_user")) {
	$err_msg =  "You must be logged in to use this page";
}

include('templates/general/header.inc');
if($err_msg) {
	include('templates/password/error.inc');
}
else {
	if($success) {
		print "Your password has been successfully changed.";
	}
	include('templates/password/changePassword.inc');
}
include('templates/general/footer.inc');
?>
