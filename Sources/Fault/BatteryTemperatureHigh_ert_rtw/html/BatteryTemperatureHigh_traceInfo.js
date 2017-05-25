function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Tmax */
	this.urlHashMap["BatteryTemperatureHigh:1"] = "ert_main.c:37&BatteryTemperatureHigh.c:48";
	/* <Root>/Chart */
	this.urlHashMap["BatteryTemperatureHigh:3"] = "BatteryTemperatureHigh.c:19,47,172,195&BatteryTemperatureHigh.h:38,43,44,45,46,47";
	/* <Root>/F_lev */
	this.urlHashMap["BatteryTemperatureHigh:2"] = "ert_main.c:40&BatteryTemperatureHigh.c:174";
	/* <S1>:103 */
	this.urlHashMap["BatteryTemperatureHigh:3:103"] = "BatteryTemperatureHigh.c:66,75";
	/* <S1>:181 */
	this.urlHashMap["BatteryTemperatureHigh:3:181"] = "BatteryTemperatureHigh.c:67,76";
	/* <S1>:184 */
	this.urlHashMap["BatteryTemperatureHigh:3:184"] = "BatteryTemperatureHigh.c:79";
	/* <S1>:187 */
	this.urlHashMap["BatteryTemperatureHigh:3:187"] = "BatteryTemperatureHigh.c:95";
	/* <S1>:189 */
	this.urlHashMap["BatteryTemperatureHigh:3:189"] = "BatteryTemperatureHigh.c:88,100,114";
	/* <S1>:191 */
	this.urlHashMap["BatteryTemperatureHigh:3:191"] = "BatteryTemperatureHigh.c:107,123";
	/* <S1>:185 */
	this.urlHashMap["BatteryTemperatureHigh:3:185"] = "BatteryTemperatureHigh.c:129";
	/* <S1>:102 */
	this.urlHashMap["BatteryTemperatureHigh:3:102"] = "BatteryTemperatureHigh.c:71,138";
	/* <S1>:28 */
	this.urlHashMap["BatteryTemperatureHigh:3:28"] = "BatteryTemperatureHigh.c:141";
	/* <S1>:23 */
	this.urlHashMap["BatteryTemperatureHigh:3:23"] = "BatteryTemperatureHigh.c:150,157";
	/* <S1>:98 */
	this.urlHashMap["BatteryTemperatureHigh:3:98"] = "BatteryTemperatureHigh.c:162";
	/* <S1>:104 */
	this.urlHashMap["BatteryTemperatureHigh:3:104"] = "BatteryTemperatureHigh.c:65";
	/* <S1>:186 */
	this.urlHashMap["BatteryTemperatureHigh:3:186"] = "BatteryTemperatureHigh.c:131";
	/* <S1>:183 */
	this.urlHashMap["BatteryTemperatureHigh:3:183"] = "BatteryTemperatureHigh.c:68";
	/* <S1>:182 */
	this.urlHashMap["BatteryTemperatureHigh:3:182"] = "BatteryTemperatureHigh.c:85";
	/* <S1>:194 */
	this.urlHashMap["BatteryTemperatureHigh:3:194"] = "BatteryTemperatureHigh.c:81";
	/* <S1>:192 */
	this.urlHashMap["BatteryTemperatureHigh:3:192"] = "BatteryTemperatureHigh.c:116";
	/* <S1>:188 */
	this.urlHashMap["BatteryTemperatureHigh:3:188"] = "BatteryTemperatureHigh.c:97";
	/* <S1>:190 */
	this.urlHashMap["BatteryTemperatureHigh:3:190"] = "BatteryTemperatureHigh.c:104";
	/* <S1>:193 */
	this.urlHashMap["BatteryTemperatureHigh:3:193"] = "BatteryTemperatureHigh.c:124";
	/* <S1>:25 */
	this.urlHashMap["BatteryTemperatureHigh:3:25"] = "BatteryTemperatureHigh.c:164";
	/* <S1>:26 */
	this.urlHashMap["BatteryTemperatureHigh:3:26"] = "BatteryTemperatureHigh.c:147";
	/* <S1>:24 */
	this.urlHashMap["BatteryTemperatureHigh:3:24"] = "BatteryTemperatureHigh.c:143";
	/* <S1>:108 */
	this.urlHashMap["BatteryTemperatureHigh:3:108"] = "BatteryTemperatureHigh.c:72";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "BatteryTemperatureHigh"};
	this.sidHashMap["BatteryTemperatureHigh"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "BatteryTemperatureHigh:3"};
	this.sidHashMap["BatteryTemperatureHigh:3"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/Tmax"] = {sid: "BatteryTemperatureHigh:1"};
	this.sidHashMap["BatteryTemperatureHigh:1"] = {rtwname: "<Root>/Tmax"};
	this.rtwnameHashMap["<Root>/Chart"] = {sid: "BatteryTemperatureHigh:3"};
	this.sidHashMap["BatteryTemperatureHigh:3"] = {rtwname: "<Root>/Chart"};
	this.rtwnameHashMap["<Root>/F_lev"] = {sid: "BatteryTemperatureHigh:2"};
	this.sidHashMap["BatteryTemperatureHigh:2"] = {rtwname: "<Root>/F_lev"};
	this.rtwnameHashMap["<S1>:103"] = {sid: "BatteryTemperatureHigh:3:103"};
	this.sidHashMap["BatteryTemperatureHigh:3:103"] = {rtwname: "<S1>:103"};
	this.rtwnameHashMap["<S1>:181"] = {sid: "BatteryTemperatureHigh:3:181"};
	this.sidHashMap["BatteryTemperatureHigh:3:181"] = {rtwname: "<S1>:181"};
	this.rtwnameHashMap["<S1>:184"] = {sid: "BatteryTemperatureHigh:3:184"};
	this.sidHashMap["BatteryTemperatureHigh:3:184"] = {rtwname: "<S1>:184"};
	this.rtwnameHashMap["<S1>:187"] = {sid: "BatteryTemperatureHigh:3:187"};
	this.sidHashMap["BatteryTemperatureHigh:3:187"] = {rtwname: "<S1>:187"};
	this.rtwnameHashMap["<S1>:189"] = {sid: "BatteryTemperatureHigh:3:189"};
	this.sidHashMap["BatteryTemperatureHigh:3:189"] = {rtwname: "<S1>:189"};
	this.rtwnameHashMap["<S1>:191"] = {sid: "BatteryTemperatureHigh:3:191"};
	this.sidHashMap["BatteryTemperatureHigh:3:191"] = {rtwname: "<S1>:191"};
	this.rtwnameHashMap["<S1>:185"] = {sid: "BatteryTemperatureHigh:3:185"};
	this.sidHashMap["BatteryTemperatureHigh:3:185"] = {rtwname: "<S1>:185"};
	this.rtwnameHashMap["<S1>:102"] = {sid: "BatteryTemperatureHigh:3:102"};
	this.sidHashMap["BatteryTemperatureHigh:3:102"] = {rtwname: "<S1>:102"};
	this.rtwnameHashMap["<S1>:28"] = {sid: "BatteryTemperatureHigh:3:28"};
	this.sidHashMap["BatteryTemperatureHigh:3:28"] = {rtwname: "<S1>:28"};
	this.rtwnameHashMap["<S1>:23"] = {sid: "BatteryTemperatureHigh:3:23"};
	this.sidHashMap["BatteryTemperatureHigh:3:23"] = {rtwname: "<S1>:23"};
	this.rtwnameHashMap["<S1>:98"] = {sid: "BatteryTemperatureHigh:3:98"};
	this.sidHashMap["BatteryTemperatureHigh:3:98"] = {rtwname: "<S1>:98"};
	this.rtwnameHashMap["<S1>:104"] = {sid: "BatteryTemperatureHigh:3:104"};
	this.sidHashMap["BatteryTemperatureHigh:3:104"] = {rtwname: "<S1>:104"};
	this.rtwnameHashMap["<S1>:186"] = {sid: "BatteryTemperatureHigh:3:186"};
	this.sidHashMap["BatteryTemperatureHigh:3:186"] = {rtwname: "<S1>:186"};
	this.rtwnameHashMap["<S1>:183"] = {sid: "BatteryTemperatureHigh:3:183"};
	this.sidHashMap["BatteryTemperatureHigh:3:183"] = {rtwname: "<S1>:183"};
	this.rtwnameHashMap["<S1>:182"] = {sid: "BatteryTemperatureHigh:3:182"};
	this.sidHashMap["BatteryTemperatureHigh:3:182"] = {rtwname: "<S1>:182"};
	this.rtwnameHashMap["<S1>:194"] = {sid: "BatteryTemperatureHigh:3:194"};
	this.sidHashMap["BatteryTemperatureHigh:3:194"] = {rtwname: "<S1>:194"};
	this.rtwnameHashMap["<S1>:192"] = {sid: "BatteryTemperatureHigh:3:192"};
	this.sidHashMap["BatteryTemperatureHigh:3:192"] = {rtwname: "<S1>:192"};
	this.rtwnameHashMap["<S1>:188"] = {sid: "BatteryTemperatureHigh:3:188"};
	this.sidHashMap["BatteryTemperatureHigh:3:188"] = {rtwname: "<S1>:188"};
	this.rtwnameHashMap["<S1>:190"] = {sid: "BatteryTemperatureHigh:3:190"};
	this.sidHashMap["BatteryTemperatureHigh:3:190"] = {rtwname: "<S1>:190"};
	this.rtwnameHashMap["<S1>:193"] = {sid: "BatteryTemperatureHigh:3:193"};
	this.sidHashMap["BatteryTemperatureHigh:3:193"] = {rtwname: "<S1>:193"};
	this.rtwnameHashMap["<S1>:25"] = {sid: "BatteryTemperatureHigh:3:25"};
	this.sidHashMap["BatteryTemperatureHigh:3:25"] = {rtwname: "<S1>:25"};
	this.rtwnameHashMap["<S1>:26"] = {sid: "BatteryTemperatureHigh:3:26"};
	this.sidHashMap["BatteryTemperatureHigh:3:26"] = {rtwname: "<S1>:26"};
	this.rtwnameHashMap["<S1>:24"] = {sid: "BatteryTemperatureHigh:3:24"};
	this.sidHashMap["BatteryTemperatureHigh:3:24"] = {rtwname: "<S1>:24"};
	this.rtwnameHashMap["<S1>:108"] = {sid: "BatteryTemperatureHigh:3:108"};
	this.sidHashMap["BatteryTemperatureHigh:3:108"] = {rtwname: "<S1>:108"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
