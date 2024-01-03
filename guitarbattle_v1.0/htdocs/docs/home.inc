     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="349" valign="top">
        <table width="349" cellpadding="2" cellspacing="0">
<?php
	$result = mysql_query("select id, name from battle_categories");
	while($row = mysql_fetch_row($result)) {
		$category_id = $row[0];
		$category_name = $row[1];
		$count_battle_list = mysql_fetch_row(mysql_query("select count(id) from battles where parent_category=$category_id and winner=0 and hide=0"));
		$total_battles = $count_battle_list[0];
		if($total_battles == 0) {
			$battles_listed = "0";
			$no_battles = 1;
			$no_battles_text = "         <tr>\n          <td class=\"item\">Currently no battles.</td>\n         </tr>\n";
		}
		else if($total_battles == 1) {
			$battles_listed = "1";
			$no_battles = 0;
		}
		else if($total_battles <= 25) {
			$battles_listed = "1 - $total_battles";
			$no_battles = 0;
		}
		else {
			$battles_listed = "1 - 25";
			$no_battles = 0;
		}
		print("         <tr>\n          <td class=\"item_title\">$category_name: <b class=\"normal\">[$battles_listed of $total_battles]</b></td>\n         </tr>\n");
		if($no_battles != 0) {
			print("$no_battles_text");
		}
		$active_battle_count = mysql_fetch_row(mysql_query("select count(id) from battles where parent_category=$category_id and winner=0 and hide=0 and active=1"));
		$active_battle_total = $active_battle_count[0];
		$result2 = mysql_query("select id, user1, user2 from battles where parent_category=$category_id and winner=0 and hide=0 and active=1 order by unix_timestamp(timestamp) asc limit 25");
		while($row2 = mysql_fetch_row($result2)) {
			$battle_id = $row2[0];
			$user1_id = $row2[1];
			$user2_id = $row2[2];
			$user1_info = mysql_fetch_row(mysql_query("select username from users where id=$user1_id"));
			if($user2_id == 0) {
				$user2_info[0] = "<b class=\"alarm\">WAITING...</b>";
			}
			else {
				$user2_info = mysql_fetch_row(mysql_query("select username from users where id=$user2_id"));
			}
			$user1_username = $user1_info[0];
			$user2_username = $user2_info[0];

			print("         <tr>\n          <td class=\"item\"><a href=\"battles.php?mode=view_battle&battle_id=$battle_id\" onMouseOver=\"window.status='View This Battle'; return true\" onMouseOut=\"window.status=''; return true\">$user1_username vs. $user2_username</a></td>\n         </tr>\n");
		}
		if($active_battle_total < 25) {
			$inactive_battle_limit = (25 - $active_battle_total);
			$result2 = mysql_query("select id, user1, user2 from battles where parent_category=$category_id and winner=0 and hide=0 and active=0 order by unix_timestamp(timestamp) asc limit $inactive_battle_limit");
			while($row2 = mysql_fetch_row($result2)) {
				$battle_id = $row2[0];
				$user1_id = $row2[1];
				$user2_id = $row2[2];
				$user1_info = mysql_fetch_row(mysql_query("select username from users where id=$user1_id"));
				if($user2_id == 0) {
					$user2_info[0] = "<b class=\"alarm\">WAITING...</b>";
				}
				else {
					$user2_info = mysql_fetch_row(mysql_query("select username from users where id=$user2_id"));
				}
				$user1_username = $user1_info[0];
				$user2_username = $user2_info[0];
	
				print("         <tr>\n          <td class=\"item\"><a href=\"battles.php?mode=view_battle&battle_id=$battle_id\" onMouseOver=\"window.status='View This Battle'; return true\" onMouseOut=\"window.status=''; return true\">$user1_username vs. $user2_username</a></td>\n         </tr>\n");
			}
		}
		$count_battle_list = mysql_fetch_row(mysql_query("select count(id) from battles where parent_category=$category_id and winner=0"));
		$total_battles = $count_battle_list[0];
		if($total_battles > 25) {
			print("         <tr>\n          <td class=\"item\"><a class=\"misc\" href=\"battles.php?mode=active_battles&category_id=$category_id\" onMouseOver=\"window.status='View All Active Battles in the $category_name'; return true\" onMouseOut=\"window.status=''; return true\"><b>+ More...</b></a></td>\n         </tr>\n");
		}
		print("         <tr>\n          <td class=\"item\"><a class=\"misc\" href=\"battles.php?mode=start_battle&battle_category=$category_id\" onMouseOver=\"window.status='Start a Battle in the $category_name'; return true\" onMouseOut=\"window.status=''; return true\">+ Start a Battle</a></td>\n         </tr>\n");
		print("         <tr>\n          <td class=\"item\"><a class=\"misc\" href=\"battles.php?mode=finished_battles&category_id=$category_id\" onMouseOver=\"window.status='View Finished Battles of the $category_name'; return true\" onMouseOut=\"window.status=''; return true\">+ View Finished Battles</a></td>\n         </tr>\n");
	}
?>
        </table>
       </td>
       <td width="2" valign="top"><img src="images/2px_spacer.jpg"></td>
       <td width="349" valign="top">
<?php include('right_column.inc'); ?>
       </td>
      </tr>
     </table>
