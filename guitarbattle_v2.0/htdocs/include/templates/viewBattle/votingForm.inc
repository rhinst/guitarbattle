<table class="items" border="0" cellspacing="0" cellpadding="4">
<tr>
  <td class="item_title" colspan="2" align="left">
    <b class="title_light"><? print $competitor_username; ?></b>
  </td>
</tr>
<?
  $i = 0;
  foreach($voting_categories as $category) {
    vilw_result_globalize($voting_categories_cols, $category, "cat_");
    $row_style = ($i % 2 == 0)?("listing_row1"):("listing_row2");
?>
<tr>
  <td class="<? print $row_style; ?>" align="right">
    <? print $cat_name; ?>:&nbsp;
  </td>
  <td class="<? print $row_style; ?>" align="left">
    <? voting_scale("cat_" . $cat_id . "_vote_" . $usernum); ?>
  </td>
</tr>
<?
    $i++;
  }
?>
</table>
