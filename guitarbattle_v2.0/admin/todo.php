<?

switch($action) {
case "add":
	$open = 1;
	vilw_query(vilw_sql_insert($todo_cols, $todo_table));
	break;
case "close":
	foreach($close_items as $item) {
		vilw_query("update todo set open='0' where id='" . $item ."'");
	}
	break;
case "delete":
	foreach($delete_items as $item) {
		vilw_query(vilw_sql_delete($todo_table, "where id='" . $item . "'"));
	}
	break;
}

$open_items = vilw_result_array(vilw_query(vilw_sql_select($todo_cols, $todo_table, "where open='1' order by id desc")));
$closed_items = vilw_result_array(vilw_query(vilw_sql_select($todo_cols, $todo_table, "where open='0' order by id desc")));

include('templates/general/header.inc'); 
include('templates/todo/add_item.inc');
include('templates/todo/open_items.inc');
include('templates/todo/closed_items.inc');
include('templates/general/footer.inc'); 
?>
