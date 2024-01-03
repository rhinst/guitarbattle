     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700">
        <table width="700" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title" colspan="2">Login:</td>
         </tr>
<?php
	if($error == 1) {
?>
         <tr>
          <td class="item" colspan="2"><b class="alarm">You have entered an invalid username/password.</b><br><br></td>
         </tr>
<?php
	}
?>
         <form name="loginform" method="post" action="docs/action_handler.php?action=login">
          <input type="hidden" name="goto" value="<?php print("$goto"); ?>">
         <tr>
          <td class="item_light" width="100">Username: </td>
          <td class="item" width="600"><input type="text" name="username" size="20" maxlength="16"></td>
         </tr>
         <tr>
          <td class="item_light" width="100">Password: </td>
          <td class="item" width="600"><input type="password" name="password" size="20" maxlength="16"></td>
         </tr>
         <tr>
          <td class="item" colspan="2"><input type="submit" value="Login"></td>
         </tr>
         </form>
	 <script language="javascript">
	 <!-- //
	     document.loginform.username.focus();
	 // -->
	 </script>
         <tr>
          <td class="item" colspan="2"><br>Can't  remember your username and/or password? <a href="index.php?location=forgotinfo" onMouseOver="window.status='Forgot your username and/or password?'; return true;" onMouseOut="window.status=''; return true;">Click Here</a>.<br><br>If you are not currently a member please <a href="index.php?action=join" onMouseOver="window.status='Join GuitarBattle.com Now'; return true;" onMouseOut="window.status=''; return true;">Click Here</a> to join now.</td>
         </tr>
        </table>
       </td>
      </tr>
     </table>
