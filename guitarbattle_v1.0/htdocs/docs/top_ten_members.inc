<?php
	$res = mysql_query("select count(*) from users where win_percent!=-1 and points!=0");

	$check = mysql_fetch_row($res);
	if($check[0] == 0) {
		print("         <tr><td class=\"item\" colspan=\"4\">&nbsp;</td></tr>\n");
		print("         <tr><td class=\"large\" colspan=\"4\">Top 10 Members:</td></tr>\n");
		print("         <tr><td class=\"item\" colspan=\"4\">N/A</td></tr>\n");
	}
	else if($check[0] > 0){

		$res = mysql_query("select id, username, win_percent, points from users where points>0 order by points desc limit 10");
		print("         <tr><td class=\"item\" colspan=\"4\">&nbsp;</td></tr>\n");
		print("         <tr><td class=\"large\" colspan=\"4\">Top 10 Members:</td></tr>\n");
		print("         <tr><td class=\"item_dark\" width=\"200\">Member:</td><td class=\"item_dark\" width=\"50\">Points:</td><td class=\"item_dark\" width=\"150\">Win Percent:</td><td class=\"item\" width=\"300\">&nbsp;</td></tr>\n");

		for($i = 1; $user_info = mysql_fetch_row($res); $i++) {
			$user_id = $user_info[0];
			$username = $user_info[1];
			$user_win_percent = $user_info[2];
			$user_points = $user_info[3];

			print("         <tr><td class=\"item\">" . $i . ". <a href=\"members.php?mode=display_profile&id=" . $user_id . "\" onMouseOver=\"window.status='View Member Profile'; return true;\" onMouseOut=\"window.status=''; return true;\">" . $username . "</a></td><td class=\"item\">" . $user_points . "</td><td class=\"item\"><b class=\"alarm\">" .  $user_win_percent . "%</b></td><td class=\"item\">&nbsp;</td></tr>\n");
		}
	}
?>
