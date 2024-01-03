     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700">
        <table width="700" cellpadding="2" cellspacing="0">
         <form method="post" action="docs/action_handler.php?action=post_message">
         <input type="hidden" name="battle_id" value="<?php print("$battle_id"); ?>">
         <input type="hidden" name="post_user" value="<?php print("$current_user"); ?>">
         <tr>
          <td class="item_title">Post A Message: [Battle #<?php print("$battle_id"); ?>]</td>
         </tr>
         <tr>
          <td class="item">You are logged in as: <b><?php print("$current_user"); ?></b></td>
         </tr>
         <tr>
          <td class="item">Message:</td>
         </tr>
         <tr>
          <td class="item"><textarea name="message" rows="5" cols="40"></textarea></td>
         </tr>
         <tr>
          <td class="item"><input type="submit" value="Post Message"></td>
         </tr>
        </table>
       </td>
      </tr>
     </table>
