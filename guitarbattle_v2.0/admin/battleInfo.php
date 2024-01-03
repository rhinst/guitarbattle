<?
include('templates/general/header.inc');
if(isset($battle_id)) {
  $battle_info = get_battle_info($battle_id);
  vilw_result_globalize($battles_cols, $battle_info, "battle_");
}


switch($action) {
case "reupload1":
  if(($song) && ($song != "none")) {
	$id_battle = $battle_id;
	$mp3_info = get_mp3_info($song);
	$file_name = $song_name;
	$file_type = $song_type;
	$file_size = filesize($song);
	$file_contents = fread(fopen($song, "r"), $file_size);
	$views = 0;
	$username = $battle_user1;
	$collab = $battle_collab2;
	$genre = $battle_genre;
	$mpeg_version = $mp3_info->mpeg_version;
	$mpeg_layer = $mp3_info->mpeg_layer;
	$bitrate = $mp3_info->bitrate;
	$sample_rate = $mp3_info->sample_rate;
	$channel_mode = $mp3_info->channel_mode;
	vilw_query(vilw_sql_insert($mp3s_cols, $mp3s_table));
	$mp3_id = mysql_insert_id();
	vilw_query("update " . $battles_table . " set file1='"  . $mp3_id . "' where id=" . $battle_id);
	vilw_query(vilw_sql_delete($mp3s_table, "where id = '" . $battle_file1 . "'"));
	$battle_file1 = $mp3_id;
  }
  break;
case "reupload2":
  if(($song) && ($song != "none")) {
	$id_battle = $battle_id;
	$mp3_info = get_mp3_info($song);
	$file_name = $song_name;
	$file_type = $song_type;
	$file_size = filesize($song);
	$file_contents = fread(fopen($song, "r"), $file_size);
	$views = 0;
	$username = $battle_user2;
	$collab = $battle_collab2;
	$genre = $battle_genre;
	$mpeg_version = $mp3_info->mpeg_version;
	$mpeg_layer = $mp3_info->mpeg_layer;
	$bitrate = $mp3_info->bitrate;
	$sample_rate = $mp3_info->sample_rate;
	$channel_mode = $mp3_info->channel_mode;
	vilw_query(vilw_sql_insert($mp3s_cols, $mp3s_table));
	$mp3_id = mysql_insert_id();
	vilw_query("update " . $battles_table . " set file2='"  . $mp3_id . "' where id=" . $battle_id);
	vilw_query(vilw_sql_delete($mp3s_table, "where id = '" . $battle_file2 . "'"));
	$battle_file2 = $mp3_id;
  }
  break;
case "remove_user1":
  //Delete user1's mp3
  vilw_query(vilw_sql_delete($mp3s_table, "where id='" . $battle_file1 . "'"));
  //Delete any votes in the battle
  vilw_query(vilw_sql_delete($votes_table, "where battle_id='" . $battle_id . "'"));
  // move user2 to user1
  vilw_query("update " . $battles_table . " set user1=user2, file1=file2, collab1=collab2, collab1_confirmed=collab2_confirmed, user2='', collab2='', collab2_confirmed='0' where id='" . $battle_id . "'");
  //Restore the vote bank points that user1 used to join this battle
  vilw_query("update " . $users_table . " set vote_bank = (vote_bank + " . $vote_bank_quota . ") where username='" . $battle_user1 . "'");
  // Refresh battle info
  $battle_info = get_battle_info($battle_id);
  vilw_result_globalize($battles_cols, $battle_info, "battle_");
  break;
case "remove_user2":
  // Delete user2's mp3
  vilw_query(vilw_sql_delete($mp3s_table, "where id='" . $battle_file2 . "'"));
  // Delete any votes in the battle
  vilw_query(vilw_sql_delete($votes_table, "where battle_id='" . $battle_id . "'"));
  // Remove user2 from battle
  vilw_query("update " . $battles_table . " set user2='', collab2='', collab2_confirmed='0' where id='" . $id . "'");
  // Restore the vote bank points that user2 used to join this battle
  vilw_query("update " . $users_table . " set vote_bank = (vote_bank + " . $vote_bank_quota . ") where username='" . $battle_user2 . "'");
  // Refresh battle info
  $battle_info = get_battle_info($battle_id);
  vilw_result_globalize($battles_cols, $battle_info, "battle_");
  break;
}

if(isset($battle_id)) {
  include('templates/battleInfo/form.inc');
}

include('templates/general/footer.inc');
?>
