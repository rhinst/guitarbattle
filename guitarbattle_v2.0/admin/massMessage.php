<?
	include('templates/general/header.inc');
	switch($action) {
	case "send":
		$users = vilw_result_array(vilw_query(vilw_sql_select($users_cols, $users_table, $wherecl)));

		$new = 1;
		$unread = 1;
		$timestamp = date("YmdHis");
		foreach($users as $user) {
			vilw_result_globalize($users_cols, $user, "user_");
			send_message($from, $user_username, $subject, $message);
		}


		include('templates/massMessage/sent.inc');
		break;
	default:
		include('templates/massMessage/form.inc');
		break;
	}
	include('templates/general/footer.inc');
	
?>
