<?php
	include('gb.lib');

	if($location) {
		$location = urlencode($location);
	}
	if(!isset($action)) {
		header("Location: ../index.php");
	}
	switch($action) {
		case('login'): {

			if(($username != "Rob L") && ($username != "Rob H")) {
				$username = strtolower($username);
			}

			$login_result = 0;
			$get_user_info = mysql_fetch_row(mysql_query("select id from users where username='$username' and password='" . base64_encode($password) . "'"));
			$user_id = $get_user_info[0];
			if(!isset($user_id)) {
				$login_result = 0;
			}
			else {
				$login_result = 1;
			}
			
			if($login_result == 1) {
				vilw_query("insert into logins (username, ip_addr) values ('" . $username . "','" . $REMOTE_ADDR . "')");

				$current_time = date("Y-m-d H:i:s");
				mysql_query("update users set last_login='$current_time' where id=$user_id");
				session_start();
				session_register('guitar_battle_login');
				session_register('current_user');
				session_register('current_password');
				$guitar_battle_login = $user_id;
				$current_user = $username;
				$current_password = $password;
				header("Location: .." . $goto);
			}
			else if($login_result == 0) {
				header("Location: ../index.php?action=login&error=1");
			}
			break;
		}
		case('logout'): {
			session_start();
			session_destroy();
			header("Location: ../index.php");
			break;
		}
		case('submit_link'): {
			if(!isset($current_user)) {
				$user_sub = "NOT LOGGED IN";
			}
			else {
				$user_sub = $current_user;
			}

			if($link_url == "") {
				header("Location: ../index.php?location=submit_link&error=1");
			}
			else {
				$current_time = date("Y-m-d H:i:s");
				$mail_result = gb_mail($webmaster_address, "GuitarBattle.com Link Submission", "From User: $user_sub\nAt: $current_time\nLink URL: $link_url", "LinkSubmission@GuitarBattle.com");
				if(!$mail_result) {
					header("Location: ../index.php?action=error");
				}
				else {
					header("Location: ../index.php?action=contact_us_sent");
				}
			}
			break;
		}
		case('contact'): {
			if($email_address == "") {
				header("Location: ../index.php?location=contact&error=1&message_body=$message_body");
			}
			else if((strlen($email_address) < 6) || (!ereg('^((([0-9]|[a-z])+\.?([0-9]|[a-z])+))+\@{1}(([0-9]|[a-z])+\.?([0-9]|[a-z])+)+\.[a-z]{2,4}$', $email_address))) {
				header("Location: ../index.php?location=contact&error=1&message_body=$message_body");
			}
			else if($message_body == "") {
				header("Location: ../index.php?location=contact&error=2&email_address=$email_address");
			}
			else {
				$current_time = date("Y-m-d H:i:s");
				$mail_result = gb_mail($info_address, "GuitarBattle.com Question/Suggestion", "From: $email_address\nAt: $current_time\nMessage:\n$message_body", "$email_address", "(GuitarBattle.com)");
				if(!$mail_result) {
					header("Location: ../index.php?action=error");
				}
				else {
					header("Location: ../index.php?action=contact_us_sent");
				}
			}
			break;
		}
		case('forgotinfo'): {
			$user_info = mysql_fetch_row(mysql_query("select id, username, password from users where email_address='$email_address'"));
			$user_id = $user_info[0];
			$username = $user_info[1];
			$password = base64_decode($user_info[2]);
			if(!isset($user_id)) {
				header("Location: ../index.php?location=forgotinfo&error=1");
			}
			else {
				gb_mail("$email_address", "Your GuitarBattle.com Account Information:", "Your GuitarBattle.com Account information:\n\nE-mail address: $email_address\nUsername: $username\nPassword: $password\n\nPlease note that you may login to http://www.guitarbattle.com and reset your password if you wish.\n\nPlease contact webmaster@guitarbattle.com for more information, do not reply to this message.\n\n-GuitarBattle.com", "autoresponse@guitarbattle.com");
				header("Location: ../index.php?location=passwd_reset&origin=2");
			}
			break;
		}
		case('changepasswd'): {
			if(!$login) {
				header("Location: index.php");
			}
			else {
				if(($password == $password_verify) && ((strlen($password)) > 3) && (ereg('^([0-9]|[a-z])+$', $password))) {
					$result = mysql_query("update users set password='" . base64_encode($password) . "' where id=$guitar_battle_login");
					if($result) {
						header("Location: ../index.php?location=passwd_reset");
					}
					else {
						header("Location: ../index.php?action=changepasswd&error=1");
					}
				}
				else{
					header("Location: ../index.php?action=changepasswd&error=1");
				}
			}
			break;
		}
		case('register'): {
			//Check Entries:
			$entries_pass = 0;
			if(!isset($privacy)) {
				$privacy = 1;
			}
			else if($privacy == "on") {
				$privacy = 0;
			}
			if(!isset($accept_terms)) {
				$accept_terms = 0;
			}
			else if($accept_terms == "on") {
				$accept_terms = 1;
			}

			if((strlen($firstname) < 3) || (strlen($lastname) < 3)) {
				header("Location: ../index.php?action=join&error=1&firstname=$firstname&lastname=$lastname&email_address=$email_address&username=$username&password=$password&password_verify=$password_verify");
			}
			else if((strlen($email_address) < 6) || (!ereg('^((([0-9]|[a-z])+\.?([0-9]|[a-z])+))+\@{1}(([0-9]|[a-z])+\.?([0-9]|[a-z])+)+\.[a-z]{2,4}$', $email_address))) {
				header("Location: ../index.php?action=join&error=2&firstname=$firstname&lastname=$lastname&username=$username&password=$password&password_verify=$password_verify");
			}
			else if((strlen($username) < 4) || (!ereg('^([0-9]|[a-z])+$', $username))) {
				header("Location: ../index.php?action=join&error=3&firstname=$firstname&lastname=$lastname&email_address=$email_address&password=$password&password_verify=$password_verify");
			}
			else if((strlen($password) < 4) || ($password_verify != $password) || ((!ereg('^([0-9]|[a-z])+$', $password)))) {
				header("Location: ../index.php?action=join&error=4&firstname=$firstname&lastname=$lastname&username=$username&email_address=$email_address");
			}
			else if($accept_terms == 0) {
				header("Location: ../index.php?action=join&error=7&firstname=$firstname&lastname=$lastname&username=$username&email_address=$email_address");
			}
			else {
				$entries_pass = 1;
			}

			//Check db for existing user:
			$user_info = mysql_fetch_row(mysql_query("select id from users where username='$username'"));
			$user_check1 = $user_info[0];
			if(isset($user_check1)) {
				header("Location: ../index.php?action=join&error=5&firstname=$firstname&lastname=$lastname&email_address=$email_address&password=$password&password_verify=$password_verify");
			}
			else if(!isset($user_check1)) {
				$user_info = mysql_fetch_row(mysql_query("select id from users_temp where username='$username'"));
				$user_check1b = $user_info[0];
				if(isset($user_check1b)) {
					header("Location: ../index.php?action=join&error=5&firstname=$firstname&lastname=$lastname&email_address=$email_address&password=$password&password_verify=$password_verify");
				}
			}
			$user_info = mysql_fetch_row(mysql_query("select id from users where email_address='$email_address'"));
			$user_check2 = $user_info[0];
			if(isset($user_check2)) {
				header("Location: ../index.php?action=join&error=6&firstname=$firstname&lastname=$lastname&username=$username&password=$password&password_verify=$password_verify");
			}
			if(!isset($user_check1) && (!isset($user_check1b)) && !isset($user_check2) && $entries_pass == 1) {
				$join_date = date("Y-m-d H:i:s");
				$firstname_fix = addslashes($firstname);
				$lastname_fix = addslashes($lastname);
				mysql_query("insert into users_temp (username, password, firstname, lastname, email_address, privacy, join_date, confirm_id) values ('$username','" .  base64_encode($password) . "', '$firstname_fix', '$lastname_fix', '$email_address', $privacy, '$join_date', encrypt('$username'))");

				$temp_user_info = mysql_fetch_row(mysql_query("select id, confirm_id from users_temp where username='$username'"));
				$temp_user_id = $temp_user_info[0];
				$temp_user_confirm_id = $temp_user_info[1];
				$mail_result = gb_mail("$email_address", "Your GuitarBattle.com Account Confirmation:", "This is an automatically generated response. Please do not reply to this e-mail.  Please contact webmaster@guitarbattle.com for further assistance or information.\n\nHere is your account confirmation link:\n\nhttp://www.guitarbattle.com/account_confirmation.php?id=$temp_user_id&confirm_id=$temp_user_confirm_id\n\n-----\nAfter clicking on the confirmation link above, your account will be activated.\n\n-GuitarBattle.com", "autoresponse@guitarbattle.com");
				if($mail_result) {
					header("Location: ../index.php?location=register_success");
				}
				else if(!$mail_result) {
					header("Location: ../index.php?location=register_fail");
					mysql_query("delete from users_temp where username='$username'");
				}
			}
			break;
		}
		case('post_message'): {
			//Check if user is logged in.
			if(!$login) {
				header("Location: ../index.php?login_error=1&location=$location");
			}
			else {
				$message_strip = strip_tags($message);
				$message_fix = addslashes($message_strip);
				mysql_query("insert into battle_messages (battle_id, post_user, message) values($battle_id, '$post_user', '$message_fix')");
				header("Location: ../battles.php?mode=view_battle&battle_id=$battle_id");
			}
			break;
		}
		case('start_battle'): {
			//Check if user is logged in.
			if(!$login) {
				header("Location: ../index.php?login_error=1&location=$location");
			}
			else {
				switch($step) {
					case(1): {
						if(!isset($title_battle)) {
							$title_battle = 0;
						}
						if((!ereg('^.+\.mp3$', $file_name)) && ($file_type != 'audio/mpeg') && ($file_type != 'audio/mp3') || ($file_size > 665600)) {
							header("Location: ../battles.php?mode=error");
						}
						else {
							$timestamp = date("Y-m-d H:i:s");
							$file_contents = addslashes(fread(fopen($file, "r"), filesize($file)));
							$result = mysql_query("insert into battle_mp3s (file_name, file_type, file_contents, file_tab, view_count) values ('$file_name', '$file_type', '$file_contents', '0', 0)");
							$mp3_id = mysql_insert_id();
							$mp3_info = mysql_fetch_row(mysql_query("select length(file_contents) from battle_mp3s where id=" . $mp3_id));
							$mp3_filesize = $mp3_info[0];
							if($result && ($mp3_filesize > 0)) {
								mysql_query("insert into battles (timestamp, parent_category, title_battle, user1, user2, file1, votes1, votes2, winner) values ('$timestamp', $parent_category, $title_battle, $guitar_battle_login, 0, $mp3_id, 0, 0, 0)");
								$battle_info = mysql_fetch_row(mysql_query("select LAST_INSERT_ID()"));
								$battle_id = $battle_info[0];
								header("Location: ../battles.php?mode=start_battle&step=2&battle_id=$battle_id");
							}
							else if($mp3_filesize <= 0) {
								mysql_query("delete from battle_mp3s where id=" . $mp3_id);
								header("Location: ../battles.php?mode=error");
							}
							else {
								header("Location: ../battles.php?mode=error");
							}
						}
						break;
					}
					case(2): {
						//Get MP3 ID:
						$file_info = mysql_fetch_row(mysql_query("select file1 from battles where id=$battle_id"));
						$file_id = $file_info[0];
						if($tablature == 0) {
							$file_tab_fix = 0;
						}
						else {
							$file_tab_strip = strip_tags($file_tab);
							$file_tab_fix = addslashes($file_tab_strip);
						}
						$result = mysql_query("update battle_mp3s set file_tab='$file_tab_fix' where id=$file_id");
						if($result) {
							mysql_query("update battles set hide=0 where id=$battle_id");
							header("Location: ../battles.php?mode=start_battle&step=finish&battle_id=$battle_id");
						}
						else {
							header("Location: ../battles.php?mode=error");
						}
						break;
					}
				}
			}
			break;
		}
		case('join_battle'): {
			//Check if user is logged in.
			if(!$login) {
				header("Location: ../index.php?login_error=1&location=$location");
			}
			else {
				switch($step) {
					case(1): {
						$battle_info = mysql_fetch_row(mysql_query("select user1, user2 from battles where id=$battle_id"));
						$battle_user1 = $battle_info[0];
						$battle_user2 = $battle_info[1];
						if($battle_user2 == 0) {
							if ($file == 'none') {
                                                	        header("Location: ../battles.php?mode=error");
							}
							else if((!ereg('^.+\.mp3$', $file_name)) && ($file_type != 'audio/mpeg') && ($file_type != 'audio/mp3') && (filesize($file) > 665600)) {
                                                	        header("Location: ../battles.php?mode=error");
                                                	}
							else if($guitar_battle_login == $battle_user1) {
								header("Location: ../battles.php?mode=battle_self_error");
							}
                                                	else {
								//Close battle before uploading file.
								$file_name_fix = addslashes($file_name);
								$file_type_fix = addslashes($file_type);
								mysql_query("update battles set user2=$guitar_battle_login where id=$battle_id");
								$timestamp = date("Y-m-d H:i:s");
                                                	        $file_contents = addslashes(fread(fopen($file, "r"), filesize($file)));
                                                	        $result = mysql_query("insert into battle_mp3s (file_name, file_type, file_contents, file_tab, view_count) values ('$file_name_fix', '$file_type_fix', '$file_contents', '0', 0)");
								$file_id = mysql_insert_id();
								$mp3_info = mysql_fetch_row(mysql_query("select length(file_contents) from battle_mp3s where id=" . $file_id));
								$mp3_filesize = $mp3_info[0];

                                                	        if($result && ($mp3_filesize > 0) && ($file_id > 0)) {
                                                	                mysql_query("update battles set timestamp='$timestamp', user2=$guitar_battle_login, file2=$file_id, active=1 where id=$battle_id");
                                                	                header("Location: ../battles.php?mode=join_battle&step=2&battle_id=$battle_id");
                                                	        }
                                                	        else {
									mysql_query("update battles set user2=0 where id=$battle_id");
                                                	                header("Location: ../battles.php?mode=error");
                                                	        }
							}
                                                }
						else {
							header("Location: ../battles.php?mode=error");
						}
						break;
					}
					case(2): {
						//Get MP3 ID:
                                                $file_info = mysql_fetch_row(mysql_query("select file2 from battles where id=$battle_id"));
                                                $file_id = $file_info[0];
                                                if($tablature == 0) {
                                                        $file_tab_fix = 0;
                                                }
                                                else {
                                                        $file_tab_strip = strip_tags($file_tab);
                                                        $file_tab_fix = addslashes($file_tab_strip);
                                                }
                                                $result = mysql_query("update battle_mp3s set file_tab='$file_tab_fix' where id=$file_id");
                                                if($result) {
                                                        header("Location: ../battles.php?mode=join_battle&step=finish&battle_id=$battle_id");
                                                }
                                                else {
							mysql_query("delete from battle_mp3s where id=$file_id");
							mysql_query("update battles set user2=0, file2=0, where id=$battle_id");
                                                        header("Location: ../battles.php?mode=error");
                                                }
						break;
					}
				}
			}
			break;
		}
		case('submit_vote'): {
			//Check if user is logged in.
                        if(!$login) {
				header("Location: ../index.php?login_error=1&location=$location");
                        }
                        else {
                                //Check if user already voted.
                                $voter_check = mysql_fetch_row(mysql_query("select count(voter_id) from battle_votes where battle_id=$battle_id and voter_id=$guitar_battle_login"));
                                if($voter_check[0] == 0) {
					//Check if vote is valid.
					$vote_check = mysql_fetch_row(mysql_query("select count(id) from battles where id=$battle_id and (user1=$competitor_id or user2=$competitor_id)"));
					if($vote_check[0] == 1) {
                                        	$result = mysql_query("insert into battle_votes (battle_id, voter_id, competitor_id) values ($battle_id, $guitar_battle_login, $competitor_id)");
                                        	if($result) {
                                        	        $vote_success = 1;
                                        	        header("Location: ../battles.php?mode=view_battle&battle_id=$battle_id&vote_success=1");
                                        	}
						else {
							header("Location: ../battles.php?mode=submit_vote&error=1");
                                        	}
					}
					else {
						header("Location: ../battles.php?mode=submit_vote&error=1");
					}
                                }
                                else {
					header("Location: ../battles.php?mode=submit_vote&error=2");
                                }
                        }
			break;
		}
		case('edit_profile'): {
			if(!$login) {
				header("Location: ../index.php?login_error=1&location=$location");
			}
			else {

				include('imgconvert.lib');

				if(($icon_file == "none") && ($profile_user_icon == "UPLOAD")) {
					header("Location: ../members.php?mode=edit_profile&error=1NOFILE");
				}
				else if(($icon_file_type != 'image/gif') && ($icon_file_type != 'image/pjpeg') && ($icon_file_type != 'image/jpeg') && ($profile_user_icon == "UPLOAD")) {
					header("Location: ../members.php?mode=edit_profile&error=1&TYPEERROR");
				}
				else {

					if($profile_user_icon == "UPLOAD") {
						//$image_size = getimagesize($icon_file);
						//$image_width = $image_size[0];
						//$image_height = $image_size[1];
						//if(($image_width != 300) || ($image_height != 150)) {
							//header("Location: ../members.php?mode=edit_profile&error=1&SIZEERROR");
						//}
						//else {
							//Find existing icon:
							$icon_exists = mysql_fetch_row(mysql_query("select count(user_id) from user_icons where user_id=$guitar_battle_login"));
							$icon_file_contents = fread(fopen($icon_file, "r"), filesize($icon_file));

							$icon_file_contents = addslashes(getResizedContents($icon_file_contents, 300, 150, true));
							if($icon_exists[0] == 0) {
								mysql_query("insert into user_icons (user_id, file_name, file_type, file_contents) values ($guitar_battle_login, '$icon_file_name', '$icon_file_type', '$icon_file_contents')");
							}
							else if($icon_exists[0] == 1) {
								mysql_query("update user_icons set file_name='$icon_file_name', file_type='$icon_file_type', file_contents='$icon_file_contents' where user_id=$guitar_battle_login");
							}
							$profile_user_icon = $guitar_battle_login;
						//}
					}
					$row = mysql_fetch_row(mysql_query("select count(user_id) from user_profiles where user_id=$guitar_battle_login"));
					$profile_name_fix = addslashes(strip_tags($profile_name));
					$profile_nickname_fix = addslashes(strip_tags($profile_nickname));
					$profile_location_fix = addslashes(strip_tags($profile_location));
					$profile_influences_fix = addslashes(strip_tags($profile_influences));
					$profile_occupation_fix = addslashes(strip_tags($profile_occupation));
					if($row[0] == 1) {
						mysql_query("update user_profiles set image_id=$profile_user_icon, name='$profile_name_fix', nickname='$profile_nickname_fix', location='$profile_location_fix', influences='$profile_influences_fix', occupation='$profile_occupation_fix' where user_id=$guitar_battle_login");
						header("Location: ../members.php?mode=edit_profile");
					}
					else if($row[0] == 0){
						mysql_query("insert into user_profiles (user_id, image_id, name, nickname, location, influences, occupation) values ($guitar_battle_login, $profile_user_icon, '$profile_name_fix', '$profile_nickname_fix', '$profile_location_fix', '$profile_influences_fix', '$profile_occupation_fix')");
						header("Location: ../members.php?mode=edit_profile");
					}
				}	
			}	
			break;
		}
	}
?>
