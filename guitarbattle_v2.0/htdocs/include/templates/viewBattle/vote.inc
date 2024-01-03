<? include('templates/viewBattle/votingCheckForm.inc'); ?>
<form name="voting_form" action="<? print $PHP_SELF; ?>" method="post" onSubmit="return(checkVotingForm());">
<? vilw_hidden("action", "vote"); ?>
<? vilw_hidden("battle_id"); ?>
<? vilw_hidden("user1", $battle_user1); ?>
<? vilw_hidden("user2", $battle_user2); ?>
<table border="0" cellspacing="0" cellpadding="2">
  <tr>
    <td colspan="3" align="center">
      <b class="large_text">Vote on this Battle:</b>
    </td>
  </tr>
  <tr>
    <td align="center">
      <?
          $usernum = "1";
	  $competitor_username = $battle_user1;
          include('templates/viewBattle/votingForm.inc');
      ?>
    </td>
    <td>&nbsp;</td>
    <td align="center">
      <?
          $usernum = "2";
          $competitor_username = $battle_user2;
          include('templates/viewBattle/votingForm.inc');
      ?>
    </td>
  </tr>
  <tr>
    <td colspan="3" align="center">
      <input class="button" type="submit" value="Submit Vote">
    </td>
  </tr>
</table>
</form>
