#pragma once

#ifndef _ORG_VO_
#define _ORG_VO_
#include "../../GlobalInclude.h"
#include "../../dto/org/OrgDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个示例菜单显示JsonVO对象，用于响应给前端
 */
class OrgJsonVO : public JsonVO<OrgPageDTO::Wrapper>
{
	DTO_INIT(OrgJsonVO, JsonVO<OrgPageDTO::Wrapper>);
public:
	// 在构造函数中实例化data列表
	OrgJsonVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORG_VO_