#include "stdafx.h"
#include "TitleController.h"
#include "../../service/Title/TitleService.h"
// 分页查询数据
TitlePageJsonVO::Wrapper TitleController::execQueryTitle(const TitleQuery::Wrapper& query, const PayloadDTO& payload)
{
    
     // 定义一个Service
    TitleService service;
    // 分页查询数据
    auto result = service.listAll(query);
    // 创建响应对象
    auto jvo = TitlePageJsonVO::createShared();
    // 响应结果
   jvo->success(result);
    return jvo;
}

// 新增数据
Uint64JsonVO::Wrapper TitleController::execAddTitle(const TitleDTO::Wrapper& dto)
{
    // 定义返回数据对象
    auto jvo = Uint64JsonVO::createShared();
    // 非空校验
	if (!dto->id || !dto->name || !dto->num )
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
    // 有效值校验
	if (dto->id < 0 || dto->name->empty() || dto->num->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	TitleService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
    // 响应结果
	
		jvo->success(UInt64(id));

    return jvo;
}

// 修改数据
Uint64JsonVO::Wrapper TitleController::execModifyTitle(const TitleDTO::Wrapper& dto)
{
    // 创建响应对象
    auto jvo = Uint64JsonVO::createShared();
	if (!dto->id || dto->id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	TitleService service;
	// 执行数据修改
	service.updateData(dto);
		jvo->success(dto->id.getValue({}));

	
    // 响应结果
    
    return jvo;
}

// 删除数据
Uint64JsonVO::Wrapper TitleController::execRemoveTitle(const TitleDTO_delete::Wrapper& dto)
{
    // 创建响应对象
    auto jvo = Uint64JsonVO::createShared();
	if (!dto->id || dto->id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	TitleService service;
	// 执行数据删除
	service.removeData(dto->id.getValue({}));
		jvo->success(dto->id.getValue({}));
	
	
    // 响应结果
   
    return jvo;
}