<?

if(!($c)) {
	setcookie("test_cookie", "1");
	header("location: " . $PHP_SELF . "?c=1");
}

function checkOS() {

	$browser = $GLOBALS['HTTP_USER_AGENT'];

	if(stristr($browser, "Linux")) return ("Linux");
	if(stristr($browser, "Irix")) return ("Irix");
	if(stristr($browser, "Win")) {
		if(stristr($browser, "98")) return ("Windows 98");
		if(stristr($browser, "95")) return ("Windows 95");
		if(stristr($browser, "NT")) return ("Windows NT/2000/XP");
		if(stristr($browser, "16")) return ("Windows 3.x");
		return("Windows (Version Unknown");
	}
	if(stristr($browser, "SunOS")) return ("SunOS");
	if(stristr($browser, "Mac")) return ("Macintosh");
	if(stristr($browser, "WebTV")) return ("WebTV");
	if(stristr($browser, "HP")) return("HP-UX");
	if(stristr($browser, "X11")) return("X-Windows");

	return("Unknown");
}

$osVersion = checkOS();

include('templates/general/header.inc');
switch($action) {
case "report":
	$report = "The following bug report was submitted from " . $REMOTE_ADDR;
	$report .= " by ";
	if(session_is_registered("authenticated_user")) {
		$report .= $authenticated_user . ":\n";
	}
	else {
		$report .= " an anonymous user:\n";
	}
	$report .= "Date: " . date("m/d/Y H:i") . "\n";
	$report .= "Operating System: " . $osVersion . "\n";	
	$report .= "Browser String: " . $browserVersion . "\n";	
	$report .= "Screen Resolution: " . $screenRes . "\n";
	$report .= "Color Depth: " . $colorDepth . "\n";
	$report .= "Java Enabled: " . $javaEnabled . "\n";
	$report .= "JavaScript Version: " . $jsVersion . "\n";
	$report .= "Cookies Enabled: " . (($test_cookie)?("Yes"):("No")) . "\n\n";
	$report .= "Problem: " . $problem . "\n";
	mail($bugs_email, "BUG REPORT",  $report, "From: " . $sitename . " Bugs Page <" . $bugs_email . ">");
	include('templates/bugReport/thankYou.inc');
	break;
default:
	include('templates/bugReport/form.inc');
}
include('templates/general/footer.inc'); 
?>

