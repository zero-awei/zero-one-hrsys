#include "stdafx.h"
#include "CheckRetiresListController.h"
#include "../../service/RosterOfPer/CheckRetiresListService.h"
/**
 * 人员花名册-（离退休员工-分页查询员工列表）--pine
 */
CheckRetiresListPageJsonVO::Wrapper CheckRetiresListController::execQueryCheckRetiresList(const CheckRetiresListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	CheckRetiresListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = CheckRetiresListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
