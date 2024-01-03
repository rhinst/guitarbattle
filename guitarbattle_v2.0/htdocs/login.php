<?
if(session_is_registered("authenticated_user")) {
	if((!$HTTP_SESSION_VARS["goto"]) || ($HTTP_SESSION_VARS["goto"] == $REQUEST_URI)) {
		$HTTP_SESSION_VARS["goto"] = "index.php";
	}
	header("location: " . $HTTP_SESSION_VARS["goto"]);
	exit;
}
?>
<?  include('templates/general/header.inc'); ?>
<table border="0" width="200" cellpadding="0" cellspacing="0">
  <tr>	
    <td bgcolor="#ffffff" align="center"><img src="images/login_header.jpg"><br></td>
  </tr>
  <tr>
    <td align="center" bgcolor="#000000">
     <table border="0" cellspacing="1" cellpadding="0" width="100%" height="100%">
      <tr>
       <td bgcolor="#bb0000" align="center"><br>
<? include('templates/general/loginBox.inc'); ?>
       </td>
      </tr>
     </table>
    </td>
  </tr>
</table>
<? include('templates/general/footer.inc'); ?>
