<script language="javascript">
<!--//
function confirmRemove() {
	return(confirm('Are you sure you want to remove this user from this battle?'));
}
//-->
</script>

<table class="item" border="0" cellpadding="4" cellspacing="0">
 <tr>
  <th colspan="3" align="left">Battle Information</th>
 </tr>
 <tr>
  <td>User 1:</td>
  <td>
    <? print $battle_user1; ?>
  </td>
  <td>
  <? if($battle_user2) { ?>
    <form action="<? print $PHP_SELF; ?>" method="post" onSubmit="return(confirmRemove());">
    <? vilw_hidden("action", "remove_user1"); ?>
    <? vilw_hidden("battle_id"); ?>
    <input type="submit" value="Remove User">
    </form>
  <? } ?>
  </td>
 </tr>
 <tr>
   <td>
     Reupload File: 
   </td>
   <td>
     <form action="<? print $PHP_SELF; ?>" method="post" enctype="multipart/form-data">
     <? vilw_hidden("action", "reupload1"); ?>
     <? vilw_hidden("battle_id"); ?>
     <input type="file" name="song">
   </td>
   <td>
     <input type="submit" value="Reupload">
     </form>
   </td>
 </tr>
 <tr>
  <td>User 2:</td>
  <td>
    <? print $battle_user2; ?>
  </td>
  <td>
  <? if($battle_user2) { ?>
    <form action="<? print $PHP_SELF; ?>" method="post" onSubmit="return(confirmRemove());">
    <? vilw_hidden("action", "remove_user2"); ?>
    <? vilw_hidden("battle_id"); ?>
    <input type="submit" value="Remove User">
    </form>
  <? } ?>
  </td>
 </tr>
<? if($battle_user2) { ?>
 <tr>
   <td>
     Reupload File: 
   </td>
   <td>
     <form action="<? print $PHP_SELF; ?>" method="post" enctype="multipart/form-data">
     <? vilw_hidden("action", "reupload2"); ?>
     <? vilw_hidden("battle_id"); ?>
     <input type="file" name="song">
   </td>
   <td>
     <input type="submit" value="Reupload">
     </form>
   </td>
 </tr>
<? } ?>
 <tr>
  <td>
  <? if($battle_user2 == '') { ?>
    Date Created:
  <? } else { ?>
    Date Started:
  <? } ?>
  </td>
  <td colspan="2"><? print mysql_datetime_printable($battle_timestamp); ?></td>
 </tr>
</table>
