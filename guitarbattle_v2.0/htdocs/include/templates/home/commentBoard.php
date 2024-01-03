<?
include('templates/home/commentsHeader.inc');
$comments = vilw_result_array(vilw_query(vilw_sql_select($comments_cols, $comments_table, "where battle_id='0' and ((timestamp + INTERVAL 5 minute) >= now()) order by id asc")));
?>
<table border="0" cellspacing="0" cellpadding="2">
<?
$i = 0;
foreach($comments as $comment) {
	$row_style = ($i % 2 == 0)?("comments_row1"):("comments_row2");
	vilw_result_globalize($comments_cols, $comment, "comment_");
	$printable_date = substr($comment_timestamp, 4, 2) . "." . substr($comment_timestamp, 6, 2) . "." . substr($comment_timestamp, 0,4);
	print "<tr>\n";
	print "<td width=\"125\" class=\"" . $row_style . "\">" . $comment_username . ":&nbsp;</td>\n";
	print "<td class=\"" . $row_style . "\">" . htmlspecialchars($comment_comment) . "<img src=\"" . $baseURL . "/images/spacer.gif\" width=\"5\" height=\"3\"></td>\n";
	print "</tr>\n";
	$i++;
}
print "</table>\n";
include('templates/home/commentsFooter.inc');
?>
