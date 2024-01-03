<? 


if(session_is_registered("compilation_id")) {
	$track_list = vilw_result_array(vilw_query(vilw_sql_select($track_lists_cols, $track_lists_table, "where compilation_id='" . $HTTP_SESSION_VARS["compilation_id"] . "'")));
	$total_time = 0;
	foreach($track_list as $track) {
		vilw_result_globalize($track_lists_cols, $track, "tl_");
		$total_time += $tl_track_length;	
	}
}

switch($action) {
case "start":
	$status = "";
	$order_date = date("Y-m-d H:i:s");
	vilw_query(vilw_sql_insert($compilations_cols, $compilations_table));
	$compilation_id = mysql_insert_id();
	session_register("compilation_id");
	$HTTP_SESSION_VARS["compilation_id"] = $compilation_id;
	header("location: " . $PHP_SELF);
	break;
case "add":
	$res = vilw_query(vilw_sql_select($track_lists_cols, $track_lists_table, "where compilation_id='" . $HTTP_SESSION_VARS["compilation_id"] . "' and mp3_id='" . $mp3_id . "'"));
	if(mysql_num_rows($res) == 1) {
		include('templates/general/header.inc');
		$err_msg = "You cannot add the same track more than once.";
		include('templates/compilation/error.inc');
		include('templates/general/footer.inc');
		exit;
	}
	$res = vilw_query(vilw_sql_select($mp3s_cols, $mp3s_table, "where id='" . $mp3_id . "'"));
	if(!($row = mysql_fetch_row($res))) {
		include('templates/general/header.inc');
		$err_msg = "Error locating requested song.";
		include('templates/compilation/error.inc');
		include('templates/general/footer.inc');
		exit;
	}
	vilw_result_globalize($mp3s_cols, $row);
	$track_length = (($file_size / ($bitrate * 1000)) * 8);
	if(($total_time + $track_length) > ($max_compilation_length * 60)) {
		include('templates/general/header.inc');
		$err_msg = "Your compilation CD may not exceed " . $max_compilation_length . " minutes.";
		include('templates/compilation/error.inc');
		include('templates/general/footer.inc');
		exit;
	}
	$track_number = count($track_list) + 1;
	vilw_query(vilw_sql_insert($track_lists_cols, $track_lists_table));
	header("location: " . $PHP_SELF . "?action=search&search_username=" . $search_username . "&search_song_name=" . $search_song_name . "&search_genre=" . $search_genre);
	break;
case "delete":
	vilw_query(vilw_sql_delete($track_lists_table, "where compilation_id='" . $HTTP_SESSION_VARS["compilation_id"] . "' and mp3_id='" . $mp3_id . "'"));
	header("location: " . $PHP_SELF);
	break;
}

include('templates/general/header.inc'); 
if(!session_is_registered("compilation_id")) {
	include('templates/compilation/start.inc');
}
else {
?>
<script language="javascript">
function popupPlayer(mp3_id, song_name) {
	mp3PlayerWin = window.open('<? print $baseURL; ?>/mp3Player.php?mp3_id=' + mp3_id + '&mp3_name=' + song_name, 'mp3PlayerWin', 'width=214,height=107,scrollbars=no,toolbar=no,titlebar=no,location=no,menubar=no,resizable=no,directories=no');
}
</script>
<?
	print "<h2>Custom " . $sitename . " Compilation CD Creation</h2>\n";
	include('templates/compilation/searchTracks.inc');
	if($action == "search") {
		$wherecl = "where username like '%" . $search_username . "%' and song_name like '%" . $search_song_name . "%'";
		if($search_genre) {
			$wherecl .= " and genre='" . $search_genre . "'";
		}
		$songs = vilw_result_array(vilw_query(vilw_sql_select($mp3s_cols, $mp3s_table, $wherecl)));
		include('templates/compilation/searchResults.inc');
	}
	$mode = "edit";
	include('templates/compilation/printList.inc');
}
include('templates/general/footer.inc');
?>
