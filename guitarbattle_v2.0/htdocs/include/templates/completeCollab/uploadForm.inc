<form action="<? print $PHP_SELF; ?>" method="post" enctype="multipart/form-data">
<? vilw_hidden("action", "upload"); ?>
<? vilw_hidden("battle_id"); ?>
<table class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title" colspan="3">
      Upload Final Version
    <td>
  </tr>
  <tr>
    <td align="right">
      Upload MP3:
    </td>
    <td align="right">
      <input type="file" name="song">
    </td>
    <td align="center">
      <input class="button" type="submit" value="Upload">
    </td>
  </tr>
</table>
</form>
