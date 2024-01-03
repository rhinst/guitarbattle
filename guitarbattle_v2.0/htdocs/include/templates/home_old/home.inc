            <table width="100%" border="0" cellspacing="0" cellpadding="0">
              <tr valign="top">
                <td width="100%" style="font-size: 0px">
                  <table width="100%" border="0" cellspacing="0" cellpadding="0">
                    <tr valign="top">
                      <td width="100%" style="font-size: 0px">
                        <? include('templates/home/news.inc'); ?>
                      </td>
                      <td width="204" align="center">
                        <?
				$user_profile_info = get_random_user_profile();
				vilw_result_globalize($profiles_cols, $user_profile_info, "featured_profile_");
				include('templates/home/featured.inc'); 
                        ?>
                      </td>
                    </tr>
                 </table>
                </td>
              </tr>
              <tr valign="top">
                <td style="font-size: 0px">
                  <table border="0" cellspacing="0" cellpadding="0">
                    <tr valign="top">
                      <td align="center">
			<?
				$battles = get_battle_list("not-complete", "", 10, "timestamp", "desc");
                        	include('templates/home/newBattles.inc'); 
			?>  
                      </td>
                      <td align="center">
			<?
				$battles = get_battle_list("in-progress", "", 10, "timestamp", "asc");
				$battles = vilw_result_array(vilw_query(vilw_sql_select($battles_cols, $battles_table, "where ((to_days(now()) - to_days(timestamp)) >= " . ($battle_duration - 2) . ") and active=1 and user2 != '' order by timestamp asc limit 10")));
                        	include('templates/home/endingBattles.inc');
			?>
                      </td>
                      <td align="center">
                        <?
				$logins = get_current_logins();
				include('templates/home/currentLogins.inc');
                        ?>
                      </td>
                    </tr>
                  </table> 
                </td>
              </tr>
            </table>
