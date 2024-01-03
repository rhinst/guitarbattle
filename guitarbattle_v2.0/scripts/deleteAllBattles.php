#!/usr/local/bin/php -q
<?
  /*
      This script will delete all battles, temp-battles, and their corresponding comments, votes, and mp3s.
  */

include('gb.lib');

/* Wait 5 seconds, which should hopefully be enough time for you to say
    "DOH!" and hit ctrl-c, if this isn't what you meant to do... */
sleep(5);

//Preserve backing mp3's
$backings = Array();

print "Deleting MP3s...";
$res = vilw_query("select mp3_id from " . $backings_table);
while($row = mysql_fetch_row($res)) {
	$backings[] = $row[0];
}


if(count($backings) > 0) {
	$wherecl = "where id not in (";
	while($mp3_id = current($backings)) {
		$wherecl .= $mp3_id;
		if(next($backings)) {
			$wherecl .= ",";
		}
	}
	$wherecl .= ")";

	//Delete songs
	vilw_query(vilw_sql_delete($mp3s_table, $wherecl));
}
print "Done\n";



//Delete comments
print "Deleting Battle Comments...";
vilw_query(vilw_sql_delete($comments_table, ""));
print "Done\n";

//Delete votes
print "Deleting Battle Votes...";
vilw_query(vilw_sql_delete($votes_table, ""));
print "Done\n";

//Delete temp-battles
print "Deleting Temp-battles...";
vilw_query(vilw_sql_delete($battles_temp_table, ""));
print "Done\n";

//Delete battles
print "Deleting Battles...";
vilw_query(vilw_sql_delete($battles_table, ""));
print "Done\n";
?>
