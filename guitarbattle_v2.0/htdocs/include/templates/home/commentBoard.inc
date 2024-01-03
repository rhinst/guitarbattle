                  <table width="100%" border="0" cellspacing="0" cellpadding="0">
                    <tr>
                      <td rowspan="3" style="background-image: url('images/news_frame_left.jpg'); font-size: 0px" width="20" height="198">
                        <img src="images/spacer.gif" border="0" alt="" width="20" height="198">
                      </td>
                      <td style="background-image: url('images/news_frame_top.jpg'); font-size: 0px" height="14">
                        <img src="images/spacer.gif" border="0" alt="" width="1" height="14">
                      </td>
                      <td rowspan="3" style="background-image: url('images/news_frame_right.jpg'); font-size: 0px" width="13" height="198">
                        <img src="images/spacer.gif" border="0" alt="" width="13" height="198">
                      </td>
                    </tr>
                    <tr valign="top">
                      <td height="170" style="background-color: #F1EDEE">
                        <b>Comment Board:</b>
                        <iframe src="include/templates/home/commentBoard.php" frameborder="0" width="100%" height="155"></iframe>
                      </td>
                    </tr>
                    <tr valign="top">
                      <td style="background-image: url('images/news_frame_bottom.jpg'); font-size: 0px" height="14">
                        <img src="images/spacer.gif" border="0" alt="" width="1" height="14">
                      </td>
                    </tr>
                  <? if(session_is_registered("authenticated_user")) { ?>
                    <tr>
                      <td colspan="3" align="center">
                        <form action="<? print $PHP_SELF; ?>" method="post">
                        <? vilw_hidden("action", "comment"); ?>
                        <b>Post a comment:</b>
                        <? vilw_input("comment", 30); ?>
                        <input class="button" type="submit" value="Post">
                        </form>
                      </td>
                    </tr>
                  <? } ?>
                  </table>

