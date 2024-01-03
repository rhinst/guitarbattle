<table class="items" width="250" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title">
      You have <? print count($collabs); ?> collaboration(s) in progress:
    </td>
  </tr>
<?
  foreach($collabs as $collab) {
    vilw_result_globalize($battles_cols, $collab, "battle_");
?>
  <tr>
    <td>
      <?
        if($battle_user1 == $authenticated_user) {
		$partner = $battle_collab1;
	}
	else if($battle_collab1 == $authenticated_user) {
		$partner = $battle_user1;
	}
	else if($battle_user2 == $authenticated_user) {
		$partner = $battle_collab2;
	}
	else {
		$partner = $battle_user2;
	}
      ?>
      <a href="<? print $baseURL; ?>/completeCollab.php?battle_id=<? print $battle_id; ?>"><? print $partner; ?></a>
    </td>
  </tr>
<?
  }
?>
</table>
