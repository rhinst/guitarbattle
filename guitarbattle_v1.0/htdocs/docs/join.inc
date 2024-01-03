<script language="JavaScript">
function check_form() {
	var f = document.join_form;

	if(f.firstname.value == '') {
		alert('You must enter your first name');
		f.firstname.focus();
		return false;
	}

	if(f.lastname.value == '') {
		alert('You must enter your last name');
		f.lastname.focus();
		return false;
	}

	if(f.email_address.value == '') {
		alert('You must enter your e-mail address');
		f.email_address.focus();
		return false;
	}

	if(f.username.value == '') {
		alert('You must enter a username');
		f.username.focus();
		return false;
	}

	if(f.password.value == '') {
		alert('You must enter a password');
		f.password.focus();
		return false;
	}	

	if(f.password_verify.value != f.password.value) {
		alert('Passwords do not match');
		f.password.focus();
		return false; 
	}

	if(!f.accept_terms.checked) {
		alert('You cannot continue unless you have read and agree to the User Agreement');
		f.user_agreement_text.focus();
		return false;
	}

	return true;
}
</script>

     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700">
        <table width="700" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title" colspan="2">Join GuitarBattle.com:</td>
         </tr>
         <tr>
          <td class="large" colspan="2">Join the GuitarBattle.com community now! Membership is absolutely free!</td>
         </tr>
         <tr>
          <td class="item" colspan="2">GuitarBattle.com membership allows you to vote on all battles, post messages and, most importantly, compete in head-to-head battles with other users. What are you waiting for? <b>Get started and register now for FREE</b>.</td>
         </tr>
         <tr><td class="small_print" colspan="2">&nbsp;</td></tr>
         <tr>
          <td class="large" colspan="2">Account Information:</td>
         </tr>
<?php
	if(!isset($error)) {
		$error = "NONE";
	}
	switch($error) {
		case('NONE'): {
			break;
		}
		case(1): {
			print("         <tr><td class=\"item\" colspan=\"2\"><b class=\"alarm\">You have not entered a valid first and/or last name. These entries must be at least 3 characters in length.</b></td></tr>");
			break;
		}
		case(2): {
			print("         <tr><td class=\"item\" colspan=\"2\"><b class=\"alarm\">You have not entered a valid e-mail address. Please note that this e-mail address must be entered correctly in order to activate your account.</b></td></tr>");
			break;
		}
		case(3): {
			print("         <tr><td class=\"item\" colspan=\"2\"><b class=\"alarm\">You have not entered a valid username. Usernames must consist of between 4 to 16 lowercase, alphanumeric only characters.</b></td></tr>");
			break;
		}
		case(4): {
			print("         <tr><td class=\"item\" colspan=\"2\"><b class=\"alarm\">You have either not entered a valid password or your have not properly re-entered the password for verification. Passwords must consist of between 4 to 16 lowercase, alphanumeric only characters.</b></td></tr>");
			break;
		}
		case(5): {
			print("         <tr><td class=\"item\" colspan=\"2\"><b class=\"alarm\">The username you have selected is already in use. Please select a new username.</b></td></tr>");
			break;
		}
		case(6): {
			print("         <tr><td class=\"item\" colspan=\"2\"><b class=\"alarm\">An account is already registered under the e-mail address that you have specified.</b></td></tr>");
			break;
		}
		case(7): {
			print("         <tr><td class=\"item\" colspan=\"2\"><b class=\"alarm\">You must read and agree to the User Agreement below in order to proceed.</b></td></tr>");
			break;
		}
	}
?>
         <form method="post" action="docs/action_handler.php?action=register" name="join_form" onSubmit="return(check_form())">
         <tr>
          <td class="item_light" width="200">First Name: </td>
          <td class="item" width="500"><input type="text" name="firstname" value="<?php print("$firstname"); ?>" size="30" maxlength="16"></td>
         </tr>
         <tr>
          <td class="item_light" width="200">Last Name: </td>
          <td class="item" width="500"><input type="text" name="lastname" value="<?php print("$lastname"); ?>" size="30" maxlength="16"></td>
         </tr>
         <tr>
          <td class="item_light" width="200">E-mail Address: </td>
          <td class="item" width="500"><input type="text" name="email_address" value="<?php print("$email_address"); ?>" size="30" maxlength="40"></td>
         </tr>
         <tr>
          <td class="item_light" width="200">Username: </td>
          <td class="item" width="500"><input type="text" name="username" value="<?php print("$username"); ?>" size="30" maxlength="16"></td>
         </tr>
         <tr>
          <td class="item_light" width="200">Password: </td>
          <td class="item" width="500"><input type="password" name="password" value="<?php print("$password"); ?>" size="30" maxlength="16"></td>
         </tr>
         <tr>
          <td class="item_light" width="200">Re-enter Password: </td>
          <td class="item" width="500"><input type="password" name="password_verify" value="<?php print("$password_verify"); ?>" size="30" maxlength="16"></td>
         </tr>
         <tr><td class="small_print" colspan="2">&nbsp;</td></tr>
         <tr>
          <td class="large" colspan="2">User Agreement:</td>
         </tr>
         <tr>
          <td class="item" colspan="2"><textarea name="user_agreement_text" rows="5" cols="60"><?php include('agreement.txt'); ?></textarea></td>
         </tr>
         <tr>
          <td class="small_print" colspan="2"><input type="checkbox" name="accept_terms"> I have read and agree to the terms provided in the User Agreement.</td>
         </tr>
         <tr>
          <td class="small_print" colspan="2"><input type="checkbox" name="privacy" checked> Yes! GuitarBattle.com may make the information that I supply available to selected companies so that they may contact me regarding products or services that may be of interest to me.<br><br></td>
         </tr>
         <tr>
          <td class="item" colspan="2">After submitting this information you will receive a confirmation e-mail at the e-mail address that you entered in your account information. You must receive this e-mail and follow the confirmation link in order to activate your account.<br><br></td>
         </tr>
         <tr>
          <td class="item" colspan="2"><input type="submit" value="Submit Information"></td>
         </tr>
         </form>
        </table>
       </td>
      </tr>
     </table>
