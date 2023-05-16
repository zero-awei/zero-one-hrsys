#ifndef __CONTRACTQUERY__
#define __CONTRACTQUERY__

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class ContractQuery : public PageQuery
{
	DTO_INIT(ContractQuery, PageQuery);

	// 合同信息标识
	DTO_FIELD(String, PIMCONTRACTID);
	DTO_FIELD_INFO(PIMCONTRACTID) {
		info->description = ZH_WORDS_GETTER("contract.PIMCONTRACTID");
	}
	// 建立人
	DTO_FIELD(String, CREATEMAN);
	DTO_FIELD_INFO(CREATEMAN) {
		info->description = ZH_WORDS_GETTER("contract.CREATEMAN");
	}
	// 建立时间
	DTO_FIELD(String, CREATEDATE);
	DTO_FIELD_INFO(CREATEDATE) {
		info->description = ZH_WORDS_GETTER("contract.CREATEDATE");
	}
	// 更新时间
	DTO_FIELD(String, UPDATEDATE);
	DTO_FIELD_INFO(UPDATEDATE) {
		info->description = ZH_WORDS_GETTER("contract.UPDATEDATE");
	}
	// 合同信息名称
	DTO_FIELD(String, PIMCONTRACTNAME);
	DTO_FIELD_INFO(PIMCONTRACTNAME) {
		info->description = ZH_WORDS_GETTER("contract.PIMCONTRACTNAME");
	}

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TESTQUERY_H_