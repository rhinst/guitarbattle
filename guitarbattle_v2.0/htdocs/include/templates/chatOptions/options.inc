<script language="javascript">
<!--//
function popupChat() {
	window.open('<? print $baseURL; ?>/chat/index.php', 'chatWindow', 'width=450,height=300,scrollbars=no');
}
//-->
</script>

<br>
<table class="items" width="300" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title">
      Chat Options 
    </td>
  </tr>
  <tr>
    <td align="center">
      <a href="<? print $baseURL; ?>/chatOptions.php" target="_top">Close Chat Frame</a>
    </td>
  </tr>
  <tr>
    <td align="center">
      <a href="<? print $baseURL; ?>/frames.php?goto=/chatOptions.php" target="_top">Open Chat Frame</a>
    </td>
  </tr>
  <tr>
    <td align="center">
      <a href="<? print $baseURL; ?>/chatOptions.php?action=popup" target="_top">Open Chat Popup Window</a>
    </td>
  </tr>
</table>

<? if($action == "popup") { ?>
<script language="javascript">
<!--//
popupChat();
//-->
</script>
<? } ?>
