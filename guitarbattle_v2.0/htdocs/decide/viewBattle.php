<?
require_login();

$voting_categories = get_voting_categories();
$votes_cols = get_votes_cols($voting_categories);

$voting_category_ids = Array();
foreach($voting_categories as $cat) {
  vilw_result_globalize($voting_categories_cols, $cat, "cat_");
  $voting_category_ids[] = $cat_id;
}

$battle_info = get_battle_info($battle_id);
vilw_result_globalize($battles_cols, $battle_info, "battle_");

if(!$battle_id) {
	include('templates/general/header.inc');
	$err_msg = "You have not selected a battle to view.";
	include('templates/viewBattle/error.inc');
	include('templates/general/footer.inc');
	exit;	
}

if(($battle_hide == 1) && ($authenticated_user != $battle_user1) && ($authenticated_user != $battle_user2) && ($authenticated_user != $battle_collab1) && ($authenticated_user != $battle_collab2)) {
	include('templates/general/header.inc');
	$err_msg = "This battle is not available for viewing at this time.";
	include('templates/viewBattle/error.inc');
	include('templates/general/footer.inc');
	exit;
}

switch($action) {
case "comment":
	if($comment) {
		$username = $authenticated_user;
		$timestamp = date("YmdHis");
		vilw_query(vilw_sql_insert($comments_cols, $comments_table));
	}
	header("Location: " . $PHP_SELF . "?battle_id=" . $battle_id);
	break;
case "vote":
	if(user_already_voted($authenticated_user, $battle_id)) {
	include('templates/general/header.inc');
		$err_msg = "You have already voted on this battle";
		include('templates/viewBattle/error.inc');
		include('templates/general/footer.inc');
		exit;
	}
	else if(($authenticated_user == $battle_user1) || ($authenticated_user == $battle_user2)) {
		include('templates/general/header.inc');
		$err_msg = "You may not rate your own battle.";
		include('templates/viewBattle/error.inc');
		include('templates/general/footer.inc');
		exit;
	}
	else {
		for($i = 1; $i <= 2; $i++) {
			$valar = Array($battle_id, $authenticated_user, $HTTP_POST_VARS["user" . $i]);
			foreach($voting_categories as $cat) {
				vilw_result_globalize($voting_categories_cols, $cat,  "cat_");
				$val = $HTTP_POST_VARS["cat_" . $cat_id . "_vote_" . $i];
				if(($val < $min_vote) || ($val > $max_vote)) {
					include('templates/general/header.inc');
					$err_msg = "Nice try, cheater.";
					include('templates/viewBattle/error.inc');
					include('templates/general/footer.inc');
					exit;
				}
				$valar[] = $val;
			}
			vilw_query(vilw_sql_insert($votes_cols, $votes_table, $valar));
			if($GLOBALS["battle_collab" . $i] != '') {
				$valar = Array($battle_id, $authenticated_user, $GLOBALS["battle_collab" . $i]);
				foreach($voting_categories as $cat) {
					vilw_result_globalize($voting_categories_cols, $cat,  "cat_");
					$valar[] = $HTTP_POST_VARS["cat_" . $cat_id . "_vote_" . $i];
				}
				vilw_query(vilw_sql_insert($votes_cols, $votes_table, $valar));
			}
		}
		count_vote($authenticated_user);
	}
	header("Location: " . $PHP_SELF . "?battle_id=" . $battle_id);
	break;
}


$comments = get_comments($battle_id);
$voters = get_voter_list($battle_id);

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
	include('templates/viewBattle/displayCompetitor.inc');
      ?>
    </td>
    <td width="20" align="center">
      <img src="images/spacer.gif" height="160" width="20" alt="" border="0"><br>VS.
    </td>
    <td width="200" align="center">
      <?
	if($battle_user2 != '') {
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
		include('templates/viewBattle/displayCompetitor.inc');
	}
	else if($battle_challenger != '') {
		include('templates/viewBattle/reserved.inc'); 
	}
	else if($battle_user1 == $authenticated_user) {
		include('templates/viewBattle/ownBattle.inc');
	}
	else {
		include('templates/viewBattle/openSpot.inc');
	}
      ?>
    </td>
  </tr>
<? if($battle_active == "0") { ?>
  <tr>
    <td colspan="3" align="center">
      <? include('templates/viewBattle/complete.inc'); ?>
    </td>
  </tr>
<? } ?>
  <tr>
    <td colspan="3" align="center">
      <br><br>
<?
  if(($battle_active == "1") && ($battle_user2 != '') && (!user_already_voted($authenticated_user, $battle_id)) && ($authenticated_user != $battle_user1) && ($authenticated_user != $battle_user2)) {
    include('templates/viewBattle/vote.inc'); 
  }
  else if($battle_user2 != '') {
    $voteResults = vilw_result_array(vilw_query(vilw_sql_select($votes_cols, $votes_table, "where battle_id='" . $battle_id . "'")));
    $totalVotes = count($voteResults) / 2;
    foreach($voting_category_ids as $cat_id) {
      $GLOBALS["cat_" . $cat_id . "_vote_1"] = 0;    
      $GLOBALS["cat_" . $cat_id . "_vote_2"] = 0;    
    }   
    foreach($voteResults as $vote) {
      vilw_result_globalize($votes_cols, $vote, "vote_");
      foreach($voting_category_ids as $cat_id) {
        if($vote_competitor == $battle_user1) {
	  $GLOBALS["cat_" . $cat_id . "_vote_1"] += $GLOBALS["vote_cat_" . $cat_id];
	}
	else {
	  $GLOBALS["cat_" . $cat_id . "_vote_2"] += $GLOBALS["vote_cat_" . $cat_id];
	}
      }
    }
    $total_score1 = 0;
    $total_score2 = 0;
    foreach($voting_category_ids as $cat_id) {
      if($totalVotes > 0) {
        $GLOBALS["cat_" . $cat_id . "_vote_1"] /= $totalVotes;
        $GLOBALS["cat_" . $cat_id . "_vote_2"] /= $totalVotes;
      }
      $total_score1 += $GLOBALS["cat_" . $cat_id . "_vote_1"];
      $total_score2 += $GLOBALS["cat_" . $cat_id . "_vote_2"];
    }   
    $total_score1 /= count($voting_category_ids);
    $total_score2 /= count($voting_category_ids);
    $total_score1 = round($total_score1, 2);
    $total_score2 = round($total_score2, 2);
    include('templates/viewBattle/voteResults.inc'); 
  }
  else {
    include('templates/viewBattle/noVoting.inc');
  }
?>
    </td>
  </tr>
  <tr>
    <td colspan="3" align="center">
      <? include('templates/viewBattle/battleInfo.inc'); ?>
    </td>
  </tr>
  <tr>
    <td colspan="3" align="center">
      <? include('templates/viewBattle/votingRoster.inc'); ?>
    </td>
  </tr>
  <tr>
    <td colspan="3" align="center">
      <? include('templates/viewBattle/printComments.inc'); ?>
    </td>
  </tr>
<? if($battle_active == "1") { ?>
  <tr>
    <td colspan="3" align="center">
      <? include('templates/viewBattle/addComment.inc'); ?>
    </td>
  </tr>
<? } ?>
</table>
<? include('templates/general/footer.inc'); ?>
