// VillageWorld.com Data Verification Functions

var whitespace = " \t\n\r";

function isalphanumeric(s) {
	var i;

	if(isempty(s)) return true;

	for(i = 0; i < s.length; i++) {
		var c = s.charAt(i);
		if(!isalnum(c)) 
			return false;
	}
	
	return true;
}

function iswhitespace(c)
{
	return(!(whitespace.indexOf(c) == -1));
}

function isselected(o) {
	if (o.selectedIndex != 0) {
		return true;
	} else {
		return false;
	}
}

function isempty(s)
{
	return ((s == null) || (s.length == 0));
}

function isblank (s)
{
	var i;

	if (isempty(s)) return true;

	for (i = 0; i < s.length; i++)
	{
		var c = s.charAt(i);

		if (!iswhitespace(c))
			return false;
	}

	return true;
}

function isdigit (c)
{
	return ((c >= "0") && (c <= "9"))
}


function isletter (c)
{
	return (((c >= "a") && (c <= "z")) || ((c >= "A") && (c <= "Z")));
}

function isalnum (c)
{
	return isdigit(c) || isletter(c);
}

function isnumber (s)
{
	var i;
	if(isblank(s)) { return false; }

	for (i = 0; i < s.length; i++)
	{
		var c = s.charAt(i);
		if (!isdigit(c))
			return false;
	}

	return true;
}

function isfloat(s)
{
	var p = s;
	var slength = p.length;
	var i=0;

	if (isblank(s))	{
		return false;
	}

	p = removechars(p, '.,');

	return isnumber(p);	
}

function isdollaramount(s)
{
	var p = s;
	var slength = p.length;
	var tmpstr = "";
	var i;
	var c;

	if (isblank(s))	{
		return false;
	}

	if(p.charAt(0) == '-') {
		p = right(p, slength-1);
		slength--;
	}

	if (p.charAt(0) == '$') {
		p = right(p, slength-1); 	
		slength--;
	}

	return(isfloat(p));
}

function getfloatfromdollar(s)
{
	if(!isdollaramount(s)) { return(-1); }

	var p = s;
	var slength = p.length;

	if (p.charAt(0) == '-') {
		p = right(p, slength-1); 	
		slength--;
	}
	
	if (p.charAt(0) == '$') {
		p = right(p, slength-1); 	
		slength--;
	}

	p = removechars(p, ',');

	return(parseFloat(p));

}

function removechars (s, badchar)
{
	var i;
	var returnString = "";

	for (i = 0; i < s.length; i++)
	{
		var c = s.charAt(i);
		if (badchar.indexOf(c) == -1)
			returnString += c;
	}

	return returnString;
}

function keepchars (s, goodchar)
{
	var i;
	var returnString = "";

	for (i = 0; i < s.length; i++)
	{
		var c = s.charAt(i);
		if (goodchar.indexOf(c) != -1)
			returnString += c;
	}

	return returnString;
}


function isemail(s)
{
	if (isblank(s)) {
		return false;
	}

	var i = 1;
	var slength = s.length;

	while ((i < slength) && (s.charAt(i) != "@"))
	{
		i++
	}

	if ((i >= slength) || (s.charAt(i) != "@"))
	{
		return false;
	}
	else
	{
		i += 2;
	}

	while ((i < slength) && (s.charAt(i) != "."))
	{
		i++
	}

	if ((i >= slength - 1) || (s.charAt(i) != "."))
	{
		return false;
	}
	else
	{
		return true;
	}
}

function isphone(s)
{
	var p = removechars(s, "-(). ");
	var l = p.length;
	if (l < 10) {
		return false;
	}
	return isnumber(p);
}

function checkselect(o, desc) {
	if (!isselected(o)) {
		alert('You must select ' + desc);
		o.focus();
		return false;
	} else {
		return true;
	}
}

function checkblank(o, desc) {
	if (isblank(o.value)) {
		alert('You must enter ' + desc);
		o.focus();
		return false;
	} else {
		return true;
	}
}

function ltrim(s)
{
	var returnString = '';
	var i = 0;
	var slength = s.length;
	
	while ((i< slength) && (iswhitespace(charAt(s))))
	{
		i++;						
	}

	while(i<s.length)
	{
		returnString += s.charAt(i);
	}

	return(returnString);
}


function rtrim(s)
{
	var returnString = '';
	var slength = s.length;
	var i = slength-1;	
	
	while ((i>=0) && (iswhitespace(charAt(s))))
	{
		i++;						
	}

	while(i>=s.length)
	{
		returnString = s.charAt(i) + returnString;
	}

	return(returnString);
}

function left(s, n)
{

	var returnString = '';
	var i = 0;
	var slength = s.length;
	
	if (n < slength) { slength= n; }

	while(i<slength)
	{
		returnString += s.charAt(i);
		i++;
	}

	return returnString;
}


function right(s, n)
{

	var returnString = '';
	var slength = s.length;
	var startpos = slength - n;
	var i = slength-1;
	
	if (startpos < 0) { startpos = 0; }
	
	while(i>=startpos)
	{
		returnString = s.charAt(i) + returnString;
		i--;
	}

	return returnString;
}

function normalizecard(cardnumber) {
	return keepchars(cardnumber, "0123456789");
}

function passescardsum(cardnumber) {
	var cleannumber = new String(); 
	var cardstring = new String(cardnumber);
	var flipstring = new String();
	var checksum = 0;

	cleannumber = removechars(cardstring, " -");

	if (keepchars(cleannumber, "0123456789") != cleannumber)
	{
		return false;
	}       

        // Switch Digits Around
        for (var i = cleannumber.length; i >= 0; i--)
        {
                flipstring += cleannumber.charAt(i);
        }

        for(var i = 0; i < flipstring.length; i += 2)
        {
                checksum += eval(flipstring.charAt(i));
                if ((flipstring.charAt(i + 1) * 2) > 9)
                {
                        checksum += eval((flipstring.charAt(i + 1) * 2) - 9);
                }
                else
                {
                        checksum += eval(flipstring.charAt(i + 1) * 2);
                }
        }


        if (checksum != 0 && checksum % 10 != 0)
        {
                return false;
        }

        return true;
}

function getradiovalue (radio)
{
	selected = -1;

	for (var i = 0; i < radio.length; i++)
    	{   
		if (radio[i].checked) 
		{ 
			selected = i;
			break; 
		}
    	}
    
	if (selected == -1) 
	{
		return "";
	}
	else
	{
		return radio[selected].value;
	}
}

function getselectvalue (select)
{
	return select.options[select.selectedIndex].value;
}

function doselect(o, selval) {
	var i = 0;

	while((i < o.length) && (o.options[i].value != selval)) {
		i++;	
	}
	if(o.options[i].value == selval) {
		o.selectedIndex = i;		
	}
}


function isvisa(cc)
{
	return (((cc.length == 16) || (cc.length == 13)) && (cc.substring(0,1) == 4));
}

function ismastercard(cc)
{
	firstdig = cc.substring(0,1);
	seconddig = cc.substring(1,2);
	return ((cc.length == 16) && (firstdig == 5) && ((seconddig >= 1) && (seconddig <= 5)));
}

function isamericanexpress(cc)
{
	firstdig = cc.substring(0,1);
	seconddig = cc.substring(1,2);
	return ((cc.length == 15) && (firstdig == 3) && ((seconddig == 4) || (seconddig == 7)));
}

function isdiscover(cc)
{
	first4digs = cc.substring(0,4);
	return ((cc.length == 16) && (first4digs == "6011"));
}

function verifycard(cardtype, cardnumber)
{
	cardtype = cardtype.toLowerCase();

	if (!passescardsum(cardnumber)) {
		return false;
	}

	cardnumber = normalizecard(cardnumber);

	if ((cardtype == "visa") && (isvisa(cardnumber))) {
		return true;
	}
	else if ((cardtype == "mc") && (ismastercard(cardnumber))) {
		return true;
	}
	else if ((cardtype == "amex") && (isamericanexpress(cardnumber))) {
		return true;
	}
	else if ((cardtype == "discover") && (isdiscover(cardnumber))) {
		return true;
	}
	else {
		return false;
	}
}

function isdate(s)
{
        while(s.indexOf("-") != -1) {
                s = replacechars(s, "-", "/");
        }

        var delim1 = s.indexOf("/");
        var delim2 = s.lastIndexOf("/");
        if(delim1 != -1 && delim1 == delim2) { return false; }

        if(delim1 != -1) {
                var mm = parseInt(s.substring(0,delim1),10);
                var dd = parseInt(s.substring(delim1+1,delim2),10);
                var yyyy = parseInt(s.substring(delim2+1,s.length),10);
        } else {
                var mm = parseInt(s.substring(0,2),10);
                var mm = parseInt(s.substring(2,4),10);
                var mm = parseInt(s.substring(4,s.length),10);
        }

        if(isNaN(mm) || isNaN(dd) || isNaN(yyyy)) { return false; }

        if(mm<1 || mm>12) { return false; }
        if(dd<1 || dd>31) { return false; }
        if(yyyy<100) {
                if(yyyy >= 30) { yyyy += 1900; }
                else { yyyy += 2000; }
        }

        if((mm==4 || mm==6 || mm==9 || mm==11) && dd > 30) { return false; }
        else if (dd > 31) { return false; }

        if(mm==2) {   //check leap year
                if(yyyy % 4 > 0 && dd > 28) { return false; }
                else if (dd > 29) { return false; }
        }

        return true;
}

function getnumber(s) {
	return(removechars(s, ","));
}

function addcommas(s) {
	var neg = (s.substring(0, 1) == '-');
	var tmpstr = removechars(s, ",-");	
	var tmpstr2 = "";

	var i;

	decpt = tmpstr.indexOf(".");
	if(decpt == -1) {
		decpt = tmpstr.length;
	}
	predec = tmpstr.substring(0,decpt);
	postdec = tmpstr.substring(decpt+1, tmpstr.length);
	
	var n = predec.length;
	for(i = 0; i < n; i++) {
		if((i > 0) && (i % 3 == 0)) {
			tmpstr2 = predec.charAt(n-i-1) + ',' + tmpstr2;
		} else {
			tmpstr2 = predec.charAt(n-i-1) + tmpstr2;
		}
	}

	tmpstr = tmpstr2;
	if(postdec) {
		tmpstr += "." + postdec;
	}
	if(neg) {
		tmpstr = "-" + tmpstr;
	}
	return(tmpstr);	
}

function adddecimalplaces(s,n, forcedec) {

	var tmpstr = s;

	if(forcedec) {
		with(Math) {
			tmpstr = ((round(parseFloat(s)*pow(10, n)))/pow(10,n))
+ "";
		}
	}

	var decpt = tmpstr.indexOf(".");
	if(decpt == -1) {
		tmpstr = tmpstr + ".";
		decpt = tmpstr.length - 1;
	}
	var k = (tmpstr.length - 1) - decpt;
	for(i=0; i<(n-k); i++) {
		tmpstr = tmpstr + "0";
	}
	return(tmpstr);
}

function normalizedollaramount(s, forcedec) {

	var tmpstr = s;

	if(isdollaramount(tmpstr)) {
		tmpstr = adddecimalplaces(getfloatfromdollar(tmpstr) + "", 2, forcedec);
		tmpstr = "$" + addcommas(tmpstr);
		return(tmpstr);
	}
	else {
		return(-1);
	}
}
