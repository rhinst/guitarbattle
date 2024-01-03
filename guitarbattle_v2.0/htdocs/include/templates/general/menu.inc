<!-- Start Menu -->
<table width="270" border="0" cellspacing="0" cellpadding="0"><tr><td align="center">
<table border="0" cellspacing="0" cellpadding="0">
  <tr valign="middle">
    <td>
      <a class="menu_link" href="<? print $baseURL; ?>/index.php">Home</a>
    </td>
    <td width="5" rowspan="4" style="font-size: 0px">
      <img src="images/spacer.gif" width="5" border="0" alt=""> 
    </td>
    <td rowspan="4" style="font-size: 0px">
      <img src="images/menu_separator.jpg" border="0" alt=""> 
    </td>
    <td width="5" rowspan="4" style="font-size: 0px">
      <img src="images/spacer.gif" width="5" border="0" alt=""> 
    </td>
    <td>
      <a class="menu_link" href="<? print $baseURL; ?>/startBattle.php">Start Battle</a>
    </td>
    <td width="5" rowspan="4" style="font-size: 0px">
      <img src="images/spacer.gif" width="5" border="0" alt=""> 
    </td>
    <td rowspan="4" style="font-size: 0px">
      <img src="images/menu_separator.jpg" border="0" alt=""> 
    </td>
    <td width="5" rowspan="4" style="font-size: 0px">
      <img src="images/spacer.gif" width="5" border="0" alt=""> 
    </td>
    <td>
      <a class="menu_link" href="<? print $baseURL; ?>/rules.php">Rules</a>
    </td>
    <td width="5" rowspan="4" style="font-size: 0px">
      <img src="images/spacer.gif" width="5" border="0" alt=""> 
    </td>
    <td rowspan="4" style="font-size: 0px">
      <img src="images/menu_separator.jpg" border="0" alt=""> 
    </td>
    <td width="5" rowspan="4" style="font-size: 0px">
      <img src="images/spacer.gif" width="5" border="0" alt=""> 
    </td>
    <td>
      <a class="menu_link" href="<? print $baseURL; ?>/store.php">GB Stores</a>
    </td>
  </tr>
  <tr valign="middle">
    <td>
      <? if(session_is_registered("authenticated_user")) { ?>
      <a class="menu_link" href="http://<? print $myDomainName; ?>">My GB</a>
      <? } else { ?>
      <a class="menu_link" href="<? print $baseURL; ?>/join.php">Join</a>
      <? } ?>
    </td>
    <td>
      <a class="menu_link" href="<? print $baseURL; ?>/listBattles.php?status=open">Join Battle</a>
    </td>
    <td>
      <a class="menu_link" href="<? print $baseURL; ?>/backings.php">Backings</a>
    </td>
    <td>
      <a class="menu_link" href="<? print $baseURL; ?>/bugReport.php">Report a Bug</a>
    </td>
  </tr>
  <tr valign="middle">
    <td>
      <? if(session_is_registered("authenticated_user")) { ?>
      <a class="menu_link" href="<? print $baseURL; ?>/index.php?action=logout" target="_top">Logout</a>
      <? } else { ?>
      <a class="menu_link" href="<? print $baseURL; ?>/login.php">Login</a>
      <? } ?>
    </td>
    <td>
      <a class="menu_link" href="<? print $baseURL; ?>/listBattles.php">List Battles</a>
    </td>
    <td>
      <a class="menu_link" href="<? print $baseURL; ?>/mboard/">Forums</a>
    </td>
    <td>
      <a class="menu_link" href="<? print $baseURL; ?>/contact.php">Contact</a>
    </td>
  </tr>
  <tr valign="middle">
    <td>
      <a class="menu_link" href="<? print $baseURL; ?>/rankings.php">Rankings</a>
    </td>
    <td>
      <a class="menu_link" href="<? print $baseURL; ?>/tournament.php">Tournaments</a>
    </td>
    <td>
      <a class="menu_link" href="<? print $baseURL; ?>/chatOptions.php">Chat</a>
    </td>
    <td>
      <a class="menu_link" href="<? print $baseURL; ?>/links.php">Links</a>
    </td>
  </tr>
</table>
</td></tr></table>
<!-- End Menu -->
