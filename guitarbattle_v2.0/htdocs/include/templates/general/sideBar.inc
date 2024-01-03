<!-- Start Side Bar -->
      <table width="171" height="100%" border="0" cellspacing="0" cellpadding="0">
        <tr valign="top">
          <td style="background-image: url('images/menu_top.jpg'); font-size: 0px" width="171" height="39">
            <img src="images/spacer.gif" width="171" height="39" border="0" alt="">
          </td>
        </tr>
        <tr valign="top">
          <td align="center" height="50" style="background-image: url('images/sidebar_slat.jpg'); font-size: 0px">
	<?
		if(session_is_registered("authenticated_user")) {
			include('templates/general/quickStats.inc');
		}
		else {
 			include('templates/general/loginBox.inc'); 
		}
	?>
          </td>
        </tr>
        <tr>
          <td style="background-image: url('images/sidebar_slat.jpg'); font-size: 0px" width="171" height="6">
            <img src="images/menu_bevel.jpg" width="171" height="6" border="0" alt="">
          </td>
<? if(isset($poll_info)) {  ?>
        </tr>
        <tr valign="top">
          <td align="center" style="background-image: url('images/sidebar_slat.jpg'); font-size: 0px" width="171" height="100">
            <?
               if($already_voted) {
                 include('templates/general/poll_results.inc'); 
               }
               else {
                 include('templates/general/poll.inc'); 
               }
            ?>
          </td>
        </tr>
        <tr>
          <td style="background-image: url('images/sidebar_slat.jpg'); font-size: 0px" width="171" height="6">
            <img src="images/menu_bevel.jpg" width="171" height="6" border="0" alt="">
          </td>
        </tr>
<? } ?>
        <tr valign="top">
          <td align="center" style="background-image: url('images/sidebar_slat.jpg'); font-size: 0px" width="171" height="100">
            <?
               $genres = get_genres();
               include('templates/general/genreMenu.inc'); 
            ?>
          </td>
        </tr>
        <tr>
          <td style="background-image: url('images/sidebar_slat.jpg'); font-size: 0px" width="171" height="6">
            <img src="images/menu_bevel.jpg" width="171" height="6" border="0" alt="">
          </td>
        </tr>
        <tr valign="top">
          <td height="70" style="background-image: url('images/sidebar_slat.jpg'); font-size: 0px" align="center">
            <br>
            <a href="mailto:<? print $advertising_email; ?>""><img src="images/sample_ad.jpg" border="0"></a>
          </td>
        </tr>
        <tr valign="top">
          <td class="menu_text" height="20" style="background-image: url('images/sidebar_slat.jpg');" align="center">
            Use these graphics to link to <? print $sitename; ?> from your website:<br><br>
          </td>
        </tr>
        <tr valign="top">
          <td height="50" style="background-image: url('images/sidebar_slat.jpg'); font-size: 0px" align="center">
            <a href="<? print $baseURL; ?>" target="_new"><img src="images/linkgraphic.jpg" border="0" alt="<? print $sitename; ?>"></a>
          </td>
        </tr>
        <tr valign="top">
          <td height="50" style="background-image: url('images/sidebar_slat.jpg'); font-size: 0px" align="center">
            <a href="<? print $baseURL; ?>" target="_new"><img src="images/linkgraphic2.jpg" border="0" alt="<? print $sitename; ?>"></a>
          </td>
        </tr>
        <tr>
          <td style="background-image: url('images/sidebar_slat.jpg'); font-size: 0px" align="center">
            &nbsp;
          </td>
        </tr>
      </table>
<!-- End Side Bar -->
