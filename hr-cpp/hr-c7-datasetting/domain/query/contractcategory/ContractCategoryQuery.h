#pragma once
#ifndef _CONTRACT_CATEGORY_QUERY_
#define _CONTRACT_CATEGORY_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 合同类别分页查询对象
 */
class ContractCategoryQuery : public PageQuery
{
	DTO_INIT(ContractCategoryQuery, PageQuery);
	// 类别名称
	DTO_FIELD(String, categoryName);
	DTO_FIELD_INFO(categoryName) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.categoryName");
	}
	// 当前页码
	DTO_FIELD(UInt32, pageNum);
	DTO_FIELD_INFO(pageNum) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.pageNum");
	}
	// 每页显示的条数
	DTO_FIELD(UInt32, pageSize);
	DTO_FIELD_INFO(pageSize) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.pageSize");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_
