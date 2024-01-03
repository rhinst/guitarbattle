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
$poll_total_votes = 0;
for($i=0; $i<4; $i++) { 
  $poll_total_votes += ($GLOBALS["poll_votes_" . $i]);
}
for($i=0; $i<4; $i++) { 
  if($GLOBALS["poll_answer_" . $i]) {
?>
  <tr>
    <td align="right" width="130" class="menu_text">
      <? print htmlspecialchars($GLOBALS["poll_answer_" . $i]); ?>
    </td>
    <td align="right" width="130" class="menu_text">
      <? print round(($GLOBALS["poll_votes_" . $i] / $poll_total_votes) * 100); ?>%
      <? print "<!-- (" . $GLOBALS["poll_votes_"  .$i] . ") -->\n"; ?>
    </td>
  </tr>
  </tr>
<?
  }
} 
?> 
  <tr>
    <td colspan="2" align="center" class="menu_text">
      (<? print $poll_total_votes; ?> total vote<? print (($poll_total_votes > 1)?("s"):("")); ?>)
    </td>
  </tr>
</table>
