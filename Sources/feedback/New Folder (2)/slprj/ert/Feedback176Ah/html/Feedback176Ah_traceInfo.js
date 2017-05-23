function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/2-D Lookup
Table2 */
	this.urlHashMap["Feedback176Ah:27"] = "Feedback176Ah.c:28&Feedback176Ah_private.h:44,47,50,53";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Feedback176Ah"};
	this.sidHashMap["Feedback176Ah"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/In7"] = {sid: "Feedback176Ah:25"};
	this.sidHashMap["Feedback176Ah:25"] = {rtwname: "<Root>/In7"};
	this.rtwnameHashMap["<Root>/In8"] = {sid: "Feedback176Ah:26"};
	this.sidHashMap["Feedback176Ah:26"] = {rtwname: "<Root>/In8"};
	this.rtwnameHashMap["<Root>/2-D Lookup Table2"] = {sid: "Feedback176Ah:27"};
	this.sidHashMap["Feedback176Ah:27"] = {rtwname: "<Root>/2-D Lookup Table2"};
	this.rtwnameHashMap["<Root>/Out4"] = {sid: "Feedback176Ah:28"};
	this.sidHashMap["Feedback176Ah:28"] = {rtwname: "<Root>/Out4"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
