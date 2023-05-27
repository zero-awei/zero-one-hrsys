#include "stdafx.h"
#include "LanguageService.h"
#include "../../domain/do/Language/LanguageDO.h"

/**
 * 语言能力service层实现
 * 负责人：君
 */
LanguagePageDTO::Wrapper LanguageService::listAll(const LanguagePageQuery::Wrapper& query)
{
	//创建返回对象
	auto pages = LanguagePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;




	return pages;
}

LanguageDTO::Wrapper LanguageService::queryOneData(const LanguageQuery::Wrapper& query)
{
	//创建返回对象
	auto data = LanguageDTO::createShared();




	return data;
}

uint64_t LanguageService::saveData(const LanguageDTO::Wrapper& dto)
{
	//组装DO数据
	LanguageDO data;


	return 1;
}

bool LanguageService::updateData(const LanguageDTO::Wrapper& dto)
{
	//组装DO数据
	LanguageDO data;


	return true;
}

bool LanguageService::removeData(string id, string languageType)
{
	//组装DO数据
	LanguageDO data;


	return true;
}
