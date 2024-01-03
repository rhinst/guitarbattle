                        <img src="images/ending_soon_title.jpg" border="0" width="204" height="25" alt="Battles Ending Soon">
                        <table class="items" width="175" border="0" cellpadding="4" cellspacing="0">
<?
	$i = 0;
	foreach($battles as $battle) {
		vilw_result_globalize($battles_cols, $battle, "battle_");
		$row_style = ($i % 2 == 0)?("listing_row1"):("listing_row2");
		print "<tr>\n";
                print "<td class=\"" . $row_style . "\" align=\"left\" width=\"175\"><a href=\"viewBattle.php?battle_id=" . $battle_id . "\">&bull; " . $battle_user1 . (($battle_collab1)?(" / " . $battle_collab1):("")) . " Vs. " . $battle_user2 . (($battle_collab2)?(" / " . $battle_collab2):("")) . "</a></td>\n";
                print "</tr>\n";
		$i++;
	}
?>
			  <tr>
                            <td bgcolor="#333333" align="right" width="175"><a class="menu_link" href="listBattles.php">&lt; View More</a></td>
                          </tr>
                        </table>
