#pragma once
#ifndef _WORKHISTORY_CONTROLLER_H_
#define _WORKHISTORY_CONTROLLER_H_
#include "stdafx.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/work-history/WorkHistoryQuery.h"
#include "domain/dto/work-history/ModWorkHistoryDTO.h"
#include "domain/vo/work-history/ModWorkHistoryVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * 示例控制器，演示基础接口的使用
 */
class WorkHistoryController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(WorkHistoryController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryWorkHistory) {
		// 定义接口标题,用到中英文字典函数，用过zh-dict.yaml确定参数
		info->summary = ZH_WORDS_GETTER("sample.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(WorkHistoryJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		//传递任职开始时间
		info->queryParams.add<String>("rzkssj").description = ZH_WORDS_GETTER("workhistory.field.rzkssj");
		//传递任职结束时间
		info->queryParams.add<String>("rzjssj").description = ZH_WORDS_GETTER("workhistory.field.rzjssj");
		//传递工作单位
		info->queryParams.add<String>("ormorgname").description = ZH_WORDS_GETTER("workhistory.field.ormorgname");
		//传递职务
		info->queryParams.add<String>("ormdutyname").description = ZH_WORDS_GETTER("workhistory.field.ormdutyname");
		//传递岗位
		info->queryParams.add<String>("ormpostname").description = ZH_WORDS_GETTER("workhistory.field.ormpostname");
		//传递兼职借调类型
		info->queryParams.add<String>("cfplx").description = ZH_WORDS_GETTER("workhistory.field.cfplx");
		//传递是否主要经历
		info->queryParams.add<String>("enable").description = ZH_WORDS_GETTER("workhistory.field.enable");
		
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/work-history", queryWorkHistory, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, WorkHistoryQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryWorkHistory(userQuery, authObject->getPayload()));
	}
	// 3.1 定义修改接口描述
	ENDPOINT_INFO(modifyWorkHistory) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("sample.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/work-history", modifyWorkHistory, BODY_DTO(WorkHistoryDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyWorkHistory(dto));
	}
private:	
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyWorkHistory(const WorkHistoryDTO::Wrapper& dto);	
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !
