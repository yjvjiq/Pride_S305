function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Vmax */
	this.urlHashMap["CellOverVoltage:1"] = "ert_main.c:37&CellOverVoltage.c:50";
	/* <Root>/Modelflag */
	this.urlHashMap["CellOverVoltage:6"] = "ert_main.c:40&CellOverVoltage.c:49";
	/* <Root>/Logic */
	this.urlHashMap["CellOverVoltage:3"] = "CellOverVoltage.c:19,48,203,226&CellOverVoltage.h:38,43,44,45,46,47";
	/* <Root>/F_lev */
	this.urlHashMap["CellOverVoltage:2"] = "ert_main.c:43&CellOverVoltage.c:205";
	/* <S1>:103 */
	this.urlHashMap["CellOverVoltage:3:103"] = "CellOverVoltage.c:68,77";
	/* <S1>:184 */
	this.urlHashMap["CellOverVoltage:3:184"] = "CellOverVoltage.c:69,78";
	/* <S1>:192 */
	this.urlHashMap["CellOverVoltage:3:192"] = "CellOverVoltage.c:81";
	/* <S1>:188 */
	this.urlHashMap["CellOverVoltage:3:188"] = "CellOverVoltage.c:97";
	/* <S1>:190 */
	this.urlHashMap["CellOverVoltage:3:190"] = "CellOverVoltage.c:90,102,116";
	/* <S1>:187 */
	this.urlHashMap["CellOverVoltage:3:187"] = "CellOverVoltage.c:109,125";
	/* <S1>:186 */
	this.urlHashMap["CellOverVoltage:3:186"] = "CellOverVoltage.c:131";
	/* <S1>:202 */
	this.urlHashMap["CellOverVoltage:3:202"] = "CellOverVoltage.c:73,140";
	/* <S1>:207 */
	this.urlHashMap["CellOverVoltage:3:207"] = "CellOverVoltage.c:143";
	/* <S1>:203 */
	this.urlHashMap["CellOverVoltage:3:203"] = "CellOverVoltage.c:159";
	/* <S1>:200 */
	this.urlHashMap["CellOverVoltage:3:200"] = "CellOverVoltage.c:152,164,178";
	/* <S1>:204 */
	this.urlHashMap["CellOverVoltage:3:204"] = "CellOverVoltage.c:171,187";
	/* <S1>:201 */
	this.urlHashMap["CellOverVoltage:3:201"] = "CellOverVoltage.c:193";
	/* <S1>:104 */
	this.urlHashMap["CellOverVoltage:3:104"] = "CellOverVoltage.c:67";
	/* <S1>:194 */
	this.urlHashMap["CellOverVoltage:3:194"] = "CellOverVoltage.c:133";
	/* <S1>:182 */
	this.urlHashMap["CellOverVoltage:3:182"] = "CellOverVoltage.c:70";
	/* <S1>:183 */
	this.urlHashMap["CellOverVoltage:3:183"] = "CellOverVoltage.c:87";
	/* <S1>:185 */
	this.urlHashMap["CellOverVoltage:3:185"] = "CellOverVoltage.c:83";
	/* <S1>:189 */
	this.urlHashMap["CellOverVoltage:3:189"] = "CellOverVoltage.c:118";
	/* <S1>:191 */
	this.urlHashMap["CellOverVoltage:3:191"] = "CellOverVoltage.c:99";
	/* <S1>:181 */
	this.urlHashMap["CellOverVoltage:3:181"] = "CellOverVoltage.c:106";
	/* <S1>:193 */
	this.urlHashMap["CellOverVoltage:3:193"] = "CellOverVoltage.c:126";
	/* <S1>:211 */
	this.urlHashMap["CellOverVoltage:3:211"] = "CellOverVoltage.c:195";
	/* <S1>:210 */
	this.urlHashMap["CellOverVoltage:3:210"] = "CellOverVoltage.c:74";
	/* <S1>:209 */
	this.urlHashMap["CellOverVoltage:3:209"] = "CellOverVoltage.c:149";
	/* <S1>:198 */
	this.urlHashMap["CellOverVoltage:3:198"] = "CellOverVoltage.c:145";
	/* <S1>:205 */
	this.urlHashMap["CellOverVoltage:3:205"] = "CellOverVoltage.c:180";
	/* <S1>:199 */
	this.urlHashMap["CellOverVoltage:3:199"] = "CellOverVoltage.c:161";
	/* <S1>:206 */
	this.urlHashMap["CellOverVoltage:3:206"] = "CellOverVoltage.c:168";
	/* <S1>:208 */
	this.urlHashMap["CellOverVoltage:3:208"] = "CellOverVoltage.c:188";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "CellOverVoltage"};
	this.sidHashMap["CellOverVoltage"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "CellOverVoltage:3"};
	this.sidHashMap["CellOverVoltage:3"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/Vmax"] = {sid: "CellOverVoltage:1"};
	this.sidHashMap["CellOverVoltage:1"] = {rtwname: "<Root>/Vmax"};
	this.rtwnameHashMap["<Root>/Modelflag"] = {sid: "CellOverVoltage:6"};
	this.sidHashMap["CellOverVoltage:6"] = {rtwname: "<Root>/Modelflag"};
	this.rtwnameHashMap["<Root>/Logic"] = {sid: "CellOverVoltage:3"};
	this.sidHashMap["CellOverVoltage:3"] = {rtwname: "<Root>/Logic"};
	this.rtwnameHashMap["<Root>/F_lev"] = {sid: "CellOverVoltage:2"};
	this.sidHashMap["CellOverVoltage:2"] = {rtwname: "<Root>/F_lev"};
	this.rtwnameHashMap["<S1>:103"] = {sid: "CellOverVoltage:3:103"};
	this.sidHashMap["CellOverVoltage:3:103"] = {rtwname: "<S1>:103"};
	this.rtwnameHashMap["<S1>:184"] = {sid: "CellOverVoltage:3:184"};
	this.sidHashMap["CellOverVoltage:3:184"] = {rtwname: "<S1>:184"};
	this.rtwnameHashMap["<S1>:192"] = {sid: "CellOverVoltage:3:192"};
	this.sidHashMap["CellOverVoltage:3:192"] = {rtwname: "<S1>:192"};
	this.rtwnameHashMap["<S1>:188"] = {sid: "CellOverVoltage:3:188"};
	this.sidHashMap["CellOverVoltage:3:188"] = {rtwname: "<S1>:188"};
	this.rtwnameHashMap["<S1>:190"] = {sid: "CellOverVoltage:3:190"};
	this.sidHashMap["CellOverVoltage:3:190"] = {rtwname: "<S1>:190"};
	this.rtwnameHashMap["<S1>:187"] = {sid: "CellOverVoltage:3:187"};
	this.sidHashMap["CellOverVoltage:3:187"] = {rtwname: "<S1>:187"};
	this.rtwnameHashMap["<S1>:186"] = {sid: "CellOverVoltage:3:186"};
	this.sidHashMap["CellOverVoltage:3:186"] = {rtwname: "<S1>:186"};
	this.rtwnameHashMap["<S1>:202"] = {sid: "CellOverVoltage:3:202"};
	this.sidHashMap["CellOverVoltage:3:202"] = {rtwname: "<S1>:202"};
	this.rtwnameHashMap["<S1>:207"] = {sid: "CellOverVoltage:3:207"};
	this.sidHashMap["CellOverVoltage:3:207"] = {rtwname: "<S1>:207"};
	this.rtwnameHashMap["<S1>:203"] = {sid: "CellOverVoltage:3:203"};
	this.sidHashMap["CellOverVoltage:3:203"] = {rtwname: "<S1>:203"};
	this.rtwnameHashMap["<S1>:200"] = {sid: "CellOverVoltage:3:200"};
	this.sidHashMap["CellOverVoltage:3:200"] = {rtwname: "<S1>:200"};
	this.rtwnameHashMap["<S1>:204"] = {sid: "CellOverVoltage:3:204"};
	this.sidHashMap["CellOverVoltage:3:204"] = {rtwname: "<S1>:204"};
	this.rtwnameHashMap["<S1>:201"] = {sid: "CellOverVoltage:3:201"};
	this.sidHashMap["CellOverVoltage:3:201"] = {rtwname: "<S1>:201"};
	this.rtwnameHashMap["<S1>:104"] = {sid: "CellOverVoltage:3:104"};
	this.sidHashMap["CellOverVoltage:3:104"] = {rtwname: "<S1>:104"};
	this.rtwnameHashMap["<S1>:194"] = {sid: "CellOverVoltage:3:194"};
	this.sidHashMap["CellOverVoltage:3:194"] = {rtwname: "<S1>:194"};
	this.rtwnameHashMap["<S1>:182"] = {sid: "CellOverVoltage:3:182"};
	this.sidHashMap["CellOverVoltage:3:182"] = {rtwname: "<S1>:182"};
	this.rtwnameHashMap["<S1>:183"] = {sid: "CellOverVoltage:3:183"};
	this.sidHashMap["CellOverVoltage:3:183"] = {rtwname: "<S1>:183"};
	this.rtwnameHashMap["<S1>:185"] = {sid: "CellOverVoltage:3:185"};
	this.sidHashMap["CellOverVoltage:3:185"] = {rtwname: "<S1>:185"};
	this.rtwnameHashMap["<S1>:189"] = {sid: "CellOverVoltage:3:189"};
	this.sidHashMap["CellOverVoltage:3:189"] = {rtwname: "<S1>:189"};
	this.rtwnameHashMap["<S1>:191"] = {sid: "CellOverVoltage:3:191"};
	this.sidHashMap["CellOverVoltage:3:191"] = {rtwname: "<S1>:191"};
	this.rtwnameHashMap["<S1>:181"] = {sid: "CellOverVoltage:3:181"};
	this.sidHashMap["CellOverVoltage:3:181"] = {rtwname: "<S1>:181"};
	this.rtwnameHashMap["<S1>:193"] = {sid: "CellOverVoltage:3:193"};
	this.sidHashMap["CellOverVoltage:3:193"] = {rtwname: "<S1>:193"};
	this.rtwnameHashMap["<S1>:211"] = {sid: "CellOverVoltage:3:211"};
	this.sidHashMap["CellOverVoltage:3:211"] = {rtwname: "<S1>:211"};
	this.rtwnameHashMap["<S1>:210"] = {sid: "CellOverVoltage:3:210"};
	this.sidHashMap["CellOverVoltage:3:210"] = {rtwname: "<S1>:210"};
	this.rtwnameHashMap["<S1>:209"] = {sid: "CellOverVoltage:3:209"};
	this.sidHashMap["CellOverVoltage:3:209"] = {rtwname: "<S1>:209"};
	this.rtwnameHashMap["<S1>:198"] = {sid: "CellOverVoltage:3:198"};
	this.sidHashMap["CellOverVoltage:3:198"] = {rtwname: "<S1>:198"};
	this.rtwnameHashMap["<S1>:205"] = {sid: "CellOverVoltage:3:205"};
	this.sidHashMap["CellOverVoltage:3:205"] = {rtwname: "<S1>:205"};
	this.rtwnameHashMap["<S1>:199"] = {sid: "CellOverVoltage:3:199"};
	this.sidHashMap["CellOverVoltage:3:199"] = {rtwname: "<S1>:199"};
	this.rtwnameHashMap["<S1>:206"] = {sid: "CellOverVoltage:3:206"};
	this.sidHashMap["CellOverVoltage:3:206"] = {rtwname: "<S1>:206"};
	this.rtwnameHashMap["<S1>:208"] = {sid: "CellOverVoltage:3:208"};
	this.sidHashMap["CellOverVoltage:3:208"] = {rtwname: "<S1>:208"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
