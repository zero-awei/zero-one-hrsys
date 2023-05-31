#pragma once
#ifndef _LEGALENTITYSETSERVICE_SERVICE_
#define _LEGALENTITYSETSERVICE_SERVICE_
#include "domain/dto/LegalEntitySet/ImportLeagalPerSettingDTO.h"
#include <list>
#include "domain/vo/LegalEntitySet/LegalEntitySetVO.h"
#include "domain/dto/LegalEntitySet/LegalEntitySetDTO.h"
#include "domain/query/LegalEntitySet/LegalEntitySetQuery.h"
#include "domain/do/LegalEntitySet/LegalEntitySetDO.h"
/*
组织管理 ——数据设置 —— 法人主体设置  -- cpt

法人主体名称下拉列表 `LegalEntitySetPullDownList`

更新指定法人设置信息  `UpdateLegalerSettingMessage`

导出法人设置 `LegalEntitySet`

新增法人设置（支持批量新增）** `LegalEntitySet`
*/
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class LegalEntitySetService
{
public:
	// 分页查询所有数据
	LegalEntitySetPageDTO::Wrapper listAll(const LegalEntitySetQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const LegalEntitySetDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const LegalEntitySetDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};


#endif // !_LEGALENTITYSETSERVICE_SERVICE_