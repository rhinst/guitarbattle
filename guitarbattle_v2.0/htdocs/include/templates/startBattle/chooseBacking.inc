<script language="javascript">
<!--//
function checkForm() {
	f = document.chooseBacking;
	if(!(f.same_backing[0].checked || f.same_backing[1].checked)) {
		alert('You must select an option.');
		f.same_backing.focus();
		return false;
	}
	
	if((f.same_backing[1].checked) && (f.backing.value == '')) {
		alert('You must either make this an "any backing" battle or upload a backing.');
		f.backing.focus();
		return false;

	}
}

function selectBacking() {
	document.chooseBacking.same_backing[0].checked = false;
	document.chooseBacking.same_backing[1].checked = true;
}

//-->
</script>


<form name="chooseBacking" action="<? print $PHP_SELF; ?>" method="post" enctype="multipart/form-data" onSubmit="return(checkForm());">
<? vilw_hidden("step", $next_step); ?>
<? vilw_hidden("start_battle_id"); ?>
<? vilw_hidden("MAX_FILE_SIZE", $max_mp3_size); ?>
<br>
<table width="400" class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title" colspan="2">
      Backing Track:
    </td>
  </tr>
  <tr>
    <td colspan="2">
      <b>Step 3: </b>In a same-backing battle, you may upload the backing track that you played over. The user who joins your battle will then download your backing track and has to play over that same track.
    </td>
  </tr>
  <tr>
    <td align="right">
      <input type="radio" name="same_backing" value="0" <? print (!$new_backing)?("checked"):(""); ?>>
    </td>
    <td align="left">
      Any Backing
    </td>
  </tr>
  <tr>
    <td align="right">
      <input type="radio" name="same_backing" value="1" <? print ($new_backing)?("checked"):(""); ?>>
    </td>
    <td align="left">
      Same Backing:
    </td>
  </tr>
<? if($new_backing != 0) { ?>
  <tr>
    <td>
      &nbsp;
    </td>
    <td align="left">
      You already uploaded a backing for this battle.
    </td>
  </tr>
  <tr>
    <td colspan="2" align="center">
      <a href="<? print $PHP_SELF; ?>?battle_id=<? print $battle_id; ?>&step=reupload_backing">Click here if you want to change it.</a>
    </td>
  </tr>
<? } else { ?>
  <tr>
    <td>
      &nbsp;
    </td>
    <td align="left">
      Upload Backing: <input type="file" name="backing" onClick="selectBacking();">
    </td>
  </tr>
<? } ?>
  <tr>
    <td align="left">
      <input class="button" type="button" value="Back" onClick="location='<? print $PHP_SELF; ?>?step=<? print $prev_step; ?>';">
    </td>
    <td align="right">
      <input class="button" type="submit" value="Next">
    </td>
  </tr>
</table>
</form>
