<?php
	require_login();

	if(!isset($mode)) {
		header("Location: ../index.php");
	}
	switch($mode) {
		case('post_message'): {
			if((strlen($post_subject) < 1) || (strlen($post_body) < 1)) {
				header("Location: ../index.php?mode=post_message&error=1");
			}
			else {
				$post_subject_fix = addslashes(strip_tags($post_subject));
				$post_body_fix = addslashes(strip_tags($post_body));
				$board_info = mysql_fetch_row(mysql_query("select board_table from boards where id=$board_id"));
				$board_table = $board_info[0];
				$timestamp = date("Y-m-d H:i:s");
				mysql_query("insert into $board_table (user, subject, body, timestamp, parent) values('$authenticated_user', '$post_subject_fix', '$post_body_fix', '$timestamp', $parent_post)");
				if($parent_post == 0) {
					$inserted_post_info = mysql_fetch_row(mysql_query("select LAST_INSERT_ID() from $board_table"));
					$link_id = $inserted_post_info[0];
				}
				else {
					$link_id = $parent_post;
				}
				header("Location: ../index.php?mode=display_post&board_id=$board_id&post_id=$link_id");
			}
			break;
		}
	}
?>
