<?
  $status_array = Array(
		Array("open", "Open"),
		Array("in-progress", "In Progress"),
		Array("complete", "Finished"));

  $vote_check_array = Array(
		Array("vote", "Have Voted"),
		Array("novote", "Have Not Voted"));

  $limit_array = Array("5", "10", "25", "50");

  $order_array = Array(
		Array("timestamp", "Date"));

?>

<br>
<table class="items" width="400" border="0" cellspacing="0" cellpadding="4">
<form action="<? print $PHP_SELF; ?>" method="post">
  <tr>
    <td class="item_title" align="left" colspan="4">
      Search Criteria:
    </td>
  <tr>
    <td align="right">
      Status:
    </td>
    <td align="left">
      <? vilw_select("status", $status_array); ?>
    </td>
    <td align="right">
      Genre:
    </td>
    <td align="left">
      <? vilw_select("genre", get_genres()); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      User:
    </td>
    <td align="left">
      <? vilw_input("username", 20); ?>
    </td>
    <td align="right">
      Vote Status:
    </td>
    <td align="left">
      <? vilw_select("vote_check", $vote_check_array); ?>
    </td>
  </tr>
  <tr>
    <td>&nbsp;</td>
    <td align="left">
      <? vilw_select("limit", $limit_array, "", "", "", true); ?> Results per page.
    </td>
    <td align="right">
      Order By:
    </td>
    <td>
      <? vilw_select("order_by", $order_array); ?>
    </td>
  </tr>
  <tr>
    <td colspan="4" align="center">
      <input class="button" type="submit" value="List Battles">
    </td>
  </tr>
</form>
</table>
