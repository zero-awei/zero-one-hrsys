#include "stdafx.h"
#include "ImportLanguageController.h"
#include "ExcelComponent.h"

/**
 * 实现语言文件上传模块
 * 负责人：君
 */
StringJsonVO::Wrapper ImportLanguageController::execImportLanguage(const ImportLanguageDTO::Wrapper& dto/*, const PayloadDTO & payload*/)
{
	auto jvo = StringJsonVO::createShared();
	jvo->success("import language competence success");
	return jvo;
}
