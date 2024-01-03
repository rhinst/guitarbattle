<?
require_login();
include('templates/general/header.inc'); 

if(!$step) {
	$step = "choose_genre";
}

if(!session_is_registered("start_battle_id")) {
	$user1 = $authenticated_user;
	$active = "1";
	$hide = "0";
	$timestamp = date("Y-m-d H:i:s");
	vilw_query(vilw_sql_insert($battles_temp_cols, $battles_temp_table));
	$start_battle_id = mysql_insert_id();
	session_register("start_battle_id");
}
else {
	$res = vilw_query(vilw_sql_select($battles_temp_cols, $battles_temp_table, "where id=" . $start_battle_id));
	$row = mysql_fetch_row($res);
	vilw_result_globalize($battles_temp_cols, $row, "new_");
}

switch($step) {
case "choose_genre":
	$prev_step = "";
	$next_step = "choose_challenger";
	$total_battles = get_user_battle_count($authenticated_user);
	$curr_battles = get_user_current_battle_count($authenticated_user);
	if($curr_battles >= $max_simultaneous_battles) {
		$err_msg = "You are already participating in the maximum number of simultaneous battles.";
		include('templates/startBattle/error.inc');
	}
	else if(($total_battles != 0) && (!check_vote_bank_quota($authenticated_user))) {
		$err_msg = "You have not voted on enough battles to be able to post your own. Go back and vote more first.";
		include('templates/startBattle/error.inc');
	}
	else {
		$genres = get_genres();
		include('templates/startBattle/chooseGenre.inc');
	}
	break;
case "choose_challenger":
	$prev_step = "choose_genre";
	$next_step = "choose_backing";
	if(!$genre) {
		if(!$new_genre) {
			$err_msg = "You must choose a genre.";
			include('templates/startBattle/error.inc');
		}
		else {
			include('templates/startBattle/chooseChallenger.inc');
		}
	}
	else {
		vilw_query("update " . $battles_temp_table . " set genre="  . $genre . " where id=" . $start_battle_id . " and user1='" . $authenticated_user . "'");	
		include('templates/startBattle/chooseChallenger.inc');
		
	}
	break;
case "reupload_backing":
	vilw_query(vilw_sql_delete($mp3s_table, "where id='" . $new_backing . "'"));
	vilw_query("update " . $battles_temp_table . " set backing='0' where id='" . $start_battle_id . "' and user1='" . $authenticated_user . "'");
	$new_backing = "0";
case "choose_backing":
	$prev_step = "choose_challenger";
	$next_step = "choose_collab";
	if($open == "0") {
		if(!user_exists($challenge_user)) {
			$err_msg = "The user '" . $challenger_user . "' does not exist.";
			include('templates/startBattle/error.inc');
		}
		else {
			vilw_query("update " . $battles_temp_table . " set challenger='"  . $challenge_user . "' where id=" . $start_battle_id . " and user1='" . $authenticated_user . "'");	
			include('templates/startBattle/chooseBacking.inc');
		}
	}
	else {
		vilw_query("update " . $battles_temp_table . " set challenger='' where id=" . $start_battle_id . " and user1='" . $authenticated_user . "'");	
		include('templates/startBattle/chooseBacking.inc');
	}
	break;
case "choose_collab":
	$prev_step = "choose_backing";
	$next_step = "upload_song";
	if($same_backing == "1") {
		if(($backing) && ($backing != "none")) {

			$id_battle = $start_battle_id;
			$mp3_info = get_mp3_info($backing);
			$file_name = $backing_name;
			$file_type = $backing_type;
			$file_size = filesize($backing);
			$file_contents = fread(fopen($backing, "r"), $file_size);
			if((substr($file_type, 0, strlen("audio")) != "audio") && (($file_type != "application/octet-stream") || (substr($file_name, strlen($file_name) - 4, 4) != ".mp3"))) {
				$err_msg = "The file you uploaded does not appear to be a valid audio file.";
				include('templates/startBattle/error.inc');
			}
			else if($file_size == 0) {
				$err_msg = "There was a problem during the upload, or the file you uploaded is not valid mp3 file.";
				include('templates/startBattle/error.inc');
			}
			else if($file_size > $max_mp3_size) {
				$err_msg = "The file you uploaded exceeds the maximum allowed size.";
				include('templates/startBattle/error.inc');
			}
			else {
				$views = 0;
				$username = $authenticated_user;	
				$genre = $new_genre;
				$mpeg_version = $mp3_info->mpeg_version;
				$mpeg_layer = $mp3_info->mpeg_layer;
				$bitrate = $mp3_info->bitrate;
				$sample_rate = $mp3_info->sample_rate;
				$channel_mode = $mp3_info->channel_mode;
				vilw_query(vilw_sql_insert($mp3s_cols, $mp3s_table));
				$mp3_id = mysql_insert_id();
				vilw_query("update " . $battles_temp_table . " set backing='"  . $mp3_id . "' where id=" . $start_battle_id . " and user1='" . $authenticated_user . "'");	
				include('templates/startBattle/chooseCollab.inc');
			}
		}
		else if($new_backing == 0) {
			$err_msg = "You didn't upload a song, or your upload failed.";
			include('templates/startBattle/error.inc');
		}
		
	}
	else {
		vilw_query("update " . $battles_temp_table . " set backing='0' where id=" . $start_battle_id . " and user1='" . $authenticated_user . "'");	
		include('templates/startBattle/chooseCollab.inc');
	}
	break;
case "reupload_song":
	vilw_query(vilw_sql_delete($mp3s_table, "where id='" . $new_file1 . "'"));
	vilw_query("update " . $battles_temp_table . " set file1='0' where id='" . $start_battle_id . "' and user1='" . $authenticated_user . "'");
	$new_file1 = "0";
case "upload_song":
	$prev_step = "choose_collab";
	$next_step = "song_info";
	if($collaborative == "1") {
		if(!user_exists($collab_user)) {
			$err_msg = "The user '" . $collab_user . "' does not exist.";
			include('templates/startBattle/error.inc');
		}
		else if($new_challenger == $authenticated_user) {
			$err_msg = "You cannot collaborate with yourself.";
			include('templates/startBattle/error.inc');
		}
		else if($new_challenger == $collab_user) {
			$err_msg = "You cannot collaborate with the user you are challenging.";
			include('templates/startBattle/error.inc');
		}
		else {
			vilw_query("update " . $battles_temp_table . " set collab1='"  . $collab_user . "' where id=" . $start_battle_id . " and user1='" . $authenticated_user . "'");	
			include('templates/startBattle/uploadSong.inc');
		}
	}
	else {
		vilw_query("update " . $battles_temp_table . " set collab1='' where id=" . $start_battle_id . " and user1='" . $authenticated_user . "'");	
		include('templates/startBattle/uploadSong.inc');
	}
	break;
case "song_info":
	$prev_step = "upload_song";
	$next_step = "verify";
	if(($song) && ($song != "none")) {
		$id_battle = $start_battle_id;
		$mp3_info = get_mp3_info($song);
		$file_name = $song_name;
		$file_type = $song_type;
		$file_size = filesize($song);
		$file_contents = fread(fopen($song, "r"), $file_size);
		if((substr($file_type, 0, strlen("audio")) != "audio") && (($file_type != "application/octet-stream") || (substr($file_name, strlen($file_name) - 4, 4) != ".mp3"))) {
			$err_msg = "The file you uploaded does not appear to be a valid audio file.<br>type is " . $file_type;
			include('templates/startBattle/error.inc');
		}
		else if($file_size == 0) {
			$err_msg = "There was a problem during the upload, or the file you uploaded is not valid mp3 file.";
			include('templates/startBattle/error.inc');
		}
		else if($file_size > $max_mp3_size) {
			$err_msg = "The file you uploaded exceeds the maximum allowed size.";
			include('templates/startBattle/error.inc');
		}
		else {
			$views = 0;
			$username = $authenticated_user;
			$genre = $new_genre;
			$mpeg_version = $mp3_info->mpeg_version;
			$mpeg_layer = $mp3_info->mpeg_layer;
			$bitrate = $mp3_info->bitrate;
			$sample_rate = $mp3_info->sample_rate;
			$channel_mode = $mp3_info->channel_mode;
			vilw_query(vilw_sql_insert($mp3s_cols, $mp3s_table));
			$mp3_id = mysql_insert_id();
			vilw_query("update " . $battles_temp_table . " set file1='"  . $mp3_id . "' where id=" . $start_battle_id . " and user1='" . $authenticated_user . "'");	
			include('templates/startBattle/songInfo.inc');
		}
		
	}
	else {
		if($new_file1 == 0) {
			$err_msg = "You didn't upload a song, or your upload failed.";
			include('templates/startBattle/error.inc');
		}
		else {
			include('templates/startBattle/songInfo.inc');
		}
	}
	break;
case "verify":
	$prev_step = "song_info";
	$next_step = "complete";
	vilw_query("update " . $mp3s_table . " set song_name='" . addslashes($song_name) . "', notes='" . addslashes($notes) . "' where id='" . $new_file1 . "'");
	$res = vilw_query(vilw_sql_select($mp3s_cols, $mp3s_table, "where id='" . $new_file1 . "'"));
	$row = mysql_fetch_row($res);
	vilw_result_globalize($mp3s_cols, $row, "mp3_");
	include('templates/startBattle/verify.inc');
	break;
case "complete":
	$prev_step = "verify";
	$next_step = "";
	$total_battles = get_user_battle_count($authenticated_user);
	$curr_battles = get_user_current_battle_count($authenticated_user);
	if($curr_battles >= $max_simultaneous_battles) {
		$err_msg = "You are already participating in the maximum number of simultaneous battles.";
		include('templates/startBattle/error.inc');
	}
	else if(($total_battles != 0) && (!check_vote_bank_quota($authenticated_user))) {
		$err_msg = "You have not voted on enough battles to be able to post your own. Go back and vote more first.";
		include('templates/startBattle/error.inc');
	}
	else {
		vilw_query("insert into " . $battles_table . " select * from " . $battles_temp_table . " where id=" . $start_battle_id . " and user1='" . $authenticated_user . "'");
		vilw_query(vilw_sql_delete($battles_temp_table, "where id=" . $start_battle_id));
		reset_vote_bank($authenticated_user);
		if(($new_challenger != '') && ($new_collab1 == '')) {
			send_challenge_message($new_challenger, $authenticated_user, $start_battle_id);
		}
		if($new_collab1 != '') {
			send_collab_message($new_collab1, $authenticated_user, $start_battle_id);
			vilw_query("update " . $battles_table . " set hide='1' where id='" . $start_battle_id . "' and user1='"  . $authenticated_user . "'");
		}
		include('templates/startBattle/complete.inc');
		session_unregister("start_battle_id");
	}
	break;
}

include('templates/general/footer.inc'); 
?>
