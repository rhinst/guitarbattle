<?php
	//Dynamic Hit Counter
	//Simply include "$number_of_hits = hits()" on the page that you would like the counter on and remember to put include('counter.php'); at the top of the file.

	include('gb.lib');

	//Interval for additional hits from one IP: (hours * 10000)
	$time_interval = 20000; //Default = 2 hours
	
	$sqlcountertbl = "counter";

	function hits () {
		global $REMOTE_ADDR;
		$ip_address = $REMOTE_ADDR;

		$previous_hit = find_ip($ip_address);
		if(isset($previous_hit)) {
			update_hit($previous_hit);
		}
		else {
			insert_hit($ip_address);
		}

		$total_hits = get_total();
		return $total_hits;
	}

	function find_ip ($ip_address) {
		global $sqlcountertbl;
		$row = mysql_fetch_row(mysql_query("select id from $sqlcountertbl where ip_address='$ip_address'"));
		$hit_id = $row[0];
		return $hit_id;
	}

	function insert_hit ($ip_address) {
		global $sqlcountertbl;
		$hit_date = get_hit_time();
		$hostname = gethostbyaddr($ip_address);

		mysql_query("insert into $sqlcountertbl (ip_address, hostname, timestamp, hits) values ('$ip_address', '$hostname', '$hit_date', 1)");
	}

	function get_total() {
		global $sqlcountertbl;
		$row = mysql_fetch_row(mysql_query("select sum(hits) from $sqlcountertbl"));
		return $row[0];
	}

	function update_hit($hit_id) {
		global $sqlcountertbl;
		global $time_interval;
		$current_time = get_hit_time();

		$row = mysql_fetch_row(mysql_query("select timestamp, hits from $sqlcountertbl where id=$hit_id"));

		$total_hits = ($row[1] + 1);
		if($current_time > ($row[0] + $time_interval)) {
			mysql_query("update $sqlcountertbl set timestamp='$current_time', hits=$total_hits where id=$hit_id");
		}
	}

	function get_hit_time() {
		$proper_date = date(Y) . date(m) . date(d) . date(H) . date(i) . date(s);
                return $proper_date;
	}

?>
