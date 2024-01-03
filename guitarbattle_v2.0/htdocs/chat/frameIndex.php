<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=us-ascii"> 
  <link href="<? print $styleSheet; ?>" rel="stylesheet" type="text/css">
  <title><? print $sitename; ?> Chat</title>
<head>
<body bgcolor="#ffffff" style="marin: 0px">
<table width="100%" height="100%" border="0" cellpadding="0" cellspacing="0">
<tr valign="top">
<td align="center" width="100%" height="90">
<?
if(!(session_is_registered("authenticated_user"))) {
	print "<br><br>You must log in before using the chat.";	
}
else {
	if(strstr($HTTP_USER_AGENT, "ozilla")) {
		$width = "800";
	}
	else {
		$width = "100%";
	}
	?>
	<applet code="Jicra.class" width="<? print $width; ?>" height="90">
	<param name="font_name" value="verdana">
	<param name="font_size" value="9">
	<param name="nick" value="<? print $authenticated_user; ?>">
	<param name="realname" value="<? print $authenticated_user; ?>">
	<param name="port" value="6667">
	<param name="user" value="<? print $authenticated_user; ?>">
	<param name="channel" value="<? print $irc_channel; ?>">
	<param name="foreground" value="000000">
	<param name="background" value="EEEEEE">
	Sorry, you don't seem to have Java 1.1 compatible browser.
	</applet>
	<?
}
?>
</td>
</tr>
</table>
</body>
</html>
