<?
require_login();

include('templates/general/header.inc');

$battle_info = get_battle_info($battle_id);
vilw_result_globalize($battles_cols, $battle_info, "battle_");

if(!$battle_id) {
	$err_msg = "You have not selected a battle.";
	include('templates/completeCollab/error.inc');
	include('templates/general/footer.inc');
	exit;
}

if(($authenticated_user != $battle_user1) && ($authenticated_user != $battle_user2) && ($authenticated_user != $battle_collab1) && ($authenticated_user != $battle_collab2)) {
	$err_msg = "You are not authorized to view this battle.";
	include('templates/completeCollab/error.inc');
	include('templates/general/footer.inc');
	exit;
}

switch($action) {
case "upload":
	if(($song) && ($song != "none")) {
		$id_battle = $battle_id;
		$mp3_info = get_mp3_info($song);
		$file_name = $song_name;
		$file_type = $song_type;
		$file_size = filesize($song);
		$file_contents = fread(fopen($song, "r"), $file_size);
		if(substr($file_type, 0, strlen("audio")) != "audio") {
			$err_msg = "The file you uploaded does not appear to be a valid audio file.";
			include('templates/comleteCollab/error.inc');
		}
		else if($file_size == 0) {
			$err_msg = "There was a problem during the upload, or the file you uploaded is not valid mp3 file.";
			include('templates/comleteCollab/error.inc');
		}
		else if($file_size > $max_mp3_size) {
			$err_msg = "The file you uploaded exceeds the maximum allowed size.";
			include('templates/comleteCollab/error.inc');
		}
		else {
			$views = 0;
			if($authenticated_user == $battle_collab1) {
				$username = $battle_user1;
			}
			else {
				$username = $battle_user2;
			}

			$genre = $battle_genre;
			$collab = $authenticated_user;
			$mpeg_version = $mp3_info->mpeg_version;
			$mpeg_layer = $mp3_info->mpeg_layer;
			$bitrate = $mp3_info->bitrate;
			$sample_rate = $mp3_info->sample_rate;
			$channel_mode = $mp3_info->channel_mode;
			vilw_query(vilw_sql_insert($mp3s_cols, $mp3s_table));
			$mp3_id = mysql_insert_id();
		}
		if($authenticated_user == $battle_collab1) {
			vilw_query(vilw_sql_delete($mp3s_table, "where id='" . $battle_file1 . "'"));
			vilw_query("update " . $battles_table . " set file1='" . $mp3_id . "', hide='0', timestamp=now() where id='" . $battle_id . "' and collab1='" . $authenticated_user . "'");
			if($battle_challenger != '') {
				send_challenge_message($battle_challenger, $battle_user1, $battle_id);
			}
		}
		else if($authenticated_user == $battle_collab2) {
			vilw_query(vilw_sql_delete($mp3s_table, "where id='" . $battle_file2 . "'"));
			vilw_query("update " . $battles_table . " set file2='" . $mp3_id . "', hide='0', timestamp=now() where id='" . $battle_id . "' and collab2='" . $authenticated_user . "'");

		}
		else {
			$err_msg = "You are not allowed to upload a song to this battle.";
			include('templates/completeCollab/error.inc');
		}
	}
	else {
		$err_msg = "You need to upload an MP3 in order to complete this battle.";
		include('templates/completeCollab/error.inc');
		
	}
	include('templates/completeCollab/battleInfo.inc');
	include('templates/completeCollab/downloadForm.inc');
	break;
case "decline":
	if($authenticated_user == $battle_collab1) {
		delete_battle($battle_id);
		send_collab_response($battle_user1, $authenticated_user, $battle_id, "declined");
	}
	else if($authenticated_user == $battle_collab2) {
		vilw_query(vilw_sql_delete($mp3s_table, "where id='" . $battle_file2 . "'"));
		vilw_query("update " . $battles_table . " set file2 = 0, user2='', collab2='', hide='0' where id='" . $battle_id . "' and collab2='" . $authenticated_user . "'");
		send_collab_response($battle_user2, $authenticated_user, $battle_id, "declined");
	}
	else {
		$err_msg = "";
		include('templates/completeCollab/error.inc');
		include('templates/general/footer.inc');
		exit;	
	}
	include('templates/completeCollab/declined.inc');
	break;
case "accept":
	if($authenticated_user == $battle_collab1) {
		vilw_query("update battles set collab1_confirmed = '1' where id = '" . $battle_id . "' and collab1 = '" . $authenticated_user . "'");
		send_collab_response($battle_user1, $authenticated_user, $battle_id, "accepted");
		$battle_collab1_confirmed = 1;
	}
	else if($authenticated_user == $battle_collab2) {
		vilw_query("update battles set collab2_confirmed = '1' where id = '" . $battle_id . "' and collab2 = '" . $authenticated_user . "'");
		send_collab_response($battle_user2, $authenticated_user, $battle_id, "accepted");
		$battle_collab2_confirmed = 1;
	}
	else {
		$err_msg = "";
		include('templates/completeCollab/error.inc');
		include('templates/general/footer.inc');
		exit;	
	}
default: 
	
	include('templates/completeCollab/battleInfo.inc');
	include('templates/completeCollab/downloadForm.inc');

	if((($authenticated_user == $battle_collab1) && ($battle_hide == 1) && ($battle_collab2 == '')) || (($authenticated_user == $battle_collab2) && ($battle_hide == 1))) {
		if((($authenticated_user == $battle_collab1) && ($battle_collab1_confirmed == 0)) || (($authenticated_user == $battle_collab2) && ($battle_collab2_confirmed == 0))) {
			include('templates/completeCollab/acceptDecline.inc');
		}
		else {
			include('templates/completeCollab/uploadForm.inc');
		}
	}
	break;
}

include('templates/general/footer.inc');
?>
