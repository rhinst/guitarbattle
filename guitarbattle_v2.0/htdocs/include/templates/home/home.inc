<table width="100%" border="0" cellspacing="0" cellpadding="0">
  <tr valign="top">
    <td style="font-size: 0px" colspan="2">
      <? include('templates/home/news.inc'); ?>
    </td>
    <td width="204" align="center">
      <?
        $user_profile_info = get_random_user_profile();
        vilw_result_globalize($profiles_cols, $user_profile_info, "featured_profile_");
        include('templates/home/featured.inc'); 
      ?>
    </td>
    <td>
      &nbsp;
    </td>
  </tr>
  <tr valign="top">
    <td align="center" style="font-size: 0px">
      <?
	$battles = get_battle_list("not-complete", "", "", "", 10, "timestamp", "desc");
       	include('templates/home/newBattles.inc'); 
      ?>  
    </td>
    <td align="center" style="font-size: 0px">
      <?
	$battles = vilw_result_array(vilw_query(vilw_sql_select($battles_cols, $battles_table, "where ((to_days(now()) - to_days(timestamp)) >= " . ($battle_duration - 2) . ") and active=1 and user2 != '' and hide='0' order by timestamp asc limit 10")));
       	include('templates/home/endingBattles.inc');
      ?>  
    </td>
    <td align="center">
      <?
	$logins = get_current_logins();
	include('templates/home/currentLogins.inc');
      ?>  
    </td>
  </tr>
</table>
<br>
<table width="100%" border="0" cellspacing="0" cellpadding="6">
  <tr>
    <td align="center">
      <table width="100%" border="0" cellspacing="0" cellpadding="4">
        <tr>
          <td height="21" width="100%" colspan="3" style="background-image: url('images/repeater_battle_listing.jpg');"><img src="images/left_battle_listing.jpg"></td>
        </tr>
        <tr>
          <td colspan="3" style="font-size: 6px;">&nbsp;</td>
        </tr>
<?
$genres = get_genres();
$i = 0;
foreach($genres as $genre) {
  vilw_result_globalize($genres_cols, $genre, "genre_");
  $res = vilw_query("select count(*) as numbattles from battles where genre='" . $genre_id . "' and hide='0' and active='1'");
  $num_battles = mysql_result($res, 0, 'numbattles');
  if($i % 3 == 0) {
    print "<tr valign=\"top\">\n";
  }
?>
        <td align="center">
          <?
            $battles = get_battle_list("", $genre_id, "", "", 10, "timestamp", "desc");
            include('templates/home/displayCategory.inc');
	    //print "-";
	  ?>
        </td>
<?
  if($i + 1 % 3 == 0) {
    print "</tr>\n";
  }
  $i++;
}

if($i + 1 % 2 == 0) {
  print "<td>&nbsp;</td>\n</tr>\n";
}
else if($i + 1 % 3 != 0) {
  print "<td>&nbsp;</td>\n<td>&nbsp;</td>\n</tr>\n";
}
?>
      </table>
    </td>
  </tr>
</table>
