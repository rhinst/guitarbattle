<?
require_login();

if(session_is_registered("authenticated_user")) {
	$username = $authenticated_user;

	switch($action) {
	case "update":
		if(($new_icon) && ($new_icon != "none")) {
			$file_type = $new_icon_type;
			$file_contents = vilw_get_resized_imagefile_contents($new_icon, $user_icon_width, $user_icon_height, true);
			vilw_query(vilw_sql_insert($images_cols, $images_table));
			$icon = mysql_insert_id();
		}
		else {
			$icon = $old_icon;
		}
		if(substr($website, 0, strlen("http://")) != "http://") {
			$website = "http://" . $website;
		}
		vilw_query(vilw_sql_replace($profiles_cols, $profiles_table));
		break;
	}


	$profile_info = get_profile_info($username);
	vilw_result_globalize($profiles_cols, $profile_info, "profile_");
}

include('templates/general/header.inc');
include('templates/editProfile/form.inc');
include('templates/general/footer.inc'); 
?>
