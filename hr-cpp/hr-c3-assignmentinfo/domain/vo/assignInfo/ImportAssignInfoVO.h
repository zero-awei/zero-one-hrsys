#pragma once
#pragma once
#ifndef _Import_Assign_VO_
#define _Import_Assign_VO_

#include "../../GlobalInclude.h"
#include "../../dto/assignInfo/ImportAssignInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class ImportAssignInfoJsonVO : public JsonVO<ImportAssignInfoDTO::Wrapper> {
	DTO_INIT(ImportAssignInfoJsonVO, JsonVO<ImportAssignInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !Import_Assign_VO_