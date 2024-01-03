<table border="0" cellspacing="0" cellpadding="2">
<tr>
  <td colspan="2">
    <b class="large_text"><? print $competitor_username; ?></b>
    <? if($collab_username != '') { ?>
    &nbsp;/&nbsp;<b class="large_text"><? print $collab_username; ?></b>
    <? } ?>
  </td>
</tr>
<?
  foreach($voting_categories as $category) {
   vilw_result_globalize($voting_categories_cols, $category, "cat_");
?>
<tr>
  <td>
    <b><? print $cat_name; ?>:</b>
  </td>
  <td>
    <? print number_format($GLOBALS["cat_" . $cat_id . "_vote_" . $usernum], 2); ?>
  </td>
</tr>
<?
  }
?>
<tr>
  <td>
    <b>Overall:</b>
  </td>
  <td>
    <? print number_format($GLOBALS["total_score" . $usernum], 2); ?>
  </td>
</tr>
</table>
