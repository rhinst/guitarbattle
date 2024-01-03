<table class="items" width="175" border="0" cellpadding="4" cellspacing="0">
  <tr>
    <td class="item_title" width="175">Å <? print "<b>" . $genre_name . "</b> " . ((count($battles) > 0)?("[1 - " . count($battles) . " of " . $num_battles . "]"):("[0 of 0]")); ?></td>
  </tr>
<?
        $j = 0;
        foreach($battles as $battle) {
                vilw_result_globalize($battles_cols, $battle, "battle_");
                $row_style = ($j % 2 == 0)?("listing_row1"):("listing_row2");
                print "<tr valign=\"top\">\n";
                print "<td class=\"" . $row_style . "\" align=\"left\" width=\"175\"><a href=\"viewBattle.php?battle_id=" . $battle_id . "\">&bull; " . $battle_user1 . (($battle_collab1)?(" / " . $battle_collab1):("")) . " Vs. " . (($battle_user2)?($battle_user2):("<b>Waiting...</b>")) . (($battle_collab2)?(" / " . $battle_collab2):("")) . "</a></td>\n";
                print "</tr>\n";
                $j++;
        }
	if(count($battles) == 0) {
		print "<tr valign=\"top\">\n";
		print "<td class=\"listing_row1\">N/A</td>\n";
		print "</tr>\n";
	}
?>
  <tr>
    <td bgcolor="#333333" align="right" width="175"><a class="menu_link" href="listBattles.php">&lt; View More</a></td>
  </tr>
</table>
