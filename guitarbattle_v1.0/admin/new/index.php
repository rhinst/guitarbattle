<?php
	include('header.inc');
	switch($mode) {
		default: {
			include('home.inc');
			break;
		}
	}
	include('footer.inc');
?>
