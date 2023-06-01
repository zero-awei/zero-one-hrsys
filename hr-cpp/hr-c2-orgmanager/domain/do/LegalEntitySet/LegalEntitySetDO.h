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

/**
 * 示例数据库实体类
 */
class LegalEntitySetDO {
	public:
	// 法人主体标识
	CC_SYNTHESIZE(string, ormsignorgid, ORMSIGNORGID);
	// 法人主体名称   表 ： t_ormsignorg 
	CC_SYNTHESIZE(string, ormsignorgname, ORMSIGNORGNAME);
	// 签约主体单位名称 t_contractsignorg
	CC_SYNTHESIZE(string, contractsignorgname, CONTRACTSIGNORGNAME);
	// 默认签约主体  t_contractsignorg
	CC_SYNTHESIZE(string, isdefaultsignorg, ISDEFAULTSIGNORG);
	LegalEntitySetDO() {
		ormsignorgid = "";
		ormsignorgname = "";
		contractsignorgname = "";
		isdefaultsignorg = "";
	};
	LegalEntitySetDO(std::vector<std::string> vec) {
		int i = 0;
		setORMSIGNORGNAME(vec[i++]);
		setCONTRACTSIGNORGNAME(vec[i++]);
		setISDEFAULTSIGNORG(vec[i++]);
	}
	LegalEntitySetDO(string ormsignorgid, string ormsignorgname, string contractsignorgname, string isdefaultsignorg) {
		this->ormsignorgid = ormsignorgid;
		this->ormsignorgname = ormsignorgname;
		this->contractsignorgname = contractsignorgname;
		this->isdefaultsignorg = isdefaultsignorg;
	}
};
#endif // !_LEGALENTITYSET_DO_
