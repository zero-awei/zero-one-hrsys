#pragma once

#include "../../GlobalInclude.h"
#include "../../dto/org/MemberDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个示例菜单显示JsonVO对象，用于响应给前端
 */
class MemberJsonVO : public JsonVO<PageMember::Wrapper>>
{
	DTO_INIT(MemberJsonVO, JsonVO<PageMember::Wrapper>>);
public:
	// 在构造函数中实例化data列表
	MemberJsonVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MENUVO_H_