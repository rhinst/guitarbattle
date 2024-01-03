<!-- Begin Search Bar -->
            <form action="<? print $baseURL; ?>/searchResults.php" method="post">
            <? vilw_hidden("action", "search"); ?>
            <table width="650" height="26" border="0" cellspacing="0" cellpadding="0">
              <tr valign="middle">
                <td style="background-image: url('images/search_bar.jpg'); font-size: 0px" width="590" height="26">
                  <table border="0" cellspacing="0" cellpadding="0">
                    <form action="<? print $PHP_SELF; ?>" method="post">
                    <tr valign="middle">
                      <td style="font-size: 0px">
                        <img src="images/spacer.gif" width="205" height="26" border="0" alt="">
                      </td>
                      <td style="font-size: 0px">
                        <img src="images/search_box_left.gif" border="0" alt="" width="16" height="16">
                      </td>
                      <td style="font-size: 0px">
                        <input class="searchbox" type="text" name="searchKeyword" size="15">
                      </td>
                      <td style="font-size: 0px">
                        <img src="images/search_box_right.gif" border="0" alt="" width="16" height="16">
                      </td>
                    </tr>
                    </form>
                  </table>
                </td>
                <td style="font-size: 0px">
                  <img src="images/spacer.gif" height="26" border="0" alt="">
                </td>
              </tr>
            </table>
            </form>
<!-- End Search Bar -->
