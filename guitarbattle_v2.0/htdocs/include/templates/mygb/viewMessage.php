<? 
  include('templates/general/popupHeader.inc');
  $message = get_message($id);
  vilw_query("update " . $messages_table . " set unread='0' where id='" .  $id . "'");
  vilw_result_globalize($messages_cols, $message, "msg_"); 
?>
<table class="items" width="90%" border="0" cellspacing="0" cellpadding="4">
  <tr valign="top">
    <td class="item_title" width="50" align="right">
      <b>From:</b>
    </td>
    <td class="item_title" align="left">
      <? print $msg_from_user; ?>&nbsp;&nbsp;&nbsp;&nbsp;[<a style="color: #ffffff" href="<? print $baseURL; ?>/include/templates/mygb/sendMessage.php?to_user=<? print urlencode($msg_from_user); ?>&subject=<? print urlencode($msg_subject); ?>">Reply</a>]
    </td>
  </tr>
  <tr valign="top">
    <td class="listing_row1" width="50" align="right">
      <b>Date:</b>
    </td>
    <td class="listing_row1" align="left">
      <? print $msg_timestamp; ?>
    </td>
  </tr>
  <tr valign="top">
    <td class="listing_row2" width="50" align="right">
      <b>Subject:</b>
    </td>
    <td class="listing_row2" align="left">
      <? print htmlspecialchars($msg_subject); ?>
    </td>
  </tr>
</table>
<table width="90%" border="0" cellspacing="0" cellpadding="4">
  <tr valign="top">
    <td colspan="2" align="left">
      <? print nl2br($msg_body); ?>
    </td>
  </tr>
</table>
<? include('templates/general/popupFooter.inc'); ?>
