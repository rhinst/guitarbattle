<?
	include('templates/general/header.inc');

	switch($action) {
	  case("cancel"): {
	    break;
	  }
	  default: {
	    if(isset($username)) {
	      $users = vilw_result_array(vilw_query(vilw_sql_select($users_cols, $users_table, "where username='" . $username . "'")));
	      vilw_result_globalize($users_cols, $users[0]);
	      $login_info = vilw_result_array(vilw_query(vilw_sql_select($logins_cols, $logins_table, "where username='" . $username . "'")));
	      if(count($login_info)) {
		vilw_result_globalize($logins_cols, $login_info[0], "login_");
	      }

	      include('templates/userInfo/form.inc');
	    }
	  }
	}

	include('templates/general/footer.inc');
?>
