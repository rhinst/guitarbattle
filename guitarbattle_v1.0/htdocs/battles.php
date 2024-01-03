<?php
	include('gb.lib');
	include('header.inc');
	switch($mode) {
		case('view_battle'): {
			if(!isset($battle_id)) {
				include('error.inc');
			}
			else {
			$row = mysql_fetch_row(mysql_query("select count(id) from battles where id=$battle_id"));
			if($row[0] == 0) {
				include('error.inc');
			}
			else {
			$battle_info = mysql_fetch_row(mysql_query("select unix_timestamp(timestamp), parent_category, title_battle, user1, user2, file1, file2, votes1, votes2, winner, hide from battles where id=$battle_id"));
			$user1_info = mysql_fetch_row(mysql_query("select username from users where id=$battle_info[3]"));
			$user2_info = mysql_fetch_row(mysql_query("select username from users where id=$battle_info[4]"));
			$battle_category_info = mysql_fetch_row(mysql_query("select name from battle_categories where id=$battle_info[1]"));
			$battle_timestamp = $battle_info[0];
			$battle_parent_category = $battle_category_info[0];
			$battle_title = $battle_info[2];
			$battle_user1_id = $battle_info[3];
			$battle_user2_id = $battle_info[4];
			$battle_user1 = $user1_info[0];
			$battle_user2 = $user2_info[0];
			$battle_file1 = $battle_info[5];
			$battle_file2 = $battle_info[6];
			$battle_winner = $battle_info[9];
			$battle_hide = $battle_info[10];
			if($battle_hide == 1) {
				include('error.inc');
			}
			else if(($battle_info[4] != 0) && ($battle_winner == 0)) {
				$battle_end_date_unformatted = strtotime("+7 days", $battle_timestamp);
				$battle_end_date = date("n/j/Y", $battle_end_date_unformatted);
				$file1_info = mysql_fetch_row(mysql_query("select view_count, file_tab, file_name from battle_mp3s where id=$battle_info[5]"));
				$file2_info = mysql_fetch_row(mysql_query("select view_count, file_tab, file_name from battle_mp3s where id=$battle_info[6]"));
				$votes1_info = mysql_fetch_row(mysql_query("select count(voter_id) from battle_votes where battle_id=$battle_id and competitor_id=$battle_info[3]"));
				$votes2_info = mysql_fetch_row(mysql_query("select count(voter_id) from battle_votes where battle_id=$battle_id and competitor_id=$battle_info[4]"));
				$battle_file1_views = $file1_info[0];
				$battle_file2_views = $file2_info[0];
				$battle_tab1 = $file1_info[1];
				$battle_tab2 = $file2_info[1];
				$battle_file1_name = $file1_info[2];
				$battle_file2_name = $file2_info[2];
				$battle_votes1 = $votes1_info[0];
				$battle_votes2 = $votes2_info[0];
				$battle_total_votes = ($battle_votes1 + $battle_votes2);
				if($battle_total_votes > 0) {
					$user1_votes_bar_height = (round(($battle_votes1 / $battle_total_votes), 2) * 100);
					$user2_votes_bar_height = (round(($battle_votes2 / $battle_total_votes), 2) * 100);
				}

				$profile1_info = mysql_fetch_row(mysql_query("select image_id from user_profiles where user_id=$battle_user1_id"));
				$profile2_info = mysql_fetch_row(mysql_query("select image_id from user_profiles where user_id=$battle_user2_id"));
				$user1_image_id = $profile1_info[0];
				$user2_image_id = $profile2_info[0];
				if(!isset($user1_image_id)) {
					$user1_image_id = -1;
				}
				if(!isset($user2_image_id)) {
					$user2_image_id = -1;
				}
				$user1_icon = "/docs/display_image.php?id=$user1_image_id";
				$user2_icon = "/docs/display_image.php?id=$user2_image_id";
				include('display_battle.inc');
			}
			else if($battle_info[4] == 0) {
				//Battle does not yet have a challenger.
				$file1_info = mysql_fetch_row(mysql_query("select view_count, file_tab, file_name from battle_mp3s where id=$battle_info[5]"));
				$battle_file1_views = $file1_info[0];
				$battle_tab1 = $file1_info[1];
				$battle_file1_name = $file1_info[2];
				$profile1_info = mysql_fetch_row(mysql_query("select image_id from user_profiles where user_id=$battle_user1_id"));
				$user1_image_id = $profile1_info[0];
				if(!isset($user1_image_id)) {
					$user1_image_id = -1;
				}
				$user1_icon = "/docs/display_image.php?id=$user1_image_id";
				include('display_unchallenged_battle.inc');
			}
			else if($battle_winner != 0) {
				//Finished battle.
				$battle_ended_date = date("g:iA n/j/Y", $battle_timestamp);
				$battle_outcome_user1 = $battle_outcome_user2 = "&nbsp;";
				$battle_user1_title = $battle_user1;
				$battle_user2_title = $battle_user2;
				if($battle_winner == $battle_user1_id) {
					$battle_outcome_user1 = "The Winner";
					$battle_user1_title = "<b class=\"alarm\">$battle_user1 (The Winner)</b>";
				}
				else if($battle_winner == $battle_user2_id) {
					$battle_outcome_user2 = "The Winner";
					$battle_user2_title = "<b class=\"alarm\">$battle_user2 (The Winner)</b>";
				}
				$file1_info = mysql_fetch_row(mysql_query("select view_count, file_tab, file_name from battle_mp3s where id=$battle_info[5]"));
				$file2_info = mysql_fetch_row(mysql_query("select view_count, file_tab, file_name from battle_mp3s where id=$battle_info[6]"));
				$battle_file1_views = $file1_info[0];
				$battle_file2_views = $file2_info[0];
				$battle_tab1 = $file1_info[1];
				$battle_tab2 = $file2_info[1];
				$battle_file1_name = $file1_info[2];
				$battle_file2_name = $file2_info[2];
				$battle_votes1 = $battle_info[7];
				$battle_votes2 = $battle_info[8];
				$profile1_info = mysql_fetch_row(mysql_query("select image_id from user_profiles where user_id=$battle_user1_id"));
				$profile2_info = mysql_fetch_row(mysql_query("select image_id from user_profiles where user_id=$battle_user2_id"));
				$user1_image_id = $profile1_info[0];
				$user2_image_id = $profile2_info[0];
				if(!isset($user1_image_id)) {
					$user1_image_id = -1;
				}
				if(!isset($user2_image_id)) {
					$user2_image_id = -1;
				}
				$user1_icon = "/docs/display_image.php?id=$user1_image_id";
				$user2_icon = "/docs/display_image.php?id=$user2_image_id";
				include('display_battle_finished.inc');
			}
			}
			}
			break;
		}
		case('start_battle'): {
			if(!isset($step)) {
				$step = 1;
			}
			switch($step) {
				case(1): {
					if(!$login) {
						include('not_logged_in.inc');
					}
					else {
						include('start_battle_step_1.inc');
					}
					break;
				}
				case(2): {
					if(!$login) {
						include('not_logged_in.inc');
					}
					else {
						include('start_battle_step_2.inc');
					}
					break;
				}
				case('finish'): {
					include('start_battle_step_finish.inc');
					break;
				}
			}
			break;
		}
		case('join_battle'): {
			if(!isset($step)) {
                                $step = 1;
                        }
                        switch($step) {
                                case(1): {
					$battle_info = mysql_fetch_row(mysql_query("select user1 from battles where id=$battle_id"));
					$battle_user1 = $battle_info[0];
                                        if(!$login) {
                                                include('not_logged_in.inc');
                                        }
                                        else if(($login) && ($guitar_battle_login != $battle_user1)) {
                                                include('join_battle_step_1.inc');
                                        }
					else {
						include('battle_self_error.inc');
					}
                                        break;
                                }
                                case(2): {
                                        if(!$login) {
                                                include('not_logged_in.inc');
                                        }
                                        else {
                                                include('join_battle_step_2.inc');
                                        }
                                        break;
                                }
                                case('finish'): {
                                        include('join_battle_step_finish.inc');
                                        break;
                                }
			}
			break;
		}
		case('finished_battles'): {
			if((!isset($group_listed)) || (!is_numeric($group_listed))) {
				$group_listed = 0;
			}
			if(!isset($category_id) || !is_numeric($category_id)) {
				include('error.inc');
			}
			else {
				$category_info = mysql_fetch_row(mysql_query("select name from battle_categories where id=$category_id"));
				$category_name = $category_info[0];
				if(isset($category_name)) {
					$group_listed = ($group_listed * 20);
					include('list_finished_battles.inc');
				}
				else {
					include('error.inc');
				}
			}
			break;
		}
		case('active_battles'): {
			if((!isset($group_listed)) || (!is_numeric($group_listed))) {
				$group_listed = 0;
			}
			if(!isset($category_id) || !is_numeric($category_id)) {
				include('error.inc');
			}
			else {
				$category_info = mysql_fetch_row(mysql_query("select name from battle_categories where id=$category_id"));
				$category_name = $category_info[0];
				if(isset($category_name)) {
					$group_listed = ($group_listed * 20);
					include('list_active_battles.inc');
				}
				else {
					include('error.inc');
				}
			}
			break;
		}
		case('post_message'): {
			//Check if user is logged in.
			if(!$login) {
				include('not_logged_in.inc');
			}
			else {
				include('post_message.inc');
			}
			break;
		}
		case('submit_vote'): {
			if($error == 1) {
				include('vote_result.inc');
			}
			else if($error == 2) {
				include('vote_result.inc');
			}
			break;
		}
		case('error'): {
			include('error.inc');
			break;
		}
		case('battle_self_error'): {
			include('battle_self_error.inc');
			break;
		}
	}
	include('footer.inc');
?>
