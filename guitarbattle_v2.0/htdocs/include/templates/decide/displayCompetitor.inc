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
  <tr>
    <td align="center">
      <?
	 include('mp3Player.inc'); 
      ?>
    </td>
  </tr>
<? if($mp3_notes) { ?>
  <tr>
    <td align="center">
      <a href="<? print $baseURL; ?>/viewSongNotes.php?id=<? print $mp3_id; ?>" target="_new">View Notes/Tablature</a>
    </td>
  </tr>
<? } ?>
  <tr>
    <td align="center">
      <a href="<? print $baseURL; ?>/loadSong.php?id=<? print $mp3_id; ?>">Download Song</a>
    </td>
  </tr>
<? if(!judge_already_voted($authenticated_user, $battle_id)) { ?>
  <tr>
    <td align="center">
      <form action="<? print $PHP_SELF; ?>" method="post">
        <? vilw_hidden("battle_id"); ?>
        <? vilw_hidden("action", "vote"); ?>
	<? vilw_hidden("competitor", $competitor_username); ?>
	<input class="button" type="submit" value="Vote for <? print $competitor_username; ?>">
      </form>
    </td>
  </tr>
<? } ?>
</table>
