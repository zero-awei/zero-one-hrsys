#include "stdafx.h"
#include "ExportLanguage.h"

/**
 * 语言能力文件导出实现
 * 负责人：君
 */
StringJsonVO::Wrapper ExportLanguageController::execDownloadLanguage()
{
	auto jvo = StringJsonVO::createShared();
	jvo->success("download language competence success");
	return jvo;
}
