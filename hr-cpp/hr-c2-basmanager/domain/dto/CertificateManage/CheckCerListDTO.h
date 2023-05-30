#pragma once
/*
* 分页查询证书列表--(证书管理-分页查询证书列表)--pine
*/
#ifndef _CHECK_CER_DTO_
#define _CHECK_CER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class CheckCerListDTO : public oatpp::DTO
{
public:
	//无参构造
	CheckCerListDTO() {};
	//有参构造
	//CheckCerListDTO(UInt64 id, String name, Int32 age, String sex) {};
	CheckCerListDTO(UInt64 ygbh, String pimperSonName, String pimVocationalName) :ygbh(ygbh), pimperSonName(pimperSonName), pimVocationalName(pimVocationalName) {};
	DTO_INIT(CheckCerListDTO, DTO);
	// 员工编号
	DTO_FIELD(UInt64, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("cermanage.field.ygbh");
	}
	// 员工姓名
	DTO_FIELD(String, pimperSonName);
	DTO_FIELD_INFO(pimperSonName) {
		info->description = ZH_WORDS_GETTER("cermanage.field.pimperSonName");
	}
	// 证书名称
	DTO_FIELD(String, pimVocationalName);
	DTO_FIELD_INFO(pimVocationalName) {
		info->description = ZH_WORDS_GETTER("cermanage.field.pimVocationalName");
	}
};

/**
 * 示例分页传输对象
 */
class CheckCerListPageDTO : public PageDTO<CheckCerListDTO::Wrapper>
{
	DTO_INIT(CheckCerListPageDTO, PageDTO<CheckCerListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 