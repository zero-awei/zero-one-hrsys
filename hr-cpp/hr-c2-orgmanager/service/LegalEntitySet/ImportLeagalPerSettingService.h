#pragma once
/*
(法人主体设置-导入法人设置)--洛洛
*/
#ifndef _IMPORTLEAGALPERSETTING_SERVICE_
#define _IMPORTLEAGALPERSETTING_SERVICE_
#include <list>

#include "domain/dto/LegalEntitySet/ImportLeagalPerSettingDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ImportLeagalPerSettingService
{
public:
	// 保存数据
	uint64_t saveData(const ImportLeagalPerSettingDTO::Wrapper& dto);

};

#endif // !_IMPORTLEAGALPERSETTING_SERVICE_

