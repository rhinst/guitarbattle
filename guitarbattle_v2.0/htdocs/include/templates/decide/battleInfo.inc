<br>
<table class="items" width="300" border="0" cellspacing="0" cellpadding="4">
  <tr valign="top">
    <td class="item_title" colspan="2" align="center">
      Battle Information:
    </td>
  </tr>
  <tr valign="top">
    <td>
      <?
	if($battle_user2 == '') {
		print "<b>Battle Created:</b>";
	}
	else {
		print "<b>Battle Started:</b>";
	}
      ?>
    </td>
    <td align="left">
      <? print mysql_datetime_printable($battle_timestamp); ?>
    </td>
  </tr>
<? 
  if($battle_user2) {
    $res = vilw_query("select (to_days(now()) - to_days(timestamp)) as age from battles where id='" . $battle_id . "'");
    $battle_age = mysql_result($res, 0, 'age');
    $days_left = $battle_duration - $battle_age - 1;
 ?>
 <? if($days_left >= 0) { ?>
  <tr>
    <td>
      <b>Battle Ends:</b>
    </td>
    <td>
      <? print (($days_left == 0)?("Today"):("In " . $days_left . " Day" . (($days_left == 1)?(""):("s")))); ?>
    </td>
  </tr>
 <? } ?>
<? } ?>
  <tr valign="top">
    <td>
      <b>Type:</b>
    </td>
    <td>
      <?
	if($battle_backing != 0) {
		print "Same Backing<br>\n";
	}
	if($battle_challenger != '') {
		print "Invite-only<br>\n";
	}
	else {
		print "Open Battle<br>\n";
	}
      ?>
    </td>
  </tr>
  <tr valign="top">
    <td>
      <b>Genre:</b>
    </td>
    <td>
      <? print get_genre_name($battle_genre); ?>
    </td>
  </tr>    
<? if($battle_backing != 0) { ?>
  <tr valign="top">
    <td>
      <b>Backing:</b>
    </td>
    <td align="left">
      <a href="loadSong.php?id=<? print $battle_backing; ?>">Download Backing</a>
    </td>
  </tr>    
<? } ?>
</table>
