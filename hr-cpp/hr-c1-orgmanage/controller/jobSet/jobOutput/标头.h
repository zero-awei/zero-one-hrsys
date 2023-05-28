//2023年5月21日
//岗位导出信息
//作者：狗皮电耗子
#pragma once
#ifndef _JOB_OUTPUT_CONTROLLER_
#define _JOB_OUTPUT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/dto/jobDownload/JobDownloadDTO.h"
#include "domain/vo/JobDownload/JobDownloadVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class JobOutputController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(JobOutputController);
public:
	ENDPOINT_INFO(downloadJobinfo) {
		info->summary = ZH_WORDS_GETTER("job.downloadurl");
		API_DEF_ADD_RSP_JSON_WRAPPER(JobDownloadJsonVO);
	}
	ENDPOINT(API_M_GET, PATH_TO_JOBSET("/export-job"), downloadJobinfo) {
		// 响应结果
		API_HANDLER_RESP_VO(execDownloadJobinfo());
		return createResponse(Status::CODE_202, "OK");
	}
private:
	JobDownloadJsonVO::Wrapper execDownloadJobinfo();
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_JOB_OUTPUT_CONTROLLER_
