#include "stdafx.h"
#include "QualificationService.h"
#include "../../dao/Qualification/QualificationDAO.h"
QualificationPageDTO::Wrapper QualificationService::listAll(const QualificationQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = QualificationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	QualificationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<QualificationDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (QualificationDO sub : result)
	{
		auto dto = QualificationDTO::createShared();
		dto->qualevel = sub.getquaLevel();
		dto->pimqualmajorname = sub.getpimQualMajorName();
		dto->quamajor = sub.getquaMajor();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, qualevel, quaLevel, pimqualmajorname, pimQualMajorName, 
			quamajor, quaMajor);
		pages->addData(dto);

	}
	return pages;
}

uint64_t QualificationService::saveData(const QualificationDTO::Wrapper& dto)
{
	// 组装DO数据
	QualificationDO data;
	data.setquaLevel(dto->qualevel.getValue(""));
	data.setpimQualMajorName(dto->pimqualmajorname.getValue(""));
	data.setquaMajor(dto->quamajor.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, quaLevel, qualevel, pimQualMajorName, pimqualmajorname, 
		quaMajor, quamajor);
	// 执行数据添加
	QualificationDAO dao;
	return dao.insert(data);
}

bool QualificationService::updateData(const QualificationDTO::Wrapper& dto)
{
	// 组装DO数据
	QualificationDO data;
	data.setquaLevel(dto->qualevel.getValue(""));
	data.setpimQualMajorName(dto->pimqualmajorname.getValue(""));
	data.setquaMajor(dto->quamajor.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, quaLevel, qualevel, pimQualMajorName, pimqualmajorname,
		quaMajor, quamajor);
	// 执行数据修改
	QualificationDAO dao;
	return dao.update(data) == 1;
}

//bool QualificationService::removeData(uint64_t id)
//{
//	QualificationDAO dao;
//	return dao.deleteById(id) == 1;
//}
