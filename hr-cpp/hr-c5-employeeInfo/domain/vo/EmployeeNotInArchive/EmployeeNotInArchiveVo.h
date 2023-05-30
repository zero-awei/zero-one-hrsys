#pragma once

#ifndef _EMPLOYEE_NOT_IN_AECHIVE_VO_
#define _EMPLOYEE_NOT_IN_AECHIVE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/EmployeeNotInArchive/EmployeeNotInArchiveDto.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class EmployeeNotInArchiveJsonVO : public JsonVO<EmployeeNotInArchiveDto::Wrapper> {
	DTO_INIT(EmployeeNotInArchiveJsonVO, JsonVO<EmployeeNotInArchiveDto::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class EmployeeNotInArchivePageJsonVO : public JsonVO <EmployeeNotInArchivePageDTO::Wrapper>
{
	DTO_INIT(EmployeeNotInArchivePageJsonVO, JsonVO<EmployeeNotInArchivePageDTO::Wrapper>);
};

class ArchiveOutPageJsonVO : public JsonVO<ArchiveOutPageDTO::Wrapper> {
	DTO_INIT(ArchiveOutPageJsonVO, JsonVO<ArchiveOutPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_ARCHIVES_VO_