#include "stdafx.h"
#include "ExportLanguage.h"

/**
 * 语言能力文件导出实现
 * 负责人：君
 */
StringJsonVO::Wrapper execDownloadLanguage(const EmployeeLanguageExportQuery::Wrapper& query)
{
	auto jvo = StringJsonVO::createShared();
	// 定义一个Service
	// AssignInfoService service;
	// //// 查询数据
	// auto result = service.exportData(query);
	// if (!result.empty()) {
	// 	jvo->success(result);
	// } else {
	// 	jvo->fail("export fail");
	// }
	return jvo;
}
