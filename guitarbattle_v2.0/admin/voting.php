<?
switch($action) {
case "add":
	vilw_query(vilw_sql_insert($voting_categories_cols, $voting_categories_table));
	break;
case "delete":
	foreach($delete_cats as $cat_id) {
		vilw_query(vilw_sql_delete($voting_categories_table, "where id='" . $cat_id . "'"));
	}
	break;
case "regen":
	$voting_categories = get_voting_categories();
	vilw_query("drop table votes");
	$sql = "create table votes (battle_id int(11) not null, voter varchar(32) not null default '', competitor varchar(32) not null default ''";
	foreach($voting_categories as $cat) {
		vilw_result_globalize($voting_categories_cols, $cat, "cat_");
		$sql .= ", cat_" . $cat_id . " int(11) not null default 0";
	}
	$sql .= ", primary key(battle_id, voter, competitor))";
	vilw_query($sql);
	break;
}
include('templates/general/header.inc');
$voting_categories = get_voting_categories();
include('templates/voting/addCategory.inc');
include('templates/voting/printCategories.inc');
include('templates/voting/regen.inc');
include('templates/general/footer.inc');
?>
