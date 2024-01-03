<?

switch($action) {
case "add":
	$date = date("Y-m-d H:i:s");
	vilw_query(vilw_sql_insert($poll_questions_cols, $poll_questions_table));
	break;
}

$polls = get_polls();

include('templates/general/header.inc');
include('templates/polls/addPoll.inc');
include('templates/polls/printList.inc');
include('templates/general/footer.inc');
?>
