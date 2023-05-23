#pragma once

#ifndef _Member_Json_VO_
#define _Member_Json_VO_

#include "../../GlobalInclude.h"
#include "../../dto/org/MemberDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个示例菜单显示JsonVO对象，用于响应给前端
 *///PageMember
class MemberJsonVO : public JsonVO<MemberDTO::Wrapper >
{
	DTO_INIT(MemberJsonVO, JsonVO<MemberDTO::Wrapper >);
public:
	// 在构造函数中实例化data列表
	MemberJsonVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_Member_Json_VO_