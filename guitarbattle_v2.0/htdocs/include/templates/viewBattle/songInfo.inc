<table class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title" colspan="2"> 
      Song Details
    </td>
  </tr>
  <tr>
    <td align="right">
      Song Length:
    </td>
    <td align="left">
      <? print readable_time(round(($mp3_file_size / ($mp3_bitrate * 1000)) * 8)); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      File Size:
    </td>
    <td align="left">
      <? print readable_size($mp3_file_size); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      Mpeg Format:
    </td>
    <td align="left">
      Version <? print $mp3_mpeg_version; ?>, Layer <? print $mp3_mpeg_layer; ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      Bit Rate:
    </td>
    <td align="left">
      <? print $mp3_bitrate; ?> Kbps
    </td>
  </tr>
  <tr>
    <td align="right">
      Sample Rate:
    </td>
    <td align="left">
      <? print $mp3_sample_rate; ?> Hz
    </td>
  </tr>
  <tr>
    <td colspan="2" align="center">
      <? PRINT $mp3_channel_mode; ?> 
    </td>
  </tr>
</table>
