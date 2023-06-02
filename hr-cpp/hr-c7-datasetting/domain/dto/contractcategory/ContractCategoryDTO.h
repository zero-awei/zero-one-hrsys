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
	ContractCategoryDTO(String id, String name, String createDate, String enable, String createMan, String updateMan, String updateDate, String sbm, String lx, String ormOrgId)
		: id(id), name(name), createDate(createDate), enable(enable), createMan(createMan), updateMan(updateMan), updateDate(updateDate), sbm(sbm), lx(lx), ormOrgId(ormOrgId) {};

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

	//创建日期
	DTO_FIELD(String, createDate);
	DTO_FIELD_INFO(createDate) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.createDate");
	}

	//是否启用
	DTO_FIELD(String, enable);
	DTO_FIELD_INFO(enable) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.enable");
	}

	//创建人
	DTO_FIELD(String, createMan);
	DTO_FIELD_INFO(createMan) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.createMan");
	}

	//更新人
	DTO_FIELD(String, updateMan);
	DTO_FIELD_INFO(updateMan) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.updateMan");
	}

	//更新日期
	DTO_FIELD(String, updateDate);
	DTO_FIELD_INFO(updateDate) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.updateDate");
	}

	//SBM
	DTO_FIELD(String, sbm);
	DTO_FIELD_INFO(sbm) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.sbm");
	}

	//LX
	DTO_FIELD(String, lx);
	DTO_FIELD_INFO(lx) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.lx");
	}

	//ORMORGID
	DTO_FIELD(String, ormOrgId);
	DTO_FIELD_INFO(ormOrgId) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.ormOrgId");
	}

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
