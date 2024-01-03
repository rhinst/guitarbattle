     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700">
        <table width="700" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title" colspan="2">Contact Us @ GuitarBattle.com:</td>
         </tr>
         <form method="post" action="docs/action_handler.php?action=contact">
         <tr>
          <td class="item" colspan="2">Please feel free to contact us if you have any questions or or suggestions. Please also check the <a href="index.php?location=help" onMouseOver="window.status='GuitarBattle.com FAQ'" onMouseOut="window.status=''; return true;">GuitarBattle.com FAQ</a> for answers to commonly asked questions.</td>
         </tr>
         <tr><td class="item" colspan="2">&nbsp;</td></tr>
<?php
	if(!isset($error)) {
		$error = 0;
	}
	else if($error == 1) {
		print("<tr><td class=\"item\" colspan=\"2\"><b class=\"alarm\">You have not entered a valid e-mail address.</b></td></tr>");
	}
	else if($error == 2) {
		print("<tr><td class=\"item\" colspan=\"2\"><b class=\"alarm\">You have not entered any text in the body of your message.</b></td></tr>");
	}
?>
         <tr>
          <td class="item" width="200">Your E-mail address: </td>
          <td class="item" width="500"><input type="text" name="email_address" size="30" maxlength="256"></td>
          </td>
         </tr>
         <tr>
          <td class="item" width="200" valign="top">Questions and/or Comments: </td>
          <td class="item" width="500"><textarea name="message_body" rows="5" cols="40"><?php print("$message_body"); ?></textarea></td>
         </tr>
         <tr>
          <td class="item" colspan="2"><input type="submit" value="Send Query"></td>
         </tr>
         </form>
        </table>
       </td>
      </tr>
     </table>
