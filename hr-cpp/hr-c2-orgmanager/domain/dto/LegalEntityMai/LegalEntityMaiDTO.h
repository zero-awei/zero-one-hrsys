#pragma once

#ifndef _LEGALENTITYMAIDTO_H_
#define _LEGALENTITYMAIDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* 法人主体维护数据传输对象定义--（组织管理-数据设置-法人主体维护）--TripleGold */
class LegalEntityMaiDTO : public oatpp::DTO
{
public:
	LegalEntityMaiDTO() {};
	// 有参构造函数
	LegalEntityMaiDTO(String name, String orgcode) : ORMSIGNORGNAME(name), ORGCODE(orgcode) {};
	LegalEntityMaiDTO(String id, String name, String orgcode) : ORMSIGNORGID(id), ORMSIGNORGNAME(name), ORGCODE(orgcode) {};
	/*LegalEntityMaiDTO(String id, String updateman, String createman, String createdate,
		String name, String updatedate, String orgcode, String shortForm) :
		ORMSIGNORGID(id), UPDATEMAN(updateman), CREATEMAN(createman), CREATEDATE(createdate),
		ORMSIGNORGNAME(name), UPDATEDATE(updatedate), ORGCODE(orgcode), ZZJC(shortForm) {};*/
	DTO_INIT(LegalEntityMaiDTO, DTO);
	// 法人主体标识
	DTO_FIELD(String, ORMSIGNORGID);
	DTO_FIELD_INFO(ORMSIGNORGID) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.id");
	}
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

	//// 法人主体标识
	//DTO_FIELD(String, ORMSIGNORGID);
	//DTO_FIELD_INFO(ORMSIGNORGID) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.id");
	//}
	//// 更新人
	//DTO_FIELD(String, UPDATEMAN);
	//DTO_FIELD_INFO(UPDATEMAN) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.updateman");
	//}
	//// 建立人
	//DTO_FIELD(String, CREATEMAN);
	//DTO_FIELD_INFO(CREATEMAN) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.createman");
	//}
	//// 建立时间
	//DTO_FIELD(String, CREATEDATE);
	//DTO_FIELD_INFO(CREATEDATE) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.createdate");
	//}
	//// 法人主体名称
	//DTO_FIELD(String, ORMSIGNORGNAME);
	//DTO_FIELD_INFO(ORMSIGNORGNAME) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.name");
	//}
	//// 更新时间
	//DTO_FIELD(String, UPDATEDATE);
	//DTO_FIELD_INFO(UPDATEDATE) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.updatedate");
	//}
	//// 组织编号
	//DTO_FIELD(String, ORGCODE);
	//DTO_FIELD_INFO(ORGCODE) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.orgcode");
	//}
	//// 简称
	//DTO_FIELD(String, ZZJC);
	//DTO_FIELD_INFO(ZZJC) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.short");
	//}
};

/* 定义法人主体分页传输对象 */
class LegalEntityMaiPageDTO : public PageDTO<LegalEntityMaiDTO::Wrapper> 
{
	DTO_INIT(LegalEntityMaiPageDTO, PageDTO<LegalEntityMaiDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYMAI_H_