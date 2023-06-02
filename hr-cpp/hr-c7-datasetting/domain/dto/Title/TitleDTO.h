#pragma once
#pragma once
#ifndef _TITLEDTO_H_
#define _TITLEDTO_H_
#include "../../GlobalInclude.h"
#include "ApiHelper.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个可修改职称目录信息的传输对象
 */
class TitleDTO : public oatpp::DTO
{
public:
	TitleDTO() {};
	DTO_INIT(TitleDTO, DTO);


	//排序号
	DTO_FIELD(Int32, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("Title.field.id");
	}
	//职称代码
	DTO_FIELD(String, num);
	DTO_FIELD_INFO(num) {
		info->description = ZH_WORDS_GETTER("Title.field.num");
		

	}
	//职称目录名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("Title.field.name"));
	//职称目录类型
	API_DTO_FIELD_DEFAULT(String, dtype, ZH_WORDS_GETTER("Title.field.dtype"));
	//职称类型
	API_DTO_FIELD_DEFAULT(String, Ttype, ZH_WORDS_GETTER("Title.field.type"));
};
class TitleDTO_delete :public oatpp::DTO
{
public:
	DTO_INIT(TitleDTO_delete, DTO);
	DTO_FIELD(Int32, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("Title.field.id");
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
