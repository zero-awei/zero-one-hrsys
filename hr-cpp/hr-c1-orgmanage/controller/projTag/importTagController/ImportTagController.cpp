#include "stdafx.h"
#include "ImportTagController.h"
#include "ExcelComponent.h"
#include "service/projTag/ProjTagService.h"
#define RTN(__VO__, __MSG__) __VO__->setStatus(__MSG__); \
return __VO__;

ImportProjTagJsonVO::Wrapper ImportTagController::execImportTag(const ImportTagDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto vo = ImportProjTagJsonVO::createShared();
	
	if (dto->filePath->empty()) {
		vo->init({}, RS_PARAMS_INVALID);
		return vo;
	}


	// TODO: µ÷ÓÃservice
	std::list<std::string> result;
	ProjTagService service;
	auto res = service.addMultiTag(dto, payload);

	if (res->newId->size()) vo->init(res, RS_SUCCESS);
	else vo->init(res, RS_FAIL);
	return vo;
}
