<script language="javascript">
<!--//
function confirmDelete() {
	return(confirm('Are you sure you want to delete this news item?'));
}
//-->
</script> 

<?
foreach($news as $news_item) {
	vilw_result_globalize($news_cols, $news_item, "news_");
?>
<table class="item" border="0" cellpadding="4" cellspacing="0">
  <tr>
    <th align="left" colspan="2">
      News Item:
    </th>
  </tr>
  <tr valign="top">
    <td align="left" rowspan="2">
      <form action="<? print $PHP_SELF; ?>" method="post" onSubmit="return(confirmDelete());">
        <? vilw_hidden("action", "delete"); ?>
        <? vilw_hidden("id", $news_id); ?>
        <input type="submit" value="Delete">
      </form>
    </td>
    <td align="left">
<? if($news_posted_by) { ?>
	<b>Posted By:</b> <? print $news_posted_by; ?><br><br>
<? } ?>
    </td>
  </tr>
  <tr>
    <td align="left">
      <? print nl2br($news_contents); ?>
    </td>
  </tr>
</table>
<?  } ?>
