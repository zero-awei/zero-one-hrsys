#include "stdafx.h"
#include "ImportAssignInfoController.h"
ImportAssignInfoJsonVO::Wrapper ImportAssignInfoController::execImportAssignInfo(const ImportAssignInfoDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = ImportAssignInfoJsonVO::createShared();
	return jvo;
}