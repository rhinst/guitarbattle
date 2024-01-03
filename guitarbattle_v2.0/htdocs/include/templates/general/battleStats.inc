<table class="items" width="175" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title" colspan="2" align="left">
      Battle Statistics: <b class="title_light"><? print $username; ?></b>
    </td>
  </tr> 
  <tr>
    <td class="listing_row1_bold" align="right" valign="top">
      Rank:
    </td>
    <td class="listing_row1" align="left">
      <? print $user_rank; ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row1_bold" align="right" valign="top">
      Record:
    </td>
    <td class="listing_row1" align="left">
      <? print $user_num_wins; ?>-<? print ($user_num_battles - $user_num_wins); ?>
    </td>
  </tr>
  <tr>
    <td class="listing_row1_bold" align="right" valign="top">
      Average Score:
    </td>
    <td class="listing_row1" align="left">
      <? print number_format((($user_num_battles > 0)?($user_score_sum / $user_num_battles):("0.0")), 2); ?>
    </td>
  </tr>
</table>
