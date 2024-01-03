<?

include('templates/general/header.inc');
switch($action) {
case "mail":
	$user = (session_is_registered("authenticated_user"))?($authenticated_user):("An anonymous user");
	$message = $user . " wrote:\n" . $message;
	if(mail($webmaster_email, $subject, $message, "From: " . $email)) {
		include('templates/contact/success.inc'); 
	}
	else {
		include('templates/contact/fail.inc'); 
	}
	break;
default:
	include('templates/contact/form.inc'); 
	break;
}
include('templates/general/footer.inc');
?>
