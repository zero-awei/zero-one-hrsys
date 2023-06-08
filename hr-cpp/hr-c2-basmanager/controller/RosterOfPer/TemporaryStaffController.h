#pragma once
/**
 * 挂职人员信息查询--(人员花名册-挂职人员-分页查询员工列表)--weixiaoman
 */

#ifndef _TEMPORARYSTAFFCONTROLLER_H_
#define _TEMPORARYSTAFFCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/RosterOfPer/TemporaryStaffQuery.h"
#include "domain/dto/RosterOfPer/TemporaryStaffDTO.h"
#include "domain/vo/RosterOfPer/TemporaryStaffVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * 挂职人员功能控制器
 */
class TempStaffController : public oatpp::web::server::api::ApiController 
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(TempStaffController);

	// 定义接口
public:
	// 定义查询接口描述
	ENDPOINT_INFO(queryTempStaff) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("TempStaff.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(TemporaryStaffPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("idandname").description = ZH_WORDS_GETTER("TempStaff.field.idandname");
		info->queryParams["idandname"].addExample("default", String(""));
		//info->queryParams["idandname"].required = false;
		//info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("TempStaff.field.id");
		//info->queryParams["id"].addExample("default", String(""));
		//info->queryParams["id"].required = false;
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/bas/query-tempstaff", queryTempStaff, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, TempStaffQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryTempstaff(userQuery, authObject->getPayload()));
	}

	// 导出功能
	ENDPOINT_INFO(queryExportTempStaff) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("TempStaff.export.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//定义分页参数
		//info->queryParams.add<UInt64>("pageIndex").description = API_PAGE_INDEX_DESC; 
		//info->queryParams["pageIndex"].addExample("default", oatpp::UInt64(1)); 
		//info->queryParams.add<UInt64>("pageSize").description = API_PAGE_SIZE_DESC; 
		//info->queryParams["pageSize"].addExample("default", oatpp::UInt64(10));
		// 定义其他表单参数描述
		info->queryParams.add<String>("idandname").description = ZH_WORDS_GETTER("TempStaff.field.idandname");
		info->queryParams["idandname"].addExample("default", String(""));
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/bas/get-tempstaff", queryExportTempStaff, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, TempStaffQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execExportTempstaff(userQuery, authObject->getPayload()));
	}
private:
	// 挂职人员分页查询数据
	TemporaryStaffPageJsonVO::Wrapper execQueryTempstaff(const TempStaffQuery::Wrapper& query, const PayloadDTO& payload);
	// 导出挂职人员数据
	StringJsonVO::Wrapper execExportTempstaff(const TempStaffQuery::Wrapper& query, const PayloadDTO& payload);
};

// 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _TEMPORARYSTAFFCONTROLLER_H_