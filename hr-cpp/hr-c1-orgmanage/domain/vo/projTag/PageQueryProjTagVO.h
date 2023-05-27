#pragma once
#ifndef _PAGEQUERYPROJTAGVO_H_
#define _PAGEQUERYPROJTAGVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/projTag/ProjTagDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页查询项目标签列表VO领域模型
 * 负责人：咫尺之书
 */
class PageQueryProjTagVO : public JsonVO<ProjTagPageDTO::Wrapper>
{
	DTO_INIT(PageQueryProjTagVO, JsonVO<ProjTagPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PAGEQUERYPROJTAGVO_H_