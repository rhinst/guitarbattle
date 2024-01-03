<?php
        $count_battle_list = mysql_fetch_row(mysql_query("select count(id) from battles where (user1=$id or user2=$id) and winner=0 and hide=0"));
        $total_battles = $count_battle_list[0];
        $start_list = ($active_group_listed + 1);
        if(($total_battles - $active_group_listed) > 10) {
                $end_list = (10 + $active_group_listed);
        }
        else if(($total_battles - $active_group_listed) < 10) {
                $end_list = $total_battles;
        }

        if($total_battles == 0) {
                $battles_listed = "0";
                $no_battles = 1;
                $no_battles_text = "Currently no active or unchallenged battles.\n";
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
                if($active_group_listed == 0) {
                        $battles_listed = "1 - $end_list";
                }
                else {
                        $battles_listed = "$start_list - $end_list";
                }
                $no_battles = 0;
        }
        print("          <td class=\"item_light\" width=\"150\" valign=\"top\">Active/Unchallenged Battles:<br><b class=\"normal\" valign=\"top\">[$battles_listed of $total_battles]</b></td>\n          <td class=\"item\" width=\"550\">\n");
        if($no_battles != 0) {
                print("           $no_battles_text");
        }
        $result = mysql_query("select id, user1, user2 from battles where (user1=$id or user2=$id) and winner=0 and hide=0 limit $active_group_listed, 10");
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

                print("           <br><a href=\"battles.php?mode=view_battle&battle_id=$battle_id\" onMouseOver=\"window.status='View This Battle'; return true\" onMouseOut=\"window.status=''; return true\">$user1_username vs. $user2_username</a>\n");
        }
        $pages = ($total_battles / 10);
        print("           <br>...\n");
        print("           <br><b class=\"item_small\">Results Page:</b> ");
        if(($active_group_listed / 10) >= 1) {
                $prev_group = (($active_group_listed / 10) - 1);
                print("<a class=\"misc_small\" href=\"members.php?mode=display_profile&id=$id&active_group_listed=$prev_group\" onMouseOver=\"window.status='View the Previous 10 Battles'; return true\" onMouseOut=\"window.status=''; return true\">[Previous]</a>");
        }
        if($pages > 1) {
                $page_count = 1;
                while($pages > 0) {
                        if((($active_group_listed / 10) + 1) == $page_count) {
                                print(" <b class=\"item_small\">$page_count</b> ");
                                $pages--;
                                $page_count++;
                        }
                        else {
                                $link_group = ($page_count - 1);
                                print(" <a class=\"misc_small\" href=\"members.php?mode=display_profile&id=$id&active_group_listed=$link_group\" onMouseOver=\"window.status='View Results Page $page_count'; return true;\" onMouseOut=\"window.status=''; return true;\">[$page_count]</a> ");
                                $pages--;
                                $page_count++;
                        }
                }
        }
        else if($pages <= 1) {
                print("<b class=\"item_small\">1</b>\n");
        }
        if($total_battles > ($active_group_listed + 10)) {
                $next_group = (($active_group_listed / 10) + 1);
                print("<a class=\"misc_small\" href=\"members.php?mode=display_profile&id=$id&active_group_listed=$next_group\" onMouseOver=\"window.status='View the Next 10 Battles'; return true\" onMouseOut=\"window.status=''; return true\">[Next]</a>\n");
        }
	print("          </td>\n")
?>
