<? $item = ""; ?>
<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "add"); ?>
<table class="item" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <th>Add Item</th>
  </tr>
  <tr>
    <td>
      <? vilw_textarea("item", 2, 50); ?>
    </td>
  </tr>
  <tr>
    <td align="center">
      <input type="submit" value="Add Item">
    </td>
  </tr>
</table>
</form>
