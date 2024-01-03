<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("step", $next_step); ?>
<? vilw_hidden("battle_id"); ?>
<br>
<table class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title" colspan="2">
      Please make sure the settings below are correct, and then click 'Finish' to join this battle.
    </td>
  </tr>
  <tr>
    <td>
      MP3 File:
    </td>
    <td>
      <? print htmlspecialchars($mp3_file_name); ?>
    </td>
  </tr>
  <tr>
    <td>
      Song Name:
    </td>
    <td>
      <? print htmlspecialchars($mp3_song_name); ?>
    </td>
  </tr>
  <tr>
    <td align="left">
      <input class="button" type="button" value="Back" onClick="location='<? print $PHP_SELF; ?>?step=<? print $prev_step; ?>&battle_id=<? print $battle_id; ?>';">
    </td>
    <td align="right">
      <input class="button" type="submit" value="Finish">
    </td>
  </tr>
  <tr>
</table>
</form>
