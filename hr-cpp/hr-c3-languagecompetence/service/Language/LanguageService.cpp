#include "stdafx.h"
#include "LanguageService.h"
#include "../../domain/do/Language/LanguageDO.h"
#include "../../dao/Language/LanguageDAO.h"

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

	//查询数据总条数
	LanguageDAO dao;
	uint64_t count = dao.countPage(query);
	if (count <= 0)
	{
		return pages;
	}

	//分页查询数据
	pages->total = count;
	pages->calcPages();
	list<LanguageDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (LanguageDO sub : result)
	{
		auto dto = LanguageDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, languageAbilityID, LanguageAbilityID, permission, Permission,
			gainTime, GainTime, attachment, Attachment, languageType, LanguageType, createMan, CreateMan,
			updateMan, UpdateMan, languageLevel, LanguageLevel, personID, PersonID, jlss, JLSS,
			jlglbh, JLGLBH, jlspzt, JLSPZT, jlczz, JLCZZ);
		pages->addData(dto);
	}
	return pages;
}

LanguageDTO::Wrapper LanguageService::queryOneDataById(const LanguageQuery::Wrapper& query)
{
	//创建返回对象
	auto data = LanguageDTO::createShared();
	//查询数据总条数
	LanguageDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return data;
	}

	//获取查询数据
	list<LanguageDO> result = dao.selectOneById(query->personID);
	//将DO转换成DTO
	//list迭代器
	std::list<LanguageDO>::iterator it = result.begin();
	LanguageDO sub = *it;
	ZO_STAR_DOMAIN_DO_TO_DTO(data, sub, languageAbilityID, LanguageAbilityID, permission, Permission,
		gainTime, GainTime, attachment, Attachment, languageType, LanguageType, createMan, CreateMan,
		updateMan, UpdateMan, languageLevel, LanguageLevel, personID, PersonID, jlss, JLSS,
		jlglbh, JLGLBH, jlspzt, JLSPZT, jlczz, JLCZZ);
	return data;
}

int LanguageService::saveData(const LanguageDTO::Wrapper& dto)
{
	//组装DO数据
	LanguageDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, GainTime, gainTime, Attachment, attachment, LanguageType, languageType,
		CreateMan, createMan, LanguageLevel, languageLevel, PersonID, personID);

	// 执行数据添加
	LanguageDAO dao;
	return dao.insert(data);
}

bool LanguageService::updateData(const LanguageDTO::Wrapper& dto)
{
	//组装DO数据
	LanguageDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Permission, permission, GainTime, gainTime, Attachment, attachment,
		LanguageType, languageType, UpdateMan, updateMan, LanguageLevel, languageLevel);

	//执行数据修改
	LanguageDAO dao;
	return dao.update(data) == 1;
}

bool LanguageService::removeData(string id, string languageType)
{
	//组装DO数据
	LanguageDO data;
	//执行数据删除
	LanguageDAO dao;
	return dao.deleteById(id,languageType);
}
