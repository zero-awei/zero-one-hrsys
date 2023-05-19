#include "stdafx.h"
#include "AddTagController.h"

Uint64JsonVO::Wrapper AddTagController::execAddProjTag(const ProjTagDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	// 校验dto数据
	

	
	// 执行数据新增
	//uint64_t id = service.saveData(dto);
	// id应从数据库中找到的序号字段
	uint64_t id = 1;
	//响应结果
	jvo->success(UInt64(id));
	return jvo;
}
