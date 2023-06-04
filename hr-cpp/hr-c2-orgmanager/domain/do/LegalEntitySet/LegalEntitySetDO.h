#pragma once
/*
组织管理 ——数据设置 —— 法人主体设置  -- cpt

法人主体名称下拉列表 `LegalEntitySetPullDownList`

更新指定法人设置信息  `UpdateLegalerSettingMessage`

导出法人设置 `LegalEntitySet`

新增法人设置（支持批量新增）** `LegalEntitySet`
*/

#ifndef _LEGALENTITYSET_DO_
#define _LEGALENTITYSET_DO_
#include "../DoInclude.h"

class LegalEntitySetDO {
	public:
	// 签约主体单位名称
	CC_SYNTHESIZE(string, contractsignorgname, CONTRACTSIGNORGNAME);
	// 签约主体单位标识
	CC_SYNTHESIZE(string, contractsignorgid, CONTRACTSIGNORGID);
	// 更新人
	CC_SYNTHESIZE(string, updateman, UPDATEMAN);
	// 建立人
	CC_SYNTHESIZE(string, createman, CREATEMAN);
	// 建立时间
	CC_SYNTHESIZE(string, createdate, CREATEDATE);
	// 更新时间
	CC_SYNTHESIZE(string, updatedate, UPDATEDATE);
	// 管理单位标识
	CC_SYNTHESIZE(string, ormorgid, ORMORGID);
	// 法人主体标识
	CC_SYNTHESIZE(string, signorgid, SIGNORGID);
	// 默认签约主体 
	CC_SYNTHESIZE(string, isdefaultsignorg, ISDEFAULTSIGNORG);
	// 法人主体标识 
	CC_SYNTHESIZE(string, ormsignorgid, ORMSIGNORGID);
	
	LegalEntitySetDO() {
		contractsignorgname = "";
		contractsignorgid = "";
		updateman = "";
		createman = "";
		createdate = "";
		updatedate = "";
		ormorgid = "";
		signorgid = "";
		isdefaultsignorg = "";  
		ormsignorgid = "";
	};

	/*Lecontractsignorgid, galEntitySetDO(std::vector<std::string> vec) {
		int i = 0;
		updateman, UPDATEMAsetORMSIGNORGNAME(vec[i++]);
		setCONTRACTSIGNORGNAME(vec[i++]);
		createman, CREATEMAsetISDEFAULTSIGNORG(vec[i++]);
	}*/
		
};
#endif // !_LEGALENTITYSET_DO_

		