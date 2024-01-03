<?

  if($collab_username != '') {
    if($profile_icon != 0) { 
      $bg_img = "viewImage.php?id=" . $profile_icon . "&width=" . floor($user_icon_width / 2) . "&height=" . floor($user_icon_height / 2);
    }
    else {
      $bg_img = "images/no_image_half.jpg";
    }

    if($collab_profile_icon != 0) {
      $bg_img2 = "viewImage.php?id=" . $collab_profile_icon . "&width=" . floor($user_icon_width / 2) . "&height=" . floor($user_icon_height / 2);
    }
    else {
      $bg_img2 = "images/no_image_half.jpg";
    }
  }
  else {
    if($profile_icon != 0) { 
      $bg_img = "viewImage.php?id=" . $profile_icon;
    }
    else {
      $bg_img = "images/no_image.jpg";
    }

  }

  if($battle_winner == '') {
    $fg_img = "images/spacer.gif";
  }
  else {
    $fg_img = ($competitor_username == $battle_winner)?("images/winner.gif"):("images/loser.gif"); 
  }
?>
<table border="0" width="<? print $user_icon_width; ?>" height="<? print $user_icon_height; ?>" cellspacing="0" cellpadding="0">
  <tr>
<? if ($collab_username == '') { ?>
     <td align="center" style="font-size: 0px; background-image: url('<? print $bg_img; ?>')" width="<? print $user_icon_width; ?>" height="<? print $user_icon_height; ?>">
     <a href="viewProfile.php?username=<? print $competitor_username; ?>"><img src="<? print $fg_img; ?>" width="<? print $user_icon_width; ?>" height="<? print $user_icon_height; ?>" border="0" alt="<? print $competitor_username; ?>"></a>
     </td>
<? } else { ?>
     <td align="left" style="font-size: 0px; background-image: url('<? print $bg_img; ?>')" width="<? print floor($user_icon_width / 2); ?>" height="<? print floor($user_icon_height / 2); ?>">
       <a href="viewProfile.php?username=<? print $competitor_username; ?>"><img src="<? print $fg_img; ?>" width="<? print floor($user_icon_width / 2); ?>" height="<? print floor($user_icon_height / 2); ?>" border="0" alt="<? print $competitor_username; ?>"></a>
     </td>
     <td align="right" style="font-size: 0px" width="<? print floor($user_icon_width / 2); ?>" height="<? print floor($user_icon_height / 2); ?>">
       <img src="images/top_right_div.jpg" width="<? print floor($user_icon_width / 2); ?>" height="<? print floor($user_icon_height / 2); ?>" border="0" alt="">
     </td>
   </tr>
   <tr>
     <td align="left" style="font-size: 0px" width="<? print floor($user_icon_width / 2); ?>" height="<? print floor($user_icon_height / 2); ?>">
       <img src="images/bottom_left_div.jpg" width="<? print floor($user_icon_width / 2); ?>" height="<? print floor($user_icon_height / 2); ?>" border="0" alt="">
     </td>
     <td align="right" style="font-size: 0px; background-image: url('<? print $bg_img2; ?>')" width="<? floor(print $user_icon_width / 2); ?>" height="<? print floor($user_icon_height / 2); ?>">
       <a href="viewProfile.php?username=<? print $collab_username; ?>"><img src="<? print $fg_img; ?>" width="<? print floor($user_icon_width / 2); ?>" height="<? print floor($user_icon_height / 2); ?>" border="0" alt="<? print $collab_username; ?>"></a>
     </td>

<? } ?>
  </tr>
</table>
