#pragma once
#ifndef _JOB_UPDATE_CONTROLLER_
#define _JOB_UPDATE_CONTROLLER_

#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/vo/BaseJsonVO.h"
#include "../../../domain/dto/jobSet/jobUpdateDto/JobUpdateDTO.h"
#include "../../../domain/vo/jobSet/JobUpdateVO/JobUpdateVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class JobUpdateController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(JobUpdateController);
public:
	ENDPOINT_INFO(updatejobinfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("job.set.update");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(JobUpdateJsonVO);
	}
	ENDPOINT(API_M_PUT, "/jobset", updatejobinfo, BODY_DTO(JobUpdateDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execUpdateJobinfo(dto));
	}
private:
	JobUpdateJsonVO::Wrapper execUpdateJobinfo(const JobUpdateDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController)
#endif // !_