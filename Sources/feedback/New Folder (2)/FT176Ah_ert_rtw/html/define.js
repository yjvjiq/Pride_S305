function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:34,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:71,type:"fcn"};
this.def["out2"] = {file: "FT176Ah_c.html",line:20,type:"var"};
this.def["out3"] = {file: "FT176Ah_c.html",line:21,type:"var"};
this.def["FT176Ah_U"] = {file: "FT176Ah_c.html",line:24,type:"var"};
this.def["FT176Ah_M_"] = {file: "FT176Ah_c.html",line:27,type:"var"};
this.def["FT176Ah_M"] = {file: "FT176Ah_c.html",line:28,type:"var"};
this.def["FT176Ah_step"] = {file: "FT176Ah_c.html",line:31,type:"fcn"};
this.def["FT176Ah_initialize"] = {file: "FT176Ah_c.html",line:41,type:"fcn"};
this.def["FT176Ah_terminate"] = {file: "FT176Ah_c.html",line:66,type:"fcn"};
this.def["ExtU_FT176Ah_T"] = {file: "FT176Ah_h.html",line:55,type:"type"};
this.def["RT_MODEL_FT176Ah_T"] = {file: "FT176Ah_types_h.html",line:20,type:"type"};
this.def["rtTimingBridge"] = {file: "../../slprj/ert/_sharedutils/html/model_reference_types_h.html",line:24,type:"type"};
this.def["int8_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:42,type:"type"};
this.def["uint8_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:43,type:"type"};
this.def["int16_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:44,type:"type"};
this.def["uint16_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:45,type:"type"};
this.def["int32_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:46,type:"type"};
this.def["uint32_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:47,type:"type"};
this.def["real32_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:48,type:"type"};
this.def["real64_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:49,type:"type"};
this.def["real_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:55,type:"type"};
this.def["time_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:56,type:"type"};
this.def["boolean_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:57,type:"type"};
this.def["int_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:58,type:"type"};
this.def["uint_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:59,type:"type"};
this.def["ulong_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:60,type:"type"};
this.def["char_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:61,type:"type"};
this.def["uchar_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:62,type:"type"};
this.def["byte_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:63,type:"type"};
this.def["creal32_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:73,type:"type"};
this.def["creal64_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:78,type:"type"};
this.def["creal_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:83,type:"type"};
this.def["cint8_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:90,type:"type"};
this.def["cuint8_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:97,type:"type"};
this.def["cint16_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:104,type:"type"};
this.def["cuint16_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:111,type:"type"};
this.def["cint32_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:118,type:"type"};
this.def["cuint32_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:125,type:"type"};
this.def["pointer_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:143,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["FT176Ah_c.html"] = "../FT176Ah.c";
	this.html2Root["FT176Ah_c.html"] = "FT176Ah_c.html";
	this.html2SrcPath["FT176Ah_h.html"] = "../FT176Ah.h";
	this.html2Root["FT176Ah_h.html"] = "FT176Ah_h.html";
	this.html2SrcPath["FT176Ah_private_h.html"] = "../FT176Ah_private.h";
	this.html2Root["FT176Ah_private_h.html"] = "FT176Ah_private_h.html";
	this.html2SrcPath["FT176Ah_types_h.html"] = "../FT176Ah_types.h";
	this.html2Root["FT176Ah_types_h.html"] = "FT176Ah_types_h.html";
	this.html2SrcPath["model_reference_types_h.html"] = "../model_reference_types.h";
	this.html2Root["model_reference_types_h.html"] = "../../slprj/ert/_sharedutils/html/model_reference_types_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "../../slprj/ert/_sharedutils/html/rtwtypes_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","FT176Ah_c.html","FT176Ah_h.html","FT176Ah_private_h.html","FT176Ah_types_h.html","model_reference_types_h.html","rtwtypes_h.html"];
