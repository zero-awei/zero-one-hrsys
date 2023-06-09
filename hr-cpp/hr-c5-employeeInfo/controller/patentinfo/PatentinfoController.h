#pragma once

#ifndef _PATENTINFOCONTROLLER_H_
#define _PATENTINFOCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/patentinfo/PatentinfoQuery.h"
#include "domain/vo/paptentinfo/PatentinfoVO.h"
#include "domain/dto/patentinfo/PatentinfoDTO.h"
#include "domain/dto/patentinfo/DelPatentDTO.h"
#include "domain/dto/patentinfo/AddPatentDTO.h"
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
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removePatent) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("patentInformation.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义删除接口处理
	ENDPOINT(API_M_DEL, "/employee-info/remove-patentinfo", removePatent, BODY_DTO(List<String>, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemovePatent(dto));
	}



private: // 定义接口执行函数
	////分页查看指定员工专利信息（分页查询列表）
	//PatentinfoPageJsonVO::Wrapper execQueryPagePatent(const PatentinfoQuery::Wrapper& query);

	////新增指定员工专利信息（单条新增）
	//Uint64JsonVO::Wrapper execAddPatent(const AddPatentDTO::Wrapper& dto);

	//删除指定员工专利信息（支持批量删除）
	Uint64JsonVO::Wrapper execRemovePatent(const List<String>& dto);



};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_TESTCONTROLLER_H_