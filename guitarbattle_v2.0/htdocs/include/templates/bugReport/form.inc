<script language="javascript">
<!--//
function checkScreenRes() {
	return(window.screen.width + "x" + window.screen.height); 
}

function checkColorDepth() {
	return(window.screen.colorDepth + ' bpp'); 
}

function checkJava() {
	return((navigator.javaEnabled() == true)?("Yes"):("No"));
}

//-->
</script>

<script language="JavaScript">
var jsVersion=1.0
</script>

<script language="JavaScript1.1">
   var jsVersion=1.1
</script>
<script language="JavaScript1.2">
   var jsVersion=1.2
</script>
<script language="JavaScript1.3">
   var jsVersion=1.3
</script>

<form action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("action", "report"); ?>
<? vilw_hidden("c"); ?>
<table border="0" cellspacing="0" cellpadding="4" width="410">
  <tr valign="top">
    <td width="75" style="color: #ffffff; background-color: #555555" align="right">
      Operating System:
    </td>
    <td align="left">
      <? print $osVersion; ?> 
      <? vilw_hidden("osVersion"); ?>
    </td>
  </tr>
  <tr valign="top">
    <td width="75" style="color: #ffffff; background-color: #555555" align="right">
      Web Browser:
    </td>
    <td align="left">
      <? print $HTTP_USER_AGENT; ?>
      <? vilw_hidden("browserVersion"); ?>
    </td>
  </tr>
  <tr valign="top">
    <td width="75" style="color: #ffffff; background-color: #555555" align="right">
      Screen Resolution:
    </td>
    <td align="left">
      <script language="javascript">
        document.write(checkScreenRes() + '\n');
        document.write('<input type="hidden" name="screenRes" value="' + checkScreenRes() + '">\n');
      </script>
    </td>
  </tr>
  <tr valign="top">
    <td width="75" style="color: #ffffff; background-color: #555555" align="right">
      Color Depth:
    </td>
    <td align="left">
      <script language="javascript">
        document.write(checkColorDepth());
        document.write('<input type="hidden" name="colorDepth" value="' + checkColorDepth() + '">\n');
      </script>
    </td>
  </tr>
  <tr valign="top">
    <td width="75" style="color: #ffffff; background-color: #555555" align="right">
      Java Enabled:
    </td>
    <td align="left">
      <script language="javascript">
        document.write(checkJava());
        document.write('<input type="hidden" name="javaEnabled" value="' + checkJava() + '">\n');
      </script>
    </td>
  </tr>
  <tr valign="top">
    <td width="75" style="color: #ffffff; background-color: #555555" align="right">
      JavaScript Version:
    </td>
    <td align="left">
      <script language="javascript">
        document.write(jsVersion);
        document.write('<input type="hidden" name="jsVersion" value="' + jsVersion + '">\n');
      </script>
    </td>
  </tr>
  <tr>
    <td width="75" style="color: #ffffff; background-color: #555555" align="right">
      Cookies Enabled:
    </td>
    <td align="left">
      <? print ($test_cookie)?("Yes"):("No"); ?>
    </td>
  </tr>
  <tr valign="top">
    <td width="75" style="color: #ffffff; background-color: #555555" align="right">
      Description of Problem:
    </td>
    <td align="left">
      <? vilw_textarea("problem", 8, 45); ?>
    </td>
  </tr>
  <tr valign="top">
    <td align="center" colspan="2"`>
      <input class="button" type="submit" value="Submit Bug Report">
    </td>
  </tr>
</table>
</form>
