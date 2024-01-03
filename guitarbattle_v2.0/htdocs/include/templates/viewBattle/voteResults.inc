<table class="items" width="300" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title" colspan="3" align="center">
      Voting Results for this Battle:
    </td>
  </tr>
  <tr>
    <td align="left">
      <?
          $usernum = "1";
	  $competitor_username = $battle_user1;
	  $collab_username = $battle_collab1;
          include('templates/viewBattle/competitorVoteResults.inc');
      ?>
    </td>
    <td>&nbsp;</td>
    <td align="right">
      <?
          $usernum = "2";
	  $competitor_username = $battle_user2;
	  $collab_username = $battle_collab2;
          include('templates/viewBattle/competitorVoteResults.inc');
      ?>
    </td>
  </tr>
</table>
