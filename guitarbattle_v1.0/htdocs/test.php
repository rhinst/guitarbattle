<?

 include('gb.lib');
if(gb_mail("rob@villageworld.com", "SubjecT", "message", "rob@guitarbattle.com", "Some Guy")) {
	print "mail worked";
}
else {
	print "Mail failed";
}

?>
