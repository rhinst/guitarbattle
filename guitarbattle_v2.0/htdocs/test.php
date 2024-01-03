<?
include('templates/general/header.inc');
?>
<script language="javascript">
function popShitUp() {
	mp3PlayerWin = window.open('mp3Player.php?mp3_id=164&mp3_name=test', '', 'width=214,height=107,scrollbars=no,toolbar=no,titlebar=no,location=no,menubar=no,resizable=no,directories=no,fullscreen=yes');
	//mp3PlayerWin.resizeTo(214,106);
	mp3PlayerWin.resizeTo(230,106);
	mp3PlayerWin.moveTo(300,300);
}
</script>

<a href="#" onClick="popShitUp()">Click me you fucker</a>
<?
include('templates/general/footer.inc');
?>
