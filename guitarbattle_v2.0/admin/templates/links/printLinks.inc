<script language="javascript">
<!--//
function confirmDelete() {
	return(confirm('Are you sure you want to delete this link?'));
}
//-->
</script> 

<?
foreach($links as $link) {
	vilw_result_globalize($links_cols, $link, "link_");
?>
<table class="item" border="0" cellpadding="4" cellspacing="0">
  <tr>
    <th align="left" colspan="2">
      Link:
    </th>
  </tr>
  <tr valign="top">
    <td align="left" rowspan="2">
      <form action="<? print $PHP_SELF; ?>" method="post" onSubmit="return(confirmDelete());">
        <? vilw_hidden("action", "delete"); ?>
        <? vilw_hidden("id", $link_id); ?>
        <input type="submit" value="Delete">
      </form>
    </td>
    <td align="left">
	<a href="<? print $link_link; ?>"><? print $link_name; ?></a>
    </td>
  </tr>
  <tr>
    <td align="left">
      <? print nl2br($link_description); ?>
    </td>
  </tr>
</table>
<?  } ?>
