     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700">
        <table width="700" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title" colspan="2">Edit Your Member Profile:</td>
         </tr>
         <tr>
          <td class="large" colspan="2">Edit <?php print("$current_user"); ?>'s Member Profile:</td>
         </tr>
         <tr>
          <td class="item" colspan="2">Here you may edit your member profile.  This information is available for other user's to view. After you are finished editing this form please click on the "Make Changes" button at the bottom of this page to save the changes you have made to your member profile.</td>
         </tr>
         <tr><td class="item" colspan="2">&nbsp;</td></tr>
         <tr>
          <td class="large" colspan="2">Personal Information:</td>
         </tr>
         <form method="post" action="docs/action_handler.php?action=edit_profile" enctype="multipart/form-data">
         <tr>
          <td class="item_light" width="150">Name: </td>
          <td class="item" width="550"><input type="text" name="profile_name" size="50" maxlength="255" value="<?php print("$profile_name"); ?>"></td>
         </tr>
         <tr>
          <td class="item_light" width="150">Nickname: </td>
          <td class="item" width="550"><input type="text" name="profile_nickname" size="50" maxlength="255" value="<?php print("$profile_nickname"); ?>"></td>
         </tr>
         <tr>
          <td class="item_light" width="150">Location: </td>
          <td class="item" width="550"><input type="text" name="profile_location" size="50" maxlength="255" value="<?php print("$profile_location"); ?>"></td>
         </tr>
         <tr>
          <td class="item_light" width="150">Influences: </td>
          <td class="item" width="550"><input type="text" name="profile_influences" size="50" maxlength="255" value="<?php print("$profile_influences"); ?>"></td>
         </tr>
         <tr>
          <td class="item_light" width="150">Occupation: </td>
          <td class="item" width="550"><input type="text" name="profile_occupation" size="50" maxlength="255" value="<?php print("$profile_occupation"); ?>"></td>
         </tr>
         <tr><td class="item" colspan="2">&nbsp;</td></tr>
         <tr>
          <td class="large" colspan="2">Member Icon:</td>
         </tr>
<?php
	if(isset($profile_image_id) && ($profile_image_id != 0)) {
		$no_icon_checked = "";
		print("         <tr><td class=\"item\" colspan=\"2\">Your Current Member Icon:</td></tr>\n");
		print("         <tr><td class=\"item\" colspan=\"2\"><a href=\"javascript: window.open('docs/view_image_page.php?id=$profile_image_id', '_blank', 'width=350, height=200, menubar=no, resizable=no, toolbar=no'); void('');\" onMouseOver=\"window.status='View Full Size'; return true;\" onMouseOut=\"window.status=''; return true;\"><img src=\"$user_icon\" width=\"150\" height=\"75\" border=\"0\"></a></td></tr>\n");
		print("         <tr><td class=\"item\" colspan=\"2\"><input type=\"radio\" name=\"profile_user_icon\" value=\"$profile_image_id\" checked> Keep your current icon.</td></tr>\n");
		print("         <tr><td class=\"item\" colspan=\"2\">&nbsp;</td></tr>\n");
	}
	else {
		$no_icon_checked = "checked";
	}
?>
         <tr>
          <td class="item" colspan="2"><b class="light">[All member icons displayed at 50% size. Please click on the thumbnail image to view the image at full size.]</b></td>
         </tr>
         <tr>
          <td class="item" colspan="2">If you wish to personalize your account with a member icon please note that you may either use one of our prefab icons or you may upload your own, original member icon. All member icons must be either JPEG or GIF file type and will be automatically resized to 300 x 150 pixels.</td>
         </tr>
         <tr>
          <td class="item_light" colspan="2">Select a prefab member icon:</td>
         </tr>
         <tr>
          <td class="item" colspan="2" align="center">
           <table>
<?php
	$result = mysql_query("select user_id from user_icons where ((user_id < -1) and (user_id > -999)) order by user_id desc");
	$td_count = 0;
	while($row = mysql_fetch_row($result)) {
		if($td_count == 0) {
			print("            <tr>\n");
		}
		else if($td_count == 3) {
			print("            </tr>\n");
			print("            <tr>\n");
			$td_count = 0;
		}
		$prefab_icon = "/docs/display_image.php?id=$row[0]";
		print("             <td class=\"item\" width=\"200\" align=\"center\"><a href=\"javascript: window.open('docs/view_image_page.php?id=$row[0]', '_blank', 'width=350, height=200, menubar=no, resizable=no, toolbar=no'); void('');\" onMouseOver=\"window.status='View Full Size'; return true;\" onMouseOut=\"window.status=''; return true;\"><img src=\"$prefab_icon\" width=\"150\" height=\"75\" border=\"0\"></a><br><input type=\"radio\" name=\"profile_user_icon\" value=\"$row[0]\"> Use this icon.</td>\n");
		$td_count++;
	}
?>
           </table>
          </td>
         </tr>
         <tr>
          <td class="item" colspan="2"><input type="radio" name="profile_user_icon" value="0" <?php print("$no_icon_checked"); ?>> No member icon.</td>
         </tr>
         <tr>
          <td class="item" colspan="2"><input type="radio" name="profile_user_icon" value="UPLOAD"> Upload your own icon:</td>
         </tr>
         <tr>
          <td class="item" colspan="2"><input type="file" name="icon_file" size="40"></td>
         </tr>
         <tr>
          <td class="item" colspan="2"><input type="submit" value="Make Changes"></td>
         </tr>
         </form>
        </table>
       </td>
      </tr>
     </table>
