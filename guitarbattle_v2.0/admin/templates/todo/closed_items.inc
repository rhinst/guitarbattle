<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "delete"); ?>
<table width="500" class="item" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <th align="left" colspan="2">
      <? print count($closed_items); ?> Closed Items:
    </th>
  </tr>
<?
	$row_num = 1;
	if(count($closed_items) == 0) {
?>
<tr>
 <td colspan="2" class="row<? print($row_num); ?>">No items found.</td>
</tr>
<?
	}
	else {
		foreach($closed_items as $item) {
			vilw_result_globalize($todo_cols, $item, "todo_");
?>
<tr>
 <td class="row<? print($row_num); ?>"><input type="checkbox" name="delete_items[]" value="<? print $todo_id; ?>"></td>
 <td align="left" class="row<? print($row_num); ?>"><? print htmlspecialchars($todo_item); ?></td>
</tr>
<?
			$row_num = ($row_num == 1) ? 2:1;
		}
	}
?>
  <tr>
    <th align="left" colspan="2">
      <input type="submit" value="Delete Selected Items">
    </th>
  </tr>
</table>
</form>
