#include "stdafx.h"
#include "ModifyAssignInfoController.h"
Uint64JsonVO::Wrapper ModifyAssignInfoController::execModifyAssignInfo(const ModifyAssignInfoDTO::Wrapper& dto)
{
	//// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//// 参数校验
	//if (!dto->id || dto->id <= 0)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// 定义一个Service
	//SampleService service;
	//// 执行数据修改
	//if (service.updateData(dto)) {
	//	jvo->success(dto->id);
	//}
	//else
	//{
	//	jvo->fail(dto->id);
	//}
	//// 响应结果
	return jvo;
}