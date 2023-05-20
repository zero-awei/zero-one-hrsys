#include "stdafx.h"
#include "AddTagController.h"
#include <iostream>
Uint64JsonVO::Wrapper AddTagController::execAddProjTag(const ProjTagDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();

	// 校验dto数据
	// 参数校验
	// 非空校验
	if (!dto->sortid || !dto->orgname || !dto->projecttag)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->sortid < 0 || dto->orgname->empty() || dto->projecttag->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	//SampleService service;
	//// 执行数据新增
	//uint64_t id = service.saveData(dto);
	//// 获取payload字段
	//String payloadid =  payload.getId();
	//String payloadname = payload.getUsername();
	// 执行数据新增
	//uint64_t id = service.saveData(dto);
	// id应从数据库中找到的序号字段
	uint64_t id = dto->sortid;
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
	// id应从数据库中找到的序号字段
	uint64_t id = dto->sortid;
	//响应结果
	jvo->success(UInt64(id));
	return jvo;
}
