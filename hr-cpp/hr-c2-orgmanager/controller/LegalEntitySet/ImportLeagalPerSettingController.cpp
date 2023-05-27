/*
(法人主体设置-导入法人设置)--洛洛
*/
#include "stdafx.h"
#include "ImportLeagalPerSettingController.h"
#include "../../service/LegalEntitySet/ImportLeagalPerSettingService.h"

Uint64JsonVO::Wrapper ImportLeagalPerSettingController::execAddLeagalPerSetting(const ImportLeagalPerSettingDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//// 参数校验
	//// 非空校验
	//if (!dto->age || !dto->name || !dto->sex)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// 有效值校验
	//if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}

	//// 定义一个Service
	//ImportLeagalPerSettingService service;
	//// 执行数据新增
	//uint64_t id = service.saveData(dto);
	//if (id > 0) {
	//	jvo->success(UInt64(id));
	//}
	//else
	//{
	//	jvo->fail(UInt64(id));
	//}
	////响应结果
	return jvo;
}
