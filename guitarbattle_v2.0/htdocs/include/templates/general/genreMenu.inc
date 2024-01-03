<table width="150" border="0" cellspacing="0" cellpadding="3">
<tr>
  <td class="menu_text" colspan="2" align="center">
    Browse By Genre:<br><br>
  </td>
</tr>
<?
$i = 0;
foreach($genres as $genre) {
  vilw_result_globalize($genres_cols, $genre, "genre_");
  $res = vilw_query("select count(*) as numbattles from battles where genre='" . $genre_id . "' and hide='0' and active='1'");
  $num_battles = mysql_result($res, 0, 'numbattles');
  if($i % 2 == 0) {
    print "<tr>\n";
  } 
?>
    <td width="75" align="left"><a class="menu_link" href="<? print $baseURL . "/listBattles.php?genre=" . $genre_id; ?>"><? print $genre_name . "(" . $num_battles . ")"; ?></a></td>    
<?
  if($i % 2 == 1) {
    print "</tr>\n";
  } 
  $i++;
}

if($i % 2 == 0) {
  print "<td>&nbsp;</td>\n</tr>\n";
} 
?>
</table>
