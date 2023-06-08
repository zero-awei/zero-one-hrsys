#include "stdafx.h"
#include "LanguageService.h"
#include "../../domain/do/language/LanguageDO.h"
#include "../../dao/language/LanguageDAO.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "bsoncxx/third_party/mnmlstc/core/range.hpp"
#include "uselib/fastdfs/UseFastDFS.h"

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
	list<LanguageDO> result = dao.selectOneById(query->languageAbilityID);
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

	//初始化FastDFS服务器
	UseFastDFS fastDFS("192.168.31.128");
	//上传文件
	string url = fastDFS.upload(dto->attachment);
	data.setAttachment(url);

	//使用SimpleDateTimeFormat工具生成当前时间的字符串
	string currentTime = SimpleDateTimeFormat::format();
	data.setCreateDate(currentTime);

	//使用雪花Id生成工具生成Id
	SnowFlake f3(1, 3);
	string id = to_string(f3.nextId());
	data.setLanguageAbilityID(id);

	// 执行数据添加;
	LanguageDAO dao;
	return dao.insert(data);
}

bool LanguageService::updateData(const LanguageDTO::Wrapper& dto)
{
	//组装DO数据
	LanguageDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, LanguageAbilityID, languageAbilityID, Permission, permission, GainTime, gainTime, Attachment, attachment,
		LanguageType, languageType, UpdateMan, updateMan, LanguageLevel, languageLevel);

	//初始化FastDFS服务器
	UseFastDFS fastDFS("192.168.31.128");
	//上传文件
	string url = fastDFS.upload(dto->attachment);
	data.setAttachment(url);

	//使用SimpleDateTimeFormat工具生成当前时间的字符串
	string currentTime = SimpleDateTimeFormat::format();
	data.setUpdateDate(currentTime);

	//执行数据修改
	LanguageDAO dao;
	return dao.update(data) == 1;
}

int LanguageService::removeData(const DeleteLanguageDTO::Wrapper& dto)
{
	//执行数据删除
	LanguageDAO dao;
	int count = 0;
	for (auto it = dto->languageAbilityID->begin(); it != dto->languageAbilityID->end(); ++it)
	{
		count += dao.deleteById(*it);
	}
	return count;
}
