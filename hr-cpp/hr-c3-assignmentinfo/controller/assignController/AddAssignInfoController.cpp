#include "stdafx.h"
#include "AddAssignInfoController.h"
//#include "../../service/assignInfo/AddAssignInfoService.h"


AddAssignInfoJsonVO::Wrapper AddAssignInfoController::execAddAssignInfo(const AddAssignInfoDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = AddAssignInfoJsonVO::createShared();
	// 参数校验
	// 非空校验
	//if (!dto->id || !dto->assign || !dto->organize || !dto->depart || !dto->job || !dto->post || !dto->start_time || !dto->end_time)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// 有效值校验
	//if (dto->id->empty())
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}

	//// 定义一个Service
	//AddAssignInfoService service;
	//// 执行数据新增
	//uint64_t id = service.saveData(dto);
	//if (id > 0) {
	//	jvo->success(UInt64(id));
	//}
	//else
	//{
	//	jvo->fail(UInt64(id));
	//}
	//响应结果
	return jvo;
}

