<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "add"); ?>
<table border="0" cellspacing="0" cellpadding="0">
 <tr>
  <th colspan="3" align="left">Add a Genre:</th>
 </tr>
  <tr>
    <td align="right">
      Name:
    </td>
    <td align="left">
      <? vilw_input("name", 10); ?>
    </td>
    <td>
      <input type="submit" value="Add Genre">
    </td>
  </tr>
</table>
</form>
