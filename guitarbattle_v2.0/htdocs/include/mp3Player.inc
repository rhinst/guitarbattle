<?
	$mp3_url = $baseURL . "/loadSong.php?id=" . $mp3_id;
	$prefix = "";
	$mp3_name = $prefix . $mp3_name;
?>

<OBJECT classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000" codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=6,0,0,0" WIDTH="214" HEIGHT="107" id="mp3player" ALIGN="">
 <PARAM NAME=movie VALUE="/flash/mp3player.swf<? print("?url_location=" . urlencode($mp3_url) . "&filename=" . urlencode($mp3_name)); ?>">
 <PARAM NAME=quality VALUE=high> <PARAM NAME=bgcolor VALUE=#161B28>
 <EMBED src="/flash/mp3player.swf<? print("?url_location=" . urlencode($mp3_url) . "&filename=" . urlencode($mp3_name)); ?>" quality=high bgcolor=#161B28  WIDTH="214" HEIGHT="107" NAME="player" ALIGN="" TYPE="application/x-shockwave-flash" PLUGINSPAGE="http://www.macromedia.com/go/getflashplayer"></EMBED>
</OBJECT>
