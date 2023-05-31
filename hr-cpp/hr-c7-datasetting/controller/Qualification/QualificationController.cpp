#include "stdafx.h"
#include "QualificationController.h"
#include"../../service/Qualification/QualificationService.h"

// 分页查询数据
QualificationPageJsonVO::Wrapper QualificationController::execQueryQualification(const QualificationQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	QualificationService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = QualificationPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// 新增数据
Uint64JsonVO::Wrapper QualificationController::execAddQualification(const QualificationDTO::Wrapper& dto)
{

	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->pimqualmajorid || !dto->qualevel || !dto->pimqualmajorname || !dto->quamajor)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//// 有效值校验
	if (dto->pimqualmajorid->empty() || dto->qualevel->empty() || dto->pimqualmajorname->empty() || dto->quamajor->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	QualificationService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	jvo->success(UInt64(id));

	return jvo;
}

// 修改数据
Uint64JsonVO::Wrapper QualificationController::execModifyQualification(const QualificationDTO::Wrapper& dto)
{
	// 定义返回数据对象

	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->pimqualmajorid || !dto->qualevel || !dto->pimqualmajorname || !dto->quamajor)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	QualificationService service;
	service.updateData(dto);
	jvo->success(dto->pimqualmajorid || dto->qualevel || dto->pimqualmajorname || dto->quamajor);
	return jvo;
}

 //删除数据
Uint64JsonVO::Wrapper QualificationController::execRemoveQualification(const QualificationDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	// 响应结果
	return jvo;
}

//Uint64JsonVO::Wrapper QualificationController::execRemoveQualification(const QualificationDTO::Wrapper& dto)
//{
//	// 定义返回数据对象
//	auto jvo = Uint64JsonVO::createShared();
//	// 参数校验
//	if (!dto->pimqualmajorid || !dto->qualevel || !dto->pimqualmajorname || !dto->quamajor)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// 定义一个Service
//	QualificationService service;
//	// 执行数据删除
//	service.removeData(dto->pimqualmajorid.getValue(""));
//	jvo->success(dto->pimqualmajorid);
//
//	// 响应结果
//	return jvo;
//}




























//#include "stdafx.h"
//#include "QualificationController.h"
//
//QualificationPageJsonVO::Wrapper QualificationController::executeQueryAll_ld(const QualificationQuery::Wrapper& query)
//{
//	//定义一个Service
//	QualificationService service;
//	//查询数据
//	auto result = service.listAll_ld(query);
//	//响应结果
//	auto jvo = QualificationPageJsonVO::createShared();
//	jvo->success(result);
//	return jvo;
//}
//
//Uint64JsonVO::Wrapper QualificationConstroller::execAddQualification_ld(const QualificationDTO::Wrapper& dto)
//{
//	auto vo = Uint64JsonVO::createShared();
//	//参数校验
//	//1.非空校验
//	if (!dto->name || !dto->id || !dto->pimpersonid || !dto->ormorgid) {
//		vo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return vo;
//	}
//	//2.有效值校验
//	if (dto->name->empty() || dto->id->empty() || dto->pimpersonid->empty() || dto->ormorgid->empty()) {
//		vo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return vo;
//	}
//	//定一个Service
//	QualificationService service;
//	//执行数据新增
//	uint64_t id = service.saveData_ld(dto);
//	if (id > 0) {
//		vo->success(UInt64(id));
//	}
//	else {
//		vo->fail(UInt64(id));
//	}
//	return vo;
//}
//
//StringJsonVO::Wrapper QualificationConstroller::execRemoveQualification_ld(const QualificationRemoveDTO::Wrapper& dto)
//{
//	// 定义返回数据对象
//	auto vo = StringJsonVO::createShared();
//	// 参数校验
//	if (!dto->id || dto->id->empty())
//	{
//		vo->fail("parameter is empty");
//		return vo;
//	}
//	// 定义一个Service
//	QualificationService service;
//	// 执行数据删除
//	auto it = dto->id->begin();
//	while (it != dto->id->end()) {
//		if (service.removeData_ld(it->getValue(""))) {
//			vo->success("delete success");
//		}
//		else
//		{
//			vo->fail("delete fail");
//		}
//		it++;
//	}
//	return vo;
//}