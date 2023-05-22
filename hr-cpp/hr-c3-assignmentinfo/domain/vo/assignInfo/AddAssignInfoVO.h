#pragma once
#pragma once
#ifndef _Add_Assign_VO_
#define _Add_Assign_VO_

#include "../../GlobalInclude.h"
#include "../../dto/assignInfo/AddAssignInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class AddAssignInfoJsonVO : public JsonVO<AddAssignInfoDTO::Wrapper> {
	DTO_INIT(AddAssignInfoJsonVO, JsonVO<AddAssignInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !Add_Assign_VO_