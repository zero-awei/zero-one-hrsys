#include "stdafx.h"
#include "ArchivesController.h"

ArchivesJsonVO::Wrapper ArchivesController::execQuerySpecifiedArchivesInfo(const ArchivesQuery::Wrapper& dto, const PayloadDTO& payload)
{
	// Service
	// 响应结果
	auto jvo = ArchivesJsonVO::createShared();
	return jvo;
}

Uint64JsonVO::Wrapper ArchivesController::execAddArchivesInfo(const ArchivesDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 有效值校验
	if (dto->archivesNo->empty() || dto->managementUnits->empty() || dto->YGBH->empty() || 
		dto->DABGD->empty() || dto->archivesCenterName->empty() || dto->YGBH->empty()   || 
		dto->PimPersonName->empty() || dto->ygzt->empty() || dto->ORMORGName->empty()   || dto->DAZT->empty() )
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// Service
	return jvo;
}

Uint64JsonVO::Wrapper ArchivesController::execRemoveArchivesInfo(const ArchivesDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->archivesNo)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// Service
	return jvo;
}

ArchivesPageJsonVO::Wrapper ArchivesController::execQueryArchivesinfo(const ArchivesQuery::Wrapper& query)
{
	// 创建响应对象
	auto vo = ArchivesPageJsonVO::createShared();
	// 创建分页对象
	auto pdto = ArchivesPageDTO::createShared();
	pdto->addData(ArchivesDTO::createShared());
	pdto->addData(ArchivesDTO::createShared());
	// 响应结果
	vo->success(pdto);
	return vo;
}