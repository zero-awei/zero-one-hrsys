#pragma once
#ifndef _PAGEQUERYVO_H_
#define _PAGEQUERYVO_H_

#include "../../GlobalInclude.h"
#include "../../query/projTag/PageProjTagQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 下拉列表VO领域模型
 * 负责人：Andrew
 */
class PageQueryProjTagVO : public JsonVO<PageProjTagQuery::Wrapper>
{
	DTO_INIT(PageQueryProjTagVO, JsonVO<PageProjTagQuery::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PAGEQUERYVO_H_