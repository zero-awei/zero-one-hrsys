#pragma once
#pragma once
#ifndef _Modify_Assign_VO_
#define _Modify_Assign_VO_

#include "../../GlobalInclude.h"
#include "../../dto/assignInfo/ModifyAssignInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class ModifyAssignInfoJsonVO : public JsonVO<ModifyAssignInfoDTO::Wrapper> {
	DTO_INIT(ModifyAssignInfoJsonVO, JsonVO<ModifyAssignInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !Modify_Assign_VO_