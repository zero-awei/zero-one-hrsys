#include "stdafx.h"
#include "ArchiveService.h"
#include "../../dao/archive/ArchiveDAO.h"
ArchivePageDTO::Wrapper ArchiveService::listAll(const ArchiveQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ArchivePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ArchiveDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ArchiveDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ArchiveDO sub : result)
	{
		auto dto = ArchiveDTO::createShared();
		dto->sortid= sub.getsortID();
		dto->archivename = sub.getarchiveName();
		dto->cabinetnum = sub.getcabinetNum();
 		dto->layernum = sub.getlayerNum();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, sortid, sortID, archivename, archiveName, cabinetnum, cabinetNum,
			layernum, layerNum, numid, numID);
		pages->addData(dto);

	}
	return pages;
}

uint64_t ArchiveService::saveData(const ArchiveDTO::Wrapper& dto)
{
	// 组装DO数据
	ArchiveDO data;
	data.setsortID(dto->sortid.getValue(1));
 	data.setarchiveName(dto->archivename.getValue(""));
 	data.setcabinetNum(dto->cabinetnum.getValue(1));
	data.setlayerNum(dto->layernum.getValue(1));
	data.setnumID(dto->numid.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, sortID, sortid, archiveName, archivename, cabinetNum, cabinetnum,
		layerNum, layernum, numID, numid);
		// 执行数据添加
	ArchiveDAO dao;
	return dao.insert(data);
}

bool ArchiveService::updateData(const ArchiveDTO::Wrapper& dto)
{
	// 组装DO数据
	ArchiveDO data;
	data.setsortID(dto->sortid.getValue(1));
	data.setarchiveName(dto->archivename.getValue(""));
	data.setcabinetNum(dto->cabinetnum.getValue(1));
	data.setlayerNum(dto->layernum.getValue(1));
	data.setnumID(dto->numid.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data,dto, sortID, sortid,archiveName, archivename, cabinetNum, cabinetnum,
		layerNum, layernum, numID, numid);
		// 执行数据修改
		ArchiveDAO dao;
	return dao.update(data) == 1;
}

bool ArchiveService::removeData(uint64_t id)
{
	ArchiveDAO dao;
	return dao.deleteById(id) == 1;
}
