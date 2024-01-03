<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "add"); ?>
<table class="item" border="0" cellspacing="0" cellpadding="4">
  <th colspan="2" align="left">
    Add Rank:
  </th>
  <tr valign="top">
    <td align="right">
      Name:
    </td>
    <td align="left">
      <? vilw_input("name", 30); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      # Battles:
    </td>
    <td align="left">
      <? vilw_input("num_battles", 3); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Score:
    </td>
    <td align="left">
      <? vilw_input("score", 4); ?>
    </td>
  </tr>
  <tr valign="top">
    <td colspan="2" align="right">
      <input type="submit" value="Add">
    </td>
  </tr>
</table>
</form>
