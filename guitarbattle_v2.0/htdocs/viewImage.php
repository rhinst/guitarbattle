<?
	$res = vilw_query(vilw_sql_select($images_cols, $images_table, "where id=" . $id));
	$row = mysql_fetch_row($res);
	vilw_result_globalize($images_cols, $row);
	if($width && $height) {
		$file_contents = vilw_get_resized_image_contents($file_contents, $width, $height, $foreceddimensions = true);
	}
	header("Content-length: " . strlen($file_contents));
	header("Content-type: " . $file_type);
	header("Content-disposition: inline");
	print("$file_contents");

?>
