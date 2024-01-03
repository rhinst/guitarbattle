<?php
	$results = mysql_fetch_row(mysql_query("select count(id) from users where username like '%$search_text%'"));
	$total_matches = $results[0];
	if(($total_matches == 0) || ($search_text == "")) {
		print("         <tr><td class=\"item\">No Matching Results.</td></tr>\n");
	}
	else {
		if($total_matches >= 50) {
			$match_listing = "1 - 50 of $total_matches";
		}
		else {
			$match_listing = "1 - $total_matches of $total_matches";
		}
		print("         <tr><td class=\"large\">Results: <b class=\"normal\">[$match_listing]</b></td></tr>\n");
		$result = mysql_query("select id, username from users where username like '%$search_text%' limit 50");
		while($user_info = mysql_fetch_row($result)) {
			$user_id = $user_info[0];
			$username = $user_info[1];
			print("         <tr><td class=\"item\"><a href=\"members.php?mode=display_profile&id=$user_id\" onMouseOver=\"window.status='View Member Profile'; return true;\" onMouseOut=\"window.status=''; return true;\">$username</a></td></tr>\n");
		}
	}
?>
