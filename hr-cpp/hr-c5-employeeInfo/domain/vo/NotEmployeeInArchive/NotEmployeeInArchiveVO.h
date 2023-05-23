#pragma once

#ifndef _NOT_EMPLOYEE_IN_ARCHIVE_VO_
#define _NOT_EMPLOYEE_IN_ARCHIVE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/NotEmployeeInArchive/NotEmployeeInArchiveDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示JsonVO，用于响应给客户端的Json对象
 */
class NotEmployeeInArchiveVO : public JsonVO<NotEmployeeInArchiveDTO::Wrapper> {
	DTO_INIT(NotEmployeeInArchiveVO, JsonVO<NotEmployeeInArchiveDTO::Wrapper>);
};

/**
 * 分页显示JsonVO，用于响应给客户端的Json对象
 */
class NotEmployeeInArchivePageJsonVO : public JsonVO<NotEmployeeInArchivePageDTO::Wrapper> {
	DTO_INIT(NotEmployeeInArchivePageJsonVO, JsonVO<NotEmployeeInArchivePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_NOT_EMPLOYEE_IN_ARCHIVE_