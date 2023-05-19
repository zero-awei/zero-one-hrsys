#include "stdafx.h"
#include "EducationController.h"

//EducationPageJsonVO::Wrapper EducationController::execEducation(const EducationQuery::Wrapper& query, const PayloadDTO& payload)
StringJsonVO::Wrapper EducationController::execQueryEducationPage(const EducationPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	auto vo = StringJsonVO::createShared();
	vo->success("execQueryEducationPage success");
	return vo;

}

StringJsonVO::Wrapper EducationController::execQueryEducationSingle(const EducationSingleQuery::Wrapper& query, const PayloadDTO& payload)
{
	auto vo = StringJsonVO::createShared();
	vo->success("execQueryEducationPage success");
	return vo;
}

StringJsonVO::Wrapper EducationController::execAddEducationSingle(const EducationDTO::Wrapper& dto)
{
	auto vo = StringJsonVO::createShared();
	vo->success("execaddEducationSingle success");
	return vo;
}

StringJsonVO::Wrapper EducationController::execModifyEducationSingle(const EducationDTO::Wrapper& dto)
{
	auto vo = StringJsonVO::createShared();
	vo->success("execaddEducationSingle success");
	return vo;
}

StringJsonVO::Wrapper EducationController::execRemoveEducation(const EducationDTO::Wrapper& dto)
{
	auto vo = StringJsonVO::createShared();
	vo->success("execRemoveEducation success");
	return vo;
}

StringJsonVO::Wrapper EducationController::execImportEducation(const EducationDTO::Wrapper& dto)
{
	auto vo = StringJsonVO::createShared();
	vo->success("execRemoveEducation success");
	return vo;
}

