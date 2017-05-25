function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Vmin */
	this.urlHashMap["CellUnderVoltage:1"] = "ert_main.c:37&CellUnderVoltage.c:47";
	/* <Root>/Logic */
	this.urlHashMap["CellUnderVoltage:3"] = "CellUnderVoltage.c:19,46,171,194&CellUnderVoltage.h:38,43,44,45,46,47";
	/* <Root>/F_lev */
	this.urlHashMap["CellUnderVoltage:2"] = "ert_main.c:40&CellUnderVoltage.c:173";
	/* <S1>:103 */
	this.urlHashMap["CellUnderVoltage:3:103"] = "CellUnderVoltage.c:65,74";
	/* <S1>:184 */
	this.urlHashMap["CellUnderVoltage:3:184"] = "CellUnderVoltage.c:66,75";
	/* <S1>:192 */
	this.urlHashMap["CellUnderVoltage:3:192"] = "CellUnderVoltage.c:78";
	/* <S1>:188 */
	this.urlHashMap["CellUnderVoltage:3:188"] = "CellUnderVoltage.c:94";
	/* <S1>:190 */
	this.urlHashMap["CellUnderVoltage:3:190"] = "CellUnderVoltage.c:87,99,113";
	/* <S1>:187 */
	this.urlHashMap["CellUnderVoltage:3:187"] = "CellUnderVoltage.c:106,122";
	/* <S1>:186 */
	this.urlHashMap["CellUnderVoltage:3:186"] = "CellUnderVoltage.c:128";
	/* <S1>:202 */
	this.urlHashMap["CellUnderVoltage:3:202"] = "CellUnderVoltage.c:70,137";
	/* <S1>:207 */
	this.urlHashMap["CellUnderVoltage:3:207"] = "CellUnderVoltage.c:140";
	/* <S1>:200 */
	this.urlHashMap["CellUnderVoltage:3:200"] = "CellUnderVoltage.c:149,156";
	/* <S1>:201 */
	this.urlHashMap["CellUnderVoltage:3:201"] = "CellUnderVoltage.c:161";
	/* <S1>:104 */
	this.urlHashMap["CellUnderVoltage:3:104"] = "CellUnderVoltage.c:64";
	/* <S1>:194 */
	this.urlHashMap["CellUnderVoltage:3:194"] = "CellUnderVoltage.c:130";
	/* <S1>:182 */
	this.urlHashMap["CellUnderVoltage:3:182"] = "CellUnderVoltage.c:67";
	/* <S1>:183 */
	this.urlHashMap["CellUnderVoltage:3:183"] = "CellUnderVoltage.c:84";
	/* <S1>:185 */
	this.urlHashMap["CellUnderVoltage:3:185"] = "CellUnderVoltage.c:80";
	/* <S1>:189 */
	this.urlHashMap["CellUnderVoltage:3:189"] = "CellUnderVoltage.c:115";
	/* <S1>:191 */
	this.urlHashMap["CellUnderVoltage:3:191"] = "CellUnderVoltage.c:96";
	/* <S1>:181 */
	this.urlHashMap["CellUnderVoltage:3:181"] = "CellUnderVoltage.c:103";
	/* <S1>:193 */
	this.urlHashMap["CellUnderVoltage:3:193"] = "CellUnderVoltage.c:123";
	/* <S1>:211 */
	this.urlHashMap["CellUnderVoltage:3:211"] = "CellUnderVoltage.c:163";
	/* <S1>:210 */
	this.urlHashMap["CellUnderVoltage:3:210"] = "CellUnderVoltage.c:71";
	/* <S1>:209 */
	this.urlHashMap["CellUnderVoltage:3:209"] = "CellUnderVoltage.c:146";
	/* <S1>:198 */
	this.urlHashMap["CellUnderVoltage:3:198"] = "CellUnderVoltage.c:142";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "CellUnderVoltage"};
	this.sidHashMap["CellUnderVoltage"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "CellUnderVoltage:3"};
	this.sidHashMap["CellUnderVoltage:3"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/Vmin"] = {sid: "CellUnderVoltage:1"};
	this.sidHashMap["CellUnderVoltage:1"] = {rtwname: "<Root>/Vmin"};
	this.rtwnameHashMap["<Root>/Logic"] = {sid: "CellUnderVoltage:3"};
	this.sidHashMap["CellUnderVoltage:3"] = {rtwname: "<Root>/Logic"};
	this.rtwnameHashMap["<Root>/F_lev"] = {sid: "CellUnderVoltage:2"};
	this.sidHashMap["CellUnderVoltage:2"] = {rtwname: "<Root>/F_lev"};
	this.rtwnameHashMap["<S1>:103"] = {sid: "CellUnderVoltage:3:103"};
	this.sidHashMap["CellUnderVoltage:3:103"] = {rtwname: "<S1>:103"};
	this.rtwnameHashMap["<S1>:184"] = {sid: "CellUnderVoltage:3:184"};
	this.sidHashMap["CellUnderVoltage:3:184"] = {rtwname: "<S1>:184"};
	this.rtwnameHashMap["<S1>:192"] = {sid: "CellUnderVoltage:3:192"};
	this.sidHashMap["CellUnderVoltage:3:192"] = {rtwname: "<S1>:192"};
	this.rtwnameHashMap["<S1>:188"] = {sid: "CellUnderVoltage:3:188"};
	this.sidHashMap["CellUnderVoltage:3:188"] = {rtwname: "<S1>:188"};
	this.rtwnameHashMap["<S1>:190"] = {sid: "CellUnderVoltage:3:190"};
	this.sidHashMap["CellUnderVoltage:3:190"] = {rtwname: "<S1>:190"};
	this.rtwnameHashMap["<S1>:187"] = {sid: "CellUnderVoltage:3:187"};
	this.sidHashMap["CellUnderVoltage:3:187"] = {rtwname: "<S1>:187"};
	this.rtwnameHashMap["<S1>:186"] = {sid: "CellUnderVoltage:3:186"};
	this.sidHashMap["CellUnderVoltage:3:186"] = {rtwname: "<S1>:186"};
	this.rtwnameHashMap["<S1>:202"] = {sid: "CellUnderVoltage:3:202"};
	this.sidHashMap["CellUnderVoltage:3:202"] = {rtwname: "<S1>:202"};
	this.rtwnameHashMap["<S1>:207"] = {sid: "CellUnderVoltage:3:207"};
	this.sidHashMap["CellUnderVoltage:3:207"] = {rtwname: "<S1>:207"};
	this.rtwnameHashMap["<S1>:200"] = {sid: "CellUnderVoltage:3:200"};
	this.sidHashMap["CellUnderVoltage:3:200"] = {rtwname: "<S1>:200"};
	this.rtwnameHashMap["<S1>:201"] = {sid: "CellUnderVoltage:3:201"};
	this.sidHashMap["CellUnderVoltage:3:201"] = {rtwname: "<S1>:201"};
	this.rtwnameHashMap["<S1>:104"] = {sid: "CellUnderVoltage:3:104"};
	this.sidHashMap["CellUnderVoltage:3:104"] = {rtwname: "<S1>:104"};
	this.rtwnameHashMap["<S1>:194"] = {sid: "CellUnderVoltage:3:194"};
	this.sidHashMap["CellUnderVoltage:3:194"] = {rtwname: "<S1>:194"};
	this.rtwnameHashMap["<S1>:182"] = {sid: "CellUnderVoltage:3:182"};
	this.sidHashMap["CellUnderVoltage:3:182"] = {rtwname: "<S1>:182"};
	this.rtwnameHashMap["<S1>:183"] = {sid: "CellUnderVoltage:3:183"};
	this.sidHashMap["CellUnderVoltage:3:183"] = {rtwname: "<S1>:183"};
	this.rtwnameHashMap["<S1>:185"] = {sid: "CellUnderVoltage:3:185"};
	this.sidHashMap["CellUnderVoltage:3:185"] = {rtwname: "<S1>:185"};
	this.rtwnameHashMap["<S1>:189"] = {sid: "CellUnderVoltage:3:189"};
	this.sidHashMap["CellUnderVoltage:3:189"] = {rtwname: "<S1>:189"};
	this.rtwnameHashMap["<S1>:191"] = {sid: "CellUnderVoltage:3:191"};
	this.sidHashMap["CellUnderVoltage:3:191"] = {rtwname: "<S1>:191"};
	this.rtwnameHashMap["<S1>:181"] = {sid: "CellUnderVoltage:3:181"};
	this.sidHashMap["CellUnderVoltage:3:181"] = {rtwname: "<S1>:181"};
	this.rtwnameHashMap["<S1>:193"] = {sid: "CellUnderVoltage:3:193"};
	this.sidHashMap["CellUnderVoltage:3:193"] = {rtwname: "<S1>:193"};
	this.rtwnameHashMap["<S1>:211"] = {sid: "CellUnderVoltage:3:211"};
	this.sidHashMap["CellUnderVoltage:3:211"] = {rtwname: "<S1>:211"};
	this.rtwnameHashMap["<S1>:210"] = {sid: "CellUnderVoltage:3:210"};
	this.sidHashMap["CellUnderVoltage:3:210"] = {rtwname: "<S1>:210"};
	this.rtwnameHashMap["<S1>:209"] = {sid: "CellUnderVoltage:3:209"};
	this.sidHashMap["CellUnderVoltage:3:209"] = {rtwname: "<S1>:209"};
	this.rtwnameHashMap["<S1>:198"] = {sid: "CellUnderVoltage:3:198"};
	this.sidHashMap["CellUnderVoltage:3:198"] = {rtwname: "<S1>:198"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
