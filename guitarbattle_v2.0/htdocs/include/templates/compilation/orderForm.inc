<br><br>
<script language="javascript">
<!-- //
function checkForm() {
	
	f = document.orderform;
	if(f.fn.value == '') {
		f.fn.focus();
		alert('You must specify a first name');
		return(false);
	}

	if(f.ln.value == '') {
		f.ln.focus();
		alert('You must specify a last name');
		return(false);
	}

	if(f.address.value == '') {
		f.address.focus();
		alert('You must specify a street address');
		return(false);
	}

	if(f.city.value == '') {
		f.city.focus();
		alert('You must specify a city');
		return(false);
	}

	if(f.zip.value == '') {
		f.zip.focus();
		alert('You must specify a zip code');
		return(false);
	}

	if(f.email.value == '') {
		f.email.focus();
		alert('You must specify an e-mail address to send confirmation to');
		return(false);
	}

	return(true);
}
//-->
</script>

<table border="0" class="items" width="500" cellspacing="0" cellpadding="4">
  <tr>
    <td class="item_title">
      Order Information:
    </td>
  </tr>
  <tr>
    <td align="center">
      Please provide the required shipping information and click 'Checkout' to proceed to the PayPal checkout screen. For each CD that you order, you will be billed $<? print number_format($compilation_cost, 2); ?> plus shipping. Shipping costs are $<? print number_format($domestic_shipping_rate, 2); ?> for orders within the United States, and $<? print number_format($international_shipping_rate, 2); ?> for international orders. Residents of New York state must pay tax on their orders as well. If you have any questions or comments about your order, feel free to e-mail <a href="mailto: <? print $sales_email; ?>"><? print $sales_email; ?></a>
    </td>
  </tr>
</table>
<br><br>

<form name="orderform" action="<? print $PHP_SELF; ?>" method="post" onSubmit="return(checkForm())">
<? vilw_hidden("action", "complete"); ?>
<table border="0" class="items" width="500" cellspacing="0" cellpadding="4">
  <tr>
    <td colspan="2" class="item_title">
      Shipping Information:
    </td>
  </tr>
  <tr>
    <td align="right">
      First Name:
    </td>
    <td align="left">
      <? vilw_input("fn"); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      Last Name:
    </td>
    <td align="left">
      <? vilw_input("ln"); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      Street Address:
    </td>
    <td align="left">
      <? vilw_input("address"); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      City:
    </td>
    <td align="left">
      <? vilw_input("city"); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      State:
    </td>
    <td align="left">
      <? vilw_stateselect("state"); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      OR
    </td>
    <td align="left">
      &nbsp;
    </td>
  </tr>
  <tr>
    <td align="right">
      Province:
    </td>
    <td align="left">
      <? vilw_input("province"); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      Zip Code:
    </td>
    <td align="left">
      <? vilw_input("zip"); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      Country:
    </td>
    <td align="left">
      <? vilw_countryselect("country"); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      Phone Number:
    </td>
    <td align="left">
      <? vilw_input("phone"); ?>
    </td>
  </tr>
  <tr>
    <td align="right">
      E-mail Address:
    </td>
    <td align="left">
      <? vilw_input("email"); ?>
    </td>
  </tr>
  <tr>
    <td colspan="2" align="center">
      <input type="submit" class="button" value="Checkout"> 
    </td>
  </tr>
</table>
</form>
