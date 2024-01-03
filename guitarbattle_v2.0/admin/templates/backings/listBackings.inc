<script language="javascript">
<!--//
function confirmDelete() {
	return(confirm('Are you sure you want to delete this backing?'));
}
//-->
</script> 

<?
foreach($backings as $backing) {
	vilw_result_globalize($backings_cols, $backing, "backing_");
?>
<table class="item" border="0" cellpadding="4" cellspacing="0">
  <tr>
    <th align="left" colspan="2">
      Backing:
    </th>
  </tr>
  <tr valign="top">
    <td align="left" rowspan="2">
      <form action="<? print $PHP_SELF; ?>" method="post" onSubmit="return(confirmDelete());">
        <? vilw_hidden("action", "delete"); ?>
        <? vilw_hidden("id", $backing_id); ?>
        <? vilw_hidden("mp3_id", $backing_mp3_id); ?>
        <input type="submit" value="Delete">
      </form>
    </td>
    <td align="left">
      <a href="<? print $baseURL; ?>/loadSong.php?id=<? print $backing_mp3_id; ?>"><? print $backing_name; ?></a>
    </td>
  </tr>
  <tr>
    <td align="left">
      <? print nl2br(htmlspecialchars($backing_description)); ?>
    </td>
  </tr>
</table>
<?  } ?>
