function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Tmin */
	this.urlHashMap["BatteryTemperatureLow:1"] = "ert_main.c:37&BatteryTemperatureLow.c:48";
	/* <Root>/Chart */
	this.urlHashMap["BatteryTemperatureLow:3"] = "BatteryTemperatureLow.c:19,47,172,195&BatteryTemperatureLow.h:38,43,44,45,46,47";
	/* <Root>/F_lev */
	this.urlHashMap["BatteryTemperatureLow:2"] = "ert_main.c:40&BatteryTemperatureLow.c:174";
	/* <S1>:103 */
	this.urlHashMap["BatteryTemperatureLow:3:103"] = "BatteryTemperatureLow.c:66,75";
	/* <S1>:189 */
	this.urlHashMap["BatteryTemperatureLow:3:189"] = "BatteryTemperatureLow.c:67,76";
	/* <S1>:188 */
	this.urlHashMap["BatteryTemperatureLow:3:188"] = "BatteryTemperatureLow.c:79";
	/* <S1>:187 */
	this.urlHashMap["BatteryTemperatureLow:3:187"] = "BatteryTemperatureLow.c:95";
	/* <S1>:185 */
	this.urlHashMap["BatteryTemperatureLow:3:185"] = "BatteryTemperatureLow.c:88,100,114";
	/* <S1>:184 */
	this.urlHashMap["BatteryTemperatureLow:3:184"] = "BatteryTemperatureLow.c:107,123";
	/* <S1>:195 */
	this.urlHashMap["BatteryTemperatureLow:3:195"] = "BatteryTemperatureLow.c:129";
	/* <S1>:102 */
	this.urlHashMap["BatteryTemperatureLow:3:102"] = "BatteryTemperatureLow.c:71,138";
	/* <S1>:28 */
	this.urlHashMap["BatteryTemperatureLow:3:28"] = "BatteryTemperatureLow.c:141";
	/* <S1>:23 */
	this.urlHashMap["BatteryTemperatureLow:3:23"] = "BatteryTemperatureLow.c:150,157";
	/* <S1>:98 */
	this.urlHashMap["BatteryTemperatureLow:3:98"] = "BatteryTemperatureLow.c:162";
	/* <S1>:104 */
	this.urlHashMap["BatteryTemperatureLow:3:104"] = "BatteryTemperatureLow.c:65";
	/* <S1>:186 */
	this.urlHashMap["BatteryTemperatureLow:3:186"] = "BatteryTemperatureLow.c:131";
	/* <S1>:190 */
	this.urlHashMap["BatteryTemperatureLow:3:190"] = "BatteryTemperatureLow.c:68";
	/* <S1>:194 */
	this.urlHashMap["BatteryTemperatureLow:3:194"] = "BatteryTemperatureLow.c:85";
	/* <S1>:193 */
	this.urlHashMap["BatteryTemperatureLow:3:193"] = "BatteryTemperatureLow.c:81";
	/* <S1>:191 */
	this.urlHashMap["BatteryTemperatureLow:3:191"] = "BatteryTemperatureLow.c:116";
	/* <S1>:182 */
	this.urlHashMap["BatteryTemperatureLow:3:182"] = "BatteryTemperatureLow.c:97";
	/* <S1>:183 */
	this.urlHashMap["BatteryTemperatureLow:3:183"] = "BatteryTemperatureLow.c:104";
	/* <S1>:192 */
	this.urlHashMap["BatteryTemperatureLow:3:192"] = "BatteryTemperatureLow.c:124";
	/* <S1>:25 */
	this.urlHashMap["BatteryTemperatureLow:3:25"] = "BatteryTemperatureLow.c:164";
	/* <S1>:26 */
	this.urlHashMap["BatteryTemperatureLow:3:26"] = "BatteryTemperatureLow.c:147";
	/* <S1>:24 */
	this.urlHashMap["BatteryTemperatureLow:3:24"] = "BatteryTemperatureLow.c:143";
	/* <S1>:108 */
	this.urlHashMap["BatteryTemperatureLow:3:108"] = "BatteryTemperatureLow.c:72";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "BatteryTemperatureLow"};
	this.sidHashMap["BatteryTemperatureLow"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "BatteryTemperatureLow:3"};
	this.sidHashMap["BatteryTemperatureLow:3"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/Tmin"] = {sid: "BatteryTemperatureLow:1"};
	this.sidHashMap["BatteryTemperatureLow:1"] = {rtwname: "<Root>/Tmin"};
	this.rtwnameHashMap["<Root>/Chart"] = {sid: "BatteryTemperatureLow:3"};
	this.sidHashMap["BatteryTemperatureLow:3"] = {rtwname: "<Root>/Chart"};
	this.rtwnameHashMap["<Root>/F_lev"] = {sid: "BatteryTemperatureLow:2"};
	this.sidHashMap["BatteryTemperatureLow:2"] = {rtwname: "<Root>/F_lev"};
	this.rtwnameHashMap["<S1>:103"] = {sid: "BatteryTemperatureLow:3:103"};
	this.sidHashMap["BatteryTemperatureLow:3:103"] = {rtwname: "<S1>:103"};
	this.rtwnameHashMap["<S1>:189"] = {sid: "BatteryTemperatureLow:3:189"};
	this.sidHashMap["BatteryTemperatureLow:3:189"] = {rtwname: "<S1>:189"};
	this.rtwnameHashMap["<S1>:188"] = {sid: "BatteryTemperatureLow:3:188"};
	this.sidHashMap["BatteryTemperatureLow:3:188"] = {rtwname: "<S1>:188"};
	this.rtwnameHashMap["<S1>:187"] = {sid: "BatteryTemperatureLow:3:187"};
	this.sidHashMap["BatteryTemperatureLow:3:187"] = {rtwname: "<S1>:187"};
	this.rtwnameHashMap["<S1>:185"] = {sid: "BatteryTemperatureLow:3:185"};
	this.sidHashMap["BatteryTemperatureLow:3:185"] = {rtwname: "<S1>:185"};
	this.rtwnameHashMap["<S1>:184"] = {sid: "BatteryTemperatureLow:3:184"};
	this.sidHashMap["BatteryTemperatureLow:3:184"] = {rtwname: "<S1>:184"};
	this.rtwnameHashMap["<S1>:195"] = {sid: "BatteryTemperatureLow:3:195"};
	this.sidHashMap["BatteryTemperatureLow:3:195"] = {rtwname: "<S1>:195"};
	this.rtwnameHashMap["<S1>:102"] = {sid: "BatteryTemperatureLow:3:102"};
	this.sidHashMap["BatteryTemperatureLow:3:102"] = {rtwname: "<S1>:102"};
	this.rtwnameHashMap["<S1>:28"] = {sid: "BatteryTemperatureLow:3:28"};
	this.sidHashMap["BatteryTemperatureLow:3:28"] = {rtwname: "<S1>:28"};
	this.rtwnameHashMap["<S1>:23"] = {sid: "BatteryTemperatureLow:3:23"};
	this.sidHashMap["BatteryTemperatureLow:3:23"] = {rtwname: "<S1>:23"};
	this.rtwnameHashMap["<S1>:98"] = {sid: "BatteryTemperatureLow:3:98"};
	this.sidHashMap["BatteryTemperatureLow:3:98"] = {rtwname: "<S1>:98"};
	this.rtwnameHashMap["<S1>:104"] = {sid: "BatteryTemperatureLow:3:104"};
	this.sidHashMap["BatteryTemperatureLow:3:104"] = {rtwname: "<S1>:104"};
	this.rtwnameHashMap["<S1>:186"] = {sid: "BatteryTemperatureLow:3:186"};
	this.sidHashMap["BatteryTemperatureLow:3:186"] = {rtwname: "<S1>:186"};
	this.rtwnameHashMap["<S1>:190"] = {sid: "BatteryTemperatureLow:3:190"};
	this.sidHashMap["BatteryTemperatureLow:3:190"] = {rtwname: "<S1>:190"};
	this.rtwnameHashMap["<S1>:194"] = {sid: "BatteryTemperatureLow:3:194"};
	this.sidHashMap["BatteryTemperatureLow:3:194"] = {rtwname: "<S1>:194"};
	this.rtwnameHashMap["<S1>:193"] = {sid: "BatteryTemperatureLow:3:193"};
	this.sidHashMap["BatteryTemperatureLow:3:193"] = {rtwname: "<S1>:193"};
	this.rtwnameHashMap["<S1>:191"] = {sid: "BatteryTemperatureLow:3:191"};
	this.sidHashMap["BatteryTemperatureLow:3:191"] = {rtwname: "<S1>:191"};
	this.rtwnameHashMap["<S1>:182"] = {sid: "BatteryTemperatureLow:3:182"};
	this.sidHashMap["BatteryTemperatureLow:3:182"] = {rtwname: "<S1>:182"};
	this.rtwnameHashMap["<S1>:183"] = {sid: "BatteryTemperatureLow:3:183"};
	this.sidHashMap["BatteryTemperatureLow:3:183"] = {rtwname: "<S1>:183"};
	this.rtwnameHashMap["<S1>:192"] = {sid: "BatteryTemperatureLow:3:192"};
	this.sidHashMap["BatteryTemperatureLow:3:192"] = {rtwname: "<S1>:192"};
	this.rtwnameHashMap["<S1>:25"] = {sid: "BatteryTemperatureLow:3:25"};
	this.sidHashMap["BatteryTemperatureLow:3:25"] = {rtwname: "<S1>:25"};
	this.rtwnameHashMap["<S1>:26"] = {sid: "BatteryTemperatureLow:3:26"};
	this.sidHashMap["BatteryTemperatureLow:3:26"] = {rtwname: "<S1>:26"};
	this.rtwnameHashMap["<S1>:24"] = {sid: "BatteryTemperatureLow:3:24"};
	this.sidHashMap["BatteryTemperatureLow:3:24"] = {rtwname: "<S1>:24"};
	this.rtwnameHashMap["<S1>:108"] = {sid: "BatteryTemperatureLow:3:108"};
	this.sidHashMap["BatteryTemperatureLow:3:108"] = {rtwname: "<S1>:108"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
