#pragma once
#ifndef _M_LD_DTO_
#define _M_LD_DTO_
#include "../../GlobalInclude.h"
//#include "domain/vo/JsonVO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class LaborDispatchMDTO : public oatpp::DTO
{
	DTO_INIT(LaborDispatchMDTO, DTO);

	DTO_FIELD(String, corporateName);
	DTO_FIELD_INFO(corporateName) {
		info->description = ZH_WORDS_GETTER("labordispatch_mug.field.corporatename");
	}

	DTO_FIELD(String, corporateAddress);
	DTO_FIELD_INFO(corporateAddress) {
		info->description = ZH_WORDS_GETTER("labordispatch_mug.field.corporateaddress");
	}
	
	DTO_FIELD(String, corporateContact);
	DTO_FIELD_INFO(corporateContact) {
		info->description = ZH_WORDS_GETTER("labordispatch_mug.field.corporatecontact");
	}

	DTO_FIELD(String, corporateNumber);
	DTO_FIELD_INFO(corporateNumber) {
		info->description = ZH_WORDS_GETTER("labordispatch_mug.field.corporatenumber");
	}
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_LD_M_QUERY_