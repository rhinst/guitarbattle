<script language="javascript">
<!--//
  function checkUser(f, userNum) {
<?
    foreach($voting_categories as $cat) {
      vilw_result_globalize($voting_categories_cols, $cat, "cat_");
      print "ctl = f['cat_"  . $cat_id . "_vote_' + userNum];\n";
      print "if(ctl.selectedIndex == 0) {\n";
      print "  alert('You must fill out all the voting fields for both users.');\n";
      print "  ctl.focus();\n";
      print "  return false;\n";
      print "}\n"; 
    }
    print "return true;\n";
    
?>
  }

  function checkVotingForm() {
    f = document.voting_form;
    if(!checkUser(f, '1')) {
      return false;
    }

    return(checkUser(f, '2'));
  }
//-->
</script>
