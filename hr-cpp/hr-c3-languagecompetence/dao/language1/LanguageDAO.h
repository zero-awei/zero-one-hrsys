#pragma once
#ifndef _LANGUAGE_DAO_
#define _LANGUAGE_DAO_

#include "BaseDAO.h"
#include "../../domain/do/language/LanguageDO.h"
#include "../../domain/query/language/LanguageQuery.h"
#include "../../domain/query/languagePage/LanguagePageQuery.h"

/**
 * 关于语言能力模块的数据库操作
 * 负责人：君
 */
class LanguageDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const LanguageQuery::Wrapper& query);
	// 分页查询query统计数据条数
	uint64_t countPage(const LanguagePageQuery::Wrapper& query);
	// 分页查找数据
	list<LanguageDO> selectWithPage(const LanguagePageQuery::Wrapper& query);
	// 通过姓名查询数据
	list<LanguageDO> selectOneById(const string& id);
	// 插入数据
	int insert(const LanguageDO& iObj);
	// 修改数据
	int update(const LanguageDO& uObj);
	// 通过ID删除数据
	int deleteById(std::string id);
};

#endif  // !_LANGUAGE_DAO_
