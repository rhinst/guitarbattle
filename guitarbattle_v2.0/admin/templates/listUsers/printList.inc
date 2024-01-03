<script language="javascript">
<!--//
function confirmDelete() {
	return(confirm('Are you sure you want to delete these users?'));	
}
//-->
</script>


<form action="<? print $PHP_SELF; ?>" method="post" onSubmit="return(confirmDelete());">
<? vilw_hidden("action", "delete"); ?>
<table class="item" border="0" cellpadding="4" cellspacing="0">
 <tr>
  <th colspan="8" align="left">Results: <? print(count($users)); ?> User<? print(((count($users) == 1) ? "":"s")); ?> Found</th>
 </tr>
 <tr>
  <? if($mode == "cancelUser") { ?>
  <th></th>
  <? } ?>
  <th>Username</th>
  <th>E-mail Address</th>
  <th>First Name</th>
  <th>Last Name</th>
  <th>Country</th>
  <th>Join Date</th>
  <th>IP Address</th>
 </tr>
<?
	$row_num = 1;
	foreach($users as $user) {
		vilw_result_globalize($users_cols, $user);
?>
<tr>
 <? if($mode == "cancelUser") { ?>
 <td class="row<? print($row_num); ?>"><input type="checkbox" name="delete_users[]" value="<? print $username; ?>"></td>
 <? } ?>
 <td class="row<? print($row_num); ?>"><a href="userInfo.php?username=<? print($username); ?>"><? print($username); ?></a></td>
 <td class="row<? print($row_num); ?>"><? print($eml_addr); ?></td>
 <td class="row<? print($row_num); ?>"><? print($fn); ?></td>
 <td class="row<? print($row_num); ?>"><? print($ln); ?></td>
 <td class="row<? print($row_num); ?>"><? print($country); ?></td>
 <td class="row<? print($row_num); ?>"><? print($join_date); ?></td>
 <td class="row<? print($row_num); ?>"><? print($ip_addr); ?></td>
</tr>
<?
		$row_num = ($row_num == 1) ? 2:1;
	}
?> 
<? if($mode == "cancelUser") { ?>
 <tr>
  <th colspan="8" align="left"><input type="submit" value="Delete Users"></th>
 </tr>
<? } ?>
</table>
 </form>
