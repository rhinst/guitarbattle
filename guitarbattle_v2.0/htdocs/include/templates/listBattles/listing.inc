<br>
<table class="items" width="400" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title" colspan="4">
<? if(count($battles) > 1) { ?>
      <b>Showing Battles <? print $start_limit + 1; ?> to <? print $start_limit + count($battles); ?>:</b>
<? } else { ?>
      <b>Showing Battles <? print count($battles); ?> of <? print count($battles); ?>:</b>
<? } ?>
    </td>
  </tr>
  <tr>
    <td class="item_title">
      Initiator
    </td>
    <td class="item_title">
      Challenger
    </td>
    <td class="item_title">
      Genre
    </td>
    <td class="item_title" class="listing_row2">
      &nbsp;
    </td>
    </td>
  </tr>
<?
	$i = 0;
	foreach($battles as $battle) {
		vilw_result_globalize($battles_cols, $battle, "battle_");
		$row_style = ($i % 2 == 0)?("listing_row1"):("listing_row2");
		print "<tr>\n";
		print "<td class=\"" . $row_style . "\" align=\"left\" width=\"75\">" . (($battle_winner == $battle_user1)?("<b class=\"green\">" . $battle_user1 . (($battle_collab1)?(" / " . $battle_collab1):("")) . "</b>"):($battle_user1 . (($battle_collab1)?(" / " . $battle_collab1):("")))) . "</td>\n";
		print "<td class=\"" . $row_style . "\" align=\"left\" width=\"75\">" . (($battle_winner == $battle_user2)?("<b class=\"green\">" . $battle_user2 . "</b>"):($battle_user2)) .  (($battle_collab2)?(" / " . $battle_collab2):("")) . "</td>\n";
		print "<td class=\"" . $row_style ."\">" . get_genre_name($battle_genre) . "</td>\n";
		print "<td class=\"" . $row_style . "\" align=\"left\" width=\"75\"><a href=\"viewBattle.php?battle_id=" . $battle_id . "\">View Battle</a></td>\n";
		print "</tr>\n";
		$i++;
	}
?>
</table>
