     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700" valign="top">
        <table width="700" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title">Start a Battle:</td>
         </tr>
         <tr>
          <td class="item">You are logged in as: <b><?php print("$current_user"); ?></b></td>
         </tr>
         <tr>
          <td class="large">Step 1:</td>
         </tr>
         <tr>
          <td class="small_print">First, select the category that you wish to begin a battle in.</td>
         </tr>
         <tr>
          <td class="small_print">Second, select the mp3 file from your computer by clicking on the "Browse..." button. <b>Please note that the maximum accepted size for an mp3 file is 650kb.</b></td>
         </tr>
         <tr>
          <td class="small_print">After selecting the proper mp3 file that you wish to enter into a GuitarBattle click on the "Next >>" button to continue to the next step in starting a battle. <b>Please make sure that you allow the browser to fully upload your mp3 file.</b></td>
         </tr>
         <tr><td class="item">&nbsp;</td></tr>
         <tr>
          <td class="main"><b>Battle Category:</b></td>
         </tr>
         <form method="post" action="docs/action_handler.php?action=start_battle&step=1" enctype="multipart/form-data">
          <input type="hidden" name="MAX_FILE_SIZE" value="665600">
         <tr>
          <td class="item">
           <select name="parent_category">
<?php
	$get_categories = mysql_query("select id, name from battle_categories");
	while($category_info = mysql_fetch_row($get_categories)) {
		$category_id = $category_info[0];
		$category_name = $category_info[1];
		if($category_id != $battle_category) {
			print("            <option value=\"$category_id\">$category_name</option>\n");
		}
		else {
			print("            <option value=\"$category_id\" selected>$category_name</option>\n");
		}
	}
?>
           </select>
          </td>
         </tr>
         <tr><td class="item">&nbsp;</td></tr>
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
