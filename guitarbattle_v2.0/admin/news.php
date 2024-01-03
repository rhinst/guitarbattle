<?
	include('templates/general/header.inc');

	switch($action) {
	  case("add"): {
	    $timestamp = date("YmdHis");
	    vilw_query(vilw_sql_insert($news_cols, $news_table));
	    break;
	  }
	  case("update"): {

	    break;
	  }
	  case("delete"): {
	    vilw_query(vilw_sql_delete($news_table, "where id=" . $id));
	    break;
	  }
	}

	include('templates/news/addNews.inc');
	$news = get_news();
	include('templates/news/listNews.inc');

	include('templates/general/footer.inc');
?>
