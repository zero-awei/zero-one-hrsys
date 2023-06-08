#include "stdafx.h"
#include "CheckCerListController.h"
#include "../../service/CertificateManage/CheckCerListService.h"
/**
* 分页查询证书列表--(证书管理-分页查询证书列表)--pine
 */
CheckCerListPageJsonVO::Wrapper CheckCerListController::execQueryCheckCerList(const CheckCerListQuery::Wrapper& query, const PayloadDTO& payload)
{
	////创建响应对象
	//auto vo = CheckCerListPageJsonVO::createShared();
	////创建分页对象
	//auto pdto = CheckCerListPageDTO::createShared();
	//pdto->addData(CheckCerListDTO::createShared(1, "zs"));
	//pdto->addData(CheckCerListDTO::createShared(2, "ls"));
	////响应结果
	//vo->success(pdto);
	//return vo;

	// 定义一个Service
	CheckCerListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = CheckCerListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
