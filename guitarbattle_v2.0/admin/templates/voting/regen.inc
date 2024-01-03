<script language="javascript">
<!--//
function confirmRegen() {
	return(confirm('Are you SURE you want to do this? It will completely erase ALL of the votes on the site!'));
}
//-->
</script>

<table class="item" width="350" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td align="center">
      <b>Note:</b> Whenever you change the voting categories, you must recreate the voting tables (unless you want to break the site). By pressing this button, however, you will be cleaing ALL VOTES for every battle on the site. This functionality is only meant to be used when the site is first created, or when the voting system is being overhauled. Use it sparingly!!
    </td>
  </tr>
  <tr>
    <td align="center">
      <form action="<? print $PHP_SELF; ?>" method="post" onSubmit="return(confirmRegen());">
      <? vilw_hidden("action", "regen"); ?>
      <input type="submit" value="Recreate Voting Tables">
      </form>
    </td>
  </tr>
</table>
