#include "stdafx.h"
#include "DeleteAssignInfoController.h"
Uint64JsonVO::Wrapper DeleteAssignInfoController::execDeleteAssignInfo(const DeleteAssignInfoDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//// 参数校验
	//if (!dto->id || dto->id <= 0)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// 定义一个Service
	//SampleService service;
	//// 执行数据删除
	//if (service.removeData(dto->id.getValue(0))) {
	//	jvo->success(dto->id);
	//}
	//else
	//{
	//	jvo->fail(dto->id);
	//}
	//// 响应结果
	return jvo;
}