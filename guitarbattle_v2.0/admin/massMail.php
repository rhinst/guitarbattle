<?
	include('templates/general/header.inc');
	switch($action) {
	case "mail":
		$wherecl = "";
		if($public == "1") {
			$wherecl = "where public = '1'";
		}	
		$users = vilw_result_array(vilw_query(vilw_sql_select($users_cols, $users_table, $wherecl)));

		$tolist = tempnam("/tmp/", "gb_mm_");
		$msgfile = tempnam("/tmp/", "gb_mm_");

		$fh = fopen($tolist, "w");
		foreach($users as $user) {
			vilw_result_globalize($users_cols, $user, "user_");
			fwrite($fh, $user_eml_addr . ":" . $user_fn . " " . $user_ln . "\n");
		}
		fclose($fh);

		$fh = fopen($msgfile, "w");
		fwrite($fh, "Subject: " . $subject . "\n");
		fwrite($fh, $message);
		fclose($fh);

		$result = `mmailer "$from_email" "$from_name" "$tolist" "$msgfile"`;
		include('templates/massMail/sending.inc');
		break;
	default:
		include('templates/massMail/form.inc');
		break;
	}
	include('templates/general/footer.inc');
	
?>
