#pragma once
#ifndef _TRAININGRECORDCONTROLLER_H_
#define _TRAININGRECORDCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/trainingrecord/TrainingRecordQuery.h"
#include "domain/vo/trainingrecord/TrainingRecordVO.h"
#include "domain/dto/trainingrecord/TrainingRecordDTO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TrainingRecordController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(TrainingRecordController);
public: // 定义接口

	ENDPOINT_INFO(queryTrainingRecord) {

		//定义接口标题
		info->summary = ZH_WORDS_GETTER("trainingrecord.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(TrainingRecordPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();

	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/trainingrecord/query", queryTrainingRecord, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, TrainingRecordPageQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryTrainingRecord(userQuery, authObject->getPayload()));
	}

private: // 定义接口执行函数
	TrainingRecordPageJsonVO::Wrapper execQueryTrainingRecord(const TrainingRecordPageQuery::Wrapper& query, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController)

#endif