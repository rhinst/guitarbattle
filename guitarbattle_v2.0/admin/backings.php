<?
	include('templates/general/header.inc');

	switch($action) {
	  case("add"): {
	     if(($song) && ($song != "none")) {
		$file_name = $song_name;
		$file_type = $song_type;
		$file_contents = fread(fopen($song, "r"), filesize($song));
		vilw_query(vilw_sql_insert($mp3s_cols, $mp3s_table));
		$mp3_id = mysql_insert_id();
		vilw_query(vilw_sql_insert($backings_cols, $backings_table));
             }
	    break;
	  }
	  case("update"): {

	    break;
	  }
	  case("delete"): {
            vilw_query(vilw_sql_delete($mp3s_table, "where id='" . $mp3_id . "'"));
            vilw_query(vilw_sql_delete($backings_table, "where id='" . $id . "'"));
	    break;
	  }
	}

	include('templates/backings/addBacking.inc');
	$backings = vilw_result_array(vilw_query(vilw_sql_select($backings_cols, $backings_table, "order by name asc")));
	include('templates/backings/listBackings.inc');

	include('templates/general/footer.inc');
?>
