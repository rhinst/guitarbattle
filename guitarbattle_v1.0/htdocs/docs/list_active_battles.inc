
     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="349" valign="top">
        <table width="349" cellpadding="2" cellspacing="0">
<?php
        $count_battle_list = mysql_fetch_row(mysql_query("select count(id) from battles where parent_category=$category_id and winner=0 and hide=0"));
        $active_battle_count = mysql_fetch_row(mysql_query("select count(id) from battles where parent_category=$category_id and winner=0 and hide=0 and active=1"));
        $total_battles = $count_battle_list[0];
	$active_battles = $active_battle_count[0];
	$start_list = ($group_listed + 1);
	if(($total_battles - $group_listed) > 20) {
		$end_list = (20 + $group_listed);
	}
	else if(($total_battles - $group_listed) < 20) {
		$end_list = $total_battles;
	}

        if($total_battles == 0) {
                $battles_listed = "0";
                $no_battles = 1;
                $no_battles_text = "         <tr>\n          <td class=\"item\">Currently no battles.</td>\n         </tr>\n";
        }
        else if($total_battles == 1) {
                $battles_listed = "1";
                $no_battles = 0;
        }
	else if($end_list == $start_list) {
		$battles_listed = $end_list;
		$no_battles = 0;
	}
        else {
		if($group_listed == 0) {
			$battles_listed = "1 - $end_list";
		}
		else {
                	$battles_listed = "$start_list - $end_list";
		}
                $no_battles = 0;
        }
        print("         <tr>\n          <td class=\"item_title\">$category_name: <b class=\"normal\">[$battles_listed of $total_battles]</b></td>\n         </tr>\n");
        if($no_battles != 0) {
                print("$no_battles_text");
        }
	if($active_battles >= $group_listed) {
        	$result = mysql_query("select id, user1, user2 from battles where parent_category=$category_id and winner=0 and hide=0 and active=1 order by unix_timestamp(timestamp) asc limit $group_listed, 20");
        	while($row = mysql_fetch_row($result)) {
        	        $battle_id = $row[0];
        	        $user1_id = $row[1];
        	        $user2_id = $row[2];
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
	if(((($active_battles - ($group_listed + 20)) < 20) && ($total_battles - $active_battles) > 0)) {
		if(((($group_listed + 20) - $active_battles) < 20)) {
			$limit = (($group_listed + 20) - $active_battles);
			$start_point = 0;
		}
		else {
			$limit = 20;
			$start_point = (($group_listed) - $active_battles);
		}
        	$result = mysql_query("select id, user1, user2 from battles where parent_category=$category_id and winner=0 and hide=0 and active=0 order by unix_timestamp(timestamp) asc limit $start_point, $limit");
        	while($row = mysql_fetch_row($result)) {
        	        $battle_id = $row[0];
        	        $user1_id = $row[1];
        	        $user2_id = $row[2];
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
	$pages = ($total_battles / 20);
	print("         <tr>\n          <td class=\"item\">...</td>\n         </tr>\n");
	print("         <tr>\n");
	print("          <td class=\"small_print\">Results Page: ");
	if(($group_listed / 20) >= 1) {
		$prev_group = (($group_listed / 20) - 1);
               	print("           <a class=\"misc_small\" href=\"battles.php?mode=active_battles&category_id=$category_id&group_listed=$prev_group\" onMouseOver=\"window.status='View the Previous 20 Battles'; return true\" onMouseOut=\"window.status=''; return true\">[Previous]</a>");
	}
	if($pages > 1) {
		$page_count = 1;
		while($pages > 0) {
			if((($group_listed / 20) + 1) == $page_count) {
				print(" $page_count ");
				$pages--;
				$page_count++;
			}
			else {
				$link_group = ($page_count - 1);
				print(" <a class=\"misc_small\" href=\"battles.php?mode=active_battles&category_id=$category_id&group_listed=$link_group\">[$page_count]</a> ");
				$pages--;
				$page_count++;
			}
		}
	}
	else if($pages <= 1) {
		print("1\n");
		print("          </td>\n");
		print("         </tr>\n");
	}
        if($total_battles > ($group_listed + 20)) {
		$next_group = (($group_listed / 20) + 1);
                print("<a class=\"misc_small\" href=\"battles.php?mode=active_battles&category_id=$category_id&group_listed=$next_group\" onMouseOver=\"window.status='View the Next 20 Battles'; return true\" onMouseOut=\"window.status=''; return true\">[Next]</a>\n");
		print("          </td>\n");
		print("         </tr>\n");
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
