
#include "stdafx.h"
#include "patentinfoService.h"
#include "../../dao/patentinfo/t_pimpatentDAO.h"

PatentinfoPageDTO::Wrapper PaperinfoService::listAll(const PatentinfoQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = PatentinfoPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	t_pimpatentDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<PatentinfoDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (PatentinfoDO sub : result)
	{
		auto dto = PatentinfoDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, zlh, ZLH, pimpatentname, PIMPATENTNAME, zlhqsj, ZLHQSJ
			, pimpatentname, PIMPATENTNAME, enclolure, ENCLOLURE)
		pages->addData(dto);
	}
	return pages;
}

uint64_t PaperinfoService::saveData(const PatentinfoDTO::Wrapper& dto)
{
	// 组装DO数据
	PatentinfoDTO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, zlh, ZLH, pimpatentname, PIMPATENTNAME, zlhqsj, ZLHQSJ
		, pimpatentname, PIMPATENTNAME, enclolure, ENCLOLURE)
		// 执行数据添加
		t_pimpatentDAO dao;
	return dao.insert(data);
}

bool PaperinfoService::removeData(string pimpaperid)
{
	t_pimpatentDAO dao;
	return dao.deleteById(pimpaperid) == 1;
}