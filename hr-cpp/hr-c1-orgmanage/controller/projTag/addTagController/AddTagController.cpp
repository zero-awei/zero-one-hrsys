#include "stdafx.h"
#include "AddTagController.h"
#include <iostream>
#include "service/projTag/ProjTagService.h"
#include "SimpleDateTimeFormat.h"
StringJsonVO::Wrapper AddTagController::execAddProjTag(const ProjTagDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();

	// 校验dto数据
	// 参数校验
	// 检验组织标识是否为空
	if (!dto->ormorgid)
	{
		jvo->init("-1", RS_PARAMS_INVALID);
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
	// 执行成功后返回项目标签id值
	String id = service.saveData(dto);

	//响应结果
	if (id != "-1")
	{
		jvo->init(id, RS_SUCCESS);
	}
	else
	{
		jvo->init(id, RS_FAIL);
	}
	return jvo;
}
