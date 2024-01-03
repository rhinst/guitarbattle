<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "comment"); ?>
<? vilw_hidden("battle_id"); ?>
<br><br>
<table border="0" cellpadding="0" cellspacing="0">
  <tr>
    <td align="left">
      <b>Add a Comment:</b>
    </td>
  </tr>
  <tr>
    <td align="left">
      <? vilw_textarea("comment", 3, 50, ""); ?>
    </td>
  </tr>
  <tr>
    <td align="left">
      <input class="button" type="submit" value="Add Comment"> 
    </td>
  </tr>
</table>
</form>
