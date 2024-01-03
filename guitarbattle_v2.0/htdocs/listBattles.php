<?
include('templates/general/header.inc'); 

//Defaults:
if(!$start_limit)  {
	$start_limit = 0;
}
if(!$status) {
	$status = "";
}
if(!$genre) {
	$genre = "";
}
if(!$username) {
	$username = "";
}
if(!$vote_check) {
	$vote_check = "";
}
if(!$limit) {
	$limit = "10";
}
if(!$order_by) {
	$order_by = "timestamp";
}
if(!$order) {
	$order = "desc";
}
if(!isset($active)) {
	if($status == "complete") {
 		$active = "0"; 
	}
	else {
		$active = "1";
	}
}
if(!isset($hide)) {
	$hide = "0";
}

/*
TODO: set values of variables used in function below, 
based on what type of battles we want to list (as determined by vars passed to page)
*/
switch($status) {

}

$limit_str = $start_limit . "," . $limit;
$battles = get_battle_list($status, $genre, $username, $vote_check, $limit_str, $order_by, $order, $active, $hide);

include('templates/listBattles/filter.inc');
include('templates/listBattles/listing.inc');
include('templates/listBattles/pageNav.inc');

include('templates/general/footer.inc'); 
?>
