<table border="0" cellspacing="5" cellpadding="0">
<? 
$i = 0;
foreach($polls as $poll) {
  vilw_result_globalize($poll_questions_cols, $poll, "poll_");
  
  if($i % 2 == 0) {
    print "<tr valign=\"top\">\n";
  }
?>
<td>
  <table class="item" width="200" border="0" cellspacing="0" cellpadding="4">
   <tr>
    <th align="left">Poll #<? print $poll_id; ?>:</th>
   </tr>
    <tr>
      <td>
        <? print htmlspecialchars($poll_question); ?>
      </td>
    </tr>
  <?
    print "<ul>\n";
    for($i=0; $i<4; $i++) {
      if($GLOBALS["poll_answer_" . $i]) {
  ?>
    <tr>
      <td>
        <li><? print $GLOBALS["poll_answer_" . $i]; ?></li>
      </td>
    </tr>
  <?
      }
    }
    print "</table>\n";

    print "</ul>\n";
    print "</td>\n";
    if($i % 2 == 1) {
      print "</tr>\n";
    }
    $i++;
  }
  if($i % 2 == 1) {
    print "<td>&nbsp;</td>\n";
    print "</tr>\n";
  }
?>
</table>
