#ifndef __CONTRACTDTO__
#define __CONTRACTDTO__

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//DTO:合同信息
class ContractDTO_ : public oatpp::DTO
{
public:
	ContractDTO_() {};
	ContractDTO_(String PIMCONTRACTID, String CREATEMAN, String CREATEDATE, \
	String UPDATEDATE, String PIMCONTRACTNAME) :\
		PIMCONTRACTID(PIMCONTRACTID), CREATEMAN(CREATEMAN),\
		CREATEDATE(CREATEDATE), UPDATEDATE(UPDATEDATE),\
		PIMCONTRACTNAME(PIMCONTRACTNAME){};

	DTO_INIT(ContractDTO_, DTO);

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