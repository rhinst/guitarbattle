     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700">
        <table width="700" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title">Forgot Your Username and/or Password?:</td>
         </tr>
<?php
	if($error == 1) {
?>
         <tr>
          <td class="item"><b class="alarm">No accounts were found under the provided e-mail address.</b></td>
         </tr>
<?php
	}
?>
         <tr>
          <td class="small_print">If you cannot remember your your username or password please enter the e-mail address that you registered your account under so we may send you your username and your new password. You may then login to the site and change your password as you desire.<br><br></td>
         </tr>
         <form method="post" action="docs/action_handler.php?action=forgotinfo">
         <tr>
          <td class="item">E-mail address: <input type="text" name="email_address" size="45" maxlength="40"></td>
         </tr>
         <tr>
          <td class="item"><input type="submit" value="Submit"></td>
         </tr>
         </form>
         <tr>
          <td class="item"><br>If you are not currently a member please <a href="index.php?action=join" onMouseOver="window.status='Join GuitarBattle.com Now'; return true;" onMouseOut="window.status=''; return true;">Click Here</a> to join now.</td>
         </tr>
        </table>
       </td>
      </tr>
     </table>
