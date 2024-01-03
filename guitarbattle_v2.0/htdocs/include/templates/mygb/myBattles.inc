<table class="items" width="175" border="0" cellpadding="4" cellspacing="0">
  <tr>
    <td class="item_title">
      Your Active Battles:
    </td>
  </tr>
<?
	$i = 0;
	foreach($battles as $battle) {
		vilw_result_globalize($battles_cols, $battle, "battle_");
		$row_style = ($i % 2 == 0)?("listing_row1"):("listing_row2");
		print "<tr>\n";
		print "<td class=\"" . $row_style . "\" align=\"left\" width=\"175\"><a href=\"" . $baseURL . "/viewBattle.php?battle_id=" . $battle_id . "\">&bull; " . $battle_user1 . (($battle_collab1)?(" / " . $battle_collab1):("")) . " Vs. " . $battle_user2 . (($battle_collab2)?(" / " . $battle_collab2):("")) . "</a></td>\n";
		print "</tr>\n";
		$i++;
	}
?>
</table>
