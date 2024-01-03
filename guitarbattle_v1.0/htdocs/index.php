<?php
	//Under Construction Page:
	//include('construction_redirect.php');

	include('gb.lib');
	//include('counter.php');
	//hits();
	include('header.inc');
	if(isset($login_error)) {
		include('not_logged_in.inc');
	}
	else if(!isset($action)) {
		if(!isset($location)) {
			$location = 'home';
		}
		switch($location) {
			case('home'): {
				include('home.inc');
				break;
			}
			case('help'): {
				include('help.inc');
				break;
			}
			case('utilities'): {
				include('utilities.inc');
				break;
			}
			case('links'): {
				include('links.inc');
				break;
			}
			case('submit_link'): {
				include('submit_link.inc');
				break;
			}
			case('contact'): {
				include('contact_us.inc');
				break;
			}
			case('forgotinfo'): {
				include('forgotinfo.inc');
				break;
			}
			case('passwd_reset'): {
				include('passwd_reset.inc');
				break;
			}
			case('register_success'): {
				include('register_success.inc');
				break;
			}
			case('register_fail'): {
				include('register_fail.inc');
				break;
			}
			case('register_complete'): {
				include('register_complete.inc');
				break;
			}
		}
	}
	else {
		switch($action) {
			case('login'): {
				include('login.inc');
				break;
			}
			case('changepasswd'): {
				if(!$login) {
					include('not_logged_in.inc');
				}
				else {
					include('changepasswd.inc');
				}
				break;
			}
			case('join'): {
				include('join.inc');
				break;
			}
			case('error'): {
				include('error.inc');
				break;
			}
			case('contact_us_sent'): {
				include('contact_us_sent.inc');
				break;
			}
		}
	}
	include('footer.inc');
?>
