#pragma once
#ifndef _BLACKLIST_EMPLOYEE_VO_
#define _BLACKLIST_EMPLOYEE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/Blacklist/BlacklistDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 黑名单员工显示JsonVO，用于响应给客户端的Json对象
 */
class BlacklistEmployeeJsonVO : public JsonVO<BlacklistDTO::Wrapper> {
	DTO_INIT(BlacklistEmployeeJsonVO, JsonVO<BlacklistDTO::Wrapper>);
};


/**
 * 黑名单员工分页显示JsonVO，用于响应给客户端的Json对象
 */
class BlacklistEmployeePageJsonVO : public JsonVO<BlacklistPageDTO::Wrapper> {
	DTO_INIT(BlacklistEmployeePageJsonVO, JsonVO<BlacklistPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // 