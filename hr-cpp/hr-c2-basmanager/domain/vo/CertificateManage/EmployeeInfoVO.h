#pragma once
/**
 * (证书管理-分页查询员工信息列表)--weixiaoman
 */
#ifndef _EMPLOYEEINFO_VO_
#define _EMPLOYEEINFO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/CertificateManage/EmployeeInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 人员信息显示JsonVO，用于响应给客户端的Json对象
 */
class EmployeeInfoJsonVO : public JsonVO<EmployeeInfoDTO::Wrapper> {
	DTO_INIT(EmployeeInfoJsonVO, JsonVO<EmployeeInfoDTO::Wrapper>);
};

/**
 * 人员信息显示JsonVO，用于响应给客户端的Json对象
 */
class EmployeeInfoPageJsonVO : public JsonVO<EmployeeInfoPageDTO::Wrapper> {
	DTO_INIT(EmployeeInfoPageJsonVO, JsonVO<EmployeeInfoPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_EMPLOYEEINFO_VO_