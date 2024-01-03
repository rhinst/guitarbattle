<script language="javascript">
<!--//
  function pageBack() {
    <? if($start_limit > 0) { ?>
      document.page_nav_form.start_limit.value = (eval(document.page_nav_form.start_limit.value) - <? print $limit; ?>);
      document.page_nav_form.submit();
    <? } ?> 
  }

  function pageForward() {
    <? if(count($battles) == $limit) { ?>
      document.page_nav_form.start_limit.value = (eval(document.page_nav_form.start_limit.value) + <? print $limit; ?>);
      document.page_nav_form.submit();
    <? } ?> 
  }
//-->>
</script>

<table border="0" cellspacing="0" cellpadding="4">
<form name="page_nav_form" action="<? print $PHP_SELF; ?>" method="post">
<? vilw_hidden("start_limit"); ?>
<? vilw_hidden("limit"); ?>
<? vilw_hidden("genre"); ?>
<? vilw_hidden("status"); ?>
<? vilw_hidden("order_by"); ?>
<? vilw_hidden("order"); ?>
<? vilw_hidden("active"); ?>
<? vilw_hidden("hide"); ?>
  <tr>
    <td align="left">
      <input class="button" type="button" onClick="pageBack()" value="Previous <? print $limit; ?>">
    </td>
    <td align="left">
      <input class="button" type="button" onClick="pageForward()" value="Next <? print $limit; ?>">
    </td>
  </tr>
</form>
</table>
