<table class="item" border="0" cellpadding="4" cellspacing="0">
 <tr>
  <th align="left">Mailing <? print count($users); ?> Users:</th>
 </tr>
<?
foreach($users as $user) { 
  vilw_result_globalize($users_cols, $user, "user_");
?>
 <tr>
  <td><? print $user_username; ?> (<? print $user_eml_addr; ?>)</td>
 </tr>
 </tr>
<? } ?>
</table>
