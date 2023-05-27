#pragma once
#ifndef _PAGEPROJTAGQUERY_H_
#define _PAGEPROJTAGQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页查询项目标签Query领域模型
 * 负责人：咫尺之书
 */
class PageProjTagQuery : public PageQuery
{
	DTO_INIT(PageProjTagQuery, PageQuery);
	DTO_FIELD_INFO(tagName) {
		info->description = ZH_WORDS_GETTER("projTag.pageQuery.tagName");
	}
	DTO_FIELD(String, tagName);
	DTO_FIELD_INFO(order) {
		info->description = ZH_WORDS_GETTER("projTag.pageQuery.order");
	}
	DTO_FIELD(String, order);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PAGEPROJTAGQUERY_H_