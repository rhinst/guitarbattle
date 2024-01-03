<br>
<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "update_prefs"); ?>
<table class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title" colspan="2">
      User Preferences
    </td>
  </tr>
  <tr>
    <td align="right">
      WebAmp MP3 Player:
    </td>
    <td align="left">
      <? vilw_select("pref_popup_player", $webamp_options, $popup_player, "", "", true); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      Chat Window
    </td>
    <td align="left">
      <? vilw_select("pref_embed_chat", $chat_options, $embed_chat, "", "", true); ?>
    </td>
  </tr>
  <tr>
    <td colspan="2" align="center">
      <input class="button" type="submit" value="Update Preferences">
    </td>
  </tr>
</table>
</form>
