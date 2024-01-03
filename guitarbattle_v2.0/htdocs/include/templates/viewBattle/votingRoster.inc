			<br>
			<table border="0" cellpadding="0" cellspacing="0"><tr><td>
                        <table class="items" width="175" border="0" cellpadding="4" cellspacing="0">
			  <tr>
			    <td class="item_title" width="175">Voting Roster:</td>
			  </tr>
			  <tr>
			    <td>
<?
	while($voter = current($voters)) {
                print "<a href=\"" . $baseURL . "/viewProfile.php?username=" . $voter . "\">" . $voter . "</a>";
		if(next($voters)) {
			print(", ");
		}
	}
	if(count($voters) == 0) {
		print "&nbsp;";
	}
?>
			    </td>
			  </tr>
                        </table>
			</td></tr></table>
