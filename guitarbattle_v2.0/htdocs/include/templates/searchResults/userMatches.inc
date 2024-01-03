<br>
<table class="items" border="0" width="350" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title"><? print count($users); ?> Matching Users:</td>
  </tr>
<?
	$i = 0;
	foreach($users as $user) {
		vilw_result_globalize($users_cols, $user, "user_");
		$row_style = ($i % 2 == 0)?("listing_row1"):("listing_row2");
		print "<tr>\n";
                print "<td class=\"" . $row_style . "\" align=\"left\" width=\"175\"><a href=\"" . $baseURL . "/viewProfile.php?username=" . $user_username . "\">" . $user_username . "</a></td>\n";
                print "</tr>\n";
		$i++;
	}
?>
</table>
<br><br>
