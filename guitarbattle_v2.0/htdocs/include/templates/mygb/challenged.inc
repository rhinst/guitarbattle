<table class="items" width="250" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title">
      You have <? print count($challenges); ?> challenge(s) to respond to:
    </td>
  </tr>
<?
  foreach($challenges as $challenge) {
    vilw_result_globalize($battles_cols, $challenge, "battle_");
?>
  <tr>
    <td>
      <a href="<? print $baseURL; ?>/viewBattle.php?battle_id=<? print $battle_id; ?>"><? print $battle_user1 . (($battle_collab1)?(" / " . $battle_collab1):("")); ?></a>
    </td>
  </tr>
<?
  }
?>
</table>
