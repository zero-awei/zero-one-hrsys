#include "stdafx.h"
#include "NotEmployeeInArchiveController.h"

NotEmployeeInArchivePageJsonVO::Wrapper NotEmployeeInArchiveController::execQueryNotEmployeeInArchive(const NotEmployeeInArchiveQuery::Wrapper& query, const PayloadDTO& payload){
	// 创建响应对象
	auto vo = NotEmployeeInArchivePageJsonVO::createShared();
	// 创建分页对象
	auto adto = NotEmployeeInArchivePageDTO::createShared();
	adto->addData(NotEmployeeInArchiveDTO::createShared());
	adto->addData(NotEmployeeInArchiveDTO::createShared());
	// 响应结果
	vo->success(adto);
	return vo;
}

Uint64JsonVO::Wrapper NotEmployeeInArchiveController::execModifyNotEmployeeInArchive(const NotEmployeeInArchiveDTO::Wrapper& dto){
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}