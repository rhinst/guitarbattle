<br>
<table class="items" width="400" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title" colspan="4">
      <b>Tie Battles Awaiting Decision:</b>
    </td>
  </tr>
  <tr>
    <td class="item_title">ID</td>
    <td class="item_title">User 1</td>
    <td class="item_title">User 2</td>
    <td class="item_title">Score</td>
  </tr>
<?
	$i = 0;
	foreach($tie_battles as $battle) {
		vilw_result_globalize($battles_cols, $battle, "battle_");
		$row_style = ($i % 2 == 0)?("listing_row1"):("listing_row2");
		print "<tr>\n";
                print "<td class=\"" . $row_style . "\" align=\"left\"><a href=\"decide.php?battle_id=" . $battle_id . "\">" . $battle_id . "</a></td>\n";
                print "<td class=\"" . $row_style . "\" align=\"left\">" . $battle_user1 . "</td>\n";
                print "<td class=\"" . $row_style . "\" align=\"left\">" . $battle_user2 . "</td>\n";
                print "<td class=\"" . $row_style . "\" align=\"left\">" . number_format($battle_score1, 2) . " - " . number_format($battle_score2, 2) . "</td>\n";
                print "</tr>\n";
		$i++;
	}
?>
</table>
<br><br>
