#pragma once
#ifndef _CONTRACTCATEGORYDTO_H_
#define _CONTRACTCATEGORYDTO_H_

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

#define API_DTO_FIELD(_TYPE_, _NAME_, _DESCRIPTION_, _REQUIRE_, _DEFAULT_) \
DTO_FIELD(_TYPE_, _NAME_) = _DEFAULT_; \
DTO_FIELD_INFO(_NAME_) { \
	info->description = _DESCRIPTION_; \
	info->required = _REQUIRE_; \
}

#define API_DTO_FIELD_DEFAULT(_TYPE_, _NAME_, _DESCRIPTION_) \
DTO_FIELD(_TYPE_, _NAME_); \
DTO_FIELD_INFO(_NAME_) { \
	info->description = _DESCRIPTION_; \
}

/*
	合同类别传输对象
*/
class ContractCategoryDTO : public oatpp::DTO
{
public:
	ContractCategoryDTO() {};
	ContractCategoryDTO(String id, String name) :id(id), name(name) {};
	DTO_INIT(ContractCategoryDTO, DTO);

	//合同类别编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.categoryID");
	}

	//合同类别名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.name");
	}

	// 你可以根据需要添加其他字段
};

/**
 * 合同类别分页传输对象
 */
class ContractCategoryPageDTO : public PageDTO<ContractCategoryDTO::Wrapper>
{
	DTO_INIT(ContractCategoryPageDTO, PageDTO<ContractCategoryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTRACTCATEGORYDTO_H_
