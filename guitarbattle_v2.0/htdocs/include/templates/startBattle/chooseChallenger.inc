<script language="javascript">
<!--//
function checkForm() {
	f = document.chooseChallenger;
	
	if(!(f.open[0].checked || f.open[1].checked)) {
		alert('You must select an option.');
		f.open.focus();
		return false;
	}

	if((f.open[1].checked) && (f.challenge_user.value == '')) {
		alert('You must either make this an open battle or supply the username of a <? print $sitename; ?> user to challenge.');
		f.challenge_user.focus();
		return false;	
	}
	return(true);
}

function selectChallenger() {
	document.chooseChallenger.open[0].checked = false;
	document.chooseChallenger.open[1].checked = true;
}

function deselectChallenger() {
	document.chooseChallenger.challenge_user.value = '';
}
//-->
</script>

<form name="chooseChallenger" action="<? print $PHP_SELF; ?>" method="post" onSubmit="return(checkForm());">
<? vilw_hidden("step", $next_step); ?>
<? vilw_hidden("start_battle_id"); ?>
<br>
<table width="400" class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title" colspan="2">
      Challenger:
    </td>
  </tr>
  <tr>
    <td colspan="2">
      <b>Step 2: </b>By default, a battle is 'open', which means that any <? print $sitename; ?> member that is the same rank as you may join the battle. If you wish to, you may challenge a particular member to a battle. In this case, the battle will be reserved for that member, and no other member will be able to join it. You may challenge any member, regardless of rank.
    </td>
  </tr>
  <tr>
    <td align="right">
      <input type="radio" name="open" value="1" <? print (!$new_challenger)?("checked"):(""); ?> onClick="deselectChallenger();">
    </td>
    <td align="left">
      Open Battle
    </td>
  </tr>
  <tr>
    <td align="right">
      <input type="radio" name="open" value="0" <? print ($new_challenger)?("checked"):(""); ?>>
    </td>
    <td align="left">
      Challenge A User
    </td>
  </tr>
  <tr>
    <td>
      &nbsp;
    </td>
    <td align="left">
      Username: <? vilw_input("challenge_user", 20, $new_challenger, "onClick=\"selectChallenger();\""); ?>
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
