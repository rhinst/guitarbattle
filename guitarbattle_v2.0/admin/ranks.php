<?
	include('templates/general/header.inc');

	switch($action) {
	  case("add"): {
	    vilw_query(vilw_sql_insert($ranks_cols, $ranks_table));
	    break;
	  }
	  case("update"): {

	    break;
	  }
	  case("delete"): {
	    vilw_query(vilw_sql_delete($ranks_table, "where id=" . $id));
	    break;
	  }
	}

	include('templates/ranks/addRank.inc');
	$ranks = get_ranks();
	include('templates/ranks/printRanks.inc');

	include('templates/general/footer.inc');
?>
