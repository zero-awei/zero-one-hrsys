#include "stdafx.h"
#include "J_PatentinfoController.h"
#include "../../service/J_patentinfo/J_PatentService.h"


J_PatentinfoJsonVO::Wrapper J_PatentinfoController::execQueryPatentinfo(const String& str)
{
	// 定义一个Service
	PatentService service;
	// 查询数据
	auto result = service.listAll(str);
	//创建响应对象
	auto vo = J_PatentinfoJsonVO::createShared();
	vo->success(result);
	return vo;
}



Uint64JsonVO::Wrapper J_PatentinfoController::execModifyPatentinfo(const ModifyPatentinfoDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->pimpatentid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	PatentService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success({});
	}
	else
	{
		jvo->fail({});
	}
	//jvo->success(dto->pimpatentid);
	return jvo;
}



