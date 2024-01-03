<br>
<form action="<? print $PHP_SELF; ?>" method="post" enctype="multipart/form-data">
<? vilw_hidden("action", "update"); ?>
<? vilw_hidden("old_icon", $profile_icon); ?>
<table class="items" width="400" border="0" cellspacing="0" cellpadding="2">
  <tr>
    <td class="item_title" colspan="2">
      Edit User Profile: <b class="title_light"><? print $authenticated_user; ?></b>
    </td>
  </tr> 
  <tr>
    <td class="listing_row2_bold" colspan="2" align="center">
      <?
	if($profile_icon != 0) {
		print "<img src=\"viewImage.php?id=" . $profile_icon . "\" alt=\"User Icon\" width=\"" . $user_icon_width . "\" height=\"" . $user_icon_height . "\">\n";
	}
	else {
		print "<img src=\"images/no_image.jpg\" alt=\"No Image Available\" width=\"" . $user_icon_width . "\" height=\"" . $user_icon_height . "\">\n";
	}
      ?> 
    </td>
  </tr>
  <tr>
    <td class="listing_row2_bold" width="100" align="right">
      Upload an Icon:
    </td>
    <td class="listing_row2_bold" align="left">
      <input type="file" name="new_icon">
    </td>
  </tr>
  <tr>
    <td class="listing_row1_bold" width="100" align="right">
      Name:
    </td>
    <td class="listing_row1" align="left">
      <? vilw_input("name", 30, $profile_name); ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row2_bold" width="100" align="right">
      Age:
    </td>
    <td class="listing_row2" align="left">
      <? vilw_input("age", 30, $profile_age); ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row1_bold" width="100" align="right">
      Gender:
    </td>
    <td class="listing_row1" align="left">
      <? $gender_options = Array("Not Specified", "Male", "Female"); ?>
      <? vilw_select("gender", $gender_options, $profile_gender); ?>
    </td>
  </tr>
    <td class="listing_row2_bold" width="100" align="right">
      How long have you been playing?:
    </td>
    <td class="listing_row2" align="left">
      <? vilw_input("how_long", 30, $profile_how_long); ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row1_bold" width="100" align="right">
      Influences:
    </td>
    <td class="listing_row1" align="left">
      <? vilw_textarea("influences", 3, 50, $profile_influences); ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row2_bold" width="100" align="right">
      Gear:
    </td>
    <td class="listing_row2" align="left">
      <? vilw_textarea("gear", 3, 50, $profile_gear); ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row1_bold" width="100" align="right">
      Location:
    </td>
    <td class="listing_row1" align="left">
      <? vilw_input("location", 30, $profile_location); ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row2_bold" width="100" align="right">
      Occupation:
    </td>
    <td class="listing_row2" align="left">
      <? vilw_input("occupation", 30, $profile_occupation); ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row1_bold" width="100" align="right">
      E-mail:
    </td>
    <td class="listing_row1" align="left">
      <? vilw_input("eml", 30, $profile_eml); ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row2_bold" width="100" align="right">
      Website:
    </td>
    <td class="listing_row2" align="left">
      <? vilw_input("website", 30, $profile_website); ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row2" colspan="2" align="right">
      <input class="button" type="submit" value="Update Profile">
    </td>
  </tr>
</table>
</form>
