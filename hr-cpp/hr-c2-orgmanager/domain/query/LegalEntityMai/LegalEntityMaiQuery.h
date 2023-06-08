#pragma once
#ifndef _LEGALENTITYMAI_H_
#define _LEGALENTITYMAI_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* 法人主体维护分页查询对象定义--（组织管理-数据设置-法人主体维护）--TripleGold */
class LegalEntityMaiQuery : public PageQuery
{
	DTO_INIT(LegalEntityMaiQuery, PageQuery);
	// 法人主体标识
	DTO_FIELD(String, ORMSIGNORGID);
	DTO_FIELD_INFO(ORMSIGNORGID) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.id");
	}
	// 更新人
	DTO_FIELD(String, UPDATEMAN);
	DTO_FIELD_INFO(UPDATEMAN) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.updateman");
	}
	// 建立人
	DTO_FIELD(String, CREATEMAN);
	DTO_FIELD_INFO(CREATEMAN) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.createman");
	}
	// 建立时间
	DTO_FIELD(String, CREATEDATE);
	DTO_FIELD_INFO(CREATEDATE) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.createdate");
	}
	// 法人主体名称
	DTO_FIELD(String, ORMSIGNORGNAME);
	DTO_FIELD_INFO(ORMSIGNORGNAME) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.name");
	}
	// 更新时间
	DTO_FIELD(String, UPDATEDATE);
	DTO_FIELD_INFO(UPDATEDATE) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.updatedate");
	}
	// 组织编号
	DTO_FIELD(String, ORGCODE);
	DTO_FIELD_INFO(ORGCODE) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.orgcode");
	}
	// 简称
	DTO_FIELD(String, ZZJC);
	DTO_FIELD_INFO(ZZJC) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.short");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYMAI_H_