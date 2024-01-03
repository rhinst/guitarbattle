<br>
<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("step", $next_step); ?>
<? vilw_hidden("battle_id"); ?>
<table width="400" class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title" colspan="2">
      Song Details 
    </td>
  </tr>
  <tr>
    <td colspan="2">
      <b>Step 6 (optional): </b>Enter details about your song, such as the name of the piece, notes, tablature, or any other information you'd like to accompany your piece.
    </td>
  </tr>
  <tr>
    <td>
      Song Name:
    </td>
    <td align="left">
      <? vilw_input("song_name", 30); ?>
    </td>
  </tr>
  <tr>
    <td colspan="2">
      Tablature/Notes:
    </td>
  </tr>
  <tr>
    <td colspan="2">
      <? vilw_textarea("notes", 8, 40); ?>
    </td>
  </tr> 
  <tr>
    <td align="left">
      <input class="button" type="button" value="Back" onClick="location='<? print $PHP_SELF; ?>?step=<? print $prev_step; ?>&battle_id=<? print $battle_id; ?>';">
    </td>
    <td align="right">
      <input class="button" type="submit" value="Next">
    </td>
  </tr>
</table>
</form>
