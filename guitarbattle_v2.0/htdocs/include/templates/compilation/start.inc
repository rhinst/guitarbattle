<br><br>
<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "start"); ?>
<table width="500" border="0" cellspacing="0" cellpadding="4">
  <tr>
    <td align="center">
      <img src="<? print $baseURL; ?>/images/compilation_cd.gif" border="0" alt="Compilation CDs from <? print $sitename; ?>">
    </td>
    <td align="center">
      <table border="0" cellspacing="0" cellpadding="0">
        <tr>
          <td align="center">
            <h2>Custom <? print $sitename; ?> Compilation CD's</h2>
          </td>
        </tr>
        <tr>
          <td align="center">
            Now you can listen to all your favorite <? print $sitename; ?> songs on your stereo, in your car, or anywhere you want! Hand-select tracks for a custom <? print $sitename; ?> compilation CD. Each CD can consist of up to <? print $max_compilation_length; ?> minutes of your favorite songs from the site. Click "Start New Compilation" below to check it out.<br>
          </td>
        </tr>
        <tr>
          <td align="center">
            <br><h2>$<? print number_format($compilation_cost); ?> Each</h2>
          </td>
        </tr>
        <tr>
          <td align="center">
            plus shipping and tax (where applicable)
          </td>
        </tr>
        <tr>
          <td align="center">
            <br><br>
            <input class="button" type="submit" value="Start New Compilation">
          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
</form>
