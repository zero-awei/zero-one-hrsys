#pragma once
#ifndef _EMPLOYEEINFO_SERVICE_
#define _EMPLOYEEINFO_SERVICE_
#include <list>
#include "domain/vo/CertificateManage/EmployeeInfoVO.h"
#include "domain/dto/CertificateManage/EmployeeInfoDTO.h"
#include "domain/query/CertificateManage/EmployeeInfoQuery.h"
/**
 * 人员信息分页查询service--(证书管理-分页查询员工信息列表)--weixiaoman
 */
class EmployeeInfoService {
public:
	EmployeeInfoPageDTO::Wrapper listAll(const EmployeeInfoQuery::Wrapper& query);
};



#endif // !_EMPLOYEEINFO_SERVICE_