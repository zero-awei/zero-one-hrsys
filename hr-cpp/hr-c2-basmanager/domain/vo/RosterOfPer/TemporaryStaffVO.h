#pragma once
/**
 * (人员花名册-挂职人员-分页查询员工列表)--weixiaoman
 */
#ifndef _TEMPORARYSTAFF_VO_
#define _TEMPORARYSTAFF_VO_

#include "../../GlobalInclude.h"
#include "../../dto/RosterOfPer/TemporaryStaffDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 挂职人员显示JsonVO，用于响应给客户端的Json对象
 */
class TemporaryStaffJsonVO : public JsonVO<TemporaryStaffDTO::Wrapper> {
	DTO_INIT(TemporaryStaffJsonVO, JsonVO<TemporaryStaffDTO::Wrapper>);
};

/**
 * 挂职人员显示JsonVO，用于响应给客户端的Json对象
 */
class TemporaryStaffPageJsonVO : public JsonVO<TemporaryStaffPageDTO::Wrapper> {
	DTO_INIT(TemporaryStaffPageJsonVO, JsonVO<TemporaryStaffPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_TEMPORARYSTAFF_VO_