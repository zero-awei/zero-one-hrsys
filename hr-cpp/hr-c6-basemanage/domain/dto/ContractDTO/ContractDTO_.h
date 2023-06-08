#ifndef __CONTRACTDTO__
#define __CONTRACTDTO__

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//DTO:合同信息
class ContractDTO_ : public oatpp::DTO
{
public:
	ContractDTO_() {};

	DTO_INIT(ContractDTO_, DTO);

	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("contract.filed.id");
	}

	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("contract.filed.name");
	}

	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("contract.filed.type");
	}

	DTO_FIELD(String, variety);
	DTO_FIELD_INFO(variety) {
		info->description = ZH_WORDS_GETTER("contract.filed.variety");
	}

	DTO_FIELD(String, date);
	DTO_FIELD_INFO(date) {
		info->description = ZH_WORDS_GETTER("contract.filed.date");
	}

	DTO_FIELD(String, condition);
	DTO_FIELD_INFO(condition) {
		info->description = ZH_WORDS_GETTER("contract.filed.condition");
	}

	DTO_FIELD(String, department_m);
	DTO_FIELD_INFO(department_m) {
		info->description = ZH_WORDS_GETTER("contract.filed.department_m");
	}

	DTO_FIELD(String, department_c);
	DTO_FIELD_INFO(department_c) {
		info->description = ZH_WORDS_GETTER("contract.filed.department_c");
	}

	DTO_FIELD(String, try_end);
	DTO_FIELD_INFO(try_end) {
		info->description = ZH_WORDS_GETTER("contract.filed.try_end");
	}

	DTO_FIELD(String, tip);
	DTO_FIELD_INFO(tip) {
		info->description = ZH_WORDS_GETTER("contract.filed.tip");
	}

	DTO_FIELD(String, infoid);
	DTO_FIELD_INFO(infoid) {
		info->description = ZH_WORDS_GETTER("contract.filed.infoid");
	}

	DTO_FIELD(String, date_end);
	DTO_FIELD_INFO(date_end) {
		info->description = ZH_WORDS_GETTER("contract.filed.date_end");
	}

	DTO_FIELD(String, emp_condition);
	DTO_FIELD_INFO(emp_condition) {
		info->description = ZH_WORDS_GETTER("contract.filed.emp_condition");
	}

	DTO_FIELD(String, contract_num);
	DTO_FIELD_INFO(contract_num) {
		info->description = ZH_WORDS_GETTER("contract.filed.contract_num");
	}

};





//DTO:导出地址
class DownloadPathDTO : public PageDTO<ContractDTO_::Wrapper>
{
public:
	DownloadPathDTO() {};

	DTO_INIT(DownloadPathDTO, PageDTO<ContractDTO_::Wrapper>);

	// 下载路径
	DTO_FIELD(String, DownloadPath);
	DTO_FIELD_INFO(DownloadPath) {
		info->description = ZH_WORDS_GETTER("contract.downloadpath");
	}
};


class ContractInfoPageDTO : public PageDTO<ContractDTO_::Wrapper>
{
public:
	ContractInfoPageDTO() {};

	DTO_INIT(ContractInfoPageDTO, PageDTO<ContractDTO_::Wrapper>);
};




#include OATPP_CODEGEN_END(DTO)

#endif // !_TESTDTO_H_