<br>
<table width="400" border="0" cellspacing="0" cellpadding="4">
<?
  foreach($links as $link) {
    vilw_result_globalize($links_cols, $link, "link_");
    print "<tr valign=\"bottom\">\n";
    print "<td style=\"background-color: #BB0000\" align=\"center\">\n";
    print "<a href=\"" . $link_link . "\"><span style=\"color: #ffffff; font-size: 12px\">" . $link_name . "</span></a>\n";
    print "</td>\n";
    print "</tr>\n";  
    print "<tr valign=\"top\">\n";
    print "<td align=\"center\">\n";
    print htmlspecialchars($link_description);
    print "</td>\n";
    print "</tr>\n";
}
?>
</table>
