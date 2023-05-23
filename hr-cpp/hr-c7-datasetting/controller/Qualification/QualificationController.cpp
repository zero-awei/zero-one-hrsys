#include "stdafx.h"
#include "QualificationController.h"

// 分页查询数据
QualificationPageJsonVO::Wrapper QualificationController::execQueryQualification(const QualificationQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 创建响应对象
	auto vo = QualificationPageJsonVO::createShared();
	// 创建分页对象
	auto pdto = QualificationPageDTO::createShared();
	// 响应结果
	vo->success(pdto);
	return vo;
}

// 新增数据
Uint64JsonVO::Wrapper QualificationController::execAddQualification(const QualificationDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	// 响应结果
	jvo->success(1);
	return jvo;
}

// 修改数据
Uint64JsonVO::Wrapper QualificationController::execModifyQualification(const QualificationDTO::Wrapper& dto)
{
	// 创建响应对象
	auto vo = Uint64JsonVO::createShared();


	// 响应结果
	vo->success(1);
	return vo;
}

// 删除数据
Uint64JsonVO::Wrapper QualificationController::execRemoveQualification(const QualificationDTO::Wrapper& dto)
{
	// 创建响应对象
	auto vo = Uint64JsonVO::createShared();

	// 响应结果
	vo->success(1);
	return vo;
}