     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700">
        <table width="700" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title" colspan="2">Change Password:</td>
         </tr>
<?php
	if($error == 1){
?>
         <tr>
          <td class="item" colspan="2"><b class="alarm">You have either not entered a valid password or your have not properly re-entered the password for verification. Passwords must consist of between 4 to 16 lowercase, alphanumeric only characters.</b><br><br></td>
         </tr>
<?php
	}
?>
         <tr>
          <td class="small_print" colspan="2">Simply enter your new desired password then re-enter the new password in the second box. After you have entered your new password click on the "Change Password" button to finalize the change. Please make sure that the next time you login you use this new password. For more information please contact <a class="small" href="index.php?location=help" onMouseOver="window.status='Help'; return true;" onMouseOut="window.status=''; return true;">webmaster@guitarbattle.com</a>.<br><br></td>
         </tr>
         <form method="post" action="docs/action_handler.php?action=changepasswd">
         <tr>
          <td class="item" width="150"><b>New Password:</b> </td>
          <td class="item" width="550"><input type="password" name="password" size="20" maxlength="16"></td>
         </tr>
         <tr>
          <td class="item" width="150"><b>Re-enter Password:</b> </td>
          <td class="item" width="550"><input type="password" name="password_verify" size="20" maxlength="16"></td>
         </tr>
         <tr>
          <td class="item" colspan="2"><input type="submit" value="Change Password"></td>
         </tr>
         </form>
        </table>
       </td>
      </tr>
     </table>
