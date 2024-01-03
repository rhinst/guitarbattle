<?

require_login();

switch($action) {
case "update_prefs":
	$username = $authenticated_user;
	$popup_player = $pref_popup_player;
	$embed_chat = $pref_embed_chat;
	vilw_query(vilw_sql_replace($preferences_cols, $preferences_table));	
	header("location: " . $PHP_SELF . "?updated=1");
	exit;
	break;
}

$webamp_options = Array(Array(0, "Embed in Browser"),
			Array(1, "Popup Window"));
$chat_options = Array(Array(0, "No Chat Frame"),
			Array(1, "Embedded Chat Frame"));

if(($popup_player = get_preference("popup_player")) == "") {
	$popup_player = 0;
}

if(($embed_chat = get_preference("embed_chat")) == "") {
	$embed_chat = 1;
}

include('templates/general/header.inc');
if($updated) {
	print "Your preferences have been updated.<br>\n";
}
include('templates/preferences/editPrefs.inc');
include('templates/general/footer.inc');
?>
