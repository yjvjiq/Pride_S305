function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/2-D Lookup
Table1 */
	this.urlHashMap["SOF176Ah:23"] = "SOF176Ah.c:27&SOF176Ah_private.h:44,47,50,53";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "SOF176Ah"};
	this.sidHashMap["SOF176Ah"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/In1"] = {sid: "SOF176Ah:21"};
	this.sidHashMap["SOF176Ah:21"] = {rtwname: "<Root>/In1"};
	this.rtwnameHashMap["<Root>/In2"] = {sid: "SOF176Ah:22"};
	this.sidHashMap["SOF176Ah:22"] = {rtwname: "<Root>/In2"};
	this.rtwnameHashMap["<Root>/2-D Lookup Table1"] = {sid: "SOF176Ah:23"};
	this.sidHashMap["SOF176Ah:23"] = {rtwname: "<Root>/2-D Lookup Table1"};
	this.rtwnameHashMap["<Root>/Out1"] = {sid: "SOF176Ah:24"};
	this.sidHashMap["SOF176Ah:24"] = {rtwname: "<Root>/Out1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
