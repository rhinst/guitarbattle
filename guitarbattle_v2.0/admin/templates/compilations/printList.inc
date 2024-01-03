<table width="400" class="item" border="0" cellspacing="0" cellpadding="2">
  <tr>
    <th>Order #</th>
    <th>Name</th>
    <th>Order Date</th>
    <th>Status</th>
  </tr>
<?
foreach($orders as $order) {
	vilw_result_globalize($compilations_cols, $order);
	print "<tr>\n";
	print "<td><a href=\"" . $PHP_SELF . "?action=view&id=" . $id . "\">" . zero_pad($id, 6) . "</a></td>\n";
	print "<td>" . $ln . ", " . $fn . "</td>\n";
	print "<td>" . mysql_datetime_printable($order_date) . "</td>\n";
	print "<td>" . $status . "</td>\n";
	print "</tr>\n";
}
?>
</table>
