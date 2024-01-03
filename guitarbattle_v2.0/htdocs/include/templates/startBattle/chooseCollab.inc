<script language="javascript">
<!--//
function checkForm() {
	f = document.chooseCollab;
	
	if(!(f.collaborative[0].checked || f.collaborative[1].checked)) {
		alert('You must select an option.');
		f.collaborative.focus();
		return false;
	}

	if((f.collaborative[1].checked) && (f.collab_user.value == '')) {
		alert('You must either make this a solo battle or supply the username of a <? print $sitename; ?> user to collaborate with.');
		f.collab_user.focus();
		return false;	
	}
	return(true);
}

function selectCollab() {
	document.chooseCollab.collaborative[0].checked = false;
	document.chooseCollab.collaborative[1].checked = true;
}

function deselectCollab() {
	document.chooseCollab.collab_user.value = '';
}
//-->
</script>




<form name="chooseCollab" action="<? print $PHP_SELF; ?>" method="post" onSubmit="return(checkForm());">
<? vilw_hidden("step", $next_step); ?>
<? vilw_hidden("start_battle_id"); ?>
<br>
<table width="400" class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title" colspan="2">
      Collaboration:
    </td>
  </tr>
  <tr>
    <td colspan="2">
      <b>Step 4: </b>In a collaborative battle, you upload an mp3 of your own and specify a member to collaborate with. That member is then notified that you wish to collaborate, and is directed to a page where he or she can download your mp3 and record a harmony or separate melody over your original song and then reupload the finished collaborative piece. 
    </td>
  </tr>
  <tr>
    <td align="right">
      <input type="radio" name="collaborative" value="0" checked onClick="deselectCollab();">
    </td>
    <td align="left">
      Solo Battle
    </td>
  </tr>
  <tr>
    <td align="right">
      <input type="radio" name="collaborative" value="1">
    </td>
    <td align="left">
      Choose a collaborative Partner:
    </td>
  </tr>
  <tr>
    <td>
      &nbsp;
    </td>
    <td align="left">
      Username: <? vilw_input("collab_user", 20, "", "onClick=\"selectCollab();\""); ?>
    </td>
  </tr>
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
