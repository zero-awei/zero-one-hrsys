#include "stdafx.h"
#include "EducationController.h"

EducationPageJsonVO::Wrapper EducationController::execQueryEducationPage(const EducationPageQuery::Wrapper& query, const PayloadDTO& payload)
//StringJsonVO::Wrapper EducationController::execQueryEducationPage(const EducationPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	/*auto vo = StringJsonVO::createShared();
	vo->success("execQueryEducationPage success");
	return vo;*/
	return EducationPageJsonVO::Wrapper();

}

EducationSingleJsonVO::Wrapper EducationController::execQueryEducationSingle(const EducationSingleQuery::Wrapper& query, const PayloadDTO& payload)
{
	/*auto vo = StringJsonVO::createShared();
	vo->success("execQueryEducationPage success");
	return vo;*/
	return EducationSingleJsonVO::Wrapper();
}

StringJsonVO::Wrapper EducationController::execAddEducationSingle(const EducationSingleDTO::Wrapper& dto)
{
	auto vo = StringJsonVO::createShared();
	vo->success("execaddEducationSingle success");
	return vo;
}

StringJsonVO::Wrapper EducationController::execModifyEducationSingle(const EducationSingleDTO::Wrapper& dto)
{
	auto vo = StringJsonVO::createShared();
	vo->success("execaddEducationSingle success");
	return vo;
}

Uint64JsonVO::Wrapper EducationController::execRemoveEducation(const EducationDeleteSingleDTO::Wrapper& dto)
{
	/*auto vo = StringJsonVO::createShared();
	vo->success("execRemoveEducation success");
	return vo;*/
	return Uint64JsonVO::Wrapper();
}

Uint64JsonVO::Wrapper EducationController::execRemoveEducationNotSingle(const EducationDeleteNotSingleDTO::Wrapper& dto)
{
	return Uint64JsonVO::Wrapper();
}

#define RTN(__VO__, __MSG__) __VO__->setStatus(__MSG__); \
return __VO__;

EudacationImportJsonVO::Wrapper EducationController::execImportEducation(const EducationImportDTO::Wrapper& dto)
{
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
	auto vo = StringJsonVO::createShared();

	// TODO: 调用service获取导出文件下载链接

	vo->success("url/download");
	return vo;
}

