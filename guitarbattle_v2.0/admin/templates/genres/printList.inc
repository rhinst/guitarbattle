<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "delete");  ?>
<table width="300" class="item" border="0" cellspacing="0" cellpadding="0">
 <tr>
  <th colspan="2" align="left">Genres:</th>
 </tr>
<?
$row_num = 1;
foreach($genres as $genre) {
  vilw_result_globalize($genres_cols, $genre, "genre_");
?>
<tr>
 <td width="20" class="row<? print($row_num); ?>"><input type="checkbox" name="delete_genres[]" value="<? print $genre_id; ?>"></td>
 <td align="left" class="row<? print($row_num); ?>"><? print $genre_name; ?></td>
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
