<br><br>
<table border="0" width="600" cellspacing="0" cellpadding="0">
  <tr>
    <td colspan="3" width="600" align="center">
      <img src="images/comments_header.jpg" width="600" border="0" alt="Comments">
    </td>
  </tr>
  <tr>
    <td width="92">&nbsp;</td>
    <td width="415">
<?  include('templates/viewBattle/frameHeader.inc'); ?>
<table width="369" border="0" cellspacing="0" cellpadding="0">
<?
$i = 0;
foreach($comments as $comment) {
	vilw_result_globalize($comments_cols, $comment, "comment_");
		$row_style = ($i % 2 == 0)?("comments_row1"):("comments_row2");
		print "<tr valign=\"top\">\n";
		print "<td class=\"" . $row_style . "\" align=\"left\" width=\"125\">" . $comment_username . "<br>\n";
		print "(" . mysql_ts_printable($comment_timestamp) . ")</td>\n";
		print "<td class=\"" . $row_style . "\" align=\"left\">" . nl2br(wordwrap(htmlspecialchars($comment_comment), 45, "\n", 1)) . "</td>\n";
		print "</tr>\n";
		$i++;
} 
$comment = "";
?>
</table>
<?  include('templates/viewBattle/frameFooter.inc'); ?>
    </td>
    <td width="93">&nbsp;</td>
  </tr>
</table>
