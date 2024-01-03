<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "add"); ?>
<table class="item" border="0" cellspacing="0" cellpadding="4">
  <th colspan="2" align="left">
    Add Link:
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
      Link:
    </td>
    <td align="left">
      <? vilw_input("link", 30); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Description:
    </td>
    <td align="left">
      <? vilw_textarea("description", 5, 30); ?>
    </td>
  </tr>
  <tr valign="top">
    <td colspan="2" align="right">
      <input type="submit" value="Add">
    </td>
  </tr>
</table>
</form>
