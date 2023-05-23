#pragma once
#pragma once
#ifndef _Assign_Info_Query_VO_
#define _Assign_Info_Query_VO_

#include "../../GlobalInclude.h"
#include "../../query/assignInfo/AssignInfoQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class AssignInfoQueryJsonVO : public JsonVO<AssignInfoQuery::Wrapper> {
	DTO_INIT(AssignInfoQueryJsonVO, JsonVO<AssignInfoQuery::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_Assign_Info_Query_VO_