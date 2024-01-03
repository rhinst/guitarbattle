<?

include('gb.lib');
include('imgconvert.lib');

switch($action) {
case "delete":
	vilw_query("delete from user_icons where id=" . $id);
	break;
case "upload":
	if(($new_img) && ($new_img != "none")) {
		$contents = fread(fopen($new_img, "r"), filesize($new_img));
		$contents = getResizedContents($contents, 300, 150, true);


		vilw_query("lock table user_icons write");
		if(!($res = vilw_query("select min(user_id) from user_icons where user_id < -1 and id > -999"))) {
			vilw_query("unlock tables");
			print mysql_error();
			exit;
		}
		$row = mysql_fetch_row($res);
		if(!$row[0]) {
			$user_id = "-2";
		}
		else {
			$user_id = ($row[0]) - 1;
		}

		vilw_query("insert into user_icons (user_id, file_name, file_type, file_contents) values ('" . $user_id .  "','" . addslashes($new_img_name) . "','" . addslashes($new_img_type) . "','" .  addslashes($contents) . "')");
		

		vilw_query("unlock tables");
	}
	break;
}
$imgs = vilw_result_array(vilw_query("select id, user_id from user_icons where user_id < -1"));

include('header.inc');
?>

<script language="javascript">
function confirmDelete() {
	return(confirm('Are you sure you want to delete this profile icon?'));
}
</script>

<?
$i=0;
print "<table border=\"0\">\n";
foreach($imgs as $img) {
	if(($i % 2) == 0) {
		print "<tr>\n";
	}
	print "<td align=\"center\">\n";
	print "<img src=\"display_image.php?id=" . $img[1] . "\"  border=\"0\"><br>\n";
	print "<form action=\"" . $PHP_SELF . "\" method=\"post\" onSubmit=\"return(confirmDelete())\">\n";
	print "<input type=\"hidden\" name=\"action\" value=\"delete\">\n";
	print "<input type=\"hidden\" name=\"id\" value=\"" . $img[0] . "\">\n";
	print "<input type=\"submit\" value=\"Delete\">\n";
	print "</form>\n";
	print "</td>\n";
	if(($i % 2) == 1) {
		print "</tr>\n";
	}
	$i++;
}
if(($i % 2) == 1) {
print "<td>&nbsp;</td>\n</tr>\n";
}
print "</table>\n";
?>

<form action="<? print $PHP_SELF; ?>" method="post" enctype="multipart/form-data">
<input type="hidden" name="action" value="upload">
Upload a new profile pic:<input type="file" name="new_img">
<input type="submit" value="Upload">
</form>

<? include('footer.inc'); ?>
