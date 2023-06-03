#include "stdafx.h"
#include "RraineeController.h"
#include "service/RosterOfPer/RraineeService.h"
 
RraineePageJsonVO::Wrapper RraineeController::execRraineeQuery(const RraineeQuery::Wrapper& query, const PayloadDTO& payload){
	RraineeService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = RraineePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

RraineePageJsonVO::Wrapper RraineeController::execRraineeExport(const RraineeQuery::Wrapper& query, const PayloadDTO& payload) {
	return RraineePageJsonVO::Wrapper();
}

