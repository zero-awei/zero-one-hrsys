#include "stdafx.h"
#include "ImportTagController.h"
#include "ExcelComponent.h"

#define RTN(__VO__, __MSG__) __VO__->setStatus(__MSG__); \
return __VO__;

ImportProjTagJsonVO::Wrapper ImportTagController::execImportTag(const ImportTagDTO::Wrapper& dto/*, const PayloadDTO& payload*/)
{
	auto vo = ImportProjTagJsonVO::createShared();
	
	if (dto->filePath->empty()) { RTN(vo, RS_PARAMS_INVALID) }

	String str1 = "123abc";
	String str2 = "456def";
	String str3 = "789ghi";
	auto it = ImportTagVO::createShared();
	it->newId->push_back("123abc");
	it->newId->push_back("456def");
	it->newId->push_back("789ghi");

	vo->init(it, RS_SUCCESS);
	return vo;
}
