#pragma once

/*
*（	数据设置——法人主体设置 ——  cpt

法人主体名称下拉列表 `LegalerNamePullDownList`

更新指定法人设置信息  `UpdateLegalerSettingMessage`

导出法人设置 `ExportLegalerSeting`

新增法人设置（支持批量新增）** `AddLegalerSeting`
*/

#ifndef _LEGALENTITYSET_DO_
#define _LEGALENTITYSET_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class LegalEntitySetDO {
	//法人主体标识
	CC_SYNTHESIZE(string, ormsignorgid, ORMSIGNORGID);
	// 法人主体名称   表 ： t_ormsignorg 
	CC_SYNTHESIZE(string, ormsignorgname, ORMSIGNORGNAME);
	// 签约主体单位名称 t_contractsignorg
	CC_SYNTHESIZE(string, contractsignorgname, CONTRACTSIGNORGNAME);
	// 默认签约主体  t_contractsignorg
	CC_SYNTHESIZE(int, isdefaultsignorg, ISDEFAULTSIGNORG);


public:
	LegalEntitySetDO() {
	}
	LegalEntitySetDO(string ormsignorgid, string ormsignorgname, string contractsignorgname, int isdefaultsignorg) {
		this->ormsignorgid = ormsignorgid;
		this->ormsignorgname = ormsignorgname;
		this->contractsignorgname = contractsignorgname;
		this->isdefaultsignorg = isdefaultsignorg;
	}
};
#endif // !_LEGALENTITYSET_DO_