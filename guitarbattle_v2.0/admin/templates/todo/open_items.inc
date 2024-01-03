<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "close"); ?>
<table width="500" class="item" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <th colspan="2" align="left">
      <? print count($open_items); ?> Open Items:
    </th>
  </tr>
<?
	$row_num = 1;
	if(count($open_items) == 0) {
?>
<tr>
 <td colspan="2" class="row<? print($row_num); ?>">No items found.</td>
</tr>
<?
	}
	else {
		foreach($open_items as $item) {
			vilw_result_globalize($todo_cols, $item, "todo_");
?>
<tr>
 <td class="row<? print($row_num); ?>"><input type="checkbox" name="close_items[]" value="<? print $todo_id; ?>"></td>
 <td align="left" class="row<? print($row_num); ?>"><? print htmlspecialchars($todo_item); ?></td>
</tr>
<?
			$row_num = ($row_num == 1) ? 2:1;
		}
	}
?>
  <tr>
    <th colspan="2" align="left">
      <input type="submit" value="Close Selected Items">
    </th>
  </tr>
</table>
</form>
