<?
include('templates/general/popupHeader.inc');

if($action == "send") {
	$from_user = $authenticated_user;
	send_message($from_user, $to_user, $subject, $body);
	print "<script language=\"javascript\">\n";
	print "window.close()\n";
	print "</script>\n";
}

if($subject) {
	$subject = "Re: " . $subject;
}
?>
<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "send"); ?>
<table border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td width="50" align="right">
      <b>To:</b>
    </td>
    <td align="left">
      <? vilw_input("to_user", 20); ?>
    </td>
  </tr>
  <tr>
    <td width="50" align="right">
      <b>Subject:</b>
    </td>
    <td align="left">
      <? vilw_input("subject", 30); ?>
    </td>
  </tr>
  <tr>
    <td width="50" colspan="2" align="left">
      <? vilw_textarea("body", 5, 40); ?>
    </td>
  </tr>
  <tr>
    <td colspan="2" align="center"><input class="button" type="submit" value="Send"></td>
  </tr>
</table>
</form>
<? include('templates/general/popupFooter.inc'); ?>
