<table class="items" width="175" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title">
      <? print $authenticated_user; ?>
    </td>
  </tr>
  <tr>
    <td>
      <a href="<? print $baseURL; ?>/preferences.php">&bull; Preferences</a>
    </td>
  </tr>
  <tr>
    <td>
      <a href="<? print $baseURL; ?>/password.php">&bull; Change Password</a>
    </td>
  </tr>
  <tr>
    <td>
      <a href="<? print $baseURL; ?>/viewProfile.php">&bull; View your Profile</a>
    </td>
  </tr>
  <tr>
    <td>
      <a href="<? print $baseURL; ?>/editProfile.php">&bull; Edit your Profile</a>
    </td>
  </tr>
</table>
