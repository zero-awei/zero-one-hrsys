#include "stdafx.h"
#include "EmployeeInformationController.h"
#include "service/EmployeeInformation/EmployeeInformationServicer.h"

//分页查询员工列表
EmployeeInformationPageJsonVO::Wrapper EmployeeInformationController::execEmployeeInformation(const EmployeeInformationPageQuery::Wrapper& query)
{
	// 定义一个Service
	EmployeeInformationServicer service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = EmployeeInformationPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}
//导入员工信息
Uint64JsonVO::Wrapper EmployeeInformationController::execImportEmployeeInfo(const EmployeeInformationDTO::Wrapper& importInfo)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!importInfo->id || !importInfo->name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (importInfo->id->empty() || importInfo->name->empty() || importInfo->age < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	EmployeeInformationServicer service;
	// 执行数据新增
	uint64_t id = service.saveData(importInfo);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;

}
//导出员工信息(导出本页在前端完成)
EmployeeInformationPageJsonVO::Wrapper EmployeeInformationController::execExportEmployeeInfo(const EmployeeInformationPageQuery::Wrapper& exportInfo)
{
	// 定义一个JsonVO对象
	auto vo = EmployeeInformationPageJsonVO::createShared();
	// 定义一个分页对象
	auto page = EmployeeInformationPageDTO::createShared();
	page->pageIndex = exportInfo->pageIndex;
	page->pageSize = exportInfo->pageSize;
	page->total = 20;
	page->calcPages();

	// 模拟计算分页数据
	int64_t start = (page->pageIndex.getValue(1) - 1) * page->pageSize.getValue(1);
	int64_t end = start + page->pageSize.getValue(1);
	// 边界值值处理
	if (start >= page->total.getValue(0) || start < 0) {
		vo->fail(page);
		return vo;
	}
	if (end > page->total.getValue(0)) end = page->total.getValue(0);
	// 循环生成测试数据
	for (int64_t i = start; i < end; i++)
	{
		auto user = EmployeeInformationDTO::createShared();
		user->name = exportInfo->name;
		user->age = exportInfo->age;
		user->id = exportInfo->id;
		user->organize = exportInfo->organize;
		user->depart = exportInfo->depart;
		user->job = exportInfo->job;
		user->post = exportInfo->post;
		user->idMum = exportInfo->idMum;
		user->birthday = exportInfo->birthday;
		user->phone = exportInfo->phone;
		user->state = exportInfo->state;
		page->addData(user);
	}
	vo->success(page);
	return vo;

}
//新增员工信息 
Uint64JsonVO::Wrapper EmployeeInformationController::execAddEmployee(const EmployeeInformationDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->id || !dto->name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->id->empty() || dto->name->empty()|| dto->age < 0 )
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	EmployeeInformationServicer service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}