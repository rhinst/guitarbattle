<?
	$categories = Array("Retailer", "Manufacturer", "Other");
?>
<form action="<? print $PHP_SELF; ?>" method="post">
<table border="0">
  <tr>
    <td align="right">
      Company:
    </td>
    <td align="left">
      <? vilw_input("company"); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      Category:
    </td>
    <td align="left">
      <? vilw_select("category", $categories); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      Website:
    </td>
    <td align="left">
      <? vilw_input("website"); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      Contact Name:
    </td>
    <td align="left">
      <? vilw_input("contact_name"); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      Contact Position:
    </td>
    <td align="left">
      <? vilw_input("contact_position"); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      Contact Phone:
    </td>
    <td align="left">
      <? vilw_input("contact_phone"); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      Contact E-mail:
    </td>
    <td align="left">
      <? vilw_input("contact_email"); ?>
    </td>
  </tr>
  <tr>
    <td colspan="2" align="left">
      Notes:
    </td>
  </tr>
  <tr>
    <td colspan="2" align="center">
      <? vilw_textarea("notes", 5, 50); ?>
    </td>
  </tr>
  <tr>
    <td colspan="2" align="right">
      <?  vilw_hidden("action"); ?> 
      <?  vilw_hidden("id"); ?> 
      <input type="submit">
    </td>
  </tr>
</table>
</form>
