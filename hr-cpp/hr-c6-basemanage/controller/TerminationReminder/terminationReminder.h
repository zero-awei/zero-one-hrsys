#pragma once
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/PageQuery.h"
#include "../../../arch-demo/Macros.h"
#include "ServerInfo.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/vo/TerminationReminderVO/TerminationReminderVO.h"
#include "domain/query/TerminationReminder/TerminationReminderQuery.h"
#include "domain/dto/TerminationReminderDTO/TerminationReminderDTO.h"
#include "service/TerminationReminder/TerminationReminderService.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

//using namespace oatpp;
//namespace multipart = oatpp::web::mime::multipart;
class TerminationReminderController :public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(TerminationReminderController);
public:
	//定义接口描述——分页查询
	ENDPOINT_INFO(queryLimit) {
		//定义接口标题
		info->summary = ZH_WORDS_GETTER("reminder.name.contract_termination_reminder");
		//定义响应参数类型——+string
		API_DEF_ADD_RSP_JSON_WRAPPER(TerminationReminderPageJsonVO);
		//定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		//增加字段
		info->queryParams.add<String>("employee_id").description = ZH_WORDS_GETTER("reminder.condition.employee_id");
		info->queryParams["employee_id"].required = false;

		info->queryParams.add<String>("employee_name").description = ZH_WORDS_GETTER("reminder.condition.employee_name");
		info->queryParams["employee_name"].required = false;

		info->queryParams.add<String>("employee_statu").description = ZH_WORDS_GETTER("reminder.condition.employee_status");
		info->queryParams["employee_statu"].required = false;

		info->queryParams.add<String>("contract_id").description = ZH_WORDS_GETTER("reminder.condition.contract_id");
		info->queryParams["contract_id"].required = false;

		info->queryParams.add<String>("contract_lb").description = ZH_WORDS_GETTER("reminder.condition.contract_lb");
		info->queryParams["contract_lb"].required = false;

		info->queryParams.add<String>("contract_statu").description = ZH_WORDS_GETTER("reminder.condition.contract_status");
		info->queryParams["contract_statu"].required = false;

		info->queryParams.add<String>("begin_time").description = ZH_WORDS_GETTER("reminder.condition.begin_time");
		info->queryParams["begin_time"].required = false;

		info->queryParams.add<String>("deadline").description = ZH_WORDS_GETTER("reminder.condition.deadline");
		info->queryParams["deadline"].required = false;

		info->queryParams.add<String>("contract_lx").description = ZH_WORDS_GETTER("reminder.condition.contract_lx");
		info->queryParams["contract_lx"].required = false;
	}
	//定义接口端点
	ENDPOINT(API_M_GET, "/contract-management/reminder-query-contract", queryLimit, QUERIES(QueryParams, qps)) {
		//解析查询参参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, TerminationReminderQuery, qps);
		//响应结果
		API_HANDLER_RESP_VO(execQueryLimit(query));
	}
	//导出全部
	ENDPOINT_INFO(ExportContract) {
		//定义接口标题
		info->summary = ZH_WORDS_GETTER("reminder.name.export_all");
		//定义响应参数类型——链接
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//增加字段
		info->queryParams.add<String>("employee_id").description = ZH_WORDS_GETTER("reminder.condition.employee_id");
		info->queryParams["employee_id"].required = false;

		info->queryParams.add<String>("employee_name").description = ZH_WORDS_GETTER("reminder.condition.employee_name");
		info->queryParams["employee_name"].required = false;

		info->queryParams.add<String>("employee_statu").description = ZH_WORDS_GETTER("reminder.condition.employee_status");
		info->queryParams["employee_statu"].required = false;

		info->queryParams.add<String>("contract_id").description = ZH_WORDS_GETTER("reminder.condition.contract_id");
		info->queryParams["contract_id"].required = false;

		info->queryParams.add<String>("contract_lb").description = ZH_WORDS_GETTER("reminder.condition.contract_lb");
		info->queryParams["contract_lb"].required = false;

		info->queryParams.add<String>("contract_statu").description = ZH_WORDS_GETTER("reminder.condition.contract_status");
		info->queryParams["contract_statu"].required = false;

		info->queryParams.add<String>("begin_time").description = ZH_WORDS_GETTER("reminder.condition.begin_time");
		info->queryParams["begin_time"].required = false;

		info->queryParams.add<String>("deadline").description = ZH_WORDS_GETTER("reminder.condition.deadline");
		info->queryParams["deadline"].required = false;

		info->queryParams.add<String>("contract_lx").description = ZH_WORDS_GETTER("reminder.condition.contract_lx");
		info->queryParams["contract_lx"].required = false;
	}
	ENDPOINT(API_M_GET, "/contract-management/reminder-export-contract", ExportContract, QUERIES(QueryParams, qps)) {
		//解析查询参参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(export_contract, TerminationReminderQuery, qps);
		//响应结果
		API_HANDLER_RESP_VO(execExportAll(export_contract));
	}
private:
	//分页查询的执行接口函数
	TerminationReminderPageJsonVO::Wrapper execQueryLimit(const TerminationReminderQuery::Wrapper& query);
	//全部导出的执行接口函数
	StringJsonVO::Wrapper execExportAll(const TerminationReminderQuery::Wrapper& query);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen