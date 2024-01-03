#!/usr/local/bin/php -q
<?
include('gb.lib');

$battles = vilw_result_array(vilw_query(vilw_sql_select($battles_cols, $battles_table)));
foreach($battles as $battle) {
	vilw_result_globalize($battles_cols, $battle);
	vilw_query("update " . $mp3s_table . " set username='" . $user1 . "', collab='" . $collab1 . "' where id='" . $file1 . "'");
	vilw_query("update " . $mp3s_table . " set username='" . $user2 . "', collab='" . $collab2 . "' where id='" . $file2 . "'");
}
?>
