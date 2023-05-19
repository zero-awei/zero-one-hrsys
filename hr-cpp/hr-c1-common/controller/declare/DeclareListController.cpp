#include "stdafx.h"
#include "DeclareListController.h"
#include "../../service/declare/DeclareService.h"


DeclareListJsonVO::Wrapper DeclareListController::execQueryDeclare(const DeclareQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	DeclareService service;
	// 查询数据
	auto result = service.declareAll(query);
	// 响应结果
	auto jvo = DeclareListJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
