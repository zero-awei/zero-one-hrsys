#include "stdafx.h"//cpp文件第一件事导入预编译标头
#include "TestController.h"
//#include "service/sample/ContractService.h"

//演示查询合同信息
StringJsonVO::Wrapper GoshController::execQueryContract(const ContractQuery::Wrapper& query)
{
	//响应结果
	auto vo = StringJsonVO::createShared();
	vo->success("contract infomation get success");
	return vo; 
}
//演示查询个人信息
StringJsonVO::Wrapper GoshController::execQueryPerson(const PersonQuery::Wrapper& query)
{
	auto vo = StringJsonVO::createShared();
	if (!query->PersonName)
	{
		return vo;
	}
	else 
	{
		vo->success("person information get success");
	}
	return vo;
}
//演示新增合同数据
Uint64JsonVO::Wrapper GoshController::execAddContract(const ContractDTO_gs::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	//if (!dto->age || !dto->name || !dto->sex)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// 有效值校验
	//if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	return jvo;

	//// 定义一个Service
	//SampleService service;
	//// 执行数据新增
	//uint64_t id = service.saveData(dto);
	//if (id > 0) {
	//	jvo->success(UInt64(id));
	//}
	//else
	//{
	//	jvo->fail(UInt64(id));
	//}
	////响应结果
	//return jvo;
}
//演示删除合同数据
Uint64JsonVO::Wrapper GoshController::execRemoveContract(const ContractDTO_gs::Wrapper& dto)
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


