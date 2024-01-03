<?

include('templates/general/header.inc');

switch($action) {
case "mail_pw":
	$userInfo = get_user_info_by_email($email_addr);
	vilw_result_globalize($users_cols, $userInfo, "user_");
	$message = "You are receiving this message because you requested a password reminder for your account at " .  $sitename . ". If you did not request any such reminder, someone may be attempting to gain access to your account, or may have used your e-mail address for their own account. If this is the case, please e-mail " . $info_email . " and we will assist you.\n\nUsername: " . $user_username . "\nPassword: " . base64_decode($user_password) . "\n";
	mail($user_eml_addr, $sitename . " Password Reminder", $message, "From: Password Reminder <" . $info_email . ">");
	include('templates/forgotPassword/sent.inc');
	break;
default:
	include('templates/forgotPassword/form.inc');
	break;
}

include('templates/general/footer.inc'); 
?>
