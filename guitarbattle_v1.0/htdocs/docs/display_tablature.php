<?php
	include('gb.lib');

	$file_info = mysql_fetch_row(mysql_query("select file_tab from battle_mp3s where id=$id"));
	$file_tab = $file_info[0];
?>
<html>
 <head>
  <title>GuitarBattle.com: User Tablature</title>
  <link href="style.css" rel="stylesheet" type="text/css">
 </head>
 <body>
  <pre><?php print("$file_tab"); ?></pre>
 </body>
</html>
