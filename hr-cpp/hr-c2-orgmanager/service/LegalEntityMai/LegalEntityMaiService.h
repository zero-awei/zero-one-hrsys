#pragma once

#ifndef _LEGALENTITYMAISERVICE_H_
#define _LEGALENTITYMAISERVICE_H_
#include <list>
#include "domain/dto/LegalEntityMai/LegalEntityMaiDTO.h"
#include "domain/query/LegalEntityMai/LegalEntityMaiQuery.h"
#include "domain/dto/LegalEntityMai/LegalEntityMaiDelDTO.h"
#include "domain/dto/LegalEntityMai/LegalEntityMaiAddDTO.h"

/* 法人主体维护服务实现--（组织管理-数据设置-法人主体维护）--TripleGold */
class LegalEntityMaiService
{
public:
	// 分页查询所有数据
	LegalEntityMaiPageDTO::Wrapper listAll(const LegalEntityMaiQuery::Wrapper& query);
	// 修改数据
	bool updateData(const LegalEntityMaiDTO::Wrapper& dto);
	// 增加数据
	uint64_t saveData(const LegalEntityMaiAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// 导入文件
	uint64_t savaBatchDataWithFile(const std::string fileName, const PayloadDTO& payload);
	// 通过ID批量删除数据
	bool deleteById(const LegalEntityMaiDelDTO::Wrapper& dto);
	// 导出文件
	std::string exportFile(const LegalEntityMaiQuery::Wrapper& query);
};

#endif // !_LEGALENTITYMAISERVICE_H_