<br><br>
<table width="350" border="0" cellspacing="0" cellpadding="4">
<tr>
  <td align="center">
    The tracks listed below are provided free of charge as backing tracks for you to play over. If you have any backing tracks you'd like to donate to the library, feel free to e-mail them to <a href="mailto: <? print $webmaster_address; ?>"><? print $webmaster_address; ?></a>
  </td>
</tr>
<?
  foreach($backings as $backing) {
    vilw_result_globalize($backings_cols, $backing, "backing_");
?>
  <tr>
    <td class="item_title">
      <? print htmlspecialchars($backing_name); ?> (<a style="color: #ffffff" href="loadSong.php?id=<? print $backing_mp3_id; ?>">Download</a>)
    </td>
  </tr>
  <tr>
    <td>
      <? print nl2br(htmlspecialchars($backing_description)); ?><br><br>
    </td>
  </tr>
<?
  }
?>
</table>
