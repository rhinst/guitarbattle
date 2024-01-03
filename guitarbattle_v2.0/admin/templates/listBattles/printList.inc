<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "delete"); ?>
<table class="item" width="300" border="0" cellpadding="4" cellspacing="0">
 <tr>
  <th colspan="5" align="left">Results: <? print(count($battles)); ?> Battle<? print(((count($users) == 1) ? "":"s")); ?> Found</th>
 </tr>
 <tr>
<? if($mode == "deleteBattle") { ?>
  <th></th>
<? } ?>
  <th>ID</th>
  <th>User 1</th>
  <th>User 2</th>
  <th>Timestamp</th>
 </tr>
<?
	$row_num = 1;
	foreach($battles as $battle) {
		vilw_result_globalize($battles_cols, $battle);
?>
<tr>
<? if($mode == "deleteBattle") { ?>
 <td class="row<?print($row_num); ?>"><input type="checkbox" name="delete_battles[]" value="<? print $id; ?>"></td>
<? } ?>
 <td class="row<? print($row_num); ?>"><a href="battleInfo.php?battle_id=<? print($id); ?>"><? print($id); ?></a></td>
 <td class="row<? print($row_num); ?>"><? print($user1); ?></td>
 <td class="row<? print($row_num); ?>"><? print($user2); ?></td>
 <td class="row<? print($row_num); ?>"><? print($timestamp); ?></td>
</tr>
<?
		$row_num = ($row_num == 1) ? 2:1;
	}
?>
<? if($mode == "deleteBattle") { ?>
 <tr>
  <th colspan="5" align="left"><input type="submit" value="Delete Battles"></th>
 </tr>
<? } ?>
</table>
</form>
