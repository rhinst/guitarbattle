<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "delete"); ?>
<table class="item" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <th>&nbsp;</th>
    <th align="left">Category</th>
  </tr>
<?
	$row_num = 1;
	foreach($voting_categories as $category) {
		vilw_result_globalize($voting_categories_cols, $category, "cat_");
?>
<tr>
 <td class="row<?print($row_num); ?>"><input type="checkbox" name="delete_cats[]" value="<? print $cat_id; ?>"></td>
 <td class="row<? print($row_num); ?>"><? print($cat_name); ?></td>
</tr>
<?
		$row_num = ($row_num == 1) ? 2:1;
	}
?>
<tr>
  <th align="left" colspan="2">
    <input type="submit" value="Delete Selected">
  </th>
</tr>
</table>
</form>
