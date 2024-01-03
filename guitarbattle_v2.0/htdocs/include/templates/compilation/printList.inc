<br><br>
<script language="javascript">
<!--//
function confirmDelete() {
	return(confirm('Are you sure you want to remove this track from your compilation?'));
}
//-->
</script>

<form action="<? print $PHP_SELF; ?>" method="post">
<table width="500" class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td colspan="6" class="item_title">
      Current Track List:
    </td>
  </tr>
  <tr>
    <td class="item_title">
      #
    </td>
    <td class="item_title">
      Song Name
    </td>
    <td class="item_title">
      User
    </td>
    <td class="item_title">
      Genre
    </td>
    <td class="item_title">
      Length
    </td>
    <td class="item_title">
      &nbsp; 
    </td> 
  </tr>
<? 
foreach($track_list as $track) { 
	vilw_result_globalize($track_lists_cols, $track, "track_");
	print "<tr>\n";
	print "<form action=\"" . $PHP_SELF . "\" method=\"post\">\n";
	vilw_hidden("action", "delete"); 
	vilw_hidden("mp3_id", $track_mp3_id); 
	print "<td>" . $track_track_number . "</td>\n";
	print "<td><a href=\"#\" onClick=\"popupPlayer('" . $track_mp3_id . "', '" . $track_song_name . "')\">" . $track_song_name . "</a></td>\n";
	print "<td>" . $track_username .  (($track_collab)?(" / " . $track_collab):("")) . "</td>\n";
	print "<td>" . get_genre_name($track_genre) . "</td>\n";
	print "<td>" . readable_time($track_track_length) . "</td>\n";
	print "<td>";
	if($mode == "edit") {
	print "<input class=\"button\" type=\"submit\" value=\"Remove Track\">";
	}
	print "</td>\n";
	print "</form>\n";
	print "</tr>\n";
} 

if(count($track_list) == 0) {
	print "<tr valign=\"middle\">\n";
	print "<td colspan=\"6\" align=\"center\"><img src=\"" . $baseURL . "/images/spacer.gif\" border=\"0\" alt=\"\" height=\"50\" width=\"200\"></td>\n";
	print "</tr>\n";
	print "<tr valign=\"middle\">\n";
	print "<td colspan=\"6\" align=\"center\">No Tracks Selected</td>\n";
	print "</tr>\n";
	print "<tr valign=\"middle\">\n";
	print "<td colspan=\"6\" align=\"center\"><img src=\"" . $baseURL . "/images/spacer.gif\" border=\"0\" alt=\"\" height=\"50\" width=\"200\"></td>\n";
	print "</tr>\n";
}
?>
  <tr>
    <form action="orderForm.php" method="post">
    <td colspan="4" align="right" class="item_title">
      Total Time: 
    </td>
    <td><? print readable_time($total_time); ?></td>
    <td>
    <? if(($mode == "edit") && ($total_time > 0)) { ?>
      <input class="button" type="submit" value="Place Order">
    <? } ?>
    </td>
    </form>
  </tr>
</table>
</form>
