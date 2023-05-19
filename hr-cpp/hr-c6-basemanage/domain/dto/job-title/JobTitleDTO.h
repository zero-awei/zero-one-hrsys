#pragma once
/**
* DTO是修改时携带参数和返回时携带参数类型
*/


#include "stdafx.h"
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "../../GlobalInclude.h"
#ifndef _JOBTITLE_DTO_
#define _JOBTITLE_DTO_

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 职称管理对象传输(临时字段)
*/
class JobTitleDTO : public oatpp::DTO {

	// 初始化DTO
	DTO_INIT(JobTitleDTO, DTO);
	// 职称id
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("title.field.id");
	}
	// 职称名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("title.field.name");
	}
	// 职称等级
	DTO_FIELD(String, grades);
	DTO_FIELD_INFO(grades) {
		info->description = ZH_WORDS_GETTER("title.field.grades");
	}
	// 职称类型
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("title.field.type");
	}
	// 专业类别
	DTO_FIELD(String, category);
	DTO_FIELD_INFO(category) {
		info->description = ZH_WORDS_GETTER("title.field.category");
	}
};

/**
 * 职称管理分页对象传输
 */
class JobTitlePageDTO : public PageDTO<JobTitleDTO::Wrapper>
{
	DTO_INIT(JobTitlePageDTO, PageDTO<JobTitleDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_JOBTITLE_DTO_