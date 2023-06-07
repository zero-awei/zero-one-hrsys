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
#include "domain/vo/jobDownload/JobDownloadVO.h"
#include "domain/query/postSet/PostDetailQuery.h"
#include "service/jobSet/jobOutputService/JobOutputService.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 导出岗位设置
 * 负责人：狗皮电耗子
 */
class JobOutputController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(JobOutputController);
public:
	ENDPOINT_INFO(downloadJobinfo) {
		info->summary = ZH_WORDS_GETTER("jobSet.export.downloadurl");
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		API_DEF_ADD_AUTH();
	}

	ENDPOINT(API_M_GET, PATH_TO_JOBSET("/export-job"), downloadJobinfo, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// 响应结果
		API_HANDLER_QUERY_PARAM(query, PostDetailQuery, qps);
		API_HANDLER_RESP_VO(execDownloadJobinfo(query));
	}
private:
	StringJsonVO::Wrapper execDownloadJobinfo(const PostDetailQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_JOB_OUTPUT_CONTROLLER_


