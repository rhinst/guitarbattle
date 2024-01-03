<?php
	function display_board_index($sqlhost, $sqluser, $sqlpass, $sqldbname, $board_table) {
?>
           <table width="696" border="0" cellspacing="1" cellpadding="4">
            <tr><td class="mboard_title" width="496">Discussion:</td><td class="mboard_title" width="75">Posts:</td><td class="mboard_title" width="125">Latest Post:</td></tr>
            <tr><td class="mboard_heading" colspan="3">Message Board Index:</td></tr>
<?php
		$get_boards = mysql_query("select id, board_table, board_name, board_description from $board_table");
		while($board_info = mysql_fetch_row($get_boards)) {
			$board_id = $board_info[0];
			$board_table = $board_info[1];
			$board_name = $board_info[2];
			$board_description = $board_info[3];
			$mboard_posts = mysql_fetch_row(mysql_query("select count(id) from $board_table"));
			$board_post_total = $mboard_posts[0];
			if($board_post_total != 0) {
				$get_last_post = mysql_fetch_row(mysql_query("select user, unix_timestamp(timestamp) from $board_table order by unix_timestamp(timestamp) desc limit 1"));
				$last_post_user = $get_last_post[0];
				$last_post_timestamp = date("g:iA n/j/Y", $get_last_post[1]);
				$last_post_info = $last_post_timestamp . "<br>By: <a class=\"small\" href=\"" . $baseURL . "/viewProfile.php?username=" . $last_post_user . "\" onMouseOver=\"window.status='View Member Profile'; return true;\" onMouseOut=\"window.status=''; return true;\">" . $last_post_user . "</a>";
			}
			else {
				$last_post_info = "Never";
			}

			print("            <tr><td class=\"mboard_item\"><a class=\"small\" href=\"index.php?mode=display_board&board_id=$board_id\" onMouseOver=\"window.status='Enter This Message Board'; return true;\" onMouseOut=\"window.status=''; return true;\">$board_name</a><br>$board_description</td><td class=\"mboard_item\" align=\"center\">$board_post_total</td><td class=\"mboard_item\" align=\"center\">$last_post_info</td></tr>\n");
		}
?>
            <tr><td class="mboard_title" colspan="3">&nbsp;</td></tr>
           </table>
<?php
	}

	function display_board($sqlhost, $sqluser, $sqlpass, $sqldbname, $board_table, $board_id, $display_limit, $group_listed) {
		mysql_connect($sqlhost, $sqluser, $sqlpass);
		mysql_select_db($sqldbname);

		$board_info = mysql_fetch_row(mysql_query("select board_table, board_name from $board_table where id=$board_id"));
		$board_table = $board_info[0];
		$board_name = $board_info[1];

		$count_posts = mysql_fetch_row(mysql_query("select count(id) from $board_table where parent=0"));
		$total_posts = $count_posts[0];

		if(($total_posts - ($group_listed * $display_limit)) >= $display_limit) {
			$first_listed = (($group_listed * $display_limit) + 1);
			$results_listed = "$first_listed - $display_limit";
		}
		else if(($total_posts - ($group_listed * $display_limit)) == 1) {
			$results_listed = (($group_listed * $display_limit) + 1);
		}
		else if($total_posts == 0) {
			$results_listed = "0";
		}
		else {
			$first_listed = ($group_listed * $display_limit) + 1;
			$results_listed = "$first_listed - $total_posts";
		}

		if(($total_posts / $display_limit) <= 1) {
			$results_info = "<b class=\"item_small\">1</b>";
		}
		else {
			for($i = 0; ($total_posts - ($display_limit * $i) >= 0); $i++) {
				$link_text = ($i + 1);
				if($i == $group_listed) {
					$results_info = $results_info . " <b class=\"item_small\">$link_text</b>";
				}
				else {
				$results_info = $results_info . " <a class=\"small\" href=\"index.php?mode=display_board&board_id=$board_id&group_listed=$i\" onMouseOver=\"window.status='View Results Page $link_text'; return true;\" onMouseOut=\"window.status=''; return true;\">$link_text</a>";
				}
			}
		}
?>
           <table width="696" border="0" cellspacing="1" cellpadding="4">
            <tr><td class="mboard_title" colspan="3">Posts: <?php print("$results_listed of $total_posts"); ?> [Display <?php print("$display_limit"); ?> results per page]</td></tr>
            <tr><td class="mboard_title" width="346">Topic:</td><td class="mboard_title" width="175">Topic Info:</td><td class="mboard_title" width="175">Last Reply:</td></tr>
            <tr><td class="mboard_heading" colspan="3"><table border="0" width="100%" cellpadding="0" cellspacing="0"><tr><td class="mboard_heading"><a class="mboard_heading" href="index.php" onMouseOver="window.status='Back to Message Board Index'; return true;" onMouseOut="window.status=''; return true;">Message Board Index</a>::<?php print("$board_name"); ?></td><td class="mboard_heading" align="right"><a class="mboard_heading" href="index.php?mode=post_message&board_id=<?php print("$board_id"); ?>" onMouseOver="window.status='Post a Message'; return true;" onMouseOut="window.status=''; return true;">Post a Message</a></td></tr></table></td></tr>
<?php
		$group_listed = ($display_limit * $group_listed);
		$get_posts = mysql_query("select id, user, subject, unix_timestamp(timestamp), views from $board_table where parent=0 order by unix_timestamp(timestamp) desc limit $group_listed, $display_limit");
		while($post_info = mysql_fetch_row($get_posts)) {
			$post_id = $post_info[0];
			$post_user = $post_info[1];
			$post_subject_full = $post_info[2];
			$post_timestamp = date("g:iA n/j/Y", $post_info[3]);
			$post_views = $post_info[4];

			if(strlen($post_subject_full) > 40) {
				$post_subject = substr($post_subject_full, 0, 40) . "...";
				
			}
			else {
				$post_subject = $post_subject_full;
			}

			$get_replies = mysql_fetch_row(mysql_query("select count(id) from $board_table where parent=$post_id"));
			$total_replies = $get_replies[0];
			if($total_replies != 0) {
				$get_last_reply = mysql_fetch_row(mysql_query("select user, unix_timestamp(timestamp) from $board_table where parent=$post_id order by unix_timestamp(timestamp) desc limit 1"));
				$last_reply_user = $get_last_reply[0];
				$last_reply_timestamp = date("g:iA n/j/Y", $get_last_reply[1]);
				$last_reply_info = $last_reply_timestamp . "<br>By: <a class=\"small\" href=\"" . $baseURL . "/viewProfile.php?username=" . $last_reply_user . "'\" onMouseOver=\"window.status='View Member Profile'; return true;\" onMouseOut=\"window.status=''; return true;\">" . $last_reply_user . "</a>";
			}
			else {
				$last_reply_info = "Never";
			}

			print("            <tr><td class=\"mboard_item\"><table border=\"0\" cellpadding=\"0\" cellspacing=\"0\"><tr><td><img src=\"../images/message.gif\"></td><td>&nbsp;</td><td><a class=\"small\" href=\"index.php?mode=display_post&board_id=$board_id&post_id=$post_id\" onMouseOver=\"window.status='View This Post'; return true;\" onMouseOut=\"window.status=''; return true;\">$post_subject</a></td></tr></table></td><td class=\"mboard_item\" align=\"center\">Viewed $post_views times, $total_replies Replies<br> By: <a class=\"small\" href=\"" . $baseURL . "/viewProfile.php?username=" . $post_user . "\" onMouseOver=\"window.status='View Member Profile'; return true;\" onMouseOut=\"window.status=''; return true;\">$post_user</a><br>At: $post_timestamp</td><td class=\"mboard_item\" align=\"center\">$last_reply_info</td></tr>\n");
		}
?>
            <tr><td class="mboard_title" colspan="3">Results Page: <?php print("$results_info"); ?></td></tr>
           </table>
<?php
	}

	function display_post($sqlhost, $sqluser, $sqlpass, $sqldbname, $board_table, $board_id, $post_id, $display_limit, $group_listed) {
		mysql_connect($sqlhost, $sqluser, $sqlpass);
		mysql_select_db($sqldbname);

		$board_info = mysql_fetch_row(mysql_query("select board_table, board_name from $board_table where id=$board_id"));
		$board_table = $board_info[0];
		$board_name = $board_info[1];
		$post_info = mysql_fetch_row(mysql_query("select user, subject, body, unix_timestamp(timestamp), views from $board_table where id=$post_id"));
		$post_user = $post_info[0];
		$post_subject = $post_info[1];
		$post_body = nl2br(htmlspecialchars($post_info[2]));
		$post_timestamp = date("g:iA n/j/Y", $post_info[3]);
		$post_views = $post_info[4];
		$get_replies = mysql_fetch_row(mysql_query("select count(id) from $board_table where parent=$post_id"));
		$total_replies = $get_replies[0];

		if(($total_replies / $display_limit) <= 1) {
			$results_info = "<b class=\"item_small\">1</b>";
		}
		else {
			for($i = 0; ($total_replies - ($display_limit * $i) >= 0); $i++) {
				$link_text = ($i + 1);
				if($i == $group_listed) {
					$results_info = $results_info . " <b class=\"item_small\">$link_text</b>";
				}
				else {
				$results_info = $results_info . " <a class=\"small\" href=\"index.php?mode=display_post&board_id=$board_id&post_id=$post_id&group_listed=$i\" onMouseOver=\"window.status='Results Page $link_text'; return true;\" onMouseOut=\"window.status=''; return true;\">$link_text</a>";
				}
			}
		}
?>
           <table width="696" border="0" cellspacing="1" cellpadding="4">
            <tr><td class="mboard_title" width="200">Message Info:</td><td class="mboard_title" width="496">Message:</td></tr>
            <tr><td class="mboard_heading" colspan="2"><table border="0" width="100%" cellpadding="0" cellspacing="0"><tr><td class="mboard_heading"><a class="mboard_heading" href="index.php" onMouseOver="window.status='Back to Message Board Index'; return true;" onMouseOut="window.status=''; return true;">Message Board Index</a>::<a class="mboard_heading" href="index.php?mode=display_board&board_id=<?php print("$board_id"); ?>" onMouseOver="window.status='Back to Message Board Post List'; return true;" onMouseOut="window.status=''; return true;"><?php print("$board_name"); ?></a></td><td class="mboard_heading" align="right"><a class="mboard_heading" href="index.php?mode=post_message&board_id=<?php print("$board_id"); ?>&parent_post=<?php print("$post_id"); ?>" onMouseOver="window.status='Reply to this Message'; return true;" onMouseOut="window.status=''; return true;">Post a Reply</a></td></tr></table></td></tr>
            <tr><td class="mboard_item" valign="top">By: <a class="small" href="<? print $baseURL;?>/viewProfile.php?username=<?php print("$post_user"); ?>" onMouseOver="window.status='View Member Profile'; return true;" onMouseOut="window.status=''; return true;"><?php print("$post_user"); ?></a><br>At: <?php print("$post_timestamp"); ?></td><td class="mboard_item">Subject: <b class="item_small"><?php print("$post_subject"); ?></b><hr><b class="item_small"><?php print("$post_body"); ?></b></td></tr>
<?php
		$views_incremented = ($post_views + 1);
                mysql_query("update $board_table set views=$views_incremented where id=$post_id");
		if($total_replies > 0) {
			if(!isset($group_listed)) {
				$group_listed = 0;
			}

			if(($total_replies - ($group_listed * $display_limit)) >= $display_limit) {
				$first_listed = (($group_listed * $display_limit) + 1);
				$results_listed = "$first_listed - $display_limit";
			}
			else if($total_replies == 1) {
				$results_listed = "1";
			}
			else {
				$first_listed = ($group_listed * $display_limit) + 1;
				$results_listed = "$first_listed - $total_replies";
			}
?>
            <tr><td class="mboard_title" colspan="2">Replies: <?php print("$results_listed of $total_replies"); ?> [Display <?php print("$display_limit"); ?> results per page]</td></tr>
<?php
			$group_listed = ($display_limit * $group_listed);
			$get_replies = mysql_query("select id, user, subject, body, unix_timestamp(timestamp) from $board_table where parent=$post_id order by unix_timestamp(timestamp) asc limit $group_listed, $display_limit");
			while($reply_info = mysql_fetch_row($get_replies)) {
				$reply_id = $reply_info[0];
				$reply_user = $reply_info[1];
				$reply_subject = $reply_info[2];
				$reply_body = nl2br(htmlspecialchars($reply_info[3]));
				$reply_timestamp = date("g:iA n/j/Y", $reply_info[4]);
?>
            <tr><td class="mboard_item" valign="top">By: <a class="small" href="<? print $baseURL; ?>/viewProfile.php?username=<?php print("$reply_user"); ?>" onMouseOver="window.status='View Member Profile'; return true;" onMouseOut="window.status=''; return true;"><?php print("$reply_user"); ?></a><br>At: <?php print("$reply_timestamp"); ?></td><td class="mboard_item">Subject: <b class="item_small"><?php print("$reply_subject"); ?></b><hr><b class="item_small"><?php print("$reply_body"); ?></b></td></tr>
<?php
			}
		}
?>
            <tr><td class="mboard_title" colspan="2">Results Page: <?php print("$results_info"); ?></td></tr>
           </table>
<?php
	}

	function post_message($sqlhost, $sqluser, $sqlpass, $sqldbname, $board_table, $board_id, $parent_post) {
		global $REQUEST_URI;
		global $current_user;
		global $error;

		mysql_connect($sqlhost, $sqluser, $sqlpass);
		mysql_select_db($sqldbname);
		$board_info = mysql_fetch_row(mysql_query("select board_table from $board_table where id=$board_id"));
		$board_table = $board_info[0];

		if($parent_post != 0) {
			$parent_post_info = mysql_fetch_row(mysql_query("select subject from $board_table where id=$parent_post"));
			$post_subject = "Re:" . $parent_post_info[0];
		}
?>
           <table width="696" border="0" cellspacing="1" cellpadding="4">
            <form method="post" action="docs/action_handler.php?mode=post_message" name="post_form" onSubmit="return(check_form())">
            <tr><td class="mboard_title">Post a Message:</td></tr>
<?php
	if($error == "1"){
		print("            <tr><td class=\"mboard_title\"><b class=\"alarm\">You must enter text in both the subject and the body in order to post a message.</b></td></tr>\n");
	}
?>
            <tr><td class="mboard_title">Logged in as: <b class="item_small"><?php print $GLOBALS["authenticated_user"]; ?></b></td></tr>
            <tr><td class="mboard_title"><table border="0" cellpadding="0" cellspacing="0"><tr><td class="mboard_title">Subject:&nbsp;&nbsp;</td><td class="mboard_title"><input type="text" name="post_subject" value="<?php print("$post_subject"); ?>" size="50" maxlength="256"></td></tr></table></td></tr>
            <tr><td class="mboard_title"><table border="0" cellpadding="0" cellspacing="0"><tr><td class="mboard_title">Message:</td></tr><tr><td class="mboard_title">&nbsp;</td></tr><tr><td class="mboard_title"><textarea name="post_body" rows="6" cols="50"></textarea></td></tr></table></td></tr>
            <tr><td class="mboard_title"><input type="submit" class="button" value="Post Message"></td></tr>
            <input type="hidden" name="board_id" value="<?php print("$board_id"); ?>">
            <input type="hidden" name="parent_post" value="<?php print("$parent_post"); ?>">
            </form>
           </table>
<?php
	}
?>
