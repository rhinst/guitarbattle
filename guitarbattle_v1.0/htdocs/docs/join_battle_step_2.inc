     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700" valign="top">
        <table width="700" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title">Join this Battle:</td>
         </tr>
         <tr>
          <td class="item">You are logged in as: <b><?php print("$current_user"); ?></b></td>
         </tr>
         <tr>
          <td class="large">Step 2:</td>
         </tr>
         <tr>
          <td class="small_print">If you would like to include a short tablature of your clip select the "Use the following tablature:" option below. If you do not wish to include a tablature simply select the "Do not include tablature" option.</td>
         </tr>
         <tr>
          <td class="small_print">Please note that the tablature will be displayed exactly as entered in the text box below in a unicode font.</td>
         </tr>
         <tr>
          <td class="small_print">To complete the join battle process click on the "Join Battle" button.</td>
         </tr>
         <tr><td class="item">&nbsp;</td></tr>
         <tr>
          <td class="main"><b>Tablature:</b></td>
         </tr>
         <form method="post" action="docs/action_handler.php?action=join_battle&step=2">
         <tr>
          <td class="item"><input type="radio" name="tablature" value="0" checked> Do not include tablature.</td>
         </tr>
         <tr>
          <td class="item"><input type="radio" name="tablature" value="1"> Use the following tablature:</td>
         </tr>
         <tr>
          <td class="item"><textarea name="file_tab" rows="10" cols="60">Type Tablature Here:</textarea></td>
         </tr>
         <tr>
          <td class="item"><input type="submit" value="Start Battle"></td>
         </tr>
         <input type="hidden" name="battle_id" value="<?php print("$battle_id"); ?>">
         </form>
        </table>
       </td>
      </tr>
     </table>
