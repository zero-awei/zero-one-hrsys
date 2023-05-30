#pragma once
/*
人员花名册-离退休人员-分页查询员工列表--pine
*/
#ifndef _CHECK_RETIRES_DTO_
#define _CHECK_RETIRES_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class CheckRetiresListDTO : public oatpp::DTO
{
public:
	//无参构造
	CheckRetiresListDTO() {};
	//有参构造
	//CheckRetiresListDTO(UInt64 id, String name, Int32 age, String sex) {};
	//CheckRetiresListDTO(UInt64 id, String name) :id(id), name(name) {};
	DTO_INIT(CheckRetiresListDTO, DTO);
	// 员工编号
	DTO_FIELD(UInt64, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.ygbh");
	}
	// 员工姓名
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.pimpersonname");
	}
};

/**
 * 示例分页传输对象
 */
class CheckRetiresListPageDTO : public PageDTO<CheckRetiresListDTO::Wrapper>
{
	DTO_INIT(CheckRetiresListPageDTO, PageDTO<CheckRetiresListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 