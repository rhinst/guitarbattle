<table class="item" border="0" cellpadding="4" cellspacing="0">
 <tr>
  <th align="left">Deleted <? print count($delete_users); ?> Battles:</th>
 </tr>
<? foreach($delete_battles as $del_battle) { ?>
 <tr>
  <td><? print $del_battle; ?></td>
 </tr>
 </tr>
<? } ?>
</table>
