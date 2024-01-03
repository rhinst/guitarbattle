<?
	include('templates/general/header.inc'); 

	switch($action) {
	case "delete":
		foreach($delete_battles as $del_battle) {
			delete_battle($del_battle);
		}
		include('templates/listBattles/deleted.inc');
		break;
	case "list":
		$battles = get_battle_list();
		include('templates/listBattles/printList.inc');
		break;
	default:
		include('templates/listBattles/form.inc');
	}

	include('templates/general/footer.inc');
?>
