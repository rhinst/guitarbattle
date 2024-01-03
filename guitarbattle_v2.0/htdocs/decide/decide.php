<?
require_login();
require_judge();

$battle_info = get_battle_info($battle_id);
vilw_result_globalize($battles_cols, $battle_info, "battle_");

if(!$battle_id) {
	include('templates/general/header.inc');
	$err_msg = "You have not selected a battle to view.";
	include('templates/decide/error.inc');
	include('templates/general/footer.inc');
	exit;	
}

if(($battle_hide == 0) || ($battle_active == 1) || ($battle_winner != '') || ($battle_score1 != $battle_score2)) {
	include('templates/general/header.inc');
	$err_msg = "This battle is not available for decision at this time.";
	include('templates/decide/error.inc');
	include('templates/general/footer.inc');
	exit;
}

switch($action) {
case "vote":
	if(judge_already_voted($authenticated_user, $battle_id)) {
	include('templates/general/header.inc');
		$err_msg = "You have already voted on this battle";
		include('templates/decide/error.inc');
		include('templates/general/footer.inc');
		exit;
	}
	else if(($authenticated_user == $battle_user1) || ($authenticated_user == $battle_user2) || ($authenticated_user == $battle_collab1) || ($authenticated_user == $battle_collab2)) {
	include('templates/general/header.inc');
		$err_msg = "You may not decide your own battle.";
		include('templates/decide/error.inc');
		include('templates/general/footer.inc');
		exit;
	}
	else {
		$judge = $authenticated_user;
		vilw_query(vilw_sql_insert($decisions_cols, $decisions_table));

		$res = vilw_query("select count(*) as num_judges from " . $users_table . " where judge='1'");
		$num_judges = mysql_result($res, 0, 'num_judges');
		$res = vilw_query("select count(*) as num_voted from " . $decisions_table . " where battle_id='" . $battle_id . "'");
		$num_voted = mysql_result($res, 0, 'num_voted');
		if($num_judges == $num_voted) {
			$res = vilw_query("select count(*) as user1_votes from " . $decisions_table . " where battle_id='" . $battle_id . "' and competitor='" . $battle_user1 . "'");
			$user1_votes = mysql_result($res, 0, 'user1_votes');
			$res = vilw_query("select count(*) as user2_votes from " . $decisions_table . " where battle_id='" . $battle_id . "' and competitor='" . $battle_user2 . "'");
			$user2_votes = mysql_result($res, 0, 'user2_votes');
			$winner = ($user1_votes > $user2_votes)?($battle_user1):($battle_user2);
			vilw_query("update " . $battles_table . " set hide='0', winner='" . $winner . "' where id='" . $battle_id . "'");
		}
		header("Location: " . $baseURL . "/decide/index.php");
		exit;
	}
	break;
}


include('templates/general/header.inc');

?>
<br>
<table width="420" border="0" cellspacing="0" cellpadding="0">
  <tr valign="top">
    <td width="200" align="center">
      <?
	$competitor_username = $battle_user1;
	$collab_username = $battle_collab1;
	$competitor_song_id = $battle_file1;
	$profile = get_profile($battle_user1);
	if($battle_collab1 != '') {
		$collab_profile = get_profile($battle_collab1);
	}
	$res = vilw_query(vilw_sql_select($mp3s_cols, $mp3s_table, "where id='" . $battle_file1 . "'"));
	$row = mysql_fetch_row($res);
	vilw_result_globalize($profiles_cols, $profile, "profile_");
	vilw_result_globalize($profiles_cols, $collab_profile, "collab_profile_");
	vilw_result_globalize($mp3s_cols, $row, "mp3_");
	include('templates/decide/displayCompetitor.inc');
      ?>
    </td>
    <td width="20" align="center">
      <img src="images/spacer.gif" height="160" width="20" alt="" border="0"><br>VS.
    </td>
    <td width="200" align="center">
      <?
	$competitor_username = $battle_user2;
	$collab_username = $battle_collab2;
	$competitor_song_id = $battle_file2;
	$profile = get_profile($battle_user2);
	if($battle_collab2 != '') {
		$collab_profile = get_profile($battle_collab2);
	}
	$res = vilw_query(vilw_sql_select($mp3s_cols, $mp3s_table, "where id='" . $battle_file2 . "'"));
	$row = mysql_fetch_row($res);
	vilw_result_globalize($profiles_cols, $profile, "profile_");
	vilw_result_globalize($profiles_cols, $collab_profile, "collab_profile_");
	vilw_result_globalize($mp3s_cols, $row, "mp3_");
	include('templates/decide/displayCompetitor.inc');
      ?>
    </td>
  </tr>
  <tr>
    <td colspan="3" align="center">
      <? include('templates/decide/battleInfo.inc'); ?>
    </td>
  </tr>
</table>
<? include('templates/general/footer.inc'); ?>
