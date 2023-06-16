#include "stdafx.h"
#include "J_PaperController.h"
#include "../../service/J_paperinfo/J_PaperService.h"

//查看指定员工论文信息（指定论文信息详情）
J_PaperinfoJsonVO::Wrapper J_PaperController::execSelectByPimpaperid(const String& str)
{
	// 定义一个Service
	PaperService service;
	// 查询数据
	auto result = service.listAll(str);
	//创建响应对象
	auto vo = J_PaperinfoJsonVO::createShared();
	vo->success(result);
	return vo;
}

////修改指定员工论文信息（单条修改）
Uint64JsonVO::Wrapper J_PaperController::execModifyByPimpaperid(const ModifyPaperinfoDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->pimpaperid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	 //定义一个Service
	PaperService service;
	 //执行数据修改
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

