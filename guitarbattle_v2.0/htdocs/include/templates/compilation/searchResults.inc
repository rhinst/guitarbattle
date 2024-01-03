<br><br>
<form action="<? print $PHP_SELF; ?>" method="post">
<table width="500" border="0" class="items" cellspacing="0" cellpadding="4">
  <tr>
    <td colspan="5" class="item_title">
      Search Results: 
    </td>
  </tr>
  <tr>
    <td class="item_title">
      Song Name
    </td>
    <td class="item_title">
      Username
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
foreach($songs as $song) { 
	vilw_result_globalize($mp3s_cols, $song, "song_");
	print "<tr>\n";
	print "<form action=\"" . $PHP_SELF . "\" method=\"post\">\n";
	vilw_hidden("action", "add"); 
	vilw_hidden("mp3_id", $song_id); 
	vilw_hidden("search_username");
	vilw_hidden("search_song_name");
	vilw_hidden("search_genre");
	print "<td><a href=\"#\" onClick=\"popupPlayer('" . $song_id . "', '" . $song_song_name . "')\">" . $song_song_name . "</a></td>\n";
	print "<td>" . $song_username .  (($song_collab)?(" / " . $song_collab):("")) . "</td>\n";
	print "<td>" . get_genre_name($song_genre) . "</td>\n";
	print "<td>" . readable_time(round(($song_file_size / ($song_bitrate * 1000)) *  8)) . "</td>\n";
	print "<td><input class=\"button\" type=\"submit\" value=\"Add Track\"></td>\n";
	print "</form>\n";
	print "</tr>\n";
}
?>
</table>
</form>
