<?
require_login();
include('templates/general/header.inc');

$users = vilw_result_array(vilw_query(vilw_sql_select($users_cols, $users_table, "where username like '%" . $searchKeyword . "%'")));
$songs = vilw_result_array(vilw_query(vilw_sql_select($mp3s_cols, $mp3s_table, "where song_name like '%" . $searchKeyword . "%' or username like '%" . $searchKeyword . "%'")));

include('templates/searchResults/userMatches.inc');
include('templates/searchResults/songMatches.inc');

include('templates/general/footer.inc');
?>
