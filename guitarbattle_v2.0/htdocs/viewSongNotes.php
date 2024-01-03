<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=us-ascii"> 
  <link href="include/style.css" rel="stylesheet" type="text/css">
  <title><? print $sitename; ?></title>
</head>
<body style="font-family: courier">
<?
  $res = vilw_query(vilw_sql_select($mp3s_cols, $mp3s_table, "where id='" . $id . "'"));
  $row = mysql_fetch_row($res);
  vilw_result_globalize($mp3s_cols, $row, "mp3_"); 
  print "<b>" . htmlspecialchars($mp3_song_name) . "</b><br><br>\n";
  print nl2br(htmlspecialchars($mp3_notes));
?>
<br><br>
</body>
</html>
