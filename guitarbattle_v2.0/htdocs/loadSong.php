<?php
	if($id) {

		$res = vilw_query(vilw_sql_select($mp3s_cols, $mp3s_table, "where id=" . $id));
		$row = mysql_fetch_row($res);
		vilw_result_globalize($mp3s_cols, $row);
		header("Content-length: " . strlen($file_contents));
		header("Content-type: " . $file_type);
		header("Content-disposition: inline; filename=$file_name");
		print("$file_contents");
	}
?>
