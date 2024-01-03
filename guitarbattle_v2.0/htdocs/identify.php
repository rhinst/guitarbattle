<? include('templates/general/header.inc'); ?>

<?

class mp3_info {
	var $isMp3;
	var $version;
	var $layer;
	var $bitRate;
	var $sampleRate;
};

//NOTE: Header might not be at 0 bytes. Search until you find the frame sync bytes. (which sucks)
// Reference Page: http://mpgedit.org/mpgedit/mpeg_format/MP3Format.html

if(($file) && ($file != "none")) {
	print "File type is " . $file_type . "<br>\n";
	$HEADER_SIZE = 4;
	$frame_header = fread(fopen($file, "r"), $HEADER_SIZE);
	$bytes = Array();
	for($i=0; $i<$HEADER_SIZE; $i++) {
		$bytes[$i] = ord($frame_header[$i]);
		print "Byte #" . $i . ": " . decbin($bytes[$i]) . "<br>\n";
	}
	print "<br><br>\n";
	if((($bytes[0] & 0xFF) == 0xFF) && (($bytes[1] & 0xE0) == 0xE0)) {
		print "Frame Sync Mask Matches<br>\n";
	}
	else {
		print "Frame Sync Mask DOES NOT Match<br>\n";
	}
	$version_mask = 0x18;
	print "Version: ";
	switch($version_mask & $bytes[1]) {
	case 0x0000:
		print "MPEG Version 2.5 (unofficial)";
		break;
	case 0x0008:
		print "reserved";
		break;
	case 0x0010:
		print "MPEG Version 2 (ISO/IEC 13818-3)";
		break;
	case 0x0018:
		print "MPEG Version 1 (ISO/IEC 11172-3)";
		break;
	default:
		print "Unknown";
	}
	print "<br>\n";
	$layer_mask = 0x06;
	print "Layer: ";
	switch($layer_mask & $bytes[1]) {
	case 0x0000:
		print "reserved";
		break;
	case 0x0002:
		print "III";
		break;
	case 0x004:
		print "II";
		break;
	case 0x006:
		print "I";
		break;
	default:
		print "Unknown";
	}
	print "<br>\n";
	$bitrate_mask = 0xF0;
	print "Bitrate: ";
}

?>
<form action="<? print $PHP_SELF; ?>" method="post" enctype="multipart/form-data">
<input type="file" name="file">
<input type="submit" value="Identify File Type">
</form>
<? include('templates/general/footer.inc'); ?>
