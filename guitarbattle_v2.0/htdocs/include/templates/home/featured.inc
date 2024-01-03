<img src="images/featured_title.jpg" border="0" width="204" height="25" alt="Featured">
<table class="items" width="175" border="0" cellpadding="4" cellspacing="0">
  <tr>
    <td class="item_title">
      Member: <a class="light_link" href="<? print $baseURL; ?>/viewProfile.php?username=<? print $featured_profile_username; ?>"><? print $featured_profile_username; ?></a>
    </td>
  </tr>
  <tr>
    <td align="center">
      <table class="items" border=0 cellpadding="1" cellspacing="0">
        <tr>
          <td><a href="<? print $baseURL; ?>/viewProfile.php?username=<? print $featured_profile_username; ?>"><img src="viewImage.php?id=<? print $featured_profile_icon; ?>" width="150" height="75" border="0"></a></td>
	</tr>
      </table>
    </td>
  </tr>
<?
	if($featured_profile_name == "") {
		$featured_profile_name = "-";
	}
	if($featured_profile_location == "") {
		$featured_profile_location = "-";
	}
	if($featured_profile_influences == "") {
		$featured_profile_influences = "-";
	}
?>
  <tr>
    <td>
      <b>Name:</b> <? print htmlspecialchars((strlen($featured_profile_name) <= 20) ? ($featured_profile_name):(substr($featured_profile_name, 0, 20) . "...")); ?><br>
      <b>Location:</b> <? print htmlspecialchars((strlen($featured_profile_location) <= 20) ? ($featured_profile_location):(substr($featured_profile_location, 0, 20) . "...")); ?><br>
      <b>Influences:</b> <? print htmlspecialchars((strlen($featured_profile_influences) <= 20) ? ($featured_profile_influences):(substr($featured_profile_influences, 0, 20) . "...")); ?>
    </td>
  </tr>
</table>
