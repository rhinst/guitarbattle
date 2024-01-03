<?
require_login();
require_judge();

$res = vilw_query(vilw_sql_select($users_cols, $users_table, "where judge='1'"));
$total_judges = mysql_num_rows($res);

$tie_battles = Array();
$res = vilw_query(vilw_sql_select($battles_cols, $battles_table, "where active=0 and winner='' and hide=1 and score1=score2 and user1 != '" . $authenticated_user . "' and user2 != '" . $authenticated_user . "' and collab1 != '" . $authenticated_user . "' and collab2 != '" . $authenticated_user . "'"));
while($row = mysql_fetch_row($res)) {
	vilw_result_globalize($battles_cols, $row, "battle_");
	$num_judges = $total_judges;
	if(is_judge($battle_user1)) {
		$num_judges--;
	}
	if(is_judge($battle_user2)) {
		$num_judges--;
	}
	if(is_judge($battle_collab1)) {
		$num_judges--;
	}
	if(is_judge($battle_collab2)) {
		$num_judges--;
	}
	if((is_judge($authenticated_user)) || (($num_judges % 2) == 0)) {
		$tie_battles[] = $row;	
	}
}

include('templates/general/header.inc');
include('templates/decide/printList.inc');
include('templates/general/footer.inc');
?>
