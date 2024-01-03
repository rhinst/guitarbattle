<?
  if($authenticated_user == $battle_collab1) {
    $mp3_id = $battle_file1;
  }
  else {
    $mp3_id = $battle_file2;
  }
  include('mp3Player.inc');
?>
<br>
<br>
<a href="loadSong.php?id=<? print $mp3_id; ?>">Download the MP3 here</a>
<br>
<br>
