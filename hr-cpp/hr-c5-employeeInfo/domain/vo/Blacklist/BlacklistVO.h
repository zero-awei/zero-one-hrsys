#pragma once

#ifndef _BLACKLIST_VO_
#define _BLACKLIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/Blacklist/BlacklistDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 黑名单数据显示JsonVO，用于响应给客户端的Json对象
 */
class BlacklistJsonVO : public JsonVO<BlacklistDTO::Wrapper> {
	DTO_INIT(BlacklistJsonVO, JsonVO<BlacklistDTO::Wrapper>);
};


/**
 * 黑名单数据分页显示JsonVO，用于响应给客户端的Json对象
 */
class BlacklistPageJsonVO : public JsonVO<BlacklistPageDTO::Wrapper> {
	DTO_INIT(BlacklistPageJsonVO, JsonVO<BlacklistPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // 