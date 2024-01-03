<br>
<table class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title">
      Error:
    </th>
  </tr>
  <tr>
    <td align="center">
      <? print htmlspecialchars($err_msg); ?>
    </td>
  </tr>
  <tr>
  <form action="<? print $PHP_SELF; ?>" method="post">
    <td align="center">
        <input class="button" type="submit" value="Back">
    </td>
  </form>
  </tr>
</table>
