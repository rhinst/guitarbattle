     <table cellpadding="0" cellspacing="0">
      <tr>
       <td width="700">
        <table width="700" cellpadding="2" cellspacing="0">
         <tr>
          <td class="item_title" colspan="2">Member Profiles:</td>
         </tr>
         <tr>
          <td class="item_light" width="150" valign="bottom">Username: </td>
          <td class="large" width="550"><?php print("$username"); ?></td>
         </tr>
         <tr>
          <td class="item_light" width="150" valign="top">Member Icon: </td>
          <td class="item" width="550"><img src="<?php print("$user_icon"); ?>" width="300" height="150"></td>
         </tr>
         <tr>
          <td class="item_light" width="150">Battles Entered: </td>
          <td class="item" width="550"><?php print("$battles_entered"); ?></td>
         </tr>
         <tr>
          <td class="item_light" width="150">Active Battles: </td>
          <td class="item" width="550"><?php print("$battles_active"); ?></td>
         </tr>
         <tr>
          <td class="item_light" width="150">Battles Won: </td>
          <td class="item" width="550"><?php print("$battles_won"); ?></td>
         </tr>
         <tr>
          <td class="item_light" width="150">Win Percentage: </td>
          <td class="item" width="550"><?php print("$win_percentage"); ?></td>
         </tr>
         <tr>
          <td class="item_light" width="150">Points: </td>
          <td class="item" width="550"><?php print("$user_points"); ?></td>
         </tr>
         <tr>
          <td class="item_light" width="150" valign="top">Name: </td>
          <td class="item" width="550"><?php print("$profile_name"); ?></td>
         </tr>
         <tr>
          <td class="item_light" width="150" valign="top">Nickname: </td>
          <td class="item" width="550"><?php print("$profile_nickname"); ?></td>
         </tr>
         <tr>
          <td class="item_light" width="150" valign="top">Location: </td>
          <td class="item" width="550"><?php print("$profile_location"); ?></td>
         </tr>
         <tr>
          <td class="item_light" width="150" valign="top">Influences: </td>
          <td class="item" width="550"><?php print("$profile_influences"); ?></td>
         </tr>
         <tr>
          <td class="item_light" width="150" valign="top">Occupation: </td>
          <td class="item" width="550"><?php print("$profile_occupation"); ?></td>
         </tr>
         <tr>
<?php include('member_profile_finished_battle_list.inc'); ?>
         </tr>
         <tr>
<?php include('member_profile_active_battle_list.inc'); ?>
         </tr>
        </table>
       </td>
      </tr>
     </table>
