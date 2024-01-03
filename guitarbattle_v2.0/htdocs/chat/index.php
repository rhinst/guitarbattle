<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=us-ascii"> 
  <link href="<? print $styleSheet; ?>" rel="stylesheet" type="text/css">
  <title><? print $sitename; ?> Chat</title>
<head>
<body bgcolor="#ffffff" topmargin="0" leftmargin="0" marginwidth="0" marginheight="0">
<table width="100%" height="100%" border="0" cellpadding="0" cellspacing="0">
<tr valign="top">
<td align="center">
<?
if(!(session_is_registered("authenticated_user"))) {
	print "<br><br>You must log in before using the chat.";	
}
else {
?>
<applet code=Jicra.class width=450 height=250>
<param name=font_name value="verdana">
<param name=font_size value="9">
<param name=nick value="<? print $authenticated_user; ?>">
<param name=realname value="<? print $authenticated_user; ?>">
<param name=port value="6667">
<param name=user value="<? print $authenticated_user; ?>">
<param name=channel value="<? print $irc_channel; ?>">
<param name=foreground value="000000">
<param name=background value="EEEEEE">
Sorry, you don't seem to have Java 1.1 compatible browser.
</applet>
<?
}
?>
</td>
</tr>
<tr>
  <td align="center">
    GB Chat requires <a href="http://java.sun.com" target="_new">Java</a> to be installed and enabled in your browser. 
  </td>
</tr>
<tr valign="bottom">
  <td align="right">
    <br><a href="javascript: window.close();"><b class="red">Close Window</b></a>
  </td>
</tr>
</table>
</body>
</html>
