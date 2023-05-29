#pragma once
#ifndef _RETIREMETDTO_H_
#define _RETIREMETDTO_H_


#include "stdafx.h"
#include "../../GlobalInclude.h"
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)
class RetirementDTO : public oatpp::DTO
{
	//初始化
	DTO_INIT(RetirementDTO, DTO);
	// 员工姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("My.field.name");
	}
	// 员工编号
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("My.field.id");
	}
	//性别
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("My.field.sex");
	}
	// 年龄
	DTO_FIELD(UInt64, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("My.field.age");
	}
};

/**
 * 示例分页传输对象
 */
class RetirementPageDTO : public PageDTO<RetirementDTO::Wrapper>
{
	DTO_INIT(RetirementPageDTO, PageDTO<RetirementDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RETIREMETDTO_H_
