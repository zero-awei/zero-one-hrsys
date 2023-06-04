#pragma once
#ifndef _EMPLOYEEINFO_DTO_
#define _EMPLOYEEINFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
*  人员信息查询，输入搜索框使用--(证书管理-分页查询员工信息列表)--weixiaoman
*/
class EmployeeInfoDTO : public oatpp::DTO
{
	DTO_INIT(EmployeeInfoDTO, DTO);
	//员工姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("EmpInfo.field.name");
	}
	//唯一标识
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("EmpInfo.field.pimpersonId");
	}

};

/**
 * 人员信息分页传输对象
 */
class EmployeeInfoPageDTO : public PageDTO<EmployeeInfoDTO::Wrapper>
{
	DTO_INIT(EmployeeInfoPageDTO, PageDTO<EmployeeInfoDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_EMPLOYEEINFO_DTO_