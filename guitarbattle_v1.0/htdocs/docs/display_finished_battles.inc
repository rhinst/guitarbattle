     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700">
        <table width="700" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title">Welcome to <b class="alarm">The Vault</b> (View Finished Battles):</td>
         </tr>
         <tr>
          <td class="item">Welcome the The Vault. This is where all finished battles are listed. Here you may find all finished battles listed by battle number and the winner's username.</td>
         </tr>
<?php
	$get_category = mysql_query("select id, name from battle_categories");
	while($category_info = mysql_fetch_row($get_category)) {
		print("         <tr><td class=\"large\">$category_info[1]</td></tr>\n");
		$get_battle = mysql_query("select id, user1, user2, winner from battles where parent_category=$category_info[0] and winner != 0 and hide=0 order by id desc");
		$battle_info = mysql_fetch_row($get_battle);
		if(!isset($battle_info[0])) {
			print("         <tr><td class=\"item\">No finished battles.</td></tr>\n");
		}
		else {
			$get_battle = mysql_query("select battles.id, battles.winner, users.username from users, battles where battles.parent_category = $category_info[0] and battles.winner != 0 and battles.hide=0 and users.id = battles.winner order by id desc");
			while($battle_info = mysql_fetch_row($get_battle)) {
				$battle_winner = $battle_info[2];
				print("         <tr><td class=\"item\"><a href=\"battles.php?mode=view_battle&battle_id=$battle_info[0]\">Battle #$battle_info[0]: <b class=\"alarm\">$battle_winner</b></a></td></tr>\n");
			}
		}
		print("         <tr><td class=\"item\">&nbsp;</td></tr>\n");
	}
?>
        </table>
       </td>
      </tr>
     </table>
