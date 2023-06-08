#include "stdafx.h"
#include "EducationService.h"
#include "dao/education/EducationDAO.h"
#include "domain/query/educationSingle/EducationSingleQuery.h"
#include "../hr-c3-assignmentinfo/Macros.h"
#include "SimpleDateTimeFormat.h"
#include "domain/dto/educationDelete/EducationDeleteDTO.h"
#include "SnowFlake.h"
#include "domain/dto/educationAdd/EducationAddDTO.h"



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

int EducationService::saveEducation(const EducationAddDTO::Wrapper& dto)
{
	// 组装DO数据
	EducationDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, FunXL, XL,
		FunQSSJ, QSSJ, FunJSSJ, JSSJ, FunBYYX, BYYX, FunXKML, XKML, FunSXZY, SXZY,
		FunXLLX, XLLX, FunXXXZ, XXXZ, FunSFDYXL, SFDYXL, FunSFZGXL, SFZGXL, FunBTZ, BTZ,
		FunXWZ, XWZ, FunXLCX, XLCX, FunFJ, FJ, FunPIMPERSONID, PIMPERSONID);

	//使用SimpleDateTimeFormat工具生成当前时间的字符串
	string currentTime = SimpleDateTimeFormat::format();
	//data.setCreateDate(currentTime);

	//使用雪花Id生成工具生成Id
	SnowFlake f3(1, 3);
	string id = to_string(f3.nextId());
	data.setFunPIMEDUCATIONID(id);

	// 执行数据添加
	EducationDAO dao;
	return dao.insertEducation(data);            
}

bool EducationService::updateEducation(const EducationAddDTO::Wrapper& dto)
{
	// 组装DO对象
	EducationDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, FunXL, XL,
		FunQSSJ, QSSJ, FunJSSJ, JSSJ, FunBYYX, BYYX, FunXKML, XKML, FunSXZY, SXZY,
		FunXLLX, XLLX, FunXXXZ, XXXZ, FunSFDYXL, SFDYXL, FunSFZGXL, SFZGXL, FunBTZ, BTZ,
		FunXWZ, XWZ, FunXLCX, XLCX, FunFJ, FJ, FunPIMPERSONID, PIMPERSONID);
	//使用SimpleDateTimeFormat工具生成当前时间的字符串
	//string currentTime = SimpleDateTimeFormat::format();
	//data.setUpdateDate(currentTime);
	// TODO: 调用dao操作数据库
	EducationDAO dao;
	return dao.updateEducaiton(data) == 1;
}

bool EducationService::removeEducation(const EducationDeleteSingleDTO::Wrapper& dto)
{

	EducationDAO dao;
	int count = 0;
	for (auto it = dto->PIMEDUCATIONID->begin(); it != dto->PIMEDUCATIONID->end(); ++it)
	{
		count += dao.deleteEducaiton(*it);
	}
	return count;
	
	/*ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, FunPIMEDUCATIONID,  PIMEDUCATIONID, FunPIMPERSONID, PIMPERSONID);
	EducationDAO dao;
	return dao.deleteEducaiton(data) == 1;*/
}

//bool EducationService::removeEducationNotSingle(const EducationDeleteNotSingleDTO::Wrapper& dto)
//{
	//EducationDAO postDeleteDAO;
	//auto sqlSession = postDeleteDAO.getSqlSession();
	////开启事务
	//sqlSession->beginTransaction();
	//bool isSuccess = true;
	/*for (const auto& item : *dto->deleteIds) {
		if (postDeleteDAO.deleteEducaiton(item->c_str()) != 1)
		{
			isSuccess = false;
			return isSuccess;
		}
	}
	sqlSession->commitTransaction();*/
	//return isSuccess;
//}
