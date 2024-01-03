     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700">
        <table width="700" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title" colspan="2">Submit a Link to GuitarBattle.com:</td>
         </tr>
         <form method="post" action="docs/action_handler.php?action=submit_link">
         <tr>
          <td class="item" colspan="2">Please feel free to submit your favorite link.</td>
         </tr>
         <tr><td class="item" colspan="2">&nbsp;</td></tr>
<?php
	if(!isset($error)) {
		$error = 0;
	}
	else if($error == 1) {
		print("<tr><td class=\"item\" colspan=\"2\"><b class=\"alarm\">You have not entered a link.</b></td></tr>");
	}
?>
         <tr>
          <td class="item" width="100">Link URL: </td>
          <td class="item" width="600"><input type="text" name="link_url" size="30" maxlength="256" value="http://"></td>
          </td>
         <tr>
          <td class="item" colspan="2"><input type="submit" value="Submit Link"></td>
         </tr>
         </form>
        </table>
       </td>
      </tr>
     </table>
