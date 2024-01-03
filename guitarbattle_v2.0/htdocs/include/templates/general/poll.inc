<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "poll_vote"); ?>
<? vilw_hidden("poll_id"); ?>
<table width="150" border="0" cellspacing="0" cellpadding="2">
  <tr>
    <td class="menu_text" colspan="2" align="center">
      <b><span style="color: #ffffff; font-size: 12px">GB Poll</span></b>
    </td>
  </tr>
  <tr>
    <td class="menu_text" colspan="2" align="left">
      <? print htmlspecialchars($poll_question); ?>
    </td>
  </tr>
<?
for($i=0; $i<4; $i++) { 
  if($GLOBALS["poll_answer_" . $i]) {
?>
  <tr>
    <td align="right" width="20">
      <input type="radio" name="poll_choice" value="<? print $i; ?>">
    </td>
    <td align="left" width="130" class="menu_text">
      <? print htmlspecialchars($GLOBALS["poll_answer_" . $i]); ?>
    </td>
  </tr>
<?
  }
} 
?> 
  <tr>
    <td colspan="2" align="center">
      <input class="button" type="submit" value="Vote">
    </td>
  </tr>
</table>
</form>
