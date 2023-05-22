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
	
	//排序号
	API_DTO_FIELD_DEFAULT(String, titleId, ZH_WORDS_GETTER("title.field.id"));
	//岗位证书
	API_DTO_FIELD_DEFAULT(String, titleName, ZH_WORDS_GETTER("title.field.titleName"));
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