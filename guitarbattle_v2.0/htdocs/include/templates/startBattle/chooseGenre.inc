<script language="javascript" src="include/datacheck.js">
</script>

<script language="javascript">
<!--//
function checkForm() {
	f = document.chooseGenre;
	
	if(!(checkselect(f.genre, 'a genre'))) {
		return false;
	}
	return(true);
}
//-->
</script>

<form name="chooseGenre" action="<? print $PHP_SELF; ?>" method="post" onSubmit="return(checkForm());">
<? vilw_hidden("step", $next_step); ?>
<? vilw_hidden("start_battle_id"); ?>
<br>
<table width="400" class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title" colspan="2">
      Genre:
    </td>
  </tr>
  <tr>
    <td colspan="2">
      <b>Step 1: </b>Choose a genre that best describes the song you are uploading. This will help users trying to locate songs of the genres they prefer to listen to and battles they want to participate in.
    </td>
  </tr>
  <tr>
    <td>
      Select the genre that best describes your song:
    </td>
    <td>
     <? vilw_select("genre", $genres, $new_genre); ?> 
    </td>
  </tr>
  <tr>
    <td colspan="2" align="right">
      <input class="button" type="submit" value="Next">
    </td>
  </tr>
  <tr>
</table>
</form>
