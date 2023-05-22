#pragma once
#ifndef _JOB_DOWNLOAD_DTO_
#define _JOB_DOWNLOAD_DTO_
#include "../../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)
class JobDownloadDTO : public oatpp::DTO
{
	DTO_INIT(JobDownloadDTO, DTO);

	DTO_FIELD(String, url);
	DTO_FIELD_INFO(url) {
		info->description = ZH_WORDS_GETTER("job.downloadurl");
	}
public:
	JobDownloadDTO() {
		String url = "www.baidu.com";
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_JOB_DOWNLOAD_DTO_
