     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700">
        <table width="700" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title">Change Password:</td>
         </tr>
         <tr>
<?
	if($origin == 2) {
?>
          <td class="item">Your password information request has been processed.</td>
<? 
	}
	else {
?>
          <td class="item">Your password has been reset as you have requested.</td>

<?
	}
?>
         </tr>
<?php
	if($origin == 2) {
?>
         <tr>
          <td class="item">Please check your e-mail for your user information.</td>
         </tr>
<?php
	}
?>
        </table>
       </td>
      </tr>
     </table>
