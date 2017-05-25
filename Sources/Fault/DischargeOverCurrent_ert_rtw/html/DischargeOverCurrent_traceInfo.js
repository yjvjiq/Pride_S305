function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/cur */
	this.urlHashMap["DisChargeOverCurrent:1"] = "ert_main.c:37&DisChargeOverCurrent.c:45";
	/* <Root>/curM */
	this.urlHashMap["DisChargeOverCurrent:5"] = "ert_main.c:40&DisChargeOverCurrent.c:46";
	/* <Root>/Logic */
	this.urlHashMap["DisChargeOverCurrent:3"] = "DisChargeOverCurrent.c:19,44,129,152&DisChargeOverCurrent.h:38,43,44,45";
	/* <Root>/F_lev */
	this.urlHashMap["DisChargeOverCurrent:2"] = "ert_main.c:43&DisChargeOverCurrent.c:131";
	/* <S1>:103 */
	this.urlHashMap["DisChargeOverCurrent:3:103"] = "DisChargeOverCurrent.c:60,65";
	/* <S1>:184 */
	this.urlHashMap["DisChargeOverCurrent:3:184"] = "DisChargeOverCurrent.c:61,66";
	/* <S1>:192 */
	this.urlHashMap["DisChargeOverCurrent:3:192"] = "DisChargeOverCurrent.c:69";
	/* <S1>:188 */
	this.urlHashMap["DisChargeOverCurrent:3:188"] = "DisChargeOverCurrent.c:85";
	/* <S1>:190 */
	this.urlHashMap["DisChargeOverCurrent:3:190"] = "DisChargeOverCurrent.c:78,90,104";
	/* <S1>:187 */
	this.urlHashMap["DisChargeOverCurrent:3:187"] = "DisChargeOverCurrent.c:97,113";
	/* <S1>:186 */
	this.urlHashMap["DisChargeOverCurrent:3:186"] = "DisChargeOverCurrent.c:119";
	/* <S1>:104 */
	this.urlHashMap["DisChargeOverCurrent:3:104"] = "DisChargeOverCurrent.c:59";
	/* <S1>:194 */
	this.urlHashMap["DisChargeOverCurrent:3:194"] = "DisChargeOverCurrent.c:121";
	/* <S1>:182 */
	this.urlHashMap["DisChargeOverCurrent:3:182"] = "DisChargeOverCurrent.c:62";
	/* <S1>:183 */
	this.urlHashMap["DisChargeOverCurrent:3:183"] = "DisChargeOverCurrent.c:75";
	/* <S1>:185 */
	this.urlHashMap["DisChargeOverCurrent:3:185"] = "DisChargeOverCurrent.c:71";
	/* <S1>:189 */
	this.urlHashMap["DisChargeOverCurrent:3:189"] = "DisChargeOverCurrent.c:106";
	/* <S1>:191 */
	this.urlHashMap["DisChargeOverCurrent:3:191"] = "DisChargeOverCurrent.c:87";
	/* <S1>:181 */
	this.urlHashMap["DisChargeOverCurrent:3:181"] = "DisChargeOverCurrent.c:94";
	/* <S1>:193 */
	this.urlHashMap["DisChargeOverCurrent:3:193"] = "DisChargeOverCurrent.c:114";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "DisChargeOverCurrent"};
	this.sidHashMap["DisChargeOverCurrent"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "DisChargeOverCurrent:3"};
	this.sidHashMap["DisChargeOverCurrent:3"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/cur"] = {sid: "DisChargeOverCurrent:1"};
	this.sidHashMap["DisChargeOverCurrent:1"] = {rtwname: "<Root>/cur"};
	this.rtwnameHashMap["<Root>/curM"] = {sid: "DisChargeOverCurrent:5"};
	this.sidHashMap["DisChargeOverCurrent:5"] = {rtwname: "<Root>/curM"};
	this.rtwnameHashMap["<Root>/Logic"] = {sid: "DisChargeOverCurrent:3"};
	this.sidHashMap["DisChargeOverCurrent:3"] = {rtwname: "<Root>/Logic"};
	this.rtwnameHashMap["<Root>/F_lev"] = {sid: "DisChargeOverCurrent:2"};
	this.sidHashMap["DisChargeOverCurrent:2"] = {rtwname: "<Root>/F_lev"};
	this.rtwnameHashMap["<S1>:103"] = {sid: "DisChargeOverCurrent:3:103"};
	this.sidHashMap["DisChargeOverCurrent:3:103"] = {rtwname: "<S1>:103"};
	this.rtwnameHashMap["<S1>:184"] = {sid: "DisChargeOverCurrent:3:184"};
	this.sidHashMap["DisChargeOverCurrent:3:184"] = {rtwname: "<S1>:184"};
	this.rtwnameHashMap["<S1>:192"] = {sid: "DisChargeOverCurrent:3:192"};
	this.sidHashMap["DisChargeOverCurrent:3:192"] = {rtwname: "<S1>:192"};
	this.rtwnameHashMap["<S1>:188"] = {sid: "DisChargeOverCurrent:3:188"};
	this.sidHashMap["DisChargeOverCurrent:3:188"] = {rtwname: "<S1>:188"};
	this.rtwnameHashMap["<S1>:190"] = {sid: "DisChargeOverCurrent:3:190"};
	this.sidHashMap["DisChargeOverCurrent:3:190"] = {rtwname: "<S1>:190"};
	this.rtwnameHashMap["<S1>:187"] = {sid: "DisChargeOverCurrent:3:187"};
	this.sidHashMap["DisChargeOverCurrent:3:187"] = {rtwname: "<S1>:187"};
	this.rtwnameHashMap["<S1>:186"] = {sid: "DisChargeOverCurrent:3:186"};
	this.sidHashMap["DisChargeOverCurrent:3:186"] = {rtwname: "<S1>:186"};
	this.rtwnameHashMap["<S1>:104"] = {sid: "DisChargeOverCurrent:3:104"};
	this.sidHashMap["DisChargeOverCurrent:3:104"] = {rtwname: "<S1>:104"};
	this.rtwnameHashMap["<S1>:194"] = {sid: "DisChargeOverCurrent:3:194"};
	this.sidHashMap["DisChargeOverCurrent:3:194"] = {rtwname: "<S1>:194"};
	this.rtwnameHashMap["<S1>:182"] = {sid: "DisChargeOverCurrent:3:182"};
	this.sidHashMap["DisChargeOverCurrent:3:182"] = {rtwname: "<S1>:182"};
	this.rtwnameHashMap["<S1>:183"] = {sid: "DisChargeOverCurrent:3:183"};
	this.sidHashMap["DisChargeOverCurrent:3:183"] = {rtwname: "<S1>:183"};
	this.rtwnameHashMap["<S1>:185"] = {sid: "DisChargeOverCurrent:3:185"};
	this.sidHashMap["DisChargeOverCurrent:3:185"] = {rtwname: "<S1>:185"};
	this.rtwnameHashMap["<S1>:189"] = {sid: "DisChargeOverCurrent:3:189"};
	this.sidHashMap["DisChargeOverCurrent:3:189"] = {rtwname: "<S1>:189"};
	this.rtwnameHashMap["<S1>:191"] = {sid: "DisChargeOverCurrent:3:191"};
	this.sidHashMap["DisChargeOverCurrent:3:191"] = {rtwname: "<S1>:191"};
	this.rtwnameHashMap["<S1>:181"] = {sid: "DisChargeOverCurrent:3:181"};
	this.sidHashMap["DisChargeOverCurrent:3:181"] = {rtwname: "<S1>:181"};
	this.rtwnameHashMap["<S1>:193"] = {sid: "DisChargeOverCurrent:3:193"};
	this.sidHashMap["DisChargeOverCurrent:3:193"] = {rtwname: "<S1>:193"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
