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



//DTO:上传路径
class UploadPathDTO : public oatpp::DTO
{
public:
	UploadPathDTO() {};

	DTO_INIT(UploadPathDTO, DTO);

	// 上传路径
	DTO_FIELD(String, UploadPath);
	DTO_FIELD_INFO(UploadPath) {
		info->description = ZH_WORDS_GETTER("contract.uploadpath");
	}

};

//DTO:导出地址+分页操作
class DownloadPageDTO : public PageDTO<ContractDTO_::Wrapper>
{
public:
	DownloadPageDTO() {};

	DTO_INIT(DownloadPageDTO, PageDTO);

	// 下载路径
	DTO_FIELD(String, DownloadPath);
	DTO_FIELD_INFO(DownloadPath) {
		info->description = ZH_WORDS_GETTER("contract.downloadpath");
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



#include OATPP_CODEGEN_END(DTO)

#endif // !_TESTDTO_H_