<table class="item" border="0" cellpadding="4" cellspacing="0">
 <form name="listUsersForm" action="<? print($PHP_SELF); ?>" method="post">
 <? vilw_hidden("action", "list"); ?>
 <tr>
  <th colspan="2" align="left">User Information</th>
 </tr>
 <tr>
  <td>Username:</td><td><? vilw_input("username", 16); ?></td>
 </tr>
 <tr>
  <td>Password:</td><td><input class="text" type="password" name="passwd"></td>
 </tr>
 <tr>
  <td>First Name:</td><td><? vilw_input("fn"); ?></td>
 </tr>
 <tr>
  <td>Last Name:</td><td><? vilw_input("ln"); ?></td>
 </tr>
 <tr>
  <td>E-mail Address:</td><td><? vilw_input("eml_addr", 30, "", "class=\"text\""); ?></td>
 </tr>
 <tr>
  <td>Address:</td><td><? vilw_input("address"); ?></td>
 </tr>
 <tr>
  <td>City:</td><td><? vilw_input("city"); ?></td>
 </tr>
 <tr>
  <td>State:</td><td><? vilw_stateselect("state"); ?></td>
 </tr>
 <tr>
  <td>Province:</td><td><? vilw_input("province"); ?></td>
 </tr>
 <tr>
  <td>Zip/Postal Code:</td><td><? vilw_input("zip", 6); ?></td>
 </tr>
 <tr>
  <td>Country:</td><td><? vilw_countryselect("country"); ?></td>
 </tr>
 <tr>
  <td>Telephone:</td><td><? vilw_input("telephone"); ?></td>
 </tr>
 <tr>
  <td>Public:</td><td><? print(($public ? "Yes":"No")); ?></td>
 </tr>
 <tr>
  <td>Join Date:</td><td><? print($join_date); ?></td>
 </tr>
 <tr>
  <td>Signup IP Address:</td><td><? print($ip_addr); ?></td>
 </tr>
 <tr>
  <td>Last Login:</td><td><? print(mysql_datetime_printable($login_login_ts)); ?></td>
 </tr>
 <tr>
  <td>Last Activity:</td><td><? print(mysql_datetime_printable($login_last_active)); ?></td>
 </tr>
 <tr>
  <td>Most Recent IP:</td><td><? print($login_ip_addr); ?></td>
 </tr>
 <tr>
  <td>Vote Bank:</td><td><? vilw_input("vote_bank", 3); ?></td>
 </tr>
 <tr>
  <td colspan="2"><input class="button" type="submit" value="Update"></td>
 </tr>
 </form>
</table>
