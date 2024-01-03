<?
	include('templates/general/header.inc'); 

	switch($action) {
	case "delete":
		foreach($delete_users as $del_user) {
			cancel_user($del_user);
		}
		include('templates/listUsers/deleted.inc');
		break;
	case "list":
		$users = get_user_list($username, $eml_addr);
		include('templates/listUsers/printList.inc');
		break;
	default:
		include('templates/listUsers/form.inc');
	}

	include('templates/general/footer.inc');
?>
