        <table width="349" cellpadding="2" cellspacing="0">
<?php
        if(!$login) {
		$login_info = "You are not currently logged in.";
                $login_links = "<a href=\"index.php?location=forgotinfo\" onMouseOver=\"window.status='Forgot your username and/or password?'; return true;\" onMouseOut=\"window.status=''; return true;\">Forgot your username and/or password?</a><br><a href=\"index.php?action=join\" onMouseOver=\"window.status='Join GuitarBattle.com Now'; return true;\" onMouseOut=\"window.status=''; return true;\">Join Now</a><br><a href=\"index.php?action=login\" onMouseOver=\"window.status='Login'; return true;\" onMouseOut=\"window.status=''; return true;\">Login</a><br><br>Want to advertise on GuitarBattle.com? Contact us at <a href=\"mailto:advertising@guitarbattle.com\">Advertising@GuitarBattle.com</a>.";
        }
	else {
		$login_info = "You are currently logged in as: <b>$current_user</b>";
                $login_links = "<a href=\"index.php?action=changepasswd\" onMouseOver=\"window.status='Change Your Password'; return true;\" onMouseOut=\"window.status=''; return true;\">Change Your Password</a><br><a href=\"members.php?mode=edit_profile\" onMouseOver=\"window.status='Edit Your Member Profile'; return true;\" onMouseOut=\"window.status=''; return true;\">Edit Your Member Profile</a><br><a href=\"docs/action_handler.php?action=logout\" onMouseOver=\"window.status='Logout'; return true;\" onMouseOut=\"window.status=''; return true;\">Logout</a><br><br>Want to advertise on GuitarBattle.com? Contact us at <a href=\"mailto:advertising@guitarbattle.com\">Advertising@GuitarBattle.com</a>";
        }
?>
         <tr>
          <td class="item_title">Members:</td>
         </tr>
         <tr>
<?php
	$display_date = date("F") . " " . date("j") . ", " . date("Y") . " " . date("g") . ":" . date("i") . " " . date("A");
?>
          <td class="item"><?php print("$display_date"); ?> [EST]</td>
         </tr>
         <tr>
          <td class="item"><?php print("$login_info"); ?></td>
         </tr>
         <tr>
          <td class="item"><?php print("$login_links"); ?></td>
         </tr>
         <tr>
          <td class="item_title">Current News:</td>
         </tr>
<?php
	$res = mysql_query("select unix_timestamp(ts), news from news order by unix_timestamp(ts) desc");
	while($news = mysql_fetch_row($res)) {
		if(strtotime("-7 days") < $news[0]) {
			$new_news_mark = "<img src=\"../images/new.gif\"> ";
		}
		else {
			$new_news_mark = "";
		}
		$newsdate = date("n/j/y g:iA", $news[0]);
		print("         <tr><td class=\"news_item\">" . $new_news_mark . $newsdate . ":: " . $news[1] . "</td></tr>\n");
	}
?>
        <tr>
         <td class="item_title">Polls:</td>
        </tr>
        <tr>
         <td class="item">No new polls.</td>
        </tr>
        </table>
