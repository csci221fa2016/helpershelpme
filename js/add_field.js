
var n = 1;
function add_fields() {
	n++;
	var objTo = document.getElementById('new-field');
	var divtest = document.createElement("div");
	divtest.innerHTML='<div class = "field-wrap"><label>____________Position '+n+':<span class = "req">*</span></label><input type = "text" name="e_position_'+n+'" required autocomplete = "off"/></div><div class = "field-wrap"><label>____________# of volunteers for position '+n+':<span class = "req">*</span></label><input type = "number" name="e_position_'+n+'_number" required autocomplete = "off"/>';
	
	objTo.appendChild(divtest);
}
	
