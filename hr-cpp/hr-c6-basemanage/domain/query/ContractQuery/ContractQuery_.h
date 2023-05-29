#ifndef __CONTRACTQUERY__
#define __CONTRACTQUERY__

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//合同信息query
class ContractQuery_ : public PageQuery
{
	DTO_INIT(ContractQuery_, PageQuery);

	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("expenseledger_mug.filed.id");
	}

	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("expenseledger_mug.filed.name");
	}

	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("expenseledger_mug.filed.type");
	}

	DTO_FIELD(String, variety);
	DTO_FIELD_INFO(variety) {
		info->description = ZH_WORDS_GETTER("expenseledger_mug.filed.variety");
	}

	DTO_FIELD(String, date);
	DTO_FIELD_INFO(date) {
		info->description = ZH_WORDS_GETTER("expenseledger_mug.filed.date");
	}

	DTO_FIELD(String, condition);
	DTO_FIELD_INFO(condition) {
		info->description = ZH_WORDS_GETTER("expenseledger_mug.filed.condition");
	}

	DTO_FIELD(String, department_m);
	DTO_FIELD_INFO(department_m) {
		info->description = ZH_WORDS_GETTER("expenseledger_mug.filed.department_m");
	}

	DTO_FIELD(String, department_c);
	DTO_FIELD_INFO(department_c) {
		info->description = ZH_WORDS_GETTER("expenseledger_mug.filed.department_c");
	}

	DTO_FIELD(String, date_end);
	DTO_FIELD_INFO(date_end) {
		info->description = ZH_WORDS_GETTER("expenseledger_mug.filed.date_end");
	}

	DTO_FIELD(String, tip);
	DTO_FIELD_INFO(tip) {
		info->description = ZH_WORDS_GETTER("expenseledger_mug.filed.tip");
	}

};

//导出专用query
class ContractDownloadQuery : public oatpp::DTO
{
	DTO_INIT(ContractDownloadQuery, DTO);
	DTO_FIELD_INFO(rows) {
		info->description = ZH_WORDS_GETTER("contract.export.rows");
	}
	DTO_FIELD(UInt64, rows);
	DTO_FIELD_INFO(sequence) {
		info->description = ZH_WORDS_GETTER("contract.export.sequence");
	}
	DTO_FIELD(String, sequence);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_TESTQUERY_H_