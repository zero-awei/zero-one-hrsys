#include "stdafx.h"
#include "EmployeeInfoController.h"
//#include "../../service/CertificateManage/EmployeeInfoService.h"
/**
* 证书管理人员信息查询，搜索框使用--(证书管理-分页查询员工信息)-weixiaoman
*/
EmployeeInfoPageJsonVO::Wrapper EmployeeInfoController::execQueryEmpInfo(const EmployeeInfoQuery::Wrapper& query, const PayloadDTO& payload)
{
	//// 定义一个Service
	//EmployeeInfoService service;
	//// 查询数据
	//auto result = service.listAll(query);
	//// 响应结果
	auto jvo = EmployeeInfoPageJsonVO::createShared();
	//jvo->success(result);
	return jvo;
}
