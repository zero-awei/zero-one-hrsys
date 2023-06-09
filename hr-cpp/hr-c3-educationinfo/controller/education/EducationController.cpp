#include "stdafx.h"
#include "EducationController.h"
#include "service/education/EducationService.h"

EducationPageJsonVO::Wrapper EducationController::execQueryEducationPage(const EducationPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	
	EducationService service;
	auto dto = service.listEducationPage(query);
	auto vo = EducationPageJsonVO::createShared();
	vo->success(dto);
	return vo;
}

EducationSingleJsonVO::Wrapper EducationController::execQueryEducationSingle(const EducationSingleQuery::Wrapper& query, const PayloadDTO& payload)
{
	auto vo = EducationSingleJsonVO::createShared();
	EducationService service;
	auto dto = service.listEducationSingle(query);
	vo->success(dto);
	return vo;
}

Uint64JsonVO::Wrapper EducationController::execAddEducationSingle(const EducationAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto vo = Uint64JsonVO::createShared();
	
	// 参数校验



	// 定义一个service
	EducationService service;

	// 执行数据新增 
	int id = service.saveEducation(dto);
	//响应结果
	if (id > 0) {
		vo->success(id);
	}
	else {
		vo->fail(id);
	}
	

	

	return vo;
}

Uint64JsonVO::Wrapper EducationController::execModifyEducationSingle(const EducationAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto vo = Uint64JsonVO::createShared();

	// 参数校验

	// 定义一个Service
	EducationService service;
	// 执行数据修改
	bool id = service.updateEducation(dto);
	if (id) {
		vo->success(id);
	}else{
		vo->fail(id);
	}
	
	return vo;
}

Uint64JsonVO::Wrapper EducationController::execRemoveEducation(const EducationDeleteSingleDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto vo = Uint64JsonVO::createShared();
	// 参数校验
	


	// 定义一个Service
	EducationService Service;
	
	// 执行数据删除
	int id = Service.removeEducation(dto);
	if (id > 0) {
		vo->success(id);
	}
	else
	{
		vo->fail(id);
	}
	//Service.removeEducation(dto->deleteId);
	//vo->success(dto->deleteId);
	return vo;


}

//EducationDeleteNotSingleJsonVO::Wrapper EducationController::execRemoveEducationNotSingle(const EducationDeleteNotSingleDTO::Wrapper& dto, const PayloadDTO& payload)
//{
//	
//
//	// 定义返回数据对象
//	auto jvo = EducationDeleteNotSingleJsonVO::createShared();
//	// 参数校验
//	if (!dto->deleteIds)
//	{
//		jvo->init(dto, RS_PARAMS_INVALID);
//		return jvo;
//	}
//	EducationService Service;
//
//	// 执行数据删除
//	/*if (Service.removeEducationNotSingle(dto)) {
//		jvo->success(dto);
//	}
//	else
//	{
//		jvo->fail(dto);
//	}*/
//	Service.removeEducationNotSingle(dto);
//	jvo->success(dto);
//	return jvo;
//	
//}

#define RTN(__VO__, __MSG__) __VO__->setStatus(__MSG__); \
return __VO__;

EudacationImportJsonVO::Wrapper EducationController::execImportEducation(const EducationImportDTO::Wrapper& dto, const PayloadDTO& payload)
{

	/*auto vo = StringJsonVO::createShared();
	vo->success("execImportEducation success");
	return vo;*/


	auto vo = EudacationImportJsonVO::createShared();
	// 参数校验
	if (dto->filePath->empty()) { RTN(vo, RS_PARAMS_INVALID) }

	String str1 = "123abc";
	String str2 = "456def";
	String str3 = "789ghi";
	auto ij = EudacationImportVO::createShared();
	ij->newId->push_back("123abc");
	ij->newId->push_back("456def");
	ij->newId->push_back("789ghi");

	// TODO: 调用service
	vo->init(ij, RS_SUCCESS);
	return vo;
}

StringJsonVO::Wrapper EducationController::execExportEducation(const EducationExportQuery::Wrapper& query)
{
	auto jvo = StringJsonVO::createShared();
	// 定义一个Service
	// EducationService service;
	// //// 查询数据
	// auto result = service.exportData(query);
	// if (!result.empty()) {
	// 	jvo->success(result);
	// } else {
	// 	jvo->fail("export fail");
	// }
	return jvo;
}

