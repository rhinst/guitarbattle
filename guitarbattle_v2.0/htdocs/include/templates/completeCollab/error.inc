<table class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title">
      Error Starting Battle
    </th>
  </tr>
  <tr>
    <td align="center">
      <? print htmlspecialchars($err_msg); ?>
    </td>
  </tr>
  <tr>
    <td align="center">
      <form action="<? print $PHP_SELF; ?>" method="post">
        <? vilw_hidden("battle_id"); ?>
        <input class="button" type="submit" value="Back">
      </form>
    </td>
  </tr>
</table>
