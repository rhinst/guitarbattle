<script language="javascript">
function popupPlayer(mp3_id, song_name) {
	mp3PlayerWin = window.open('<? print $baseURL; ?>/mp3Player.php?mp3_id=' + mp3_id + '&mp3_name=' + song_name, 'mp3PlayerWin', 'width=214,height=107,scrollbars=no,toolbar=no,titlebar=no,location=no,menubar=no,resizable=no,directories=no');
}
</script>

<table border="0" cellspacing="0" cellpadding="2">
  <tr>
    <td>
      <table border="0" cellspacing="0" cellpadding="0">
        <tr>
          <td align="center" style="font-size: 0px">
            <? include('templates/viewBattle/displayUserIcon.inc'); ?>
          </td>
        </tr>
      </table>
    </td>
  </tr>
  <tr>
    <td align="center">
      <a class="large_link" href="viewProfile.php?username=<? print $competitor_username; ?>"><? print $competitor_username; ?></a>
      <?  if($collab_username) {  ?>
        &nbsp;/&nbsp;<a class="large_link" href="viewProfile.php?username=<? print $collab_username; ?>""><? print $collab_username; ?></a>
      <? } ?>
    </td>
  </tr>
  <tr>
    <td align="center">
      "<? print htmlspecialchars($mp3_song_name); ?>"
    </td>
  </tr>
<? if(get_preference("popup_player") == 1) { ?>
  <tr>
    <td align="center">
      <a href="#" onClick="popupPlayer('<? print $mp3_id; ?>', '<? print $mp3_song_name; ?>')">Load MP3 Player</a>
    </td>
  </tr>
<? } else { ?>
  <tr>
    <td align="center">
      <?
	 include('mp3Player.inc'); 
      ?>
    </td>
  </tr>
<? } ?>
  <tr>
    <td align="center">
<? include('templates/viewBattle/songInfo.inc'); ?>
    </td>
  </tr>
<? if($mp3_notes) { ?>
  <tr>
    <td align="center">
      <a href="viewSongNotes.php?id=<? print $mp3_id; ?>" target="_new">View Notes/Tablature</a>
    </td>
  </tr>
<? } ?>
  <tr>
    <td align="center">
      <a href="<? print $baseURL; ?>/loadSong.php?id=<? print $mp3_id; ?>">Download Song</a>
    </td>
  </tr>
</table>
