<?php
	include('templates/general/header.inc');

	if(!isset($username)) {
		print("<br><b>Error:</b> Invalid Input.");
		include('templates/general/footer.inc');
		exit;
	}

	if(!isset($confirm_id)) {
		print("<br><b>Error:</b> Invalid Input.");
		include('templates/general/footer.inc');
		exit;
	}

	if(!$res = vilw_query(vilw_sql_select($users_temp_cols, $users_temp_table, "where username='" . $username . "' and confirm_id='" . $confirm_id . "'"))) {
		print("<br><b>Error:</b> Unable to query database.");
		include('templates/general/footer.inc');
		exit;
	}

	$user = mysql_fetch_row($res);
	vilw_result_globalize($users_temp_cols, $user);

	if(count($user) == 1) {
		//Insert User Into Users Table:
		if(!$res = vilw_query(vilw_sql_insert($users_cols, $users_table))) {
			print("<br><b>Error:</b> Unable to insert user into database.");
			include('templates/general/footer.inc');
			exit;
		}
	
		//Delete User From Temporary User Table:
		if(!$res = vilw_query(vilw_sql_delete($users_temp_table, " where username='" . $username . "'"))) {
			print("<br><b>Error:</b> Unable to delete temporary user from database.");
			include('templates/general/footer.inc');
			exit;
		}

		print("<br><b>Congratulations, you are now a member of " . $sitename . ".</b><br>");
		print("username: " . $username . "<br>");
		print("password: " . $password . "<br>");
		print("eml_addr: " . $eml_addr . "<br>");
		print("fn: " . $fn . "<br>");
		print("ln: " . $ln . "<br>");
		print("address: " . $address . "<br>");
		print("city: " . $city . "<br>");
		print("state: " . $state . "<br>");
		print("zip: " . $zip . "<br>");
		print("country: " . $country . "<br>");
		print("telephone: " . $telephone . "<br>");
		print("public: " . $public . "<br>");
		print("join_date: " . $join_date . "<br>");
		print("ip_addr: " . $ip_addr . "<br>");
	}
	else {
		print("<br><b>Error:</b> Account does not exist.");
	}

	include('templates/general/footer.inc');
?>
