<?php
	if((gethostbyaddr($REMOTE_ADDR) != 'fw.villageworld.com') && ($REMOTE_ADDR != "24.187.85.179")) {
		header("Location: under_construction.php");
	}
?>
