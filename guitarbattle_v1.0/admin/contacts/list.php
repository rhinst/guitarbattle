<?
include('gb.lib');

$contacts = vilw_result_array(vilw_query(vilw_sql_select($contact_cols, "contacts", "order by category, company")));

include('header.inc'); 

$curr_category = "";
print "<table border=\"0\">\n";
while($contact = current($contacts)) {
	print "<tr>\n";
	vilw_result_globalize($contact_cols, $contact);
	if($curr_category != $category) {
		$curr_category = $category;
		print "<td style=\"background-color: white; color: black\" align=\"center\">\n";
		print "<b>" . $category . "</b><br>\n";
		print "</td>\n";
		print "</tr>\n";
		print "<tr>\n";
	}
	print "<td align=\"center\">\n";
	print "<a href=\"info.php?id=" . $id . "\">" . $company . "</a><br>\n";
	print "</td>\n";
	next($contacts);
	print "</tr>\n";
}
include('footer.inc'); 
?>
