<script language="javascript">
<!--//
function checkForm() {
	f = document.pw_form;

	if(f.old_pass.value == '') {
		f.old_pass.focus();
		alert('You must enter your old password');
		return false;
	}

	if(f.new_pass.value != f.new_pass2.value) {
		f.new_pass.focus();
		alert('Passwords don\'t match');
		return false;

	}

	if(f.new_pass.value == '') {
		f.new_pass.focus();
		alert('You must enter a new password');
		return false;
	}

	return true;
}
//-->
</script>


<form name="pw_form" action="<? print $PHP_SELF; ?>" method="post" onSubmit="return(checkForm())">
<? vilw_hidden("action", "change_pw"); ?>
<table class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title" colspan="2">
      Change Password
    </td>
  </tr>
  <tr>
    <td align="right">
      Old Password:
    </td>
    <td align="left">
      <input type="password" name="old_pass"> 
    </td>
  </tr> 
  <tr>
    <td align="right">
      New Password:
    </td>
    <td align="left">
      <input type="password" name="new_pass"> 
    </td>
  </tr> 
  <tr>
    <td align="right">
      Confirm New Password:
    </td>
    <td align="left">
      <input type="password" name="new_pass2"> 
    </td>
  </tr> 
  <tr>
    <td colspan="2" align="center">
      <input class="button" type="submit" value="Change Password">
    </td>
  </tr>
</table>
</form>
