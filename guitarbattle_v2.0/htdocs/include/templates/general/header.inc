<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=us-ascii"> 
  <meta name="keywords" content="<? print $meta_keywords; ?>">
  <meta name="description" content="<? print $meta_description;?>">

  <link href="<? print $styleSheet; ?>" rel="stylesheet" type="text/css">
  <title><? print $sitename; ?></title>

  <script language="javascript">
  <!--//
    function newMessagePopup(numMessages) {
      window.open('<? print $baseURL; ?>/include/templates/general/newMessages.php?n=' + numMessages, '', 'width=400,height=250');
    }
  //-->
  </script>
</head>
<?
  $num_messages = 0;
  if(session_is_registered("authenticated_user")) {
    $num_messages = get_new_message_count($authenticated_user);
  }
?>
<body <? if($num_messages > 0) { print "onLoad=\"newMessagePopup('" . $num_messages . "');\""; } ?>>
<table border="0" height="100%" width="100%" cellspacing="0" cellpadding="0">
  <tr valign="top">
    <td colspan="2" height="102">
      <table width="100%" border="0" cellspacing="0" cellpadding="0">
        <tr>
          <td style="background-image: url('images/gb_logo.jpg'); font-size: 0px" width="474" height="102">
            <table width="474" border="0" cellpadding="0" cellspacing="0">
              <tr>
                <td><img src="images/spacer.gif" width="1" height="102" border="0" alt=""></td>
              </tr>
            </table>
          </td>
          <td style="background-image: url('images/menu_top_slat.jpg'); font-size: 0px" height="102" align="center">
            <? include('templates/general/menu.inc'); ?>
          </td>
          <td style="background-image: url('images/top_right.jpg'); font-size: 0px" width="114" height="102">
            <table width="114" border="0" cellpadding="0" cellspacing="0">
              <tr>
                <td><img src="images/spacer.gif" width="1" height="102" border="0" alt=""></td>
              </tr>
            </table>
          </td>
        </tr>
      </table>
    </td>
  </tr>
  <tr valign="top">
    <td style="font-size: 0px">
      <table width="100%" height="100%" border="0" cellspacing="0" cellpadding="0">
        <tr valign="top">
          <td width="100%" height="26" style="font-size: 0px" align="left">
            <? include('templates/general/searchBar.inc'); ?>
          </td>
        </tr>
        <tr valign="top">
          <td align="center" width="100%">
<!-- Begin Page Content -->
