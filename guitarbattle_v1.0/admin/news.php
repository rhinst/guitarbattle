<?

include('gb.lib');

switch($action) {
case "add":
	$ts = date("Y-m-d H:i:s");
	vilw_query(vilw_sql_insert($news_cols, "news"));
	break;
case "update":
	vilw_query(vilw_sql_update($news_cols, "news", "where id=" . $id));
	break;
case "delete":
	vilw_query(vilw_sql_delete("news", "where id=" . $id));
	break;
}

$news_array = vilw_result_array(vilw_query(vilw_sql_select($news_cols, "news", "order by ts desc")));

include('header.inc'); 

print "<script language=\"javascript\">\n";
print "function confirmDelete() {\n";
print "return(confirm('Are you sure you want to delete this item?'));\n";
print "}\n";
print "</script>\n";

print "<table border=\"1\" width=\"500\">\n";

reset($news_array);
while($item = current($news_array)) {
	vilw_result_globalize($news_cols, $item);
	print "<form action=\"" . $PHP_SELF . "\" method=\"post\">\n";
	vilw_hidden("action", "update");
	vilw_hidden("id");
	vilw_hidden("ts");
	print "<tr>\n";
	print "<td>";
	vilw_textarea("news", 5, 40, $news);
	print "</td>\n";
	print "<td>\n";
	print "<input type=\"submit\" value=\"Update\">\n";
	print "</form>\n";
	print "<br>\n";
	print "<form action=\"" . $PHP_SELF . "\" method=\"post\" onSubmit=\"return(confirmDelete());\">\n";
	vilw_hidden("action", "delete");
	vilw_hidden("id");
	print "<input type=\"submit\" value=\"Delete\">\n";
	print "</form>\n";
	print "</td>\n";
	print "</tr>\n";
	next($news_array);
}

print "</table>\n";

vilw_result_unglobalize($news_cols);

print "<form action=\"" . $PHP_SELF . "\" method=\"post\">\n";
vilw_hidden("action", "add");
print "<table border=\"1\">\n";
print "<tr>\n";
print "<td>\n";
vilw_textarea("news", 5, 40);
print "</td>\n";
print "</tr>\n";
print "<tr>\n";
print "<td align=\"right\">\n";
print "<input type=\"submit\" value=\"Add\">\n";
print "</td>\n";
print "</tr>\n";
print "</table>\n";
print "</form>\n";

include('footer.inc');

?>
