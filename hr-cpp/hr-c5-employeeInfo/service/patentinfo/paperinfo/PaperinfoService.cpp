
#include "stdafx.h"
#include "PaperinfoService.h"
#include "../../../dao/paperinfo/t_pimpaperDAO.h"
#include "SnowFlake.h"

PaperPageDTO::Wrapper PaperinfoService::listAll(const PaperQuery::Wrapper& query)
{ 
	// 构建返回对象
	auto pages = PaperPageDTO::createShared(); 
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	t_pimpaperDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<t_pimpaperDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (t_pimpaperDO sub : result)
	{
		auto dto = PaperDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fbsj, Fbsj, cbs, Cbs, kwqs, Kwqs,
			fj, Fj, grzlwzzzdpm, Grzlwzzzdpm, kwmc, Kwmc, pimpapername, Pimpapername);
			pages->addData(dto);
	}
	return pages;
}

int PaperinfoService::saveData(const PaperDTO::Wrapper& dto)
{
	// 组装DO数据
	t_pimpaperDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Fbsj, fbsj, Cbs, cbs, Kwqs, kwqs,
		Fj, fj, Grzlwzzzdpm, grzlwzzzdpm, Kwmc, kwmc, Pimpapername, pimpapername)
	
	// 雪花算法生成id
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
	t_pimpaperDAO dao;
	return dao.insert(data, idStr, datetime);
}

bool PaperinfoService::removeData(string pimpaperid)
{
	t_pimpaperDAO dao;
	return dao.deleteById(pimpaperid) == 1;
}