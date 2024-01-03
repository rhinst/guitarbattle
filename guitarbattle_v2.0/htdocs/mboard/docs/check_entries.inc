           <script language="JavaScript">
           function check_form() {
           	var f = document.post_form;

           	if(f.post_subject.value == '') {
           		alert('You must enter a subject');
           		f.post_subject.focus();
           		return false;
                }

           	if(f.post_body.value == '') {
           		alert('You must enter a message');
           		f.post_body.focus();
           		return false;
                }

           	return true;
           }
           </script>
