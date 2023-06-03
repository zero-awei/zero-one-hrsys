#pragma once

#ifndef _PATENTINFOCONTROLLER_H_
#define _PATENTINFOCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/patentinfo/PatentinfoQuery.h"
#include "domain/vo/patentinfo/PatentinfoVO.h"
#include "domain/dto/patentinfo/PatentinfoDTO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * 测试控制器
 */
class PatentinfoController : public oatpp::web::server::api::ApiController // 1
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(PatentinfoController);
public: // 定义接口






	//查看指定员工专利信息（指定专利信息详情）
	// 3 定义接口描述
	ENDPOINT_INFO(queryPatentinfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("patentInformation.select.summary");
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(PatentinfoJsonVO);
		//专利信息编码
		info->queryParams.add<String>("pimpatentid").description = ZH_WORDS_GETTER("patentInformation.pimpatent.pimpatentid");
		info->queryParams["pimpatentid"].addExample("default", String("E436974B-BA1A-4478-8716-6F1DC15ADFC8"));
		info->queryParams["pimpatentid"].required = true;
	}
	// 4 定义接口端点
	ENDPOINT(API_M_GET, "/employee-info/query-by-pimpatentid", queryPatentinfo, QUERY(String, pimpatentid)) {
		// 响应结果
		API_HANDLER_RESP_VO(execQueryPatentinfo(pimpatentid));
	}

	// 3.1 定义查询接口描述
	ENDPOINT_INFO(patentinfoQuery) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("patentInformation.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PatentinfoPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		// 专利号
		info->queryParams.add<String>("ZLH").description = ZH_WORDS_GETTER("patentInformation.field.ZLH");
		info->queryParams["ZLH"].addExample("default", String("123456789"));
		
	}

	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/employee-info/Page-patentinfo", patentinfoQuery, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(query, PatentinfoQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryPagePatent(query));
	}

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addPatent) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("patentInformation.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/employee-info/add-patentinfo", addPatent, BODY_DTO(PatentinfoDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddPatent(dto));
	}

	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removePatent) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("patentInformation.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义删除接口处理
	ENDPOINT(API_M_DEL, "/employee-info/remove-patentinfo", removePatent, BODY_DTO(PatentinfoDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemovePatent(dto));
	}

	// 3.1 定义修改接口描述
	ENDPOINT_INFO(modifySample) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("patentInformation.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/employee-info/modify-patentinfo", modifySample, BODY_DTO(ModifyPatentinfoDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyPatentinfo(dto));
	}


private: // 定义接口执行函数
	//分页查看指定员工专利信息（分页查询列表）
	PatentinfoPageJsonVO::Wrapper execQueryPagePatent(const PatentinfoQuery::Wrapper& query);

	//新增指定员工专利信息（单条新增）
	Uint64JsonVO::Wrapper execAddPatent(const PatentinfoDTO::Wrapper& dto);

	//删除指定员工专利信息（支持批量删除）
	Uint64JsonVO::Wrapper execRemovePatent(const PatentinfoDTO::Wrapper& dto);

	//查看指定员工专利信息（指定专利信息详情）
	PatentinfoJsonVO::Wrapper execQueryPatentinfo(const String& str);

	//修改指定员工专利信息（单条修改）
	Uint64JsonVO::Wrapper execModifyPatentinfo(const ModifyPatentinfoDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_TESTCONTROLLER_H_