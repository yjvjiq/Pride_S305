function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/cur */
	this.urlHashMap["ChargeOverCurrent:1"] = "ert_main.c:37&ChargeOverCurrent.c:44";
	/* <Root>/curM */
	this.urlHashMap["ChargeOverCurrent:5"] = "ert_main.c:40&ChargeOverCurrent.c:45";
	/* <Root>/Logic */
	this.urlHashMap["ChargeOverCurrent:3"] = "ChargeOverCurrent.c:19,43,128,151&ChargeOverCurrent.h:38,43,44,45";
	/* <Root>/F_lev */
	this.urlHashMap["ChargeOverCurrent:2"] = "ert_main.c:43&ChargeOverCurrent.c:130";
	/* <S1>:103 */
	this.urlHashMap["ChargeOverCurrent:3:103"] = "ChargeOverCurrent.c:59,64";
	/* <S1>:184 */
	this.urlHashMap["ChargeOverCurrent:3:184"] = "ChargeOverCurrent.c:60,65";
	/* <S1>:192 */
	this.urlHashMap["ChargeOverCurrent:3:192"] = "ChargeOverCurrent.c:68";
	/* <S1>:188 */
	this.urlHashMap["ChargeOverCurrent:3:188"] = "ChargeOverCurrent.c:84";
	/* <S1>:190 */
	this.urlHashMap["ChargeOverCurrent:3:190"] = "ChargeOverCurrent.c:77,89,103";
	/* <S1>:187 */
	this.urlHashMap["ChargeOverCurrent:3:187"] = "ChargeOverCurrent.c:96,112";
	/* <S1>:186 */
	this.urlHashMap["ChargeOverCurrent:3:186"] = "ChargeOverCurrent.c:118";
	/* <S1>:104 */
	this.urlHashMap["ChargeOverCurrent:3:104"] = "ChargeOverCurrent.c:58";
	/* <S1>:194 */
	this.urlHashMap["ChargeOverCurrent:3:194"] = "ChargeOverCurrent.c:120";
	/* <S1>:182 */
	this.urlHashMap["ChargeOverCurrent:3:182"] = "ChargeOverCurrent.c:61";
	/* <S1>:183 */
	this.urlHashMap["ChargeOverCurrent:3:183"] = "ChargeOverCurrent.c:74";
	/* <S1>:185 */
	this.urlHashMap["ChargeOverCurrent:3:185"] = "ChargeOverCurrent.c:70";
	/* <S1>:189 */
	this.urlHashMap["ChargeOverCurrent:3:189"] = "ChargeOverCurrent.c:105";
	/* <S1>:191 */
	this.urlHashMap["ChargeOverCurrent:3:191"] = "ChargeOverCurrent.c:86";
	/* <S1>:181 */
	this.urlHashMap["ChargeOverCurrent:3:181"] = "ChargeOverCurrent.c:93";
	/* <S1>:193 */
	this.urlHashMap["ChargeOverCurrent:3:193"] = "ChargeOverCurrent.c:113";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "ChargeOverCurrent"};
	this.sidHashMap["ChargeOverCurrent"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "ChargeOverCurrent:3"};
	this.sidHashMap["ChargeOverCurrent:3"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/cur"] = {sid: "ChargeOverCurrent:1"};
	this.sidHashMap["ChargeOverCurrent:1"] = {rtwname: "<Root>/cur"};
	this.rtwnameHashMap["<Root>/curM"] = {sid: "ChargeOverCurrent:5"};
	this.sidHashMap["ChargeOverCurrent:5"] = {rtwname: "<Root>/curM"};
	this.rtwnameHashMap["<Root>/Logic"] = {sid: "ChargeOverCurrent:3"};
	this.sidHashMap["ChargeOverCurrent:3"] = {rtwname: "<Root>/Logic"};
	this.rtwnameHashMap["<Root>/F_lev"] = {sid: "ChargeOverCurrent:2"};
	this.sidHashMap["ChargeOverCurrent:2"] = {rtwname: "<Root>/F_lev"};
	this.rtwnameHashMap["<S1>:103"] = {sid: "ChargeOverCurrent:3:103"};
	this.sidHashMap["ChargeOverCurrent:3:103"] = {rtwname: "<S1>:103"};
	this.rtwnameHashMap["<S1>:184"] = {sid: "ChargeOverCurrent:3:184"};
	this.sidHashMap["ChargeOverCurrent:3:184"] = {rtwname: "<S1>:184"};
	this.rtwnameHashMap["<S1>:192"] = {sid: "ChargeOverCurrent:3:192"};
	this.sidHashMap["ChargeOverCurrent:3:192"] = {rtwname: "<S1>:192"};
	this.rtwnameHashMap["<S1>:188"] = {sid: "ChargeOverCurrent:3:188"};
	this.sidHashMap["ChargeOverCurrent:3:188"] = {rtwname: "<S1>:188"};
	this.rtwnameHashMap["<S1>:190"] = {sid: "ChargeOverCurrent:3:190"};
	this.sidHashMap["ChargeOverCurrent:3:190"] = {rtwname: "<S1>:190"};
	this.rtwnameHashMap["<S1>:187"] = {sid: "ChargeOverCurrent:3:187"};
	this.sidHashMap["ChargeOverCurrent:3:187"] = {rtwname: "<S1>:187"};
	this.rtwnameHashMap["<S1>:186"] = {sid: "ChargeOverCurrent:3:186"};
	this.sidHashMap["ChargeOverCurrent:3:186"] = {rtwname: "<S1>:186"};
	this.rtwnameHashMap["<S1>:104"] = {sid: "ChargeOverCurrent:3:104"};
	this.sidHashMap["ChargeOverCurrent:3:104"] = {rtwname: "<S1>:104"};
	this.rtwnameHashMap["<S1>:194"] = {sid: "ChargeOverCurrent:3:194"};
	this.sidHashMap["ChargeOverCurrent:3:194"] = {rtwname: "<S1>:194"};
	this.rtwnameHashMap["<S1>:182"] = {sid: "ChargeOverCurrent:3:182"};
	this.sidHashMap["ChargeOverCurrent:3:182"] = {rtwname: "<S1>:182"};
	this.rtwnameHashMap["<S1>:183"] = {sid: "ChargeOverCurrent:3:183"};
	this.sidHashMap["ChargeOverCurrent:3:183"] = {rtwname: "<S1>:183"};
	this.rtwnameHashMap["<S1>:185"] = {sid: "ChargeOverCurrent:3:185"};
	this.sidHashMap["ChargeOverCurrent:3:185"] = {rtwname: "<S1>:185"};
	this.rtwnameHashMap["<S1>:189"] = {sid: "ChargeOverCurrent:3:189"};
	this.sidHashMap["ChargeOverCurrent:3:189"] = {rtwname: "<S1>:189"};
	this.rtwnameHashMap["<S1>:191"] = {sid: "ChargeOverCurrent:3:191"};
	this.sidHashMap["ChargeOverCurrent:3:191"] = {rtwname: "<S1>:191"};
	this.rtwnameHashMap["<S1>:181"] = {sid: "ChargeOverCurrent:3:181"};
	this.sidHashMap["ChargeOverCurrent:3:181"] = {rtwname: "<S1>:181"};
	this.rtwnameHashMap["<S1>:193"] = {sid: "ChargeOverCurrent:3:193"};
	this.sidHashMap["ChargeOverCurrent:3:193"] = {rtwname: "<S1>:193"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
