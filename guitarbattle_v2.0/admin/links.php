<?
	include('templates/general/header.inc');

	switch($action) {
	  case("add"): {
	    vilw_query(vilw_sql_insert($links_cols, $links_table));
	    break;
	  }
	  case("update"): {

	    break;
	  }
	  case("delete"): {
	    vilw_query(vilw_sql_delete($links_table, "where id=" . $id));
	    break;
	  }
	}

	include('templates/links/addLink.inc');
	$links = get_links();
	include('templates/links/printLinks.inc');

	include('templates/general/footer.inc');
?>
