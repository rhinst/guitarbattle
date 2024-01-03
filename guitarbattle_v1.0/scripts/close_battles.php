#!/usr/local/bin/php -q
<?
	include('gb.lib');

	// how long a battle should last (in days)
	$battle_life	= 7;

	// admin contact info
	$admin_email = "webmaster@guitarbattle.com";


	function get_startdate_cutoff() {
		// returns what date a battle must have started before (or on) 
		// in order to be eligible to be closed on this batch.
		global $battle_life;
		return(strtotime("-" . $battle_life . " days"));
	}

	function get_finished_battles() {
		// returns a list of id's for all battles that should be closed (battles where winner = 0 and user2 != 0 and the proper amount of time has passed)
		global $db;

		$sql = "SELECT id, user1, user2 FROM battles WHERE unix_timestamp(timestamp) <= '" . get_startdate_cutoff() . "' AND winner = 0 AND user2 != 0";

		if(!($res = mysql_query($sql, $db))) {
			print "MySQL Error: " . mysql_error($db) . "\n";
			print "SQL: " . $sql . "\n";
			exit;
		}

		$list = Array();

		while($row = mysql_fetch_row($res)) {
			$list[] = Array($row[0], $row[1], $row[2]);
		}	
		
		return($list);
	}

	function update_user_info($user, $outcome) {
		//update the user's win_percent field according to the battle's outcome (0=Loss, 1=Win)

		$prev_wins = mysql_fetch_row(mysql_query("select count(*) from battles where winner=" . $user));

		$user_wins = ($prev_wins[0] + $outcome);
		$prev_finished = mysql_fetch_row(mysql_query("select count(*) from battles where ((user1=" . $user . " or user2=" . $user . ") and winner!=0)"));

		$user_finished_battles = ($prev_finished[0] + 1);

		$user_win_percent = round((($user_wins / $user_finished_battles) * 100), 2);
		mysql_query("update users set win_percent='" . $user_win_percent . "' where id='" . $user . "'");
	}

	function close_battle($id, $user1, $user2) {
		global $admin_email;

		//close the battles (select a winner, delete vote info [except totals] and update users' win_percent field)
		$timestamp = date("Y-m-d H:i:s");
		print "Closing battle " . $id . "\n";
		$res = mysql_query("select count(*) from battle_votes where battle_id=" . $id . " and competitor_id=" . $user1);
		$user1_votes = mysql_fetch_row($res);
		$res = mysql_query("select count(*) from battle_votes where battle_id=" . $id . " and competitor_id=" . $user2);
		$user2_votes = mysql_fetch_row($res);

		if($user1_votes[0] > $user2_votes[0]) {
			$battle_winner = $user1;
			$hide = 0;
			update_user_info($user1, 1);
			update_user_info($user2, 0);
		}
		else if($user2_votes[0] > $user1_votes[0]) {
			$battle_winner = $user2;
			$hide = 0;
			update_user_info($user1, 0);
			update_user_info($user2, 1);
		}
		else if($user1_votes[0] == $user2_votes[0]){
			$battle_winner = 0;
			$hide = 1;
			mail("$admin_email", "Tie Battle Awaits Decision...", "The following battle has ended with a tie. Please decide on the winner of the battle and update the users' win percentages.\n\nBattle ID: $id\nUser1 ID (Votes): $user1 ($user1_votes[0])\nUser2 ID (Votes): $user2 ($user2_votes[0])\nBattle Link:\nhttp://www.guitarbattle.com/battles.php?mode=view_battle&battle_id=$id\n\n-GuitarBattle.com", "From: battle_ender@guitarbattle.com");
		}
		mysql_query("update battles set active=0, hide=" . $hide . ", timestamp='" . $timestamp . "', votes1=" . $user1_votes[0] . ", votes2=" . $user2_votes[0] . ", winner=" . $battle_winner . " where id=" . $id);
		mysql_query("update users set points=points+" . $user1_votes[0] . " where id=" . $user1);
		mysql_query("update users set points=points+" . $user2_votes[0] . " where id=" . $user2);
		mysql_query("delete from battle_votes where battle_id=" . $id);
	}

	$battle_ids = get_finished_battles();

	print "Found " . count($battle_ids) . " battles to close.\n";

	reset($battle_ids);
	while($battle = current($battle_ids)) {
		close_battle($battle[0], $battle[1], $battle[2]);
		next($battle_ids);
	}
?>
