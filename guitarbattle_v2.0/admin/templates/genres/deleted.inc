<table class="item" border="0" cellpadding="4" cellspacing="0">
 <tr>
  <th align="left">Deleted <? print count($delete_genres); ?> Genres:</th>
 </tr>
<? foreach($delete_genres as $del_genre_id) { ?>
 <tr>
  <td>Genre ID #<? print $del_genre_id; ?></td>
 </tr>
 </tr>
<? } ?>
</table>
