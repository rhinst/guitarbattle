<?php
	include('gb.lib');

	if((!isset($id)) || ($id == "") || ($id == 0)) {
		$id = -1;
	}
	$result = mysql_query("select file_type, file_contents, file_name from user_icons where user_id=$id");
	$row = mysql_fetch_row($result);
	$file_type = $row[0];
	$file_contents = $row[1];
	$file_name = $row[2];
	header("Content-type: " . $file_type);
	header("Content-disposition: filename=$file_name");
	print("$file_contents");
?>
