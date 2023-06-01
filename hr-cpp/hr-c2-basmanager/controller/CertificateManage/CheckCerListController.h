#pragma once

#ifndef _CHECK_CER_CONTROLLER_
#define _CHECK_CER_CONTROLLER_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/CertificateManage/CheckCerListQuery.h"
#include "domain/dto/CertificateManage/CheckCerListDTO.h"
#include "domain/vo/CertificateManage/CheckCerListVO.h"
/*下述暂未用到*/
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
* 分页查询证书列表--(证书管理-分页查询证书列表)--pine
 */
class CheckCerListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(CheckCerListController);

public://  定义接口（定义接口描述与接口端点）
	// 3定义新增接口描述
	ENDPOINT_INFO(queryCheckCerList) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("cermanage.get.checklist");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(CheckCerListPageJsonVO);
		//定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		//添加其他查询参数，required表示是否必须
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("cermanage.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;
		info->queryParams.add<String>("sex").description = ZH_WORDS_GETTER("cermanage.field.sex");
		info->queryParams["sex"].addExample("default", String("N"));
		info->queryParams["sex"].required = false;
	}
	//4 定义新增接口处理
	ENDPOINT(API_M_GET, "/bas/query-CerList", queryCheckCerList, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, CheckCerListQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryCheckCerList(query));
	}

private://定义执行函数
	// 分页查询数据
	CheckCerListPageJsonVO::Wrapper execQueryCheckCerList(const PageQuery::Wrapper& query);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController)
#endif // _CheckCerList_CONTROLLER_