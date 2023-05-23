#pragma once
#ifndef _NOT_EMPLOYEE_IN_ARCHIVE_CONTROLLER_
#define _NOT_EMPLOYEE_IN_ARCHIVE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/NotEmployeeInArchive/NotEmployeeInArchiveQuery.h"
#include "domain/dto/NotEmployeeInArchive/NotEmployeeInArchiveDTO.h"
#include "domain/vo/NotEmployeeInArchive/NotEmployeeInArchiveVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
	非员工在档控制器
*/
class NotEmployeeInArchiveController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(NotEmployeeInArchiveController);
	// 3 定义接口
	public:
		// 3.1 定义查询接口描述
		ENDPOINT_INFO(queryNotEmployeeInArchive) {
			// 定义接口标题
			info->summary = ZH_WORDS_GETTER("archive.get.summary");
			// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
			API_DEF_ADD_AUTH();
			// 定义响应参数格式
			API_DEF_ADD_RSP_JSON_WRAPPER(NotEmployeeInArchivePageJsonVO);
			// 定义分页参数描述
			API_DEF_ADD_PAGE_PARAMS();
		}
		// 3.2 定义查询接口处理
		ENDPOINT(API_M_GET, "/not-employee-in-archive/query-by-pimpersonid", queryNotEmployeeInArchive, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
			// 解析查询参数
			API_HANDLER_QUERY_PARAM(query, NotEmployeeInArchiveQuery, qps);
			// 响应结果
			API_HANDLER_RESP_VO(execQueryNotEmployeeInArchive(query, authObject->getPayload()));
		}
		// 3.1 定义导出接口描述
		ENDPOINT_INFO(exportNotEmployeeInArchive) {
			// 定义接口标题
			info->summary = ZH_WORDS_GETTER("archive.export.summary");
			// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
			API_DEF_ADD_AUTH();
			// 定义响应参数格式
			API_DEF_ADD_RSP_JSON_WRAPPER(NotEmployeeInArchivePageJsonVO);
			// 定义分页参数描述
			API_DEF_ADD_PAGE_PARAMS();
		}
		// 3.2 定义查询接口处理
		ENDPOINT(API_M_GET, "/not-employee-in-archive/export-data", exportNotEmployeeInArchive, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
			// 解析查询参数
			API_HANDLER_QUERY_PARAM(query, NotEmployeeInArchiveQuery, qps);
			// 响应结果
			API_HANDLER_RESP_VO(execQueryNotEmployeeInArchive(query, authObject->getPayload()));
		}
		// 3.1 定义修改接口描述
		ENDPOINT_INFO(modifyNotEmployeeInArchive) {
			// 定义接口标题
			info->summary = ZH_WORDS_GETTER("archive.put.summary");
			// 定义响应参数格式
			API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		}
		// 3.2 定义修改接口处理
		ENDPOINT(API_M_PUT, "/not-employee-in-archive/modify-pimpersonid", modifyNotEmployeeInArchive, BODY_DTO(NotEmployeeInArchiveDTO::Wrapper, dto)) {
			// 响应结果
			API_HANDLER_RESP_VO(execModifyNotEmployeeInArchive(dto));
		}

private:
	// 3.3 分页查询数据
	NotEmployeeInArchivePageJsonVO::Wrapper execQueryNotEmployeeInArchive(const NotEmployeeInArchiveQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 修改数据
	Uint64JsonVO::Wrapper execModifyNotEmployeeInArchive(const NotEmployeeInArchiveDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _NOT_EMPLOYEE_IN_ARCHIVE_CONTROLLER_