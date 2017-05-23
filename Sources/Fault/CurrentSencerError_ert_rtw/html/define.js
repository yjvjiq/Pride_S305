function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:33,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:76,type:"fcn"};
this.def["CurrentSencerError_B"] = {file: "CurrentSencerError_c.html",line:20,type:"var"};
this.def["CurrentSencerError_DW"] = {file: "CurrentSencerError_c.html",line:23,type:"var"};
this.def["CurrentSencerError_M_"] = {file: "CurrentSencerError_c.html",line:26,type:"var"};
this.def["CurrentSencerError_M"] = {file: "CurrentSencerError_c.html",line:27,type:"var"};
this.def["CurrentSencerError_step"] = {file: "CurrentSencerError_c.html",line:31,type:"fcn"};
this.def["CurrentSencerError_initialize"] = {file: "CurrentSencerError_c.html",line:88,type:"fcn"};
this.def["CurrentSencerError_terminate"] = {file: "CurrentSencerError_c.html",line:109,type:"fcn"};
this.def["B_CurrentSencerError_T"] = {file: "CurrentSencerError_h.html",line:39,type:"type"};
this.def["DW_CurrentSencerError_T"] = {file: "CurrentSencerError_h.html",line:44,type:"type"};
this.def["RT_MODEL_CurrentSencerError_T"] = {file: "CurrentSencerError_types_h.html",line:20,type:"type"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:47,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:48,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:49,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:50,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:60,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:61,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["creal32_T"] = {file: "rtwtypes_h.html",line:78,type:"type"};
this.def["creal64_T"] = {file: "rtwtypes_h.html",line:83,type:"type"};
this.def["creal_T"] = {file: "rtwtypes_h.html",line:88,type:"type"};
this.def["cint8_T"] = {file: "rtwtypes_h.html",line:95,type:"type"};
this.def["cuint8_T"] = {file: "rtwtypes_h.html",line:102,type:"type"};
this.def["cint16_T"] = {file: "rtwtypes_h.html",line:109,type:"type"};
this.def["cuint16_T"] = {file: "rtwtypes_h.html",line:116,type:"type"};
this.def["cint32_T"] = {file: "rtwtypes_h.html",line:123,type:"type"};
this.def["cuint32_T"] = {file: "rtwtypes_h.html",line:130,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:148,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["CurrentSencerError_c.html"] = "../CurrentSencerError.c";
	this.html2Root["CurrentSencerError_c.html"] = "CurrentSencerError_c.html";
	this.html2SrcPath["CurrentSencerError_h.html"] = "../CurrentSencerError.h";
	this.html2Root["CurrentSencerError_h.html"] = "CurrentSencerError_h.html";
	this.html2SrcPath["CurrentSencerError_private_h.html"] = "../CurrentSencerError_private.h";
	this.html2Root["CurrentSencerError_private_h.html"] = "CurrentSencerError_private_h.html";
	this.html2SrcPath["CurrentSencerError_types_h.html"] = "../CurrentSencerError_types.h";
	this.html2Root["CurrentSencerError_types_h.html"] = "CurrentSencerError_types_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
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
"ert_main_c.html","CurrentSencerError_c.html","CurrentSencerError_h.html","CurrentSencerError_private_h.html","CurrentSencerError_types_h.html","rtwtypes_h.html"];
