<?php
	$location = urlencode($REQUEST_URI);
?>
     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700">
        <table width="700" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title" colspan="7">Battle #<?php print("$battle_id"); ?>: <b class="item"><?php print("$battle_user1"); ?> vs.</b> <b class="alarm">WAITING...</b> [<?php print("$battle_parent_category"); ?>]</td>
         </tr>
         <tr><td class="item" width="700" align="center" colspan="7">&nbsp;</td></tr>
         <tr>
          <td class="item" width="30" align="left">&nbsp;</td>
          <td class="item" width="310" align="left" colspan="2"><a class="misc" href="members.php?mode=display_profile&id=<?php print("$battle_user1_id"); ?>" onMouseOver="window.status='View Member Profile'; return true;" onMouseOut="window.status=''; return true;"><img src="<?php print("$user1_icon"); ?>" border="0" width="300" height="150"></a></td>
          <td class="item" width="20" align="center">&nbsp;</td>
          <td class="item" width="310" align="right" colspan="2">&nbsp;</td>
          <td class="item" width="30" align="right">&nbsp;</td>
         </tr>
         <tr><td class="item" width="700" align="center" colspan="7">&nbsp;</td></tr>
         <tr>
          <td class="item" width="30" align="left">&nbsp;</td>
          <td class="item" width="160" align="left">&nbsp;</td>
          <td class="large" width="150" align="left"><?php print("$battle_user1"); ?></td>
          <td class="large" width="20" align="center">vs.</td>
          <td class="large" width="150" align="right"><b class="alarm">No Challenger</b></td>
          <td class="item" width="160" align="right">&nbsp;</td>
          <td class="item" width="30" align="right">&nbsp;</td>
         </tr>
         <tr>
          <td class="item" width="30" align="left">&nbsp;</td>
          <td class="item" width="160" align="left">&nbsp;</td>
          <td class="item" width="150" align="left"><?php print("$battle_file1_name"); ?></td>
          <td class="large" width="20" align="center">&nbsp;</td>
          <td class="large" width="150" align="right">&nbsp;</td>
          <td class="item" width="160" align="right">&nbsp;</td>
          <td class="item" width="30" align="right">&nbsp;</td>
         </tr>
         <tr>
          <td class="item" width="190" align="left" colspan="2">&nbsp;</td>
          <td class="item" width="150" align="left">Listened to:</td>
          <td class="item" width="20" align="center">&nbsp;</td>
          <td class="item" width="150" align="right">&nbsp;</td>
          <td class="item" width="190" align="right" colspan="2">&nbsp;</td>
         </tr>
         <tr>
          <td class="item" width="190" align="left" colspan="2">&nbsp;</td>
          <td class="item" width="150" align="left"><b class="light"><?php print("$battle_file1_views"); ?></b> time(s)</td>
          <td class="item" width="20" align="center">&nbsp;</td>
          <td class="item" width="150" align="right">Click Here to:</td>
          <td class="item" width="190" align="right" colspan="2">&nbsp;</td>
         </tr>
         <tr>
          <td class="item" width="190" align="left" colspan="2">&nbsp;</td>
          <td class="item" width="150" align="left"><a class="misc" href="docs/listen.php?id=<?php print("$battle_file1"); ?>" onMouseOver="window.status='Click Here to Listen'; return true;" onMouseOut="window.status=''; return true;">+ Listen</a></td>
          <td class="item" width="20" align="center">&nbsp;</td>
          <td class="item" width="150" align="right"><a class="misc" href="battles.php?mode=join_battle&battle_id=<?php print("$battle_id"); ?>" onMouseOver="window.status='Challenge This User'; return true;" onMouseOut="window.status=''; return true;">+ Join This Battle</a></td>
          <td class="item" width="190" align="right" colspan="2">&nbsp;</td>
         </tr>
<?php
	if($battle_tab1 == '0') {
		$tab1_link = "<b>[No Tablature]</b>";
	}
	else {
		$tab1_link = "<a class=\"misc\" href=\"javascript: window.open('docs/display_tablature.php?id=$battle_file1', '_blank', 'status=no, height=300, width=500, scrollbars=yes, toolbar=no, resizable=yes'); void('');\" onMouseOver=\"window.status='View Tablature'; return true;\" onMouseOut=\"window.status=''; return true;\">+ View Tablature</a>";
	}
?>
         <tr>
          <td class="item" width="190" align="left" colspan="2">&nbsp;</td>
          <td class="item" width="150" align="left"><?php print("$tab1_link"); ?></td>
          <td class="item" width="20" align="center">&nbsp;</td>
          <td class="item" width="150" align="right">&nbsp;</td>
          <td class="item" width="190" align="right" colspan="2">&nbsp;</td>
         </tr>
         <tr>
          <td class="item" width="190" align="left" colspan="2">&nbsp;</td>
          <td class="item" width="150" align="left"><a class="misc" href="members.php?mode=display_profile&id=<?php print("$battle_user1_id"); ?>" onMouseOver="window.status='View Member Profile'; return true;" onMouseOut="window.status=''; return true;">+ View Member Profile</a></td>
          <td class="item" width="20" align="center">&nbsp;</td>
          <td class="item" width="150" align="right">&nbsp;</td>
          <td class="item" width="190" align="right" colspan="2">&nbsp;</td>
         </tr>
        </table>
        <table width="700" cellpadding="2" cellspacing="0">
         <tr><td class="item" width="700" colspan="4">&nbsp;</td></tr>
         <tr><td class="item" width="60">&nbsp;</td><td class="item_title" width="580" colspan="2" align="left"><b>Battle Discussion:</b></td><td class="item" width="60" align="right">&nbsp;</td></tr>
         <tr><td class="item" width="60">&nbsp;</td><td class="small_print" width="100" align="left">User:</td><td class="small_print" width="480" align="left">Message:</td><td class="item" width="60" align="right">&nbsp;</td></tr>
<?php
	$post = 1;
	$get_messages = mysql_query("select post_user, message from battle_messages where battle_id=$battle_id");
	while($message_info = mysql_fetch_row($get_messages)) {
		$message_user = $message_info[0];
		$message_text = $message_info[1];
		print("         <tr><td class=\"item\" width=\"60\">&nbsp;</td><td class=\"post$post\" width=\"100\" valign=\"top\">$message_user</td><td class=\"post$post\" width=\"380\">$message_text</td><td class=\"item\" width=\"60\" align=\"right\">&nbsp;</td></tr>");
		if($post == 1) {
			$post = 2;
		}
		else if($post == 2) {
			$post = 1;
		}
	}
?>
         <tr><td class="item" width="60">&nbsp;</td><td class="item" width="580" colspan="2" align="right"><a class="misc" href="battles.php?mode=post_message&action=post_message&battle_id=<?php print("$battle_id"); ?>" onMouseOver="window.status='Post A Message'; return true;" onMouseOut="window.status=''; return true;">+ Post A Message</a></td><td class="item" width="60" align="right">&nbsp;</td></tr>
         <tr><td class="item" width="60">&nbsp;</td><td class="item" width="100">&nbsp;</td><td class="item" width="480">&nbsp;</td><td class="item" width="60" align="right">&nbsp;</td></tr>
        </table>
       </td>
      </tr>
     </table>
