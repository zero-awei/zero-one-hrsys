#pragma once

#ifndef _LEGALENTITYSETADDQUERY_DTO_
#define _LEGALENTITYSETADDQUERY_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class LegalEntitySetAddDTO : public oatpp::DTO {
public:
	LegalEntitySetAddDTO() {};
	LegalEntitySetAddDTO(String ormsignorgid, String ormorgid, String contractsignorgname, String isdefaultsignorg) : 
		ormsignorgid(ormsignorgid), ormorgid(ormorgid), contractsignorgname(contractsignorgname), isdefaultsignorg(isdefaultsignorg) {	};
	//LegalEntitySetAddDTO(String ormsignorgid, String ormorgid, String contractsignorgname, String isdefaultsignorg) {	};
	DTO_INIT(LegalEntitySetAddDTO, DTO);
	// 签约主体单位名称
	DTO_FIELD(String, contractsignorgname);
	DTO_FIELD_INFO(contractsignorgname) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgname");
	}
	// 法人主体标识
	DTO_FIELD(String, ormsignorgid);
	DTO_FIELD_INFO(ormsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormsignorgid");
	}
	//  默认签约主体
	DTO_FIELD(String, isdefaultsignorg) = "1";
	DTO_FIELD_INFO(isdefaultsignorg) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.isdefaultsignorg");
	}
	// 管理单位标识
	DTO_FIELD(String, ormorgid);
	DTO_FIELD_INFO(ormorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormorgid");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LEGALENTITYSETDELQUERY_DTO_