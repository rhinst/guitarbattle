<?
require_login();

include('templates/general/header.inc');

if(!$battle_id) {
	$err_msg = "No battle specified.";
	include('templates/declineBattle/error.inc');
	
}
else {
	$res = vilw_query(vilw_sql_select($battles_cols, $battles_table, "where id='" . $battle_id . "'"));
	if(!($row = mysql_fetch_row($res))) {
		$err_msg = "Unable to locate battle.";
		include('templates/declineBattle/error.inc');
	}
	else {
		vilw_result_globalize($battles_cols, $row, "battle_");
		if($authenticated_user != $battle_challenger) {
			$err_msg = "You cannot decline a battle that you were not challenged to.";
			include('templates/declineBattle/error.inc');
		}
		else {
			vilw_query(vilw_sql_delete($battles_table, "where id='" . $battle_id . "'"));
			send_challenge_response($battle_user1, $authenticated_user, $battle_id, "declined");
			include('templates/declineBattle/declined.inc');
		}
	}
}


include('templates/general/footer.inc');

?>
