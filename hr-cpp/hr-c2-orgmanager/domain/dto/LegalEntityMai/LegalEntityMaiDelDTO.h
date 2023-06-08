#pragma once

#ifndef _LEGALENTITYMAIDELETEDTO_H_
#define _LEGALENTITYMAIDELETEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* 构建法人主体维护批量删除DTO--（组织管理-数据设置-法人主体维护）--TripleGold */
class LegalEntityMaiDelDTO : public oatpp::DTO
{
	DTO_INIT(LegalEntityMaiDelDTO, DTO);
	// 删除数据ID数组
	DTO_FIELD(List<String>, Ids) = {};
	DTO_FIELD_INFO(Ids) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.delete.cnt");
	}

	//// 法人主体标识
	//DTO_FIELD(String, ORMSIGNORGID);
	//DTO_FIELD_INFO(ORMSIGNORGID) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.id");
	//}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYMAIDELETEDTO_H_