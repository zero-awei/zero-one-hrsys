#include "stdafx.h"
#include "EducationService.h"
#include "dao/Education/EducationDAO.h"
#include "domain/query/EducationSingle/EducationSingleQuery.h"
#include "../hr-c3-assignmentinfo/Macros.h"
#include "SimpleDateTimeFormat.h"
#include "domain/dto/EducationDelete/EducationDeleteDTO.h"



EducationPageDTO::Wrapper EducationService::listEducationPage(const EducationPageQuery::Wrapper& query)
{
	// 构建返回对象
	auto dto = EducationPageDTO::createShared();
	dto->pageIndex = query->pageIndex;
	dto->pageSize = query->pageSize;

	// 获取查询总条数
	EducationDAO dao;
	uint64_t cnt = dao.count(query);
	if (cnt <= 0)
	{
		return dto;
	}

	// 分页查询数据
	dto->total = cnt;
	dto->calcPages();
	list<EducationDO> res = dao.selectEducationPage(query);
	// 将DO转成DTO
	for (EducationDO item : res)
	{
		auto to_dto = EducationSingleDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(to_dto, item, PIMEDUCATIONID, FunPIMEDUCATIONID, XL, FunXL, 
			QSSJ, FunQSSJ, JSSJ, FunJSSJ, BYYX, FunBYYX, XKML, FunXKML, SXZY, FunSXZY, 
			XLLX, FunXLLX, XXXZ, FunXXXZ, SFDYXL, FunSFDYXL, SFZGXL, FunSFZGXL, BTZ, FunBTZ,
			XWZ, FunXWZ, XLCX, FunXLCX);
		dto->addData(to_dto);
	}
	return dto;
}

EducationSingleDTO::Wrapper EducationService::listEducationSingle(const EducationSingleQuery::Wrapper& query)
{
	EducationDAO dao;
	auto lists = dao.selectEducationSingle(query);
	auto dto = EducationSingleDTO::createShared();
	if (!lists.empty()) {
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, lists.front(), PIMEDUCATIONID, FunPIMEDUCATIONID, XL, FunXL,
			QSSJ, FunQSSJ, JSSJ, FunJSSJ, BYYX, FunBYYX, XKML, FunXKML, SXZY, FunSXZY,
			XLLX, FunXLLX, XXXZ, FunXXXZ, SFDYXL, FunSFDYXL, SFZGXL, FunSFZGXL, BTZ, FunBTZ,
			XWZ, FunXWZ, XLCX, FunXLCX);
	}
	return dto;
}

uint64_t EducationService::saveEducation(const EducationSingleDTO::Wrapper& dto)
{
	// 组装DO数据
	EducationDO data;
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, data, PIMEDUCATIONID, FunPIMEDUCATIONID, XL, FunXL,
		QSSJ, FunQSSJ, JSSJ, FunJSSJ, BYYX, FunBYYX, XKML, FunXKML, SXZY, FunSXZY,
		XLLX, FunXLLX, XXXZ, FunXXXZ, SFDYXL, FunSFDYXL, SFZGXL, FunSFZGXL, BTZ, FunBTZ,
		XWZ, FunXWZ, XLCX, FunXLCX, FJ, FunFJ);


	// 执行数据添加
	EducationDAO dao;
	return dao.insertEducation(data);
}

bool EducationService::updateEducation(const EducationSingleDTO::Wrapper& dto)
{
	// 组装DO对象
	EducationDO data;
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, data, PIMEDUCATIONID, FunPIMEDUCATIONID, XL, FunXL,
		QSSJ, FunQSSJ, JSSJ, FunJSSJ, BYYX, FunBYYX, XKML, FunXKML, SXZY, FunSXZY,
		XLLX, FunXLLX, XXXZ, FunXXXZ, SFDYXL, FunSFDYXL, SFZGXL, FunSFZGXL, BTZ, FunBTZ,
		XWZ, FunXWZ, XLCX, FunXLCX, FJ, FunFJ);
	//data.setUpdater(payload.getUsername());
	//data.setUpdateTime(SimpleDateTimeFormat::format());
	// TODO: 调用dao操作数据库
	EducationDAO dao;
	return dao.updateEducaiton(data);
}

bool EducationService::removeEducation(string id)
{
	EducationDAO postDeleteDAO;
	return postDeleteDAO.deleteEducaiton(id) == 1;
}

bool EducationService::removeEducationNotSingle(const EducationDeleteNotSingleDTO::Wrapper& dto)
{
	EducationDAO postDeleteDAO;
	auto sqlSession = postDeleteDAO.getSqlSession();
	//开启事务
	sqlSession->beginTransaction();
	bool isSuccess = true;
	for (const auto& item : *dto->deleteIds) {
		if (postDeleteDAO.deleteEducaiton(item->c_str()) != 1)
		{
			isSuccess = false;
			return isSuccess;
		}
	}
	sqlSession->commitTransaction();
	return isSuccess;
}
