<?php
	include('gb.lib');

	$confirm_id_fix = addslashes($confirm_id);
	$user_temp_info = mysql_fetch_row(mysql_query("select username, password, firstname, lastname, email_address, privacy from users_temp where id=$id and confirm_id='$confirm_id_fix'"));
	$username = $user_temp_info[0];
	$password = $user_temp_info[1];
	$firstname = $user_temp_info[2];
	$lastname = $user_temp_info[3];
	$email_address = $user_temp_info[4];
	$privacy = $user_temp_info[5];
	$join_date = date("Y-m-d H:i:s");
	if(isset($username)) {
		$result = mysql_query("insert into users (username, password, firstname, lastname, email_address, privacy, join_date, last_login) values ('$username', '$password', '$firstname', '$lastname', '$email_address', $privacy, '$join_date', '')");
		if($result) {
			$user_info = mysql_fetch_row(mysql_query("select id from users where username='$username'"));
			$user_id = $user_info[0];
			mysql_query("delete from users_temp where id=$id");
			header("Location: index.php?location=register_complete&user_id=$user_id");
		}
		else {
			mysql_query("delete from users_temp where id=$id");
			header("Location: index.php?location=register_fail");
		}
	}
	else {
		header("Location: index.php?location=register_fail");
	}
?>
