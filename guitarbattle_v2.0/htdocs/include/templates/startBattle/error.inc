<br>
<table class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title">
      Error Starting Battle:
    </th>
  </tr>
  <tr>
    <td align="center">
      <? print htmlspecialchars($err_msg); ?>
    </td>
  </tr>
<? if($prev_step != "") { ?>
  <tr>
  <form action="<? print $PHP_SELF; ?>" method="post">
  <? vilw_hidden("step", $prev_step); ?>
  <? vilw_hidden("battle_id"); ?>
    <td align="center">
        <input class="button" type="submit" value="Back">
    </td>
  </form>
  </tr>
<? } ?>
</table>
