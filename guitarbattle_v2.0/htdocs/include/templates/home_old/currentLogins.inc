			<table border="0" cellpadding="3" cellspacing="0"><tr><td>
                        <table class="items" width="175" border="0" cellpadding="4" cellspacing="0">
			  <tr>
			    <td class="item_title" width="175">Currently Logged In:</td>
			  </tr>
			  <tr>
			    <td>
<?
	while($login = current($logins)) {
		vilw_result_globalize($logins_cols, $login, "login_");
                print "<a href=\"" . $baseURL . "/viewProfile.php?username=" . $login_username . "\">" . $login_username . "</a>";
		if(next($logins)) {
			print(", ");
		}
	}
	if(count($logins) == 0) {
		print "&nbsp;";
	}
?>
			    </td>
			  </tr>
                        </table>
			</td></tr></table>
