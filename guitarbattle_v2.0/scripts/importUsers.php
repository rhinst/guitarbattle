#!/usr/local/bin/php -q
<?
/*
  This script will import all users from the old guitarbattle.com database to the new one
*/

include('gb.lib');

$old_db = "guitarbattle";
$new_db = "gb_new";

$old_users_cols = Array("id", "username", "password", "firstname", "lastname", "email_address", "privacy", "join_date", "last_login", "win_percent", "points");
$old_profiles_cols = Array("id", "user_id", "image_id", "name", "nickname", "location", "influences", "occupation");
$old_images_cols = Array("id", "user_id", "file_name", "file_type", "file_contents");

vilw_select_db($old_db);

$old_users = vilw_result_array(vilw_query(vilw_sql_select($old_users_cols, "users")));
$old_profiles = vilw_result_array(vilw_query(vilw_sql_select($old_profiles_cols, "user_profiles")));
$old_images = vilw_result_array(vilw_query(vilw_sql_select($old_images_cols, "user_icons")));

vilw_select_db($new_db);

print "Importing User Accounts...";
foreach($old_users as $old_user) {
	vilw_result_globalize($old_users_cols, $old_user, "old_");
	$res = vilw_query(vilw_sql_select($users_cols, "users", "where username='" . $old_username . "'"));
	if(mysql_num_rows($res) == 1) {
		continue;
	}
	$username = $old_username;
	$password = $old_password;
	$eml_addr = $old_email_address;
	$grp = 0;
	$mod = 0;
	$fn = $old_firstname;
	$ln = $old_lastname;
	$address = "";
	$city = "";
	$state = "";
	$province = "";
	$zip = "";
	$country = "";
	$telephone = "";
	$rank = "";
	$public = ($old_privacy == 1)?(0):(1);
	$join_date = $old_join_date;
	$ip_addr = "";
	vilw_query(vilw_sql_insert($users_cols, "users"));
}
print "Done.\n";

print "Importing User Profiles...";
foreach($old_profiles as $old_profile) {
	if(vilw_result_globalize($old_profiles_cols, $old_profile, "old_")) {
		$username = vilw_lookup($old_users, $old_user_id, 0, 1);
		$res = vilw_query(vilw_sql_select($profiles_cols, "profiles", "where username='" . $username . "'"));
		if(mysql_num_rows($res) == 1) {
			continue;
		}
		$icon = 0;
		$name = $old_name;
		$influences = $old_influences;
		$location = $old_location;
		$occupation = $old_occupation;
		$website = "";
		$how_long = "";
		vilw_query(vilw_sql_insert($profiles_cols, "profiles"));
	}
}
print "Done.\n";

print "Importing User Icons...";
foreach($old_images as $old_image) {
	if(vilw_result_globalize($old_images_cols, $old_image, "old_")) {
		$username = vilw_lookup($old_users, $old_user_id, 0, 1);
		$file_type = $old_file_type;
		$file_contents = $old_file_contents;
		vilw_query(vilw_sql_insert($images_cols, "images"));
		$new_img_id = mysql_insert_id();
		vilw_query("update profiles set icon='" . $new_img_id . "' where username='" . $username . "'");
	}
}
print "Done.\n";


?>
