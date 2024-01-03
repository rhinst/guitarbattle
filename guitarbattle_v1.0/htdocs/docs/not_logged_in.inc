<?php
	if(!isset($location)) {
		$location = urlencode($REQUEST_URI);
	}
	else {
		$location = urlencode($location);
	}
?>
     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700" valign="top">
        <table width="700" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title">Notice:</td>
         </tr>
         <tr>
          <td class="item"><b class="alarm">You must be logged in to perform this action.</b><br><br><a href="index.php?action=login&goto=<?php print("$location"); ?>" onMouseOver="window.status='Login'; return true;" onMouseOut="window.status=''; return true;">Click Here</a> to login.<br><br>If you are not currently a member please <a href="index.php?action=join" onMouseOver="window.status='Join GuitarBattle.com Now'; return true;" onMouseOut="window.status=''; return true;">Click Here</a> to join now.</td>
         </tr>
        </table>
       </td>
      </tr>
     </table>
