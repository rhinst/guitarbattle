#!/usr/local/bin/php -q
<?

include('gb.lib');

function get_mp3_info2($song_contents) {

	$mp3_info = new mp3_info();

	$mp3_info->size  = strlen($song_contents);
	$frame_sync_mask = Array(0xFF, 0xE0);
	$offset = -1;
	$chunk_size = ($mp3_info->size < 4096)?($mp3_info->size):(4096);
	for($i = 0; $i < $chunk_size; $i++) {
		if(((ord($song_contents[$i]) & $frame_sync_mask[0]) == $frame_sync_mask[0]) && ((ord($song_contents[$i+1]) & $frame_sync_mask[1]) == $frame_sync_mask[1])) {
			$offset = $i;
			break;
		}
	}
	if($offset == -1) {
		return(false);
	}

	$frame_header = substr($song_contents, $offset, 4);
		
	$version_mask = 0x18;
	$version_bits = (ord($frame_header[1]) & $version_mask);
	switch($version_bits) {
	case 0x00:
		$mp3_info->mpeg_version = 2.5;
		break;
	case 0x08:
		$mp3_info->mpeg_version = 0;
		break;
	case 0x10:
		$mp3_info->mpeg_version = 2;
		break;
	case 0x18:
		$mp3_info->mpeg_version = 1;
		break;
	}
	$layer_mask = 0x06;
	$layer_bits = (ord($frame_header[1]) & $layer_mask);
	switch($layer_bits) {
	case 0x00:
		$mp3_info->mpeg_layer = 0;
		break;
	case 0x02:
		$mp3_info->mpeg_layer = 3;
		break;
	case 0x04:
		$mp3_info->mpeg_layer = 2;
		break;
	case 0x06:
		$mp3_info->mpeg_layer = 1;
		break;
	}
	$bitrate_matrix = Array(Array(  0,   0,   0,   0,   0,   0),
				Array( 32,  32,  32,  32,   8,   8),
				Array( 64,  48,  40,  48,  16,  16),
				Array( 96,  56,  48,  56,  24,  24),
				Array(128,  64,  56,  64,  32,  32),
				Array(160,  80,  64,  80,  40,  40),
				Array(192,  96,  80,  96,  48,  48),
				Array(224, 112,  96, 112,  56,  56),
				Array(256, 128, 112, 128,  64,  64),
				Array(288, 160, 128, 144,  80,  80),
				Array(320, 192, 160, 160,  96,  96),
				Array(352, 224, 192, 176, 112, 112),
				Array(384, 256, 224, 192, 128, 128),
				Array(416, 320, 256, 224, 144, 144),
				Array(448, 384, 320, 256, 160, 160),
				Array( -1,  -1,  -1,  -1,  -1,  -1));
				
	$bitrate_mask = 0xF0;
	$bitrate_bits = (ord($frame_header[2]) & $bitrate_mask);
	if($mp3_info->mpeg_version == 1)  {
		$mp3_info->bitrate = $bitrate_matrix[$bitrate_bits / 16][$mp3_info->mpeg_layer - 1];
	}
	else {
		$mp3_info->bitrate = $bitrate_matrix[$bitrate_bits / 16][$mp3_info->mpeg_layer + 2];
	}

	$sample_rate_matrix = Array(	Array(44100, 22050, 11025),
					Array(48000, 24000, 12000),
					Array(32000, 16000,  8000),
					Array(   -1,    -1,    -1));
	$sample_rate_mask = 0x0C;
	$sample_rate_bits = (ord($frame_header[2]) & $sampe_rate_mask);
	if(($mp3_info->mpeg_version == 1) || ($mp3_info->mpeg_version == 2)) {
		$mp3_info->sample_rate = $sample_rate_matrix[$sample_rate_bits / 4][$mp3_info->mpeg_version - 1];
	}
	else {
		$mp3_info->sample_rate = $sample_rate_matrix[$sample_rate_bits / 4][2];
	}
	$channel_mask = 0xC0;
	$channel_bits = (ord($frame_header[3]) & $channel_mask);
	switch($channel_bits) {
	case 0x00:
		$mp3_info->channel_mode = "Stereo";
		break;
	case 0x40:
		$mp3_info->channel_mode = "Joint Stereo";
		break;
	case 0x80:
		$mp3_info->channel_mode = "Dual Channel Mono";
		break;
	case 0xC0:
		$mp3_info->channel_mode = "Single Channel Mono";
		break;
	}

	return($mp3_info);
}

$res = vilw_query(vilw_sql_select($mp3s_cols, $mp3s_table));
while($row = mysql_fetch_row($res)) {
	vilw_result_globalize($mp3s_cols, $row);
	$mp3_info = get_mp3_info2($file_contents);
	vilw_query("update " . $mp3s_table . " set mpeg_version='" . $mp3_info->mpeg_version . "', mpeg_layer='" . $mp3_info->mpeg_layer . "', bitrate='" . $mp3_info->bitrate . "', sample_rate = '" . $mp3_info->sample_rate . "', channel_mode = '" . $mp3_info->channel_mode . "' where id='" . $id . "'");
}

?>
