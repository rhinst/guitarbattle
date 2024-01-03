<?  require_login(); ?>

<html>
<head>
<title>GuitarBattle Chat</title>
</head>
<body bgcolor="#ffffff" topmargin="0" leftmargin="0" marginwidth="0" marginheight="0">
<table height="450" width="520" border="0" cellpadding="0" cellspacing="0">
<tr>
<td width="520" valign="center" align="center">
<applet code=Jicra.class width=500 height=300>
<param name=nick value="<? print $authenticated_user; ?>">
<param name=realname value="<? print $authenticated_user; ?>">
<param name=port value="6667">
<param name=user value="<? print $authenticated_user; ?>">
<param name=channel value="#guitarbattle">
Sorry, you don't seem to have Java 1.1 compatible browser.
</applet>
<br><a href="javascript: window.close();">Close Window</a>
</td>
</tr>
</table>
</body>
</html>
