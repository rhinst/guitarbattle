<?
include('templates/home/newsHeader.inc');
$news = get_news();
foreach($news as $news_item) {
	vilw_result_globalize($news_cols, $news_item, "news_");
	$printable_date = substr($news_timestamp, 4, 2) . "." . substr($news_timestamp, 6, 2) . "." . substr($news_timestamp, 0,4);
	print "<b style=\"color: #BB0000\">Posted by " . $news_posted_by . " on " . $printable_date . ":&nbsp;</b>\n";
	print $news_contents . "<br><img src=\"images/spacer.gif\" width=\"1\" height=\"3\"><br>\n";
}
include('templates/home/newsFooter.inc');
?>
