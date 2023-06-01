#include "stdafx.h"
#include "LegalEntitySetController.h"
#include "service/LegalEntitySet/LegalEntitySetService.h"
/*
组织管理 ——数据设置 —— 法人主体设置  -- cpt

法人主体名称下拉列表 `LegalEntitySetPullDownList`

更新指定法人设置信息  `UpdateLegalerSettingMessage`

导出法人设置 `LegalEntitySet`

新增法人设置（支持批量新增）** `LegalEntitySet`
*/ 
Uint64JsonVO::Wrapper LegalEntitySetController::execAddLegalEntitySet(const LegalEntitySetDTO::Wrapper& dto) {
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	//if (!dto->ormsignorgid || !dto->ormsignorgname || !dto->contractsignorgname) {
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// 有效值校验
	//if (!dto->ormsignorgid || !dto->ormsignorgname || !dto->contractsignorgname )
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	// 定义一个Service
	LegalEntitySetService service;
	// 执行数据新增
	uint64_t id = service.insertData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else {
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}

LegalEntitySetPageJsonVO::Wrapper LegalEntitySetController::execExportLegalEntitySet(const LegalEntitySetQuery::Wrapper& query, const PayloadDTO& payload) {
	return LegalEntitySetPageJsonVO::Wrapper();
}

LegalEntitySetPageJsonVO::Wrapper LegalEntitySetController::execLegalEntitySetPullDownList(const LegalEntitySetQuery::Wrapper& query, const PayloadDTO& payload) {
	//LegalEntitySetService service;
	//// 查询数据
	//auto result = service.legalerNamePullDownList(query);
	//// 响应结果
	//auto jvo = LegalEntitySetPageJsonVO::createShared();
	//jvo->success(result);
	//return jvo;
	return LegalEntitySetPageJsonVO::Wrapper();
}

Uint64JsonVO::Wrapper LegalEntitySetController::execModifyLegalEntitySet(const LegalEntitySetDTO::Wrapper& dto) {
	//// 定义返回数据对象
	//auto jvo = Uint64JsonVO::createShared();
	//// 参数校验
	//if (!dto->id )
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// 定义一个Service
	//LegalEntitySetService service;
	//// 执行数据修改
	//if (service.updateData(dto)) {
	//	jvo->success(dto->id);
	//}
	//else
	//{
	//	jvo->fail(dto->id);
	//}
	//// 响应结果
	//return jvo;
	return Uint64JsonVO::createShared();
}

/*---------------------------------- 法人主体设置控制器具体实现--（组织管理-数据设置-法人主体设置）--TripleGold -------------------------------*/

LegalEntitySetPageJsonVO::Wrapper LegalEntitySetController::execQueryLES(const LegalEntitySetQuery::Wrapper& query)
{
	// 定义一个Service
	LegalEntitySetService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = LegalEntitySetPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
