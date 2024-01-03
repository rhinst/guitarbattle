<?
include('templates/general/header.inc'); 
$backings = vilw_result_array(vilw_query(vilw_sql_select($backings_cols, $backings_table, "order by name asc")));
include('templates/backings/printListing.inc');
include('templates/general/footer.inc'); 
?>
