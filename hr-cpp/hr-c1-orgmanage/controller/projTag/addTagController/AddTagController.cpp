#include "stdafx.h"
#include "AddTagController.h"
#include <iostream>
#include "service/projTag/ProjTagService.h"
#include "SimpleDateTimeFormat.h"
Uint64JsonVO::Wrapper AddTagController::execAddProjTag(const ProjTagDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();

	// 校验dto数据
	// 参数校验
	// 检验项目标签标识是否为空
	if (!dto->ormorgid || !dto->ormorgid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	
	// 有效值校验
	

	// 获取payload字段
	dto->createman = payload.getUsername();
	dto->updateman = payload.getUsername();
	dto->createdate = SimpleDateTimeFormat::format();
	dto->updatedate = dto->createdate;
	
	// 定义一个service
	ProjTagService service;

	// 执行数据新增 
	uint64_t id = service.saveData(dto);

	//响应结果
	jvo->success(UInt64(id));

	return jvo;
}

Uint64JsonVO::Wrapper AddTagController::execAddProjTag(const ProjTagDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	// 校验dto数据


	// 执行数据新增
	//uint64_t id = service.saveData(dto);

	//响应结果
	jvo->success(UInt64(155149));

	return jvo;
}
