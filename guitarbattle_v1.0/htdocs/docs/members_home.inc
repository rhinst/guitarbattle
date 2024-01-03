     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700">
        <table width="700" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title" colspan="4">GuitarBattle.com Members:</td>
         </tr>
         <tr>
          <td class="item" colspan="4">Welcome to the members section of the website.</td>
         </tr>
         <tr><td class="item" colspan="4">&nbsp;</td></tr>
         <form method="post" action="members.php?search=go">
         <tr>
          <td class="item" colspan="4">Search for a member: <input type="text" name="search_text" value="<?php print("$search_text"); ?>" size="20" maxlength="16"> <input type="submit" value="Submit"></td>
         </tr>
         </form>
<?php
	if($search != "go") {
		include('top_ten_members.inc');
		print("         <tr><td class=\"item\">&nbsp;</td></tr>\n");
		$current_date = time();
		$date_last_month = strtotime("-30 days", $current_date);
		print("         <tr><td class=\"large\" colspan=\"4\">New Members (Last 30 days):</td></tr>\n");
		$row = mysql_fetch_row(mysql_query("select id, username from users where unix_timestamp(join_date) > $date_last_month"));
		if(!isset($row[0])) {
			print("         <tr><td class=\"item\" colspan=\"4\">No new users this month.</td></tr>\n");
		}
		$result = mysql_query("select id, username from users where unix_timestamp(join_date) > $date_last_month order by username asc");
		while($row = mysql_fetch_row($result)) {
			$user_id = $row[0];
			$username = $row[1];
			print("         <tr><td class=\"item\" colspan=\"4\"><a href=\"members.php?mode=display_profile&id=$user_id\" onMouseOver=\"window.status='View Member Profile'; return true;\" onMouseOut=\"window.status=''; return true;\">$username</a></td></tr>\n");
		}
	}

	if($search == "go") {
		include('member_search.inc');
	}
?>
        </table>
       </td>
      </tr>
     </table>
