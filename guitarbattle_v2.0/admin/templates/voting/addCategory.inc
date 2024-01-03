<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "add"); ?>
<table class="item" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <th colspan="3" align="left">
      Add Voting Category:
    </th>
  </tr>
  <tr>
    <td align="right">
      Name:
    </td>
    <td align="left"> 
      <? vilw_input("name", 20); ?>
    </td>
    <td align="center">
      <input type="submit" value="Add">
    </td>
  </tr>
</table>
</form>
