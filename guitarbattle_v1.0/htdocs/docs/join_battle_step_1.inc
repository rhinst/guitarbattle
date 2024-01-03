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
          <td class="large">Step 1:</td>
         </tr>
         <tr>
          <td class="small_print">First, select the mp3 file from your computer by clicking on the "Browse..." button. <b>Please note that the maximum accepted file size for an mp3 is 650kb.</b></td>
         </tr>
         <tr>
          <td class="small_print">After selecting the proper mp3 file that you wish to enter into this GuitarBattle click on the "Next >>" button to continue to the next step in joining this battle. <b>Please make sure that you allow the browser to fully upload your mp3 file.</b></td>
         </tr>
         <tr><td class="item">&nbsp;</td></tr>
         <form method="post" action="docs/action_handler.php?action=join_battle&step=1" enctype="multipart/form-data">
          <input type="hidden" name="MAX_FILE_SIZE" value="665600">
          <input type="hidden" name="battle_id" value="<?php print("$battle_id"); ?>">
         <tr>
          <td class="main"><b>Your MP3 File:</b></td>
         </tr>
         <tr>
          <td class="item"><input type="file" name="file" size="30"></td>
         </tr>
         <tr>
          <td class="item"><input type="submit" value="Next >>"></td>
         </tr>
         </form>
        </table>
       </td>
      </tr>
     </table>
