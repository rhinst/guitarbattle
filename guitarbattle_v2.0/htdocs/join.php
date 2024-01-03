<?php

	switch($action) {
		case("join"): {
			//Form Check
			if($fn == "") {
				$error = "You must enter your first name.";
			}

			else if($ln == "") {
				$error = "You must enter your last name.";
			}

			else if($address == "") {
				$error = "You must enter your address.";
			}

			else if($city == "") {
				$error = "You must enter your city.";
			}

			else if(($state == "") && ($country == "") && ($province == "")) {
				$error = "You must select your state or province and country.";
			}

			else if($zip == "") {
				$error = "You must enter your zip/postal code.";
			}

			else if($country == "") {
				$error = "You must select your country.";
			}

			else if(($state == "") && ($country == "US")) {
				$error = "You must select your state.";
			}

			else if(($province == "") && ($country != "US")) {
				$error = "You must enter your province.";
			}

			else if($eml_addr == "") {
				$error = "You must enter your e-mail address.";
			}

			else if(!ereg('^((([0-9]|[A-Za-z]|[\.\-_])+\.?([0-9]|[A-Za-z]|[\.\-_])+))+\@{1}(([0-9]|[A-Za-z]|[\-_])+\.?([0-9]|[A-Za-z]|[\-_])+)+\.[A-Za-z]{2,4}$', $eml_addr)) {
				$error = "The e-mail address that you have entered is not a valid address.";
			}

			else if(($username == "") || (!ereg('^([0-9]|[a-z])+$', $username))) {
				$error = "You have not entered a valid username.  Please make sure that the username you have entered is between 4 and 16 characters in length, entirely in lowercase and alphanumeric only.";
			}

			else if(($password == "") || (!ereg('^([0-9]|[a-z])+$', $password) && (strlen($password) > 3))) {
				$error = "You have not entered a valid password.  Please make sure that the password you have entered is between 4 and 16 characters in length, entirely in lowercase and alphanumeric only.";
			}

			else if($password_verify != $password) {
				$error = "Your password does not match the re-entered password.";
			}

			else if(!$accept_terms) {
				$error = "You cannot continue unless you have read and agree to the User Agreement.";
			}

			//Check Temporary User Table for Existing Users:
			$res = vilw_query("select count(*) from " . $users_temp_table . " where username='" . $username . "'");
			$num_temp_users = mysql_fetch_row($res);
			if($num_temp_users[0] > 0) {
				$error = "The username you have selected is already in use.  Please select a different username.";
			}

			//Check User Table for Existing Users:
			$res = vilw_query("select count(*) from " . $users_table . " where username='" . $username . "'");
			$num_users = mysql_fetch_row($res);
			if($num_users[0] > 0) {
				$error = "The username you have selected is already in use.  Please select a different username.";
			}

			//Check Temporary User Table for E-mail Address:
			$res = vilw_query("select count(*) from " . $users_temp_table . " where eml_addr='" . $eml_addr . "'");
			$num_temp_users = mysql_fetch_row($res);
			if($num_temp_users[0] > 0) {
				$error = "You have already registered an account from this location.";
			}

			//Check User Table for E-mail Address:
			$res = vilw_query("select count(*) from " . $users_table . " where eml_addr='" . $eml_addr . "'");
			$num_users = mysql_fetch_row($res);
			if($num_users[0] > 0) {
				$error = "You have already registered an account from this location.";
			}

			$ip_addr = $REMOTE_ADDR;

			//Check Temporary User Table for IP Address:
			$res = vilw_query("select count(*) from " . $users_temp_table . " where ip_addr='" . $ip_addr . "'");
			$num_temp_users = mysql_fetch_row($res);
			if($num_temp_users[0] > 0) {
				$error = "You have already registered an account from this location.";
			}

			//Check User Table for IP Address:
			$res = vilw_query("select count(*) from " . $users_table . " where ip_addr='" . $ip_addr . "'");
			$num_users = mysql_fetch_row($res);
			if($num_users[0] > 0) {
				$error = "You have already registered an account from this location.";
			}

			if(!$error) {
				//Form Passed Check

				//Insert Into Temporary Users Table:
				$join_date = date("YmdHis");
				$password = base64_encode($password);
				$confirm_id = $password . base64_encode($username);
				vilw_query(vilw_sql_insert($users_temp_cols, $users_temp_table));

				//Send Confirmation E-mail:
				$confirmation_link = $baseURL . "/confirm.php?confirm_id=" . $confirm_id . "&username=" . $username;
				$confirmation_subject = $sitename . " Account Confirmation";
				$confirmation_message = "This is an automatically generated response. Please do not reply to this e-mail.  Please contact " . $webmaster_email . " for further assistance or information.\n\nHere is your account confirmation link:\n\n" . $confirmation_link . "\n\n-----\nAfter clicking on the confirmation link above, your account will be activated.  Please remember that only one " . $sitename . " account is allowed per person.";

				$mail_res = mail($eml_addr, $confirmation_subject, $confirmation_message, "From: " . $info_email);
				if($mail_res) {
					header("Location: joinComplete.php");
				}
				else {
					//Failed to send confirmation e-mail.
					print("CONFIRMATION MAIL FAILED TO BE SENT");
				}
			}
			break;
		}
		default: {
			//Display Signup Form Normally.
			break;
		}
	}

	$user_agreement_text = fread(fopen("tos.txt", "r"), filesize("tos.txt"));

	include('templates/general/header.inc');
?>
<script language="JavaScript">
function check_form() {
        var f = document.join_form;

        if(f.fn.value == '') {
                alert('You must enter your first name.');
                f.fn.focus();
                return false;
        }

        if(f.ln.value == '') {
                alert('You must enter your last name.');
                f.ln.focus();
                return false;
        }

        if(f.address.value == '') {
                alert('You must enter your address.');
                f.address.focus();
                return false;
        }

        if(f.city.value == '') {
                alert('You must enter your city.');
                f.city.focus();
                return false;
        }

        if(f.country.value == '') {
                alert('You must enter your country.');
                f.country.focus();
                return false;
        }

        if(f.state.value == '' && f.country.value == 'US') {
                alert('You must enter your state.');
                f.state.focus();
                return false;
        }

        if(f.province.value == '' && f.country.value != 'US') {
                alert('You must enter your province.');
                f.province.focus();
                return false;
        }

        if(f.zip.value == '') {
                alert('You must enter your zip/postal code.');
                f.zip.focus();
                return false;
        }

        if(f.eml_addr.value == '') {
                alert('You must enter your e-mail address.');
                f.eml_addr.focus();
                return false;
        }

        if(f.username.value == '') {
                alert('You must enter a username.');
                f.username.focus();
                return false;
        }

        if(f.password.value == '') {
                alert('You must enter a password.');
                f.password.focus();
                return false;
        }

        if(f.password_verify.value != f.password.value) {
                alert('Your password does not match the re-entered password.');
                f.password.focus();
                return false;
        }

        if(!f.accept_terms.checked) {
                alert('You cannot continue unless you have read and agree to the User Agreement.');
                f.user_agreement_text.focus();
                return false;
        }

        return true;
}
</script>
  <br>
  <table class="items" width="500" border="0" cellpadding="4" cellspacing="0">
   <form method="POST" action="<?php print($PHP_SELF); ?>" name="join_form" onSubmit="return(check_form())">
   <?php vilw_hidden("action", "join"); ?>
   <tr><td class="item_title" colspan="4"><b>Join <? print $sitename; ?>:</b></td></tr>
<?php
	if($error) {
		print("<tr><td width=\"500\" colspan=\"4\"><b class=\"error\">Error: " . $error . "</b></td></tr>");
	}
?>
   <tr><td class="smalltext" colspan="4">(Fields in <b class="red">red</b> are optional.)</td></tr>
   <tr><td colspan="4"><b>Personal Information:</b></td></tr>
   <tr><td width="110">First Name:</td><td width="390" colspan="3"><?php vilw_input("fn", 20, "", "class=\"textbox\""); ?></td></tr>
   <tr><td>Last Name:</td><td colspan="3"><?php vilw_input("ln", 20, "", "class=\"textbox\""); ?></td></tr>
   <tr><td>Address:</td><td colspan="3"><?php vilw_input("address", 40, "", "class=\"textbox\""); ?></td></tr>
   <tr><td>City:</td><td colspan="3"><?php vilw_input("city", 40, "", "class=\"textbox\""); ?></td></tr>
   <tr><td>State:</td><td><?php vilw_stateselect("state"); ?></td><td width="110">or Province:</td><td><?php vilw_input("province", 20, "", "class=\"textbox\""); ?></td></tr>
   <tr><td>Zip/Postal Code:</td><td colspan="3"><?php vilw_input("zip", 10, "", "class=\"textbox\""); ?></td></tr>
   <tr><td>Country:</td><td colspan="3"><?php vilw_countryselect("country"); ?></td></tr>
   <tr><td>E-mail Address:</td><td colspan="3"><?php vilw_input("eml_addr", 40, "", "class=\"textbox\""); ?></td></tr>
   <tr><td><b class="red">Phone Number:</b></td><td colspan="3"><?php vilw_input("telephone", 20, "", "class=\"textbox\""); ?></td></tr>
   <tr><td colspan="4"><b>User Agreement:</b></td></tr>
   <tr><td>&nbsp;</td><td colspan="3"><?php vilw_textarea("user_agreement_text", 5, 60); ?></td></tr>
   <tr><td>&nbsp;</td><td colspan="3"><?php vilw_checkbox("accept_terms", 0); ?> I have read and agree to the User Agreement.</td></tr>
   <tr><td>&nbsp;</td><td class="smalltext" colspan="3"><?php vilw_checkbox("public", 1); ?> Yes! <? print $sitename; ?> may make the information that I supply available to selected companies so that they may contact me regarding products or services that may be of interest to me.</td></tr>
   <tr><td colspan="4"><b>Member Information:</b></td></tr>
   <tr><td>Username:</td><td colspan="3"><?php vilw_input("username", 20, "", "maxlength=\"16\" class=\"textbox\""); ?></td></tr>
   <tr><td>Password:</td><td colspan="3"><input type="password" name="password" maxlength="16"></td></tr>
   <tr><td>Verify Password:</td><td colspan="3"><input type="password" name="password_verify" maxlength="16"></td></tr>
   <tr><td colspan="4" align="center"><input class="button" type="submit" value="Submit"></td></tr>
   </form>
  </table>
<? include('templates/general/footer.inc'); ?>
