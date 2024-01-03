<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "add_alt"); ?>
<table border="0" cellspacing="0" cellpadding="0">
 <tr>
  <th colspan="3" align="left">Add an Alternate Judge:</th>
 </tr>
  <tr>
    <td align="right">
      Username:
    </td>
    <td align="left">
      <? vilw_input("username", 20); ?>
    </td>
    <td>
      <input type="submit" value="Add Judge">
    </td>
  </tr>
</table>
</form>
