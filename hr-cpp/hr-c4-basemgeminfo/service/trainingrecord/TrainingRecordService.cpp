#include "stdafx.h"
#include "TrainingRecordService.h"
#include"../../dao/trainingrecord/TrainingRecordDAO.h"
#include "../../domain/do/trainingrecord/TrainingRecordDO.h"

TrainingRecordPageDTO::Wrapper TrainingRecordService::listAll(const TrainingRecordPageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = TrainingRecordPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// 查询数据总条数,传递到dao层
	TrainingRecordDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<TrainingRecordDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (TrainingRecordDO sub : result)
	{
		auto dto = TrainingRecordDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, TRMTRIANPERSONID, _TRMTRIANPERSONID, PXBJ, _PXBJ, TRAINBEGIN, _TRAINBEGIN, TRAINEND, _TRAINEND, PXKC, _PXKC, TRMTRAINAGENCYNAME, _TRMTRAINAGENCYNAME, TRAINRES, _TRAINRES, FS, _FS);
		pages->addData(dto);
	}
	return pages;
}