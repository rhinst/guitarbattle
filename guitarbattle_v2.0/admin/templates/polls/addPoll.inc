<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "add"); ?>
<table class="item" border="0" cellspacing="0" cellpadding="4">
 <tr>
  <th colspan="2" align="left">Add Poll:</th>
 </tr>
  <tr>
    <td colspan="2">
      Question:
    </td>
  <tr>
    <td colspan="2">
      <? vilw_textarea("question", 2, 25); ?>
    </td>
  </tr>
<?  for($i=0; $i<4; $i++) { ?>
  <tr>
    <td align="right">
      Choice <? print ($i+1); ?>:
    </td>
    <td align="left">
       <? vilw_input("answer_" . $i, 20); ?>
    </td>
  </tr>
<?  } ?>
  <tr>
    <td align="right">
      Active:
    </td>
    <td align="left">
      <input type="checkbox" name="active" value="1"> 
    </td>
  </tr>
  <tr>
    <td align="center">
      <input type="submit" value="Add">
    </td>
  </tr>
</table>
</form>
