<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "add"); ?>
<table class="item" border="0" cellspacing="0" cellpadding="4">
  <th colspan="2" align="left">
    Add News Item:
  </th>
  <tr valign="top">
    <td align="right">
      Subject:
    </td>
    <td align="left">
      <? vilw_input("subject", 30); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      Posted By:
    </td>
    <td align="left">
      <? vilw_input("posted_by", 30); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="right">
      News:
    </td>
    <td align="left">
      <? vilw_textarea("contents", 5, 30); ?>
    </td>
  </tr>
  <tr valign="top">
    <td colspan="2" align="right">
      <input type="submit" value="Add">
    </td>
  </tr>
</table>
</form>
