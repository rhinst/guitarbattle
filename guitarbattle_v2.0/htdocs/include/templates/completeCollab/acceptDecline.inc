<?
  if($authenticated_user == $battle_collab1) {
    $partner = $battle_user1;
  }
  else {
    $partner = $battle_user2;
  }

?>
<table class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td align="center">
      <? print $partner; ?> has invited you to collaborate with him on this piece. Will you accept the invitation?:
    </td>
  </tr>
  <tr>
    <td align="center">
      <form action="<? print $PHP_SELF; ?>" method="post">
        <? vilw_hidden("action", "accept"); ?>
        <? vilw_hidden("battle_id"); ?>
        <input class="button" type="submit" value="Yes">
      </form>
    </td>
  </tr>
  <tr>
    <td align="center">
      <form action="<? print $PHP_SELF; ?>" method="post">
        <? vilw_hidden("action", "decline"); ?>
        <? vilw_hidden("battle_id"); ?>
        <input class="button" type="submit" value="No">
      </form>
    </td>
  </tr>
</table>
