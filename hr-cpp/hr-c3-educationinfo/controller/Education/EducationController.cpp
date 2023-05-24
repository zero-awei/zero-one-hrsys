#include "stdafx.h"
#include "EducationController.h"

EducationPageJsonVO::Wrapper EducationController::execQueryEducationPage(const EducationPageQuery::Wrapper& query, const PayloadDTO& payload)
//StringJsonVO::Wrapper EducationController::execQueryEducationPage(const EducationPageQuery::Wrapper& query, const PayloadDTO& payload, const PayloadDTO& payload)
{

	auto vo = EducationPageJsonVO::createShared();
	return vo;


}

EducationSingleJsonVO::Wrapper EducationController::execQueryEducationSingle(const EducationSingleQuery::Wrapper& query, const PayloadDTO& payload)
//StringJsonVO::Wrapper EducationController::execQueryEducationSingle(const EducationSingleQuery::Wrapper& query, const PayloadDTO& payload, const PayloadDTO& payload)
{
	
	auto vo = EducationSingleJsonVO::createShared();
	return vo;
}

Uint64JsonVO::Wrapper EducationController::execAddEducationSingle(const EducationSingleDTO::Wrapper& dto, const PayloadDTO& payload)
//StringJsonVO::Wrapper EducationController::execAddEducationSingle(const EducationSingleDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto vo = Uint64JsonVO::createShared();
	
	// 参数校验
	if (!dto->PIMEDUCATIONID)
	{	
		vo->init(UInt64(-1), RS_PARAMS_INVALID);
		return vo;
	}

	

	return vo;
}

Uint64JsonVO::Wrapper EducationController::execModifyEducationSingle(const EducationSingleDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto vo = Uint64JsonVO::createShared();

	// 参数校验
	if (!dto->PIMEDUCATIONID)
	{
		vo->init(UInt64(-1), RS_PARAMS_INVALID);
		return vo;
	}

	return vo;
}

Uint64JsonVO::Wrapper EducationController::execRemoveEducation(const EducationDeleteSingleDTO::Wrapper& dto, const PayloadDTO& payload)
//StringJsonVO::Wrapper EducationController::execRemoveEducation(const EducationDeleteSingleDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto vo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->deleteId) {
		vo->init(UInt64(-1), RS_PARAMS_INVALID);
		return vo;
	}
	return vo;
	//return Uint64JsonVO::Wrapper();
}

Uint64JsonVO::Wrapper EducationController::execRemoveEducationNotSingle(const EducationDeleteNotSingleDTO::Wrapper& dto, const PayloadDTO& payload)
//StringJsonVO::Wrapper EducationController::execRemoveEducationNotSingle(const EducationDeleteNotSingleDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto vo = Uint64JsonVO::createShared();
	if (!dto->deleteIds) {
		vo->init(UInt64(-1), RS_PARAMS_INVALID);
		return vo;
	}
	return vo;
	
}

#define RTN(__VO__, __MSG__) __VO__->setStatus(__MSG__); \
return __VO__;

EudacationImportJsonVO::Wrapper EducationController::execImportEducation(const EducationImportDTO::Wrapper& dto, const PayloadDTO& payload)
//StringJsonVO::Wrapper EducationController::execImportEducation(const EducationImportDTO::Wrapper& dto)
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

StringJsonVO::Wrapper EducationController::execExportEducation(const EducationExportQuery::Wrapper& query, const PayloadDTO& payload)
{
	auto vo = StringJsonVO::createShared();

	// TODO: 调用service获取导出文件下载链接

	vo->success("url/download");
	return vo;
}

