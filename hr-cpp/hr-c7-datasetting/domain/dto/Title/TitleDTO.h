#pragma once
#pragma once
#ifndef _TITLEDTO_H_
#define _TITLEDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个可修改职称目录信息的传输对象
 */
class TitleDTO : public oatpp::DTO
{

	DTO_INIT(TitleDTO, DTO);

	//员工编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("title.field.id");
	}
	//员工姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("title.field.name");
	}
};

/**
 * 定义一个职称目录信息分页传输对象
 */
class TitlePageDTO : public PageDTO<TitleDTO::Wrapper>
{
	DTO_INIT(TitlePageDTO, PageDTO<TitleDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _TITLEDTO_H_