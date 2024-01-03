<?
if(!$username) {
	$username = $authenticated_user;
}

$profile_info = get_profile_info($username);
$user_info = get_user_info($username);
vilw_result_globalize($profiles_cols, $profile_info, "profile_");
vilw_result_globalize($users_cols, $user_info, "user_");

include('templates/general/header.inc');
include('templates/viewProfile/printProfile.inc');
?>
<script language="javascript">
<!--//
function sendMessage() {
  window.open('include/templates/mygb/sendMessage.php?to_user=<? print $username; ?>', '', 'width=400,height=250');
}
//-->
</script>

<a href="#" onClick="sendMessage()">Send a message to this user</a>
<br>
<br>
<?
include('templates/general/battleStats.inc');
include('templates/general/footer.inc'); 
?>
