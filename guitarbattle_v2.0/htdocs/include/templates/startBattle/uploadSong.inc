<script language="javascript">
<!--//
function checkForm() {
	f = document.uploadSong;
	
	if(f.song.value == '') {
		alert('You must upload an mp3');
		f.song.focus();
		return false;
	}
	return(true);
}
//-->
</script>


<form name="uploadSong" action="<? print $PHP_SELF; ?>" method="post" enctype="multipart/form-data" onSubmit="return(checkForm());">
<? vilw_hidden("step", $next_step); ?>
<? vilw_hidden("start_battle_id"); ?>
<? vilw_hidden("MAX_FILE_SIZE", $max_mp3_size); ?>
<br>
<table width="400" class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title" colspan="2">
      MP3:
    </td>
  </tr>
  <tr>
    <td colspan="2">
      <b>Step 5: </b>Upload an mp3-format audio file of yourself playing. The song may include other instruments (synthesized or otherwise), as long as the material is not copyrighted by another performer.
    </td>
  </tr>
<? if($new_file1 != 0) { ?>
  <tr>
    <td colspan="2" align="center">
      You already uploaded an MP3.<br>
    </td>
  </tr>
  <tr>
    <td colspan="2" align="center">
      <a href="<? print $PHP_SELF; ?>?battle_id=<? print $battle_id; ?>&step=reupload_song">Click here if you want to change it.</a>
    </td>
  </tr>
<? } else { ?>
  <tr>
    <td>
      Your MP3:
    </td>
    <td align="left">
      <input type="file" name="song">
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
