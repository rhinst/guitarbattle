<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "delete_alt");  ?>
<table width="300" class="item" border="0" cellspacing="0" cellpadding="0">
 <tr>
  <th colspan="2" align="left">Alternate Judges:</th>
 </tr>
<?
$row_num = 1;
foreach($alt_judges as $judge) {
  vilw_result_globalize($users_cols, $judge, "judge_");
?>
<tr>
 <td width="20" class="row<? print($row_num); ?>"><input type="checkbox" name="delete_judges[]" value="<? print $judge_username; ?>"></td>
 <td align="left" class="row<? print($row_num); ?>"><? print $judge_username; ?></td>
</tr>
<? 
  $row_num = ($row_num == 1) ? 2:1;
}
?>
 <tr>
  <th colspan="2" align="left">
    <input type="submit" value="Delete Selected">
  </th>
 </tr>
</table>
</form>
