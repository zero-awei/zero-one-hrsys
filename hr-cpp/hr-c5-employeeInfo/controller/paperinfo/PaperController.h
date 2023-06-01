#pragma once

#ifndef _PAPERINFO_H_
#define _PAPERINFO_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"

#include "domain/query/paperinfo/PaperQuery.h"
#include "domain/vo/paperinfo/PaperVO.h"
#include "domain/dto/paperinfo/PaperDTO.h"
#include "domain/dto/paperinfo/PaperinfoDTO.h"


#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * 测试控制器
 */
class PaperController : public oatpp::web::server::api::ApiController // 1
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(PaperController);
public: // 定义接口

	//查看指定员工论文信息（指定论文信息详情）
	// 3 定义接口描述
	ENDPOINT_INFO(selectPaperinfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("paperInformation.select.summary");
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(PaperinfoJsonVO);
		//专利信息编码
		info->queryParams.add<String>("pimpaperid").description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpaperid");
		info->queryParams["pimpaperid"].addExample("default", String("123456789"));
		info->queryParams["pimpaperid"].required = true;
	}
	// 4 定义接口端点
	ENDPOINT(API_M_GET, "/employee-info/select-by-pimpaperid", selectPaperinfo, QUERY(String, pimpaperid)) {
		// 响应结果
		API_HANDLER_RESP_VO(execSelectByPimpaperid(pimpaperid));
	}



	// 3.1 定义修改接口描述
	ENDPOINT_INFO(modifyPaperinfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("patentInformation.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/employee-info/modify-by-pimpaperid", modifyPaperinfo, BODY_DTO(PaperinfoDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyByPimpaperid(dto));
	}


private: // 定义接口执行函数

	//查看指定员工论文信息（指定论文信息详情）
	PaperinfoJsonVO::Wrapper execSelectByPimpaperid(const String& str);

	//修改指定员工论文信息（单条修改）
	Uint64JsonVO::Wrapper execModifyByPimpaperid(const PaperinfoDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_PAPERINFOCONTROLLER_H_