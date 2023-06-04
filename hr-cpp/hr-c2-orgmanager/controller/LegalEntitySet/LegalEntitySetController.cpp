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

Uint64JsonVO::Wrapper LegalEntitySetController::execAddLegalEntitySet(const List<LegalEntitySetAddDTO::Wrapper> & dto, const PayloadDTO& payload) {
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//非空校验
	if (dto->size() == 0) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	}
	LegalEntitySetService service;
	//service.insertData(*dto->begin(), payload);
	for (auto it = dto->begin(); it != dto->end(); it++) {
		if (!service.insertData(*it, payload)) {
			jvo->fail(1);
			return jvo;
		}
	}
	jvo->success(1);
	// 响应结果
	return jvo;
}

LegalEntitySetPageJsonVO::Wrapper LegalEntitySetController::execExportLegalEntitySet(const LegalEntitySetQuery::Wrapper& query, const PayloadDTO& payload) {
	return LegalEntitySetPageJsonVO::Wrapper();
}


// 法人主体名称下拉列表查询
LegalEntitySetPullDownJsonVO::Wrapper LegalEntitySetController::execLegalEntitySetPullDownList() {
	auto vo = LegalEntitySetPullDownJsonVO::createShared();
	LegalEntitySetService service;
	auto dto = service.legalEntityPulldownList();
	vo->success(dto);
	return vo;
}

StringJsonVO::Wrapper LegalEntitySetController::execModifyLegalEntitySet(const LegalEntitySetUpdateDTO::Wrapper& dto) {
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->ormsignorgid || dto->ormsignorgid == "") {
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	LegalEntitySetService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->ormsignorgid);
	}
	else {
		jvo->fail(dto->ormsignorgid);
	}
	// 响应结果
	return jvo;
}

/*---------------------------------- 法人主体设置控制器具体实现--（组织管理-数据设置-法人主体设置）--TripleGold -------------------------------*/

LegalEntitySetQueryPageJsonVO::Wrapper LegalEntitySetController::execQueryLES(const LegalEntitySetQuery::Wrapper& query)
{
	// 定义一个Service
	LegalEntitySetService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = LegalEntitySetQueryPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
