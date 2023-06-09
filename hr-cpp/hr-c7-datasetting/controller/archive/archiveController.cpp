#include "stdafx.h"
#include "ArchiveController.h"
#include"../../service/archive/ArchiveService.h"

// 分页查询数据
ArchivePageJsonVO::Wrapper ArchiveController::execQueryArchive(const ArchiveQuery::Wrapper& query, const PayloadDTO& payload)
{
    // 定义一个Service
    ArchiveService service;
    // 查询数据
    auto result = service.listAll(query);
    // 响应结果
    auto jvo = ArchivePageJsonVO::createShared();
    jvo->success(result);
    return jvo;
}

// 新增数据
Uint64JsonVO::Wrapper ArchiveController::execAddArchive(const ArchiveDTO::Wrapper& dto)
{
   
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->sortid || !dto->archivename || !dto->cabinetnum||!dto->layernum||!dto->numid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//// 有效值校验
	if (dto->sortid<0 || dto->archivename->empty() || dto->cabinetnum<0 || dto->layernum<0 || dto->numid<0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	ArchiveService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	jvo->success(UInt64(id));
	
	return jvo;
}
// 修改数据
Uint64JsonVO::Wrapper ArchiveController::execModifyArchive(const ArchiveDTO::Wrapper& dto)
{
	// 定义返回数据对象
	
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->sortid || dto->sortid <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	ArchiveService service;
	service.updateData(dto);
	jvo->success(dto->sortid);
	return jvo;
}

// 删除数据
Uint64JsonVO::Wrapper ArchiveController::execRemoveArchive(const ArchiveDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->sortid || dto->sortid <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ArchiveService service;
	// 执行数据删除
	service.removeData(dto->sortid.getValue(0));
	jvo->success(dto->sortid);

	// 响应结果
	return jvo;
}