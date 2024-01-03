<?
	if($HTTP_GET_VARS["goto"]) {
		$HTTP_SESSION_VARS["goto"] = $HTTP_GET_VARS["goto"];
		header("location: " . $PHP_SELF);
	}
	if(!isset($HTTP_SESSION_VARS["goto"]) || ($HTTP_SESSION_VARS["goto"] == "/frames.php")) {
		$HTTP_SESSION_VARS["goto"] = $baseURL;
	}
?>
<html>
 <head>
  <title>
   <? print $sitename; ?>
  </title>
 </head>
 <frameset rows="100%, 90">
  <frame name="" src="<? print urldecode($HTTP_SESSION_VARS["goto"]); ?>">
  <frame name="chatframe" src="<? print $baseURL; ?>/chat/frameIndex.php" scrolling="no" noresize>
 </frameset>
</html>
