<?
	include('gb.lib');

	if(!(preg_match("/\/music\/(.*).mp3/", $PHP_SELF, $params))) {
		print "File not found";
	}
	$id = $params[1];

	$result = mysql_query("select file_type, file_contents, view_count, file_name from battle_mp3s where id=$id");
	if(!$result) {
		header("Location: ../battle.php?mode=error");
	}
	else {
		$row = mysql_fetch_row($result);
		$file_type = $row[0];
		$file_content = $row[1];
		$view_count = $row[2];
		$file_name = $row[3];
		//Increment view count.
		$view_count++;
		mysql_query("update battle_mp3s set view_count=$view_count where id=$id");
		header("Content-Length: " . strlen($file_content));
		header("Content-type: " . $file_type);
		print("$file_content");
	}
?>
