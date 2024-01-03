<?php
	if($error == 1) {
?>
     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700">
        <table width="700" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title">Notice:</td>
         </tr>
         <tr>
          <td class="item"><b class="alarm">Your vote failed. Please go back and resubmit your vote.</b></td>
         </tr>
        </table>
       </td>
      </tr>
     </table>
<?php
	}
	else if($error == 2) {
?>
     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700">
        <table width="700" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title">Notice:</td>
         </tr>
         <tr>
          <td class="item"><b class="alarm">You have already voted on this battle. Please note that you may only vote on each battle once.</b></td>
         </tr>
        </table>
       </td>
      </tr>
     </table>
<?php
	}
?>
