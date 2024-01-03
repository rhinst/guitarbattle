#!/usr/local/bin/php -q
<?

	// mysql info
	$db_host	= "localhost";
	$db_user	= "root";
	$db_pass	= "network";
	$db_name	= "guitarbattle";

	function init_sql() {
		global $db, $db_host, $db_user, $db_pass, $db_name;

		if(!($db = mysql_connect($db_host, $db_user, $db_pass))) {
			print "Error connecting to MySQL server!\n";
			exit;
		}

		mysql_select_db($db_name, $db);
	}

	function readable_size($bytes) {
        	$amount = $bytes;
        	$suffix = "bytes";
        	if($amount >= 1024) {
                	$suffix = "KB";
                	$amount = $amount / 1024;
        	}
	
        	if($amount >= 1024) {
                	$suffix = "MB";
                	$amount = $amount / 1024;
        	}
	
        	$amount = sprintf("%.2f", $amount);
	
        	return($amount . " "  . $suffix);
	}

	init_sql();
	
	print "\nGuitarBattle.com Stats\n";
	print "======================\n\n";

	if(!($res = mysql_query("select count(*) as count from battle_mp3s"))) {
		print "MySQL Error: " . mysql_error($db) . "\n";
		exit;
	}
	$num_mp3s = mysql_result($res, 'count', 0);

	if(!($res = mysql_query("select sum(length(file_contents)) as size from battle_mp3s"))) {
		print "MySQL Error: " . mysql_error($db) . "\n";
		exit;
	}
	$size_mp3s = mysql_result($res, 'size', 0);

	print "The database contains " . $num_mp3s . " mp3's (" . readable_size($size_mp3s) . ")\n";

	
	if(!($res = mysql_query("select count(*) as count from users"))) {
		print "MySQL Error: " . mysql_error($db) . "\n";
		exit;
	}
	$num_users = mysql_result($res, 'count', 0);

	print "There are " . $num_users . " active user accounts.\n";

	if(!($res = mysql_query("select count(*) as count from users_temp"))) {
		print "MySQL Error: " . mysql_error($db) . "\n";
		exit;
	}
	$num_users_temp = mysql_result($res, 'count', 0);

	print "There are " . $num_users_temp . " user accounts pending confirmation.\n";

	if(!($res = mysql_query("select count(*) as count from battles where winner=0 and user2!=0"))) {
		print "MySQL Error: " . mysql_error($db) . "\n";
		exit;
		
	}
	$num_open_battles = mysql_result($res, 'count', 0);

	print "There are " . $num_open_battles . " battles currently open.\n";

	if(!($res = mysql_query("select count(*) as count from battles where winner=0 and user2=0"))) {
		print "MySQL Error: " . mysql_error($db) . "\n";
		exit;
		
	}
	$num_unchallenged_battles = mysql_result($res, 'count', 0);

	print "There are " . $num_unchallenged_battles . " battles currently unchallenged.\n";

	if(!($res = mysql_query("select count(*) as count from battles where winner!=0"))) {
		print "MySQL Error: " . mysql_error($db) . "\n";
		exit;
		
	}
	$num_closed_battles = mysql_result($res, 'count', 0);

	print "There are " . $num_closed_battles . " finished battles currently in the vault.\n";

	if(!($res = mysql_query("select count(*) as count from battles where hide=1"))) {
		print "MySQL Error: " . mysql_error($db) . "\n";
		exit;
		
	}
	$num_hidden_battles = mysql_result($res, 'count', 0);

	print "There are " . $num_hidden_battles . " hidden battles currently awaiting decision.\n";

	print "\n";

?>
