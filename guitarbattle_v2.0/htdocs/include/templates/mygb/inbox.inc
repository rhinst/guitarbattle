<script language="javascript">
<!--//
function viewMessage(id) {
  window.open('include/templates/mygb/viewMessage.php?id=' + id, '', 'width=417,height=250,scrollbars=yes');
}

function confirmDelete() {
  if(confirm('Are you sure you want to delete the selected message(s)?')) {
    document.inbox_delete_form.submit();
  }
}
//-->
</script>

<table class="items" width="510" border="0" cellspacing="0" cellpadding="4">
<form name="inbox_delete_form"  action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "delete_messages"); ?>
  <tr>
    <td class="item_title" colspan="4" align="left">
      <table width="100%" border="0" cellspacing="0" cellpadding="0">
        <tr>
          <td class="item_title">
            <b>Inbox (<? print count($messages); ?> messages):</b>
          </td>
          <td class="item_title" align="right">
            <a class="menu_link" href="#" onClick="sendMessage()">&bull; Send a Message</a>
          </td>
        </td>
      </table>
    </td>
  </tr>
  <tr>
    <td class="item_title" width="125" align="left">Date</th>
    <td class="item_title" width="75" align="left">From</th>
    <td class="item_title" width="150" align="left">Subject</th>
    <td class="item_title" width="50">&nbsp;</th>
  </tr>
<?
	$i = 0;
	foreach($messages as $message) {
		vilw_result_globalize($messages_cols, $message, "msg_");
		$printableDate = substr($msg_timestamp, 4, 2) . "/" . substr($msg_timestamp, 6, 2) . "/" . substr($msg_timestamp, 0,4) . " " . substr($msg_timestamp, 8, 2) . ":" . substr($msg_timestamp, 10, 2);
		$row_style = ($i % 2 == 0)?("listing_row1"):("listing_row2");
		$link_style = "";
		if($msg_unread == 1) {
			$row_style .= "_bold";
			$link_style = "style=\"font-weight: bold\" ";
		}
		print "<tr>\n";
		print "<td class=\"" . $row_style . "\" align=\"left\" width=\"125\">" . $printableDate . "</td>\n";
		print "<td class=\"" . $row_style . "\" align=\"left\" width=\"75\"><a " . $link_style . "href=\"" . $baseURL . "/viewProfile.php?username=" . $msg_from_user . "\">" . $msg_from_user . "</a></td>\n";
		print "<td class=\"" . $row_style . "\" align=\"left\" width=\"150\"><a " . $link_style . "href=\"#\" onClick=\"viewMessage('" . $msg_id . "');\">" . ((strlen($msg_subject) > 0)?(htmlspecialchars($msg_subject)):("&lt;No Subject&gt;")) . "</a></td>\n";
		print "<td class=\"" . $row_style . "\" align=\"right\" width=\"50\"><input type=\"checkbox\" name=\"delete_ids[]\" value=\"" . $msg_id . "\"></td>\n";
		print "</tr>\n";
		$i++;
	}
?>
<tr>
  <td class="item_title" colspan="4" align="right">
    <a style="color: #ffffff" href="javascript: confirmDelete()">Delete Selected</a>
  </td>
</tr>
</form>
</table>
