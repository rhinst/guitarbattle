<table class="item" border="0" cellpadding="4" cellspacing="0">
 <form name="listUsersForm" action="<? print($PHP_SELF); ?>" method="post">
 <? vilw_hidden("action", "list"); ?>
 <? vilw_hidden("mode"); ?>
 <tr>
  <th colspan="2" align="left">List Users</th>
 </tr>
 <tr>
  <td>Username:</td><td><? vilw_input("username", 16, "", "class=\"text\""); ?></td>
 <tr>
 <tr>
  <td>E-mail Address:</td><td><? vilw_input("eml_addr", 30, "", "class=\"text\""); ?></td>
 <tr>
 <tr>
  <td colspan="2"><input class="button" type="submit" value="List Users"></td>
 </tr>
 </form>
</table>
