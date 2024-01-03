<?php
	include('mboard.config');
	include('mboard_functions.inc');

	if(!isset($mode)) {
		$mode = 'DEFAULT';
	}

	if($mode == 'post_message') {
		require_login();
	}
	include('header.inc');
	switch($mode) {
		case('DEFAULT'): {
			include('header_title.inc');
			display_board_index($sqlhost, $sqluser, $sqlpass, $sqldbname, $board_table);
			include('footer_addition.inc');
			break;
		}
		case('display_board'): {
			include('header_title.inc');
			$display_limit = 20;
			display_board($sqlhost, $sqluser, $sqlpass, $sqldbname, $board_table, $board_id, $display_limit, $group_listed);
			include('footer_addition.inc');
			break;
		}
		case('display_post'): {
			include('header_title.inc');
			$display_limit = 10;
			display_post($sqlhost, $sqluser, $sqlpass, $sqldbname, $board_table, $board_id, $post_id, $display_limit, $group_listed);
			include('footer_addition.inc');
			break;
		}
		case('post_message'): {
			if(!isset($parent_post)) {
				$parent_post = 0;
			}
			include('header_title.inc');
			include('check_entries.inc');
			post_message($sqlhost, $sqluser, $sqlpass, $sqldbname, $board_table, $board_id, $parent_post);
			include('footer_addition.inc');
			break;
		}
	}
	include('footer.inc');
?>
