<?

include('gb.lib');
	
switch($action) {
case "getpass":
	$res = vilw_query("select password from users where username='" . $username . "'");
	if(mysql_num_rows($res)) {
		$password = base64_decode(mysql_result($res, 0, 'password'));
	}
	else {
		$errmsg = "User acount not found: " . $username;
	}
	break;
}
	
include('header.inc'); 

if(isset($password)) {
	print $username . "'s password is <b>" . $password . "</b><br>\n";
}
else if(isset($errmsg)) {
	print htmlspecialchars($errmsg) . "<br>\n";
}
?>


<form action="<? print $PHP_SELF; ?>" method="post">
<input type="hidden" name="action" value="getpass">
Username: <input type="text" name="username" value="">
<input type="submit" value="Get Password">
</form>

<? include('footer.inc'); ?>
