<table class="items" width="300" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title">
      <b><? print count($new_users); ?> New Users:</b>
    </td>
  </tr>
<?
	$i = 0;
	foreach($new_users as $user) {
		vilw_result_globalize($users_cols, $user, "user_");
		$row_style = ($i % 2 == 0)?("listing_row1"):("listing_row2");
		print "<tr>\n";
                print "<td class=\"" . $row_style . "\" align=\"left\" width=\"125\"><a href=\"viewProfile.php?username=" . $user_username . "\">" . $user_username . "</a></td>\n";
                print "</tr>\n";
		$i++;
	}

?>
</table>
<br><br>
