<?
	//MySQL Settings:
	$dbhost = "localhost";
	$dbuser = "guitarbattle";
	$dbpass = "20gb02";
	$dbname = "gb_new";

	//Database Settings:
	$backings_table = "backings";
	$battles_table = "battles";
	$battles_temp_table = "battles_temp";
	$comments_table = "comments";
	$compilations_table = "compilations";
	$decisions_table = "decisions";
	$genres_table = "genres";
	$images_table = "images";
	$links_table = "links";
	$logins_table = "logins";
	$messages_table = "messages";
	$mp3s_table = "mp3s";
	$news_table = "news";
	$poll_answers_table = "poll_answers";
	$poll_questions_table = "poll_questions";
	$preferences_table = "preferences";
	$profiles_table = "profiles";
	$ranks_table = "ranks";
	$todo_table = "todo";
	$track_lists_table = "track_lists";
	$users_table = "users";
	$users_temp_table = "users_temp";
	$votes_table = "votes";
	$voting_categories_table = "voting_categories";


	$backings_cols = Array("id", "mp3_id", "name", "description");
	$battles_cols = Array("id", "user1", "user2", "collab1", "collab1_confirmed", "collab2", "collab2_confirmed", "challenger", "backing", "timestamp", "genre", "file1", "file2", "score1", "score2", "winner", "active", "hide");
	$battles_temp_cols = Array("id", "user1", "user2", "collab1", "collab1_confirmed", "collab2", "collab2_confirmed", "challenger", "backing", "timestamp", "genre", "file1", "file2", "score1", "score2", "winner", "active", "hide");
	$comments_cols = Array("id", "battle_id", "username", "comment", "timestamp");
	$compilations_cols = Array("id", "fn", "ln", "address", "city", "state", "province", "zip", "country", "phone", "email", "status", "order_date", "payment_date", "creation_date", "ship_date", "payment_confirmed_by", "created_by", "shipped_by", "notes", "quantity", "amount_paid", "transaction_id");
	$decisions_cols = Array("id", "battle_id", "judge", "competitor");
	$genres_cols = Array("id", "name");
	$images_cols = Array("id", "file_type", "file_contents");
	$links_cols = Array("id", "link", "name", "description");
	$logins_cols = Array("username", "ip_addr", "login_ts", "last_active");
	$messages_cols = Array("id", "from_user", "to_user", "timestamp", "subject", "body", "new", "unread");
	$mp3s_cols = Array("id", "id_battle", "username", "collab", "file_name", "file_type", "file_size", "file_contents", "song_name", "notes", "views", "mpeg_version", "mpeg_layer", "bitrate", "sample_rate", "channel_mode", "genre");
	$news_cols = Array("id", "title", "timestamp", "posted_by", "contents");
	$poll_answers_cols = Array("id", "poll_id", "username", "choice");
	$poll_questions_cols = Array("id", "date", "question", "active", "answer_0", "answer_1", "answer_2", "answer_3", "votes_0", "votes_1", "votes_2", "votes_3");
	$preferences_cols = Array("username", "popup_player", "embed_chat"); 
	$profiles_cols = Array("username", "icon", "name", "age", "gender", "influences", "gear", "location", "occupation", "eml", "website", "how_long");
	$ranks_cols = Array("id", "name", "num_battles", "score");
	$todo_cols = Array("id", "item", "open");
	$track_lists_cols = Array("compilation_id", "mp3_id", "track_number", "track_length", "username", "collab", "genre", "song_name");
	$users_cols = Array("username", "password", "eml_addr", "grp", "mod", "fn", "ln", "address", "city", "state", "zip", "country", "telephone", "public", "join_date", "ip_addr", "score_sum", "num_battles", "num_wins", "vote_bank", "rank", "judge", "alt_judge");
	$users_temp_cols = Array("username", "password", "eml_addr", "fn", "ln", "address", "city", "state", "zip", "country", "telephone", "confirm_id", "public", "join_date", "ip_addr");
	$voting_categories_cols = Array("id", "name");

	//Connect to MySQL:
	$db = vilw_connect($dbhost, $dbuser, $dbpass, $dbname);
?>
