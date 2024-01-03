     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="349" valign="top">
        <table width="349" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title">GuitarBattle.com Links:</td>
         </tr>
<?php
	$res = mysql_query("select url from links");
	while($link = mysql_fetch_row($res)) {
		print("         <tr><td class=\"item\"><a class=\"small\" target=\"_blank\" href=\"" . $link[0] . "\">" . $link[0] . "</a></td></tr>\n");
	}
?>
         <tr><td class="item">...</td></tr>
         <tr><td class="item"><a href="index.php?location=submit_link" onMouseOver="window.status='Submit a Link'; return true;" onMouseOut="window.status=''; return true;">Submit a Link</a></td></tr>
        </table>
       </td>
       <td width="2" valign="top"><img src="images/2px_spacer.jpg"></td>
       <td width="349" valign="top">
<?php include('right_column.inc'); ?>
       </td>
      </tr>
     </table>
