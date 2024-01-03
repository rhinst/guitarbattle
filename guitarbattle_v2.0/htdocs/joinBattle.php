<?
require_login();
include('templates/general/header.inc'); 

if(!$step) {
	$step = "choose_collab";
}

if(!session_is_registered("join_battle_id")) {
	$user2 = $authenticated_user;
	$active = "1";
	$hide = "0";
	$timestamp = date("Y-m-d H:i:s");
	vilw_query(vilw_sql_insert($battles_temp_cols, $battles_temp_table));
	$join_battle_id = mysql_insert_id();
	session_register("join_battle_id");
}
$res = vilw_query(vilw_sql_select($battles_temp_cols, $battles_temp_table, "where id=" . $join_battle_id));
$row = mysql_fetch_row($res);
vilw_result_globalize($battles_temp_cols, $row, "new_");

$res = vilw_query(vilw_sql_select($battles_cols, $battles_table, "where id=" . $battle_id));
$row = mysql_fetch_row($res);
vilw_result_globalize($battles_cols, $row, "old_");

switch($step) {
case "choose_collab":
	$prev_step = "";
	$next_step = "upload_song";
	$total_battles = get_user_battle_count($authenticated_user);
	$curr_battles = get_user_current_battle_count($authenticated_user);
	$res = vilw_query("select name from " . $ranks_table . " where num_battles='0' and score='0.0'");
	if(mysql_num_rows($res) == 1) {
		$lowest_rank = mysql_result($res, 0, 'name');	
	}
	if(!($rank1 = get_rank($old_user1))) {
		$rank1 = $lowest_rank;
	}
	if(!($rank2 = get_rank($new_user2))) {
		$rank2 = $lowest_rank;
	}
	if(($old_challenger == '') && ($rank1 != $rank2)) {
		$err_msg = "You may not battle a user that is a different rank than you.";
		include('templates/joinBattle/error.inc');
	}
	else if($old_user2 != '') {
		$err_msg = "Another challenger has already joined this battle.";
		include('templates/joinBattle/error.inc');
	}
	else if(($old_challenger != '') && ($old_challenger != $authenticated_user)) {
		$err_msg = "This battle is reserved for someone else, you are not allowed to join.";
		include('templates/joinBattle/error.inc');
	}
	else if($old_user1 == $authenticated_user) {
		$err_msg = "You may not battle yourself.";
		include('templates/joinBattle/error.inc');
	}
	else if($curr_battles >= $max_simultaneous_battles) {
		$err_msg = "You are already participating in the maximum number of simultaneous battles.";
		include('templates/joinBattle/error.inc');
	}
	else if(($total_battles != 0) && (!check_vote_bank_quota($authenticated_user))) {
		$err_msg = "You have not voted on enough battles to be able to post your own. Go back and vote more first.";
		include('templates/joinBattle/error.inc');
	}
	else {
		include('templates/joinBattle/chooseCollab.inc');
	}
	break;
case "upload_song":
	$prev_step = "choose_collab";
	$next_step = "song_info";
	if($collaborative == "1") {
		if(!user_exists($collab_user)) {
			$err_msg = "The user '" . $collab_user . "' does not exist.";
			include('templates/joinBattle/error.inc');
		}
		else if($collab_user == $authenticated_user) {
			$err_msg = "You cannot collaborate with yourself";
			include('templates/joinBattle/error.inc');
		}
		else if(($old_user1 == $collab_user) || ($old_collab1 == $collab_user)) {
			$err_msg = "You cannot collaborate with the users you are battling.";
			include('templates/joinBattle/error.inc');
		}
		else {
			vilw_query("update " . $battles_temp_table . " set collab2='"  . $collab_user . "' where id=" . $join_battle_id . " and user2='" . $authenticated_user . "'");	
			include('templates/joinBattle/uploadSong.inc');
		}
	}
	else {
		vilw_query("update " . $battles_temp_table . " set collab2='' where id=" . $join_battle_id . " and user1='" . $authenticated_user . "'");	
		include('templates/joinBattle/uploadSong.inc');
	}
	break;
case "song_info":
	$prev_step = "upload_song";
	$next_step = "verify";
	if(($song) && ($song != "none")) {
		$id_battle = $battle_id;
		$mp3_info = get_mp3_info($song);
		$file_name = $song_name;
		$file_type = $song_type;
		$file_size = filesize($song);
		$file_contents = fread(fopen($song, "r"), $file_size);
		if((substr($file_type, 0, strlen("audio")) != "audio") && (($file_type != "application/octet-stream")  || (substr($file_name, strlen($file_name) - 4, 4) != ".mp3"))) {
			$err_msg = "The file you uploaded does not appear to be a valid audio file.";
			include('templates/joinBattle/error.inc');
		}
		else if($file_size == 0) {
			$err_msg = "There was a problem during the upload, or the file you uploaded is not valid mp3 file.";
			include('templates/joinBattle/error.inc');
		}
		else if($file_size > $max_mp3_size) {
			$err_msg = "The file you uploaded exceeds the maximum allowed size.";
			include('templates/joinBattle/error.inc');
		}
		else {
			$views = 0;
			$username = $authenticated_user;
			$genre = $old_genre;
			$mpeg_version = $mp3_info->mpeg_version;
			$mpeg_layer = $mp3_info->mpeg_layer;
			$bitrate = $mp3_info->bitrate;
			$sample_rate = $mp3_info->sample_rate;
			$channel_mode = $mp3_info->channel_mode;
			vilw_query(vilw_sql_insert($mp3s_cols, $mp3s_table));
			$mp3_id = mysql_insert_id();
			vilw_query("update " . $battles_temp_table . " set file2='"  . $mp3_id . "' where id=" . $join_battle_id . " and user2='" . $authenticated_user . "'");	
			include('templates/joinBattle/songInfo.inc');
		}
		
	}
	else {
		if($new_file2 == 0) {
			$err_msg = "You didn't upload a song, or your upload failed.";
			include('templates/joinBattle/error.inc');
		}
		else {
			include('templates/joinBattle/songInfo.inc');
		}
	}
	break;
case "verify":
	$prev_step = "song_info";
	$next_step = "complete";
	vilw_query("update " . $mp3s_table . " set song_name='" . addslashes($song_name) . "', notes='" . addslashes($notes) . "' where id='" . $new_file2 . "'");
	$res = vilw_query(vilw_sql_select($mp3s_cols, $mp3s_table, "where id='" . $new_file2 . "'"));
	$row = mysql_fetch_row($res);
	vilw_result_globalize($mp3s_cols, $row, "mp3_");
	include('templates/joinBattle/verify.inc');
	break;
case "complete":
	$prev_step = "verify";
	$next_step = "";
	
	$total_battles = get_user_battle_count($authenticated_user);
	$curr_battles = get_user_current_battle_count($authenticated_user);
	$res = vilw_query("select name from " . $ranks_table . " where num_battles='0' and score='0.0'");
	if(mysql_num_rows($res) == 1) {
		$lowest_rank = mysql_result($res, 0, 'name');	
	}
	if(!($rank1 = get_rank($old_user1))) {
		$rank1 = $lowest_rank;
	}
	if(!($rank2 = get_rank($new_user2))) {
		$rank2 = $lowest_rank;
	}
	if(($old_challenger == '') && ($rank1 != $rank2)) {
		$err_msg = "You may not battle a user that is a different rank than you.";
		include('templates/joinBattle/error.inc');
	}
	else if($old_user2 != '') {
		$err_msg = "Another challenger has already joined this battle.";
		include('templates/joinBattle/error.inc');
	}
	else if(($old_challenger != '') && ($old_challenger != $authenticated_user)) {
		$err_msg = "This battle is reserved for someone else, you are not allowed to join.";
		include('templates/joinBattle/error.inc');
	}
	else if($old_user1 == $authenticated_user) {
		$err_msg = "You may not battle yourself.";
		include('templates/joinBattle/error.inc');
	}
	else if($curr_battles > $max_simultaneous_battles) {
		$err_msg = "You are already participating in the maximum number of simultaneous battles.";
		include('templates/joinBattle/error.inc');
	}
	else if(($total_battles != 0) && (!check_vote_bank_quota($authenticated_user))) {
		$err_msg = "You have not voted on enough battles to be able to post your own. Go back and vote more first.";
		include('templates/joinBattle/error.inc');
	}
	else {
		vilw_query("update " . $battles_table . " set user2='" . $new_user2 . "', collab2='" . $new_collab2 . "', file2='" . $new_file2 . "', timestamp=now() where id='" . $battle_id . "'");
		vilw_query(vilw_sql_delete($battles_temp_table, "where id=" . $join_battle_id));
		reset_vote_bank($authenticated_user);
		if($authenticated_user == $old_challenger) {
			send_challenge_response($old_user1, $authenticated_user, $battle_id, "accepted");
		}
		if($new_collab2 != '') {
			send_collab_message($new_collab2, $authenticated_user, $battle_id);
			vilw_query("update " . $battles_table . " set hide='1' where id='" . $battle_id . "' and user2='"  . $authenticated_user . "'");
		}
		include('templates/joinBattle/complete.inc');
		session_unregister("join_battle_id");
	}
	break;
}

include('templates/general/footer.inc'); 
?>
