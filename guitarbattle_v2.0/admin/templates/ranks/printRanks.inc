<script language="javascript">
<!--//
function confirmDelete() {
	return(confirm('Are you sure you want to delete this rank?'));
}
//-->
</script> 

<?
foreach($ranks as $rank) {
	vilw_result_globalize($ranks_cols, $rank, "rank_");
?>
<table class="item" border="0" cellpadding="4" cellspacing="0">
  <tr>
    <th align="left" colspan="2">
      Rank:
    </th>
  </tr>
  <tr valign="top">
    <td align="left" rowspan="3">
      <form action="<? print $PHP_SELF; ?>" method="post" onSubmit="return(confirmDelete());">
        <? vilw_hidden("action", "delete"); ?>
        <? vilw_hidden("id", $rank_id); ?>
        <input type="submit" value="Delete">
      </form>
    </td>
    <td align="left">
	<b><? print $rank_name; ?></b>
    </td>
  </tr>
  <tr>
    <td align="left">
	<b># Battles:&nbsp;</b><? print $rank_num_battles; ?>
    </td>
  </tr>
  <tr>
    <td align="left">
	<b>Score:&nbsp;</b><? print $rank_score; ?>
    </td>
  </tr>
</table>
<?  } ?>
