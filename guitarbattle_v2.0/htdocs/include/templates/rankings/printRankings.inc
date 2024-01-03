<table class="items" width="300" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title" colspan="4">
      <b><? print $start_index; ?> to <? print $start_index + count($users) - 1; ?> of <? print $total_users; ?> Existing Users:</b>
    </td>
  </tr>
  <tr>
    <td class="item_title">Username</td>
    <td class="item_title"># Battles</td>
    <td class="item_title">Avg Score</td>
    <td class="item_title">Ranking</td>
  </tr>
<?
	$i = 0;
	foreach($users as $user) {
		vilw_result_globalize($users_cols, $user, "user_");
		$row_style = ($i % 2 == 0)?("listing_row1"):("listing_row2");
		print "<tr>\n";
                print "<td class=\"" . $row_style . "\" align=\"left\" width=\"125\"><a href=\"viewProfile.php?username=" . $user_username . "\">" . $user_username . "</a></td>\n";
                print "<td class=\"" . $row_style . "\" align=\"left\">" . $user_num_battles . "</td>\n";
                print "<td class=\"" . $row_style . "\" align=\"left\">" . number_format((($user_num_battles > 0)?($user_score_sum / $user_num_battles):("0")), 2) . "</td>\n";
                print "<td class=\"" . $row_style . "\" align=\"left\">" . $user_rank . "</td>\n";
                print "</tr>\n";
		$i++;
	}

	if(count($users) == 0) {
		print "<tr>\n";
                print "<td class=\"listing_row1\" align=\"left\" width=\"125\" colspan=\"4\">N/A</td>\n";
                print "</tr>\n";
	}
?>
</table>
<table width="300" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td align="left">
    <? if($start_index > 1) { ?>
      <form action="<? print $PHP_SELF; ?>" method="post">
      <? vilw_hidden("start_index", ($start_index -  $users_per_page)); ?>
      <input class="button" type="submit" value="Previous <? print $users_per_page; ?>">
      </form>
    <? } ?>
    </td>
    <td align="right">
    <? if(($start_index + $users_per_page - 1) < $total_users) { ?>
      <form action="<? print $PHP_SELF; ?>" method="post">
      <? vilw_hidden("start_index", ($start_index + $users_per_page)); ?>
      <input class="button" type="submit" value="Next <? print $users_per_page; ?>">
      </form>
    <? } ?>
    </td>
</table>
