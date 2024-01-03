<?

include('templates/general/header.inc');
switch($action) {
case "delete":
	foreach($delete_genres as $del_genre_id) {
		delete_genre($del_genre_id);
		include('templates/genres/deleted.inc');
	}
	break;
case "add":
	vilw_query(vilw_sql_insert($genres_cols, $genres_table));
default:
	$genres = get_genres();
	include('templates/genres/addForm.inc');
	include('templates/genres/printList.inc');
}
include('templates/general/footer.inc');
?>
