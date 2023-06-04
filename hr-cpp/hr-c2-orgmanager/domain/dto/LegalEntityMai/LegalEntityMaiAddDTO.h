#pragma once

#ifndef _LEGALENTITYMAI_ADD_DTO_H_
#define _LEGALENTITYMAI_ADD_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* 构建法人主体维护批量新增DTO--（组织管理-数据设置-法人主体维护）--TripleGold */
class LegalEntityMaiAddDTO : public oatpp::DTO
{
public:
	LegalEntityMaiAddDTO() {};
	// 有参构造函数
	LegalEntityMaiAddDTO(String name, String orgcode) : ORMSIGNORGNAME(name), ORGCODE(orgcode) {};

	DTO_INIT(LegalEntityMaiAddDTO, DTO);
	// 法人主体名称
	DTO_FIELD(String, ORMSIGNORGNAME);
	DTO_FIELD_INFO(ORMSIGNORGNAME) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.name");
	}
	// 组织编号
	DTO_FIELD(String, ORGCODE);
	DTO_FIELD_INFO(ORGCODE) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.orgcode");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYMAI_ADD_DTO_H_