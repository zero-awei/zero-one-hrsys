#pragma once

#ifndef _LEGALENTITYSETUPDATEQUERY_DTO_
#define _LEGALENTITYSETUPDATEQUERY_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class LegalEntitySetUpdateDTO : public oatpp::DTO {
public:
	LegalEntitySetUpdateDTO() {};
	LegalEntitySetUpdateDTO(String contractsignorgid , String ormsignorgid, String ormorgid, String contractsignorgname, String isdefaultsignorg) : 
	contractsignorgid(contractsignorgid), ormsignorgid(ormsignorgid), ormorgid(ormorgid), contractsignorgname(contractsignorgname), isdefaultsignorg(isdefaultsignorg) {	};
	//LegalEntitySetUpdateDTO(String ormsignorgid, String ormorgid, String contractsignorgname, String isdefaultsignorg) {	};
	DTO_INIT(LegalEntitySetUpdateDTO, DTO);
	// 唯一标识
	DTO_FIELD(String, contractsignorgid);
	DTO_FIELD_INFO(contractsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgid");
	}
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