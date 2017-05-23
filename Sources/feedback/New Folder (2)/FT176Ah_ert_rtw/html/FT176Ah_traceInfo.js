function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/In3 */
	this.urlHashMap["FT176Ah:22"] = "FT176Ah.h:51";
	/* <Root>/In4 */
	this.urlHashMap["FT176Ah:23"] = "FT176Ah.h:52";
	/* <Root>/In5 */
	this.urlHashMap["FT176Ah:32"] = "FT176Ah.h:53";
	/* <Root>/In6 */
	this.urlHashMap["FT176Ah:33"] = "FT176Ah.h:54";
	/* <Root>/Model */
	this.urlHashMap["FT176Ah:18"] = "FT176Ah.c:20,33,58&FT176Ah.h:73";
	/* <Root>/Model1 */
	this.urlHashMap["FT176Ah:31"] = "FT176Ah.c:21,36,61&FT176Ah.h:74";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "FT176Ah"};
	this.sidHashMap["FT176Ah"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/In3"] = {sid: "FT176Ah:22"};
	this.sidHashMap["FT176Ah:22"] = {rtwname: "<Root>/In3"};
	this.rtwnameHashMap["<Root>/In4"] = {sid: "FT176Ah:23"};
	this.sidHashMap["FT176Ah:23"] = {rtwname: "<Root>/In4"};
	this.rtwnameHashMap["<Root>/In5"] = {sid: "FT176Ah:32"};
	this.sidHashMap["FT176Ah:32"] = {rtwname: "<Root>/In5"};
	this.rtwnameHashMap["<Root>/In6"] = {sid: "FT176Ah:33"};
	this.sidHashMap["FT176Ah:33"] = {rtwname: "<Root>/In6"};
	this.rtwnameHashMap["<Root>/Model"] = {sid: "FT176Ah:18"};
	this.sidHashMap["FT176Ah:18"] = {rtwname: "<Root>/Model"};
	this.rtwnameHashMap["<Root>/Model1"] = {sid: "FT176Ah:31"};
	this.sidHashMap["FT176Ah:31"] = {rtwname: "<Root>/Model1"};
	this.rtwnameHashMap["<Root>/Out2"] = {sid: "FT176Ah:21"};
	this.sidHashMap["FT176Ah:21"] = {rtwname: "<Root>/Out2"};
	this.rtwnameHashMap["<Root>/Out3"] = {sid: "FT176Ah:34"};
	this.sidHashMap["FT176Ah:34"] = {rtwname: "<Root>/Out3"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
