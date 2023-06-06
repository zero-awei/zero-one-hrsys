
#include "stdafx.h"
#include "service/patentinfo/patentinfoService.h"
#include "controller/patentinfo/PatentinfoController.h"
#include "domain/do/patentinfo/t_pimpatentDO.h"
#include "domain/dto/patentinfo/AddPatentDTO.h"
#include "domain/dto/patentinfo/DelPatentDTO.h"
#include "domain/dto/patentinfo/PatentinfoDTO.h"
#include "domain/query/patentinfo/PatentinfoQuery.h"
#include "dao/patentinfo/t_pimpatentDAO.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"

#include "../../dao/paperinfo/t_pimpaperDAO.h"

//// 分页查询专利信息 
//PatentinfoPageDTO::Wrapper PatentinfoService::listAll(const PatentinfoQuery::Wrapper& query)
//{ 
//	// 构建返回对象
//	auto pages = PatentinfoPageDTO::createShared();
//	pages->pageIndex = query->pageIndex;
//	pages->pageSize = query->pageSize;
//
//	// 查询数据总条数
//	t_pimpaperDAO dao;
//	uint64_t count = dao.count(query);
//	if (count <= 0)
//	{
//		return pages;
//	}
//
//	// 分页查询数据
//	pages->total = count;
//	pages->calcPages();
//	list<t_pimpaperDO> result = dao.selectWithPage(query);
//	// 将DO转换成DTO
//	for (t_pimpaperDO sub : result)
//	{
//		auto dto = PatentinfoPageDTO::createShared();
//		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fbsj, Fbsj, cbs, Cbs, kwqs, Kwqs,
//			fj, Fj, grzlwzzzdpm, Grzlwzzzdpm, kwmc, Kwmc, pimpapername, Pimpapername);
//			pages->addData(dto);
//	}
//	return pages;
//}


// 新增一条专利信息
int PatentinfoService::saveData(const AddPatentDTO::Wrapper& dto)
{
	//SnowFlake sf(1, 4);
	// 组装DO数据
	//SimpleDateTimeFormat times;
	PatentinfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		ZLH, zlh,
		PIMPATENTNAME, pimpatentname,
		ZLHQSJ, zlhqsj,
		ZLPZGB, zlpzgb,
		PIMPATENTID, pimpatentid)
		//ENCLOLURE, enclolure,
		//CREATEDATE, creatdate,
		//UPDATEDATE, updatedate,
		//CREATEMAN, createman,
		//UPDATEMAN, updateman,

	//雪花算法生产履历id
	SnowFlake snowFlake(1, 5);
	uint64_t id = snowFlake.nextId();
	string idStr = to_string(id);

	// 生成当前时间
	time_t rawtime;
	struct tm* info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);
	string datetime(buffer);


	// 执行数据添加
	t_pimpatentDAO dao;
	return dao.insert(data, idStr, datetime);
}



// 删除专利信息（支持批量删除）
bool PatentinfoService::removeData(const oatpp::List<oatpp::String>& dto)
{
	t_pimpatentDAO dao;
	dao.getSqlSession()->beginTransaction();
	int row = 0;
	for (auto it = dto->begin(); it != dto->end(); ++it)
	{
		row += dao.deleteById((*it).getValue({}));
	}
	if (row == dto->size())
	{
		dao.getSqlSession()->commitTransaction();
		return true;
	}
	else
	{
		dao.getSqlSession()->rollbackTransaction();
		return false;
	}
}