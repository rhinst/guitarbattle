<br><br>
<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "search"); ?>
<table width="500" border="0" class="items" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td colspan="2" class="item_title">
      Search for Tracks:
    </td>
  </tr>
  <tr>
    <td align="right">
      Username:
    </td>
    <td align="left">
      <? vilw_input("search_username"); ?> 
    </td>
  </tr>
  <tr>
    <td align="right">
      Song Name:
    </td>
    <td align="left">
      <? vilw_input("search_song_name"); ?> 
    </td>
  </tr>
  <tr>
    <td align="right">
      Genre:
    </td>
    <td align="left">
      <?
        $genres = get_genres();
        vilw_select("search_genre", $genres); 
      ?>
    </td>
  </tr>
  <tr>
    <td colspan="2" align="center">
      <input class="button" type="submit" value="Search">
    </td>
  </tr>
</table>
</form>
