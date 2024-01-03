<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("step", $next_step); ?>
<? vilw_hidden("start_battle_id"); ?>
<br>
<table class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title" colspan="2">
      Please make sure the settings below are correct, and then click 'Finish' to create your battle.
    </td>
  </tr>
  <tr>
    <td align="right" class="listing_row1">
      <b>Genre:</b>
    </td>
    <td align="left" class="listing_row1">
      <? print get_genre_name($new_genre); ?>
    </td>
  </tr>
  <tr>
    <td align="right" class="listing_row2">
      <b>Opponent:</b>
    </td>
    <td align="left" class="listing_row2">
      <? print ($new_challenger)?($new_challenger):("Open Battle"); ?>
    </td>
  </tr>
  <tr>
    <td align="right" class="listing_row1">
      <b>Backing:</b>
    </td>
    <td align="left" class="listing_row1">
      <? print ($new_backing)?("Same backing battle"):("Any backing allowed"); ?>
    </td>
  </tr>
  <tr>
    <td align="right" class="listing_row2">
      <b>Collab. Partner:</b>
    </td>
    <td align="left" class="listing_row2">
      <? print ($new_collab1)?($new_collab1):("Solo Battle"); ?>
    </td>
  </tr>
  <tr>
    <td align="right" class="listing_row1">
      <b>MP3 File:</b>
    </td>
    <td align="left" class="listing_row1">
      <? print htmlspecialchars($mp3_file_name); ?>
    </td>
  </tr>
  <tr>
    <td align="right" class="listing_row2">
      <b>Song Name:</b>
    </td>
    <td align="left" class="listing_row2">
      <? print htmlspecialchars($mp3_song_name); ?>
    </td>
  </tr>
  <tr>
    <td align="left">
      <input class="button" type="button" value="Back" onClick="location='<? print $PHP_SELF; ?>?step=<? print $prev_step; ?>';">
    </td>
    <td align="right">
      <input class="button" type="submit" value="Finish">
    </td>
  </tr>
  <tr>
</table>
</form>
