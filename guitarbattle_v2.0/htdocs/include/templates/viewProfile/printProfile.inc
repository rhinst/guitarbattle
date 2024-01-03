<br>
<table class="items" border="0" cellspacing="0" cellpadding="2">
  <tr>
    <td class="item_title" colspan="2" align="left">
      User Profile: <b class="title_light"><? print $username; ?></b>
    </td>
  </tr> 
  <tr>
    <td class="listing_row2_bold" >&nbsp;</td>
    <td class="listing_row2" align="left">
      <?
	if($profile_icon != 0) {
		print "<img src=\"viewImage.php?id=" . $profile_icon . "\" alt=\"User Icon\" width=\"" . $user_icon_width . "\" height=\"" . $user_icon_height . "\" border=\"1\">\n";
	}
	else {
		print "<img src=\"images/no_image.jpg\" alt=\"No Image Available\" width=\"" . $user_icon_width . "\" height=\"" . $user_icon_height . "\">\n";
	}
      ?> 
    </td>
  </tr>
  <tr>
    <td class="listing_row1_bold" align="right" valign="top">
      Name:
    </td>
    <td class="listing_row1" align="left">
      <? print wordwrap(htmlspecialchars($profile_name), 50, "<br>", 1); ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row2_bold" align="right" valign="top">
      Age:
    </td>
    <td class="listing_row2" align="left">
      <? print wordwrap(htmlspecialchars($profile_age), 50, "<br>", 1); ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row1_bold" align="right" valign="top">
      Gender:
    </td>
    <td class="listing_row1" align="left">
      <? print wordwrap(htmlspecialchars($profile_gender), 50, "<br>", 1); ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row2_bold" align="right" valign="top">
      How long have you been playing?:
    </td>
    <td class="listing_row2" align="left">
      <? print wordwrap(htmlspecialchars($profile_how_long), 50, "<br>", 1); ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row1_bold" align="right" valign="top">
      Influences:
    </td>
    <td class="listing_row1" align="left">
      <? print wordwrap(htmlspecialchars($profile_influences), 50, "<br>", 1); ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row2_bold" align="right" valign="top">
      Gear:
    </td>
    <td class="listing_row2" align="left">
      <? print wordwrap(htmlspecialchars($profile_gear), 50, "<br>", 1); ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row1_bold" align="right" valign="top">
      Location:
    </td>
    <td class="listing_row1" align="left">
      <? print wordwrap(htmlspecialchars($profile_location), 50, "<br>", 1); ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row2_bold" align="right" valign="top">
      Occupation:
    </td>
    <td class="listing_row2" align="left">
      <? print wordwrap(htmlspecialchars($profile_occupation), 50, "<br>", 1); ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row1_bold" align="right" valign="top">
      E-mail:
    </td>
    <td class="listing_row1" align="left">
      <a href="mailto:<? print htmlspecialchars($profile_eml); ?>"><? print wordwrap(htmlspecialchars($profile_eml), 50, "<br>", 1); ?></a>
    </td>
  </tr>
  <tr>
    <td class="listing_row2_bold" align="right" valign="top">
      Website:
    </td>
    <td class="listing_row2" align="left">
      <a href="<? print htmlspecialchars($profile_website); ?>" target="new"><? print wordwrap(htmlspecialchars($profile_website), 50, "<br>", 1); ?></a>
    </td>
  </tr>
</table>
<br>
