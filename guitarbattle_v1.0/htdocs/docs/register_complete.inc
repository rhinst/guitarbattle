<?php
	$user_info = mysql_fetch_row(mysql_query("select username, firstname, lastname, email_address from users where id=$user_id"));
	$username = $user_info[0];
	$firstname = $user_info[1];
	$lastname = $user_info[2];
	$email_address = $user_info[3];
?>
     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700">
        <table width="700" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title">GuitarBattle.com Account Registration:</td>
         </tr>
         <tr>
          <td class="item">Your account has been successfully activated. The following is your account information:</td>
         </tr>
         <tr>
          <td class="item"><b>Username:</b> <?php print("$username"); ?></td>
         </tr>
         <tr>
          <td class="item"><b>First Name:</b> <?php print("$firstname"); ?></td>
         </tr>
         <tr>
          <td class="item"><b>Last Name:</b> <?php print("$lastname"); ?></td>
         </tr>
         <tr>
          <td class="item"><b>E-mail Address:</b> <?php print("$email_address"); ?></td>
         </tr>
         <tr>
          <td class="item"><br><br><a href="index.php?action=login" onMouseOver="window.status='Login'; return true;" onMouseOut="window.status=''; return true;">Click Here</a> to login now.</td>
         </tr>
        </table>
       </td>
      </tr>
     </table>
