<?

include('gb.lib');

$res = vilw_query("select count(*) as count from battle_mp3s");
$num_mp3s = mysql_result($res, 'count', 0);
$res = vilw_query("select sum(length(file_contents)) as size from battle_mp3s");
$size_mp3s = mysql_result($res, 'size', 0);
$res = vilw_query("select count(*) as count from users");
$num_users = mysql_result($res, 'count', 0);
$res = vilw_query("select count(*) as count from users_temp");
$num_users_temp = mysql_result($res, 'count', 0);
$res = vilw_query("select count(*) as count from battles where winner=0 and user2!=0");
$num_open_battles = mysql_result($res, 'count', 0);
$res = vilw_query("select count(*) as count from battles where winner=0 and user2=0");
$num_unchallenged_battles = mysql_result($res, 'count', 0);
$res = vilw_query("select count(*) as count from battles where winner!=0");
$num_closed_battles = mysql_result($res, 'count', 0);

include('header.inc'); 

print "<table border=\"0\">\n";
print "<tr>\n";
print "<td align=\"left\">Number of MP3's in database:</td>\n";
print "<td align=\"left\">" . $num_mp3s . "</td>\n";
print "</tr>\n";
print "<tr>\n";
print "<td align=\"left\">Size of MP3's in database:</td>\n";
print "<td align=\"left\">" . readable_size($size_mp3s) . "</td>\n";
print "</tr>\n";
print "<tr>\n";
print "<td align=\"left\">Number of active user accounts:</td>\n";
print "<td align=\"left\">" . $num_users . "</td>\n";
print "</tr>\n";
print "<tr>\n";
print "<td align=\"left\">Number of user accounts pending confirmation:</td>\n";
print "<td align=\"left\">" . $num_users_temp . "</td>\n";
print "</tr>\n";
print "<tr>\n";
print "<td align=\"left\">Number of open battles:</td>\n";
print "<td align=\"left\">" . $num_open_battles . "</td>\n";
print "</tr>\n";
print "<tr>\n";
print "<td align=\"left\">Number of unchallenged battles:</td>\n";
print "<td align=\"left\">" . $num_unchallenged_battles . "</td>\n";
print "</tr>\n";
print "<tr>\n";
print "<td align=\"left\">Number of finished battles in vault:</td>\n";
print "<td align=\"left\">" . $num_closed_battles . "</td>\n";
print "</tr>\n";
print "</table>\n";

include('footer.inc');

?>
