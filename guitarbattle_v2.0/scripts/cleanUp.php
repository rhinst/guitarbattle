#!/usr/local/bin/php -q
<?

/*
   This script will:
     - Delete any temp-battles older than a specified number of hours
     - Delete any pending user accounts older than a specified number of days 
     - Delete Profiles of users that don't exist anymore
     - Delete all comments linked to battles that don't exist anymore
     - Delete votes linked to battles that don't exist anymore
     - Delete any images not linked to a profile
     - Delete all mp3s that aren't linked to a backing, a temp-battle or a battle
     - Delete incomplete compilations older than a specified number of days
*/

include('gb.lib');

/* -------------------------------------------------------------------- */
/*  Delete Expired Temp-battles                                         */
/* -------------------------------------------------------------------- */

$expired_battles = Array();

//Find expired battles
$res = vilw_query("select id from " . $battles_temp_table . " where (now() <= (timestamp + INTERVAL " . $temp_battle_life . " HOUR))");
while($row = mysql_fetch_row($res)) {
	$expired_battles[] = $row[0];
}

//Delete expired battles
$wherecl = "where id in (";
while($battle_id = current($expired_battles)) {
	$wherecl .= $battle_id;
	if(next($expired_battles)) {
		$wherecl .= ",";
	}
}
$wherecl .= ")";

$n = count($expired_battles);
if($n == 0) {
	print "Found no expired temp-battles\n";
}
else {
	print "Deleting " . $n . " expired temp-battles...";
	vilw_query(vilw_sql_delete($battles_temp_table, $wherecl));
	print "Done\n";
}

/* -------------------------------------------------------------------- */
/*  Delete Expired Pending Accounts                                     */
/* -------------------------------------------------------------------- */

$expired_accounts = Array();

//Find expired accounts
$res = vilw_query("select username from " . $users_temp_table . " where (now() >= (join_date + INTERVAL " . $pending_account_life . " DAY))");
while($row = mysql_fetch_row($res)) {
	$expired_accounts[] = $row[0];
}

//Delete expired accounts
$wherecl = "where username in (";
while($username = current($expired_accounts)) {
	$wherecl .= "'" . $username . "'";
	if(next($expired_accounts)) {
		$wherecl .= ",";
	}
}
$wherecl .= ")";

$n = count($expired_accounts);
if($n == 0) {
	print "Found no expired pending account requests\n";
}
else {
	print "Deleting " . $n . " expired pending account requests...";
	vilw_query(vilw_sql_delete($users_temp_table, $wherecl));
	print "Done\n";
}

/* -------------------------------------------------------------------- */
/*  Delete Profiles of Non-existent Users                               */
/* -------------------------------------------------------------------- */

$existing_users = Array();

//Find existing users
$res = vilw_query("select username from " . $users_table);
while($row = mysql_fetch_row($res)) {
	$existing_users[] = $row[0];
}

//Delete all profiles that don't correspond to existing users
$wherecl = "where username not in (";
while($username = current($existing_users)) {
	$wherecl .= "'" . $username . "'";
	if(next($existing_users)) {
		$wherecl .= ",";
	}
}
$wherecl .= ")";

print "Deleting orphan profiles...";
vilw_sql_delete($profiles_table, $wherecl);
print "Done\n";

/* -------------------------------------------------------------------- */
/*  Delete Comments and Votes from non-existent battles                 */
/* -------------------------------------------------------------------- */

$existing_profiles = Array();

//Find existing profiles
$res = vilw_query("select username from " . $profiles_table);
while($row = mysql_fetch_row($res)) {
	$existing_profiles[] = $row[0];
}

//Delete all images that don't correspond to existing profiles
$wherecl = "where username not in (";
while($username = current($existing_profiles)) {
	$wherecl .= "'" . $username . "'";
	if(next($existing_profiles)) {
		$wherecl .= ",";
	}
}
$wherecl .= ")";

print "Deleting orphan images...";
vilw_sql_delete($images_table, $wherecl);
print "Done\n";


/* -------------------------------------------------------------------- */
/*  Delete Comments and Votes from non-existent battles                 */
/* -------------------------------------------------------------------- */

$existing_battles = Array();

//Find existing battles
$res = vilw_query("select id from " . $battles_table);
while($row = mysql_fetch_row($res)) {
	$existing_battles[] = $row[0];
}

//Delete all comments and votes that don't correspond to existing battles
$wherecl = "where battle_id not in (";
while($battle_id = current($existing_battles)) {
	$wherecl .= "'" . $battle_id . "'";
	if(next($existing_battles)) {
		$wherecl .= ",";
	}
}
$wherecl .= ")";

print "Deleting orphan comments...";
vilw_sql_delete($comments_table, $wherecl);
print "Done\n";
print "Deleting orphan votes...";
vilw_sql_delete($votes_table, $wherecl);
print "Done\n";

/* -------------------------------------------------------------------- */
/*  Delete Unused Mp3s                                                  */
/* -------------------------------------------------------------------- */

$used_mp3s = Array();

//Count total number of mp3s in database
$res = vilw_query("select count(*) as n from " . $mp3s_table);
$total_mp3s = mysql_result($res, 0, 'n');

// Find mp3's used in backings
$res = vilw_query("select mp3_id from " . $backings_table);
while($row = mysql_fetch_row($res)) {
	$used_mp3s[] = $row[0];
}

//Find mp3's used in battles
$res = vilw_query("select file1, file2 from " . $battles_table);
while($row = mysql_fetch_row($res)) {
	if($row[0] != 0) { $used_mp3s[] = $row[0]; }
	if($row[1] != 0) { $used_mp3s[] = $row[1]; }
}

//Find mp3's used in temp-battles
$res = vilw_query("select file1, file2 from " . $battles_temp_table);
while($row = mysql_fetch_row($res)) {
	if($row[0] != 0) { $used_mp3s[] = $row[0]; }
	if($row[1] != 0) { $used_mp3s[] = $row[1]; }
}

//Delete all mp3s that aren't being used by anything
$wherecl = "where id not in (";
while($mp3_id = current($used_mp3s)) {
	$wherecl .= $mp3_id;
	if(next($used_mp3s)) {
		$wherecl .= ",";
	}
}
$wherecl .= ")";

$n = ($total_mp3s - count($used_mp3s));
if($n == 0) {
	print "Found no orphan MP3 files\n";
}
else {
	print "Deleting " . $n . " orphan MP3 files...";
	vilw_query(vilw_sql_delete($mp3s_table, $wherecl));
	print "Done\n";
}

/* -------------------------------------------------------------------- */
/*  Delete Expired Compilations                                         */
/* -------------------------------------------------------------------- */

$compilations = vilw_result_array(vilw_query(vilw_sql_select($compilations_cols, $compilations_table, "where ((order_date + INTERVAL " . $compilation_life . " DAY) <= now()) AND (status = '')")));

print "Deleting " . count($compilations) . " expired compilations...";
foreach($compilations as $compilation) {
	vilw_result_globalize($compilations_cols, $compilation, "comp_");
	vilw_query(vilw_sql_delete($track_lists_table, "where compilation_id = '" . $comp_id . "'"));
	vilw_query(vilw_sql_delete($compilations_table, "where id = '" . $comp_id . "'"));
}
print "Done.\n";


?>
