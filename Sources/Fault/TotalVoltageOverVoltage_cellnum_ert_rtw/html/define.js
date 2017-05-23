function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:33,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:79,type:"fcn"};
this.def["TotalVoltageOverVoltage_cell_DW"] = {file: "TotalVoltageOverVoltage_cellnum_c.html",line:20,type:"var"};
this.def["TotalVoltageOverVoltage_celln_U"] = {file: "TotalVoltageOverVoltage_cellnum_c.html",line:23,type:"var"};
this.def["TotalVoltageOverVoltage_cell_M_"] = {file: "TotalVoltageOverVoltage_cellnum_c.html",line:26,type:"var"};
this.def["TotalVoltageOverVoltage_cell_M"] = {file: "TotalVoltageOverVoltage_cellnum_c.html",line:27,type:"var"};
this.def["TotalVol_inner_default_F_0_true"] = {file: "TotalVoltageOverVoltage_cellnum_c.html",line:36,type:"fcn"};
this.def["TotalVoltageOverVoltage_celln_F"] = {file: "TotalVoltageOverVoltage_cellnum_c.html",line:82,type:"fcn"};
this.def["TotalVoltageOverVoltag_ValueSet"] = {file: "TotalVoltageOverVoltage_cellnum_c.html",line:519,type:"fcn"};
this.def["TotalVoltageOverVoltage_step"] = {file: "TotalVoltageOverVoltage_cellnum_c.html",line:562,type:"fcn"};
this.def["TotalVoltageOverVoltage_initialize"] = {file: "TotalVoltageOverVoltage_cellnum_c.html",line:990,type:"fcn"};
this.def["TotalVoltageOverVoltage_cellnum_terminate"] = {file: "TotalVoltageOverVoltage_cellnum_c.html",line:1045,type:"fcn"};
this.def["DW_TotalVoltageOverVoltage_ce_T"] = {file: "TotalVoltageOverVoltage_cellnum_h.html",line:66,type:"type"};
this.def["ExtU_TotalVoltageOverVoltage__T"] = {file: "TotalVoltageOverVoltage_cellnum_h.html",line:72,type:"type"};
this.def["P_TotalVoltageOverVoltage_cel_T"] = {file: "TotalVoltageOverVoltage_cellnum_types_h.html",line:21,type:"type"};
this.def["RT_MODEL_TotalVoltageOverVolt_T"] = {file: "TotalVoltageOverVoltage_cellnum_types_h.html",line:24,type:"type"};
this.def["TotalVoltageOverVoltage_celln_P"] = {file: "TotalVoltageOverVoltage_cellnum_data_c.html",line:20,type:"var"};
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
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["TotalVoltageOverVoltage_cellnum_c.html"] = "../TotalVoltageOverVoltage_cellnum.c";
	this.html2Root["TotalVoltageOverVoltage_cellnum_c.html"] = "TotalVoltageOverVoltage_cellnum_c.html";
	this.html2SrcPath["TotalVoltageOverVoltage_cellnum_h.html"] = "../TotalVoltageOverVoltage_cellnum.h";
	this.html2Root["TotalVoltageOverVoltage_cellnum_h.html"] = "TotalVoltageOverVoltage_cellnum_h.html";
	this.html2SrcPath["TotalVoltageOverVoltage_cellnum_private_h.html"] = "../TotalVoltageOverVoltage_cellnum_private.h";
	this.html2Root["TotalVoltageOverVoltage_cellnum_private_h.html"] = "TotalVoltageOverVoltage_cellnum_private_h.html";
	this.html2SrcPath["TotalVoltageOverVoltage_cellnum_types_h.html"] = "../TotalVoltageOverVoltage_cellnum_types.h";
	this.html2Root["TotalVoltageOverVoltage_cellnum_types_h.html"] = "TotalVoltageOverVoltage_cellnum_types_h.html";
	this.html2SrcPath["TotalVoltageOverVoltage_cellnum_data_c.html"] = "../TotalVoltageOverVoltage_cellnum_data.c";
	this.html2Root["TotalVoltageOverVoltage_cellnum_data_c.html"] = "TotalVoltageOverVoltage_cellnum_data_c.html";
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
"ert_main_c.html","TotalVoltageOverVoltage_cellnum_c.html","TotalVoltageOverVoltage_cellnum_h.html","TotalVoltageOverVoltage_cellnum_private_h.html","TotalVoltageOverVoltage_cellnum_types_h.html","TotalVoltageOverVoltage_cellnum_data_c.html","rtwtypes_h.html"];
