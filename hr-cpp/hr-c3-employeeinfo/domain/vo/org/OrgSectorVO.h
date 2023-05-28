#pragma once

#ifndef _Org_Sector_VO_
#define _Org_Sector_VO_

#include "../../GlobalInclude.h"
#include "../../dto/org/OrgSectorDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个示例菜单显示JsonVO对象，用于响应给前端
 */
class OrgSectorVO : public JsonVO<OrgSectorPageDTO::Wrapper>
{
	DTO_INIT(OrgSectorVO, JsonVO<OrgSectorPageDTO::Wrapper>);
public:
	// 在构造函数中实例化data列表
	OrgSectorVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_Org_Sector_VO_