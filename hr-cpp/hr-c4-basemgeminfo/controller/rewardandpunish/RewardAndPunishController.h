#pragma once
#ifndef _REWARDANDPUNISHCONTROLLER_H_
#define _REWARDANDPUNISHCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/rewardandpunish/RewardAndPunishQuery.h"
#include "domain/vo/rewardandpunish/RewardAndPunishVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class RewardAndPunishController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(RewardAndPunishController);
public: // 定义接口
	//查看指定员工简称信息(指定奖惩信息详情)
	ENDPOINT_INFO(queryRewardAndPunish) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("rewardandpunish.get.summary");
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(RewardAndPunishJsonVO);
		// 添加其他查询参数
		info->queryParams.add<String>("PIMARMYCADRESID").description = ZH_WORDS_GETTER("rewardandpunish.PIMARMYCADRESID");
		info->queryParams["PIMARMYCADRESID"].addExample("default", String("QWER-ASFD"));
	}
	ENDPOINT(API_M_GET, "/rewardandpunish", queryRewardAndPunish, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, RewardAndPunishViewQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryRewardAndPunish(query));
	}
	//修改指定奖惩信息(单条修改)
	ENDPOINT_INFO(modifyRewardAndPunish) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("RewardAndPunish.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_PUT, "/rewardandpunish", modifyRewardAndPunish, BODY_DTO(RewardAndPunishDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyRewardAndPunish(dto));
	}
	//导出指定员工奖惩信息(导出本页在前端完成)
	ENDPOINT_INFO(downloadRewardAndPunish) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("rewardandpunish.download.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 添加其他查询参数	
		info->queryParams.add<String>("PIMPERSONID").description = ZH_WORDS_GETTER("rewardandpunish.PIMPERSONID");
		info->queryParams["PIMPERSONID"].addExample("default", String("0000-QWDE"));
	}
	ENDPOINT(API_M_POST, "/rewardandpunish", downloadRewardAndPunish, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, RewardAndPunishDownloadQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execDownloadRewardAndPunish(query));
	}
private: // 定义接口执行函数
	RewardAndPunishJsonVO::Wrapper execQueryRewardAndPunish(const RewardAndPunishViewQuery::Wrapper& query);
	Uint64JsonVO::Wrapper execModifyRewardAndPunish(const RewardAndPunishDTO::Wrapper& dto);
	StringJsonVO::Wrapper execDownloadRewardAndPunish(const RewardAndPunishDownloadQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif