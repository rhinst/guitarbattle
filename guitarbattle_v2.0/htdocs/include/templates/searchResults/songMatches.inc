<table class="items" border="0" width="350" cellspacing="0" cellpadding="4">
  <tr>
    <td colspan="2" class="item_title">
      <? print count($songs); ?> Matching Songs:
    </td>
  </tr>
  <tr>
    <td class="item_title">
      Song Name
    </td>
    <td class="item_title">
      Username
    </td>
  </tr>
<?
	$i = 0;
	foreach($songs as $song) {
		vilw_result_globalize($mp3s_cols, $song, "song_");
		$row_style = ($i % 2 == 0)?("listing_row1"):("listing_row2");
		print "<tr>\n";
                print "<td class=\"" . $row_style . "\" align=\"left\" width=\"175\"><a href=\"" . $baseURL . "/loadSong.php?id=" . $song_id . "\">" . $song_song_name . "</a></td>\n";
		print "<td class=\"" . $row_style . "\" align=\"left\"><a href=\"" . $baseURL . "/viewProfile.php?username=" . $song_username . "\">" . $song_username . "</a>" . (($song_collab)?(" / <a href=\"" . $baseURL . "/viewProfile.php?username=" . $song_collab . "\">" . $song_collab . "</a>"):("")) ."</td>\n";
                print "</tr>\n";
		$i++;
	}
?>
</table>
<br><br>
