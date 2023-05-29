#include "stdafx.h"
#include "LegalEntityMaiController.h"
#include "service/LegalEntityMai/LegalEntityMaiService.h"

/* 法人主体维护控制器具体实现--（组织管理-数据设置-法人主体维护）--TripleGold */

LegalEntityMaiPageJsonVO::Wrapper LegalEntityMaiController::execQueryLEM(const LegalEntityMaiQuery::Wrapper& query)
{
	// 定义一个Service
	LegalEntityMaiService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = LegalEntityMaiPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper LegalEntityMaiController::execUpdateLEM(const LegalEntityMaiDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->ORMSIGNORGID || dto->ORMSIGNORGID == "") {
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	LegalEntityMaiService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->ORMSIGNORGID);
	}
	else {
		jvo->fail(dto->ORMSIGNORGID);
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper LegalEntityMaiController::execAddLEM(const LegalEntityMaiDTO::Wrapper& dto)
{
	/*oatpp::List<Uint64JsonVO::Wrapper> jvoList;
	int size = dtoList->size();
	for (auto it = dtoList->begin(); it != dtoList->end(); it++) {*/
		// 定义返回数据对象
		auto jvo = Uint64JsonVO::createShared();
		/*auto dto = *it;*/
		/* 参数校验 */
		// 非空检验
		if (!dto->ORMSIGNORGNAME || !dto->ORGCODE) {
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		// 有效值检验
		if (dto->ORMSIGNORGNAME->empty() || dto->ORGCODE->empty()) {
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}

		// 定义一个Service
		LegalEntityMaiService service;
		// 执行数据新增
		uint64_t id = service.saveData(dto);
		if (id > 0) {
			jvo->success(UInt64(id));
		}
		else {
			jvo->fail(UInt64(id));
		}
		//jvoList.push_back(jvo);
	//}
	// 响应结果
		return jvo;
}

StringJsonVO::Wrapper LegalEntityMaiController::execRemoveLEM(const LegalEntityMaiDTO::Wrapper& dto)
{
	/*std::list<StringJsonVO::Wrapper> jvoList;
	for (auto dto : dtoList) {*/
		// 定义返回数据对象
		auto jvo = StringJsonVO::createShared();
		// 参数校验
		if (!dto->ORMSIGNORGID || dto->ORMSIGNORGID == "") {
			jvo->init(String(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		// 定义一个Service
		LegalEntityMaiService service;
		// 执行数据删除
		if (service.removeData(dto->ORMSIGNORGID.getValue(""))) {
			jvo->success(dto->ORMSIGNORGID);
		}
		else {
			jvo->fail(dto->ORMSIGNORGID);
		}
	//}
	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper LegalEntityMaiController::execImportLEM(const LegalEntityMaiDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper LegalEntityMaiController::execExportLEM(const LegalEntityMaiQuery::Wrapper& query)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 定义一个Service
	LegalEntityMaiService service;
	// 执行文件导出
	std::string fileName = service.exportFile(query);
	if (fileName.empty()) {
		jvo->fail("fail to export");
	}
	else {
		jvo->success(fileName);
	}
	// 响应结果
	return jvo;
}

