<table border="0" cellspacing="0" cellpadding="0">
  <tr valign="middle">
    <td align="center">
      <? if($battle_challenger == $authenticated_user) { ?>
        <a href="joinBattle.php?battle_id=<? print $battle_id; ?>">Accept this Challenge</a><br> 
        <a href="declineBattle.php?battle_id=<? print $battle_id; ?>">Decline this Challenge</a><br> 
      <? } else { ?>
        This battle is reserved for <a href="viewProfile.php?username=<? print $battle_challenger; ?>"><? print $battle_challenger; ?></a>, who has not yet accepted the challenge.

      <? } ?>
    </td>
  </tr>
    
</table>
