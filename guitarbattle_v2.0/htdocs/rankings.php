<?
$users_per_page = 25;
if(!$start_index) {
	$start_index = 1;
}


include('templates/general/header.inc');
$new_users = vilw_result_array(vilw_query(vilw_sql_select($users_cols, $users_table, "where rank = '' order by username asc")));
print("<br>");
include('templates/rankings/newUsers.inc');
$total_users = mysql_num_rows(vilw_query(vilw_sql_select($users_cols, $users_table, "where rank != '' order by num_battles desc, (score_sum / num_battles) desc, username asc")));
$users = vilw_result_array(vilw_query(vilw_sql_select($users_cols, $users_table, "where rank != '' order by num_battles desc, (score_sum / num_battles) desc, username asc limit " . ($start_index - 1) . "," . $users_per_page)));
include('templates/rankings/printRankings.inc');
include('templates/general/footer.inc');
?>
