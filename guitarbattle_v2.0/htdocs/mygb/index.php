<?
require_login();

switch($action) {
case "delete_messages":
	$wherecl = "where id in (";
	reset($delete_ids);
	while($delete_id = current($delete_ids)) {
		$wherecl .= $delete_id;
		if(next($delete_ids)) {
			$wherecl .= ",";
		}
	}
	$wherecl .= ")";
	vilw_query(vilw_sql_delete($messages_table, $wherecl));
	break;
}

$user_info = get_user_info($authenticated_user);
vilw_result_globalize($users_cols, $user_info, "user_");

include('templates/general/header.inc');
?>
<script language="javascript">
<!--//
function sendMessage() {
  window.open('include/templates/mygb/sendMessage.php', '', 'width=400,height=250');
}
//-->
</script>

<br>
<table width="100%" border="0" cellspacing="0" cellpadding="6">
  <tr valign="top">
    <td width="150" rowspan="3">
      <table border="0" cellpadding="0" cellspacing="0">
        <tr>
          <td>
            <? include('templates/mygb/menu.inc'); ?>
            <br>
          </td>
        </tr>
        <tr>
          <td>
            <? include('templates/general/battleStats.inc'); ?>
            <br>
          </td>
        </tr>
        <tr>
          <td>
            <?
               $battles = vilw_result_array(vilw_query(vilw_sql_select($battles_cols, $battles_table, "where (user1='" . $authenticated_user . "' or user2='" . $authenticated_user . "' or collab1=' " . $authenticated_user . "' or collab2='" . $authenticated_user . "') and active='1'")));
               include('templates/mygb/myBattles.inc'); 
            ?>
            <br>
          </td>
        </tr>
      </table>
    </td>
    <td>
      <table width="520" border="0" cellspacing="0" cellpadding="0">
        <tr valign="top">
          <td>
            <?
		$challenges = vilw_result_array(vilw_query(vilw_sql_select($battles_cols, $battles_table, "where user1='" . $authenticated_user . "' and challenger != '' and user2 = ''")));
		include('templates/mygb/challenges.inc');
            ?>
            <br>
          </td>
          <td>
            <? 
               $collabs = vilw_result_array(vilw_query(vilw_sql_select($battles_cols, $battles_table, "where ((user1='" . $authenticated_user . "' and collab1 != '') OR (collab1 = '" . $authenticated_user . "') OR (user2='" . $authenticated_user ."' and collab2 != '') OR (collab2 = '" . $authenticated_user . "')) AND active = '1'")));
               include('templates/mygb/collabs.inc');
            ?>    
          </td>
        </tr>
        <tr>
          <td>
            <?
		$challenges = vilw_result_array(vilw_query(vilw_sql_select($battles_cols, $battles_table, "where challenger='" . $authenticated_user . "' and user2 = '' and ((collab1 = '') OR (collab1_confirmed = 1 AND hide = 0) OR (collab1_confirmed = 1 AND collab2 != ''))")));
		include('templates/mygb/challenged.inc');
            ?>
          </td>
        </tr>
      </table>
    </td>
  </tr>
<?
   $messages = check_inbox($authenticated_user);
?>
  <tr>
    <td><? include('templates/mygb/inbox.inc'); ?>
    </td>
  </tr>
</table>
<?
include('templates/general/footer.inc');
?>
