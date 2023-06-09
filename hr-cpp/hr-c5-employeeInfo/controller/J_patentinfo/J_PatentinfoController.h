#pragma once

#ifndef _J_PATENTINFOCONTROLLER_H_
#define _J_PATENTINFOCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/vo/J_patentinfo/J_PatentinfoVO.h"
#include "domain/dto/J_patentinfo/J_PatentinfoDTO.h"
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
class J_PatentinfoController : public oatpp::web::server::api::ApiController // 1
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(J_PatentinfoController);
public: // 定义接口






	//查看指定员工专利信息（指定专利信息详情）
	// 3 定义接口描述
	ENDPOINT_INFO(queryPatentinfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("patentInformation.select.summary");
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(J_PatentinfoJsonVO);
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
	//查看指定员工专利信息（指定专利信息详情）
	J_PatentinfoJsonVO::Wrapper execQueryPatentinfo(const String& str);

	//修改指定员工专利信息（单条修改）
	Uint64JsonVO::Wrapper execModifyPatentinfo(const ModifyPatentinfoDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_TESTCONTROLLER_H_