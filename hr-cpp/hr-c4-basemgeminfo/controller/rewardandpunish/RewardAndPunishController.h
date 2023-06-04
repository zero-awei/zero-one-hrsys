#pragma once

#ifndef _REWARDANDPUNISHCONTROLLER_H_
#define _REWARDANDPUNISHCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "../../domain/query/rewardandpunish/RewardAndPunishQuery.h"
#include "../../domain/vo/rewardandpunish/RewardAndPunishVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class RewardAndPunishController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(RewardAndPunishController);
public: // 定义接口

	//查看指定
	ENDPOINT_INFO(queryRewardAndPunish) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("rewardandpunish.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(RewardAndPunishJsonVO);
		// 添加其他查询参数
		info->queryParams.add<String>("pimrewardpunishmentid").description = ZH_WORDS_GETTER("rewardandpunish.pimrewardpunishmentid");
		info->queryParams["pimrewardpunishmentid"].addExample("default", String("123456789"));
	}
	ENDPOINT(API_M_GET, "/rewardandpunish/select", queryRewardAndPunish, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, RewardAndPunishDetailQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryRewardAndPunish(query));
	}

	//修改指定奖惩记录(单条修改)
	ENDPOINT_INFO(modifyRewardAndPunish) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("rewardandpunish.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_PUT, "/rewardandpunish/modify", modifyRewardAndPunish, BODY_DTO(RewardAndPunishDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyRewardAndPunish(dto));
	}

	//导出
	ENDPOINT_INFO(downloadRewardAndPunish) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("rewardandpunish.download.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 添加其他查询参数
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("rewardandpunish.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("0002CC75-F8EB-45B3-A359-0310EC7F6D5B"));
	}
	ENDPOINT(API_M_POST, "/rewardandpunish/download", downloadRewardAndPunish, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, RewardAndPunishDownloadQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execDownloadRewardAndPunish(query));
	}
private: // 定义接口执行函数
	RewardAndPunishJsonVO::Wrapper execQueryRewardAndPunish(const RewardAndPunishDetailQuery::Wrapper& query);
	StringJsonVO::Wrapper execModifyRewardAndPunish(const RewardAndPunishDTO::Wrapper& dto);
	StringJsonVO::Wrapper execDownloadRewardAndPunish(const RewardAndPunishDownloadQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif