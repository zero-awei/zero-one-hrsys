#pragma once
#ifndef _LANGUAGE_SERVICE_
#define _LANGUAGE_SERVICE_
#include <list>
#include "domain/query/Language/LanguageQuery.h"
#include "domain/dto/Language/LanguageDTO.h"
#include "domain/dto/ImportLanguage/ImportLanguageDTO.h"

/**
 * 语言能力相关服务实现
 */
class LanguageService 
{
public:
	// 分页查询所有数据
	LanguagePageDTO::Wrapper listAll(const LanguageQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const LanguageDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const LanguageDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};
#endif // !_LANGUAGE_SERVICE_