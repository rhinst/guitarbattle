<?php
	//Under Construction Page:
	//include('construction_redirect.php');

	include('gb.lib');
	include('header.inc');
	if(!isset($mode)) {
		$mode = 'home';
	}
	switch($mode) {
		case('home'): {
			include('members_home.inc');
			break;
		}
		case('display_profile'): {
			if((!isset($finished_group_listed)) || (!is_numeric($finished_group_listed))) {
                                $finished_group_listed = 0;
                        }
			else {
				$finished_group_listed = ($finished_group_listed * 10);
			}
			if((!isset($active_group_listed)) || (!is_numeric($active_group_listed))) {
                                $active_group_listed = 0;
                        }
			else {
				$active_group_listed = ($active_group_listed * 10);
			}

			$user_info = mysql_fetch_row(mysql_query("select username, win_percent, points from users where id=$id"));
			$username = $user_info[0];
			$user_win_percent = $user_info[1];
			$user_points = $user_info[2];

			if(!isset($username)) {
				include('profile_error.inc');
			}
			else {
				$battle_info_1 = mysql_fetch_row(mysql_query("select count(id) from battles where user1=$id or user2=$id"));
				$battles_entered = $battle_info_1[0];
				$battle_info_2 = mysql_fetch_row(mysql_query("select count(id) from battles where winner=$id"));
				$battles_won = $battle_info_2[0];
				$battle_info_3 = mysql_fetch_row(mysql_query("select count(id) from battles where winner=0 and (user1=$id or user2=$id)"));
				$battles_active = $battle_info_3[0];
				$profile_info = mysql_fetch_row(mysql_query("select image_id, name, nickname, location, influences, occupation from user_profiles where user_id=$id"));
				$profile_image_id = $profile_info[0];
				$profile_name = $profile_info[1];
				$profile_nickname = $profile_info[2];
				$profile_location = $profile_info[3];
				$profile_influences = $profile_info[4];
				$profile_occupation = $profile_info[5];
				$user_icon = "/docs/display_image.php?id=$profile_image_id";

				if($user_win_percent == -1) {
					$win_percentage = "N/A";
				}
				else {
					$win_percentage = $user_win_percent . "%";
				}
				include('display_member_profile.inc');
			}
			break;
		}
		case('my_gb'): {
			if($error) {
				include('error.inc');
			}
			else {
				if($login) {
					include('my_gb.inc');
				}
				else {
					include('not_logged_in.inc');
				}
			}
			break;
		}
		case('edit_profile'): {
			if($error) {
				include('error.inc');
			}
			else {
				//Check if user is logged in:
				if($login) {
					$profile_info = mysql_fetch_row(mysql_query("select image_id, name, nickname, location, influences, occupation from user_profiles where user_id=$guitar_battle_login"));
					$profile_image_id = $profile_info[0];
					$profile_name = $profile_info[1];
					$profile_nickname = $profile_info[2];
					$profile_location = $profile_info[3];
					$profile_influences = $profile_info[4];
					$profile_occupation = $profile_info[5];
					$user_icon = "/docs/display_image.php?id=$profile_image_id";
					include('edit_profile.inc');
				}
				else {
					include('not_logged_in.inc');
				}
			}
			break;
		}
	}
	include('footer.inc');
?>
