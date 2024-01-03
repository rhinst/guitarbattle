<table class="item" border="0" cellpadding="4" cellspacing="0">
 <tr>
  <th align="left">Deleted <? print count($delete_users); ?> Users:</th>
 </tr>
<? foreach($delete_users as $del_user) { ?>
 <tr>
  <td><? print $del_user; ?></td>
 </tr>
 </tr>
<? } ?>
</table>
