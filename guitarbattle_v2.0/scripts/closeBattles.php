#!/usr/local/bin/php -q
<?
/*
  This script will close finished battles
*/

include('gb.lib');

$finished_battles = vilw_result_array(vilw_query(vilw_sql_select($battles_cols, $battles_table, "where ((to_days(now()) - to_days(timestamp)) >= " . $battle_duration) . ") and active = 1 and hide = 0 and winner = '' and user2 != ''"));
$voting_categories = get_voting_categories();
$votes_cols = get_votes_cols($voting_categories);

$cat_ids = Array();
foreach($voting_categories as $cat) {
	vilw_result_globalize($voting_categories_cols, $cat, "cat_");
	$cat_ids[] = $cat_id;	
}
$num_categories = count($cat_ids);

$tie_battle_ids = Array();
$alt_judge_battles = Array();
$judges = vilw_result_array(vilw_query(vilw_sql_select($users_cols, $users_table, "where judge='1'")));
foreach($finished_battles as $battle) {
	vilw_result_globalize($battles_cols, $battle, "battle_");
	print "Closing battle " . $battle_id . "\n";
	for($i=1; $i<=2; $i++) {
		$userScore = 0.0;
		$averageScore = 0.0;
		$scores = vilw_result_array(vilw_query(vilw_sql_select($votes_cols, $votes_table, "where battle_id='" . $battle_id . "' and competitor='" . $GLOBALS["battle_user" .$i] . "'")));
		$num_scores = count($scores);
		foreach($scores as $score) {
			vilw_result_globalize($votes_cols, $score, "score_");
			foreach($cat_ids as $cat_id) {
				$userScore += $GLOBALS["score_cat_" . $cat_id];
			}
		}
		if($num_scores > 0) {
			$averageScore = $userScore / ($num_scores * $num_categories);
		}
		$GLOBALS["score" . $i] = $averageScore;
	}
	if($score1 == $score2) {
		$hide = 1;
		$winner = '';
		$num_judges = count($judges);
		if(is_judge($battle_user1)) {
			$num_judges--;	
		}	
		if(is_judge($battle_user2)) {
			$num_judges--;	
		}	
		if(is_judge($battle_collab1)) {
			$num_judges--;	
		}	
		if(is_judge($battle_collab2)) {
			$num_judges--;	
		}

		if(($num_judges % 2) == 0) {
			//TODO: need an alternate judge to make an odd # of votes
			$alt_judge_battles[] = $battle_id;
		}

		$tie_battle_ids[] = $battle_id;
	}
	else {
		$hide = 0;
		$winner = ($score1 > $score2)?($battle_user1):($battle_user2);
	}
	vilw_query("update battles set score1='" . $score1 . "', score2='" . $score2 . "', winner='" . $winner . "', active=0, hide='" . $hide . "' where id='" . $battle_id . "'");
	vilw_query("update users set score_sum = score_sum + " . $score1 . ", num_battles = num_battles + 1" . (($winner == $battle_user1)?(", num_wins = num_wins + 1"):("")) . " where username='" . $battle_user1 . "'");
	if($battle_collab1 != '') {
		vilw_query("update users set score_sum = score_sum + " . $score1 . ", num_battles = num_battles + 1" . (($winner == $battle_user1)?(", num_wins = num_wins + 1"):("")) . " where username='" . $battle_collab1 . "'");
	}
	vilw_query("update users set score_sum = score_sum + " . $score2 . ", num_battles = num_battles + 1" . (($winner == $battle_user2)?(", num_wins = num_wins + 1"):("")) . " where username='" . $battle_user2 . "'");
	if($battle_collab2 != '') {
		vilw_query("update users set score_sum = score_sum + " . $score2 . ", num_battles = num_battles + 1" . (($winner == $battle_user2)?(", num_wins = num_wins + 1"):("")) . " where username='" . $battle_collab2 . "'");
	}
}

if(count($tie_battle_ids) > 0) {
	$body = "There are " . count($tie_battle_ids) . " tied battles awaiting decision. Please go to the following URL to cast your vote for the winner:\n\n" . $baseURL . "/decide/";
	foreach($judges as $judge) {
		vilw_result_globalize($users_cols, $judge, "judge_");
		mail($judge_eml_addr, "Tie Battles Awaiting Decision", $body, "From: webmaster@guitarbattle.com");
	}
}

if(count($alt_judge_battles) > 0) {
	$body = "There are " . count($alt_judge_battles) . " tied battles that require an alternate judge.  Please go to the following URL to cast your vote for the winner:\n\n" . $baseURL . "/decide/";
	$res = vilw_query("select eml_addr from " . $users_table . " where alt_judge='1'");
	$alt_judge = mysql_result($res, 0, 'username');
	mail($alt_judge, "Tie Battles Awaiting Decision", $body, "From: webmaster@guitarbattle.com");
}


// Calculate new ranks
$users = vilw_result_array(vilw_query(vilw_sql_select($users_cols, $users_table)));
foreach($users as $user) {
	vilw_result_globalize($users_cols, $user, "user_");
	$new_rank = calculate_rank($user_num_battles, $user_score_sum);
	vilw_query("update " . $users_table . " set rank='" . $new_rank . "' where username='" . $user_username . "'");
}
?>
