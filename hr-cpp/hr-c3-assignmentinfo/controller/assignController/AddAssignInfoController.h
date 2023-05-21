#pragma once
#ifndef _Add_Assign_CONTROLLER_
#define _Add_Assign_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/dto/assignInfo/AddAssignInfoDTO.h"
#include "domain/vo/assignInfo/AddAssignInfoVO.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class AddAssignInfoController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(AddAssignInfoController);
	// 3 定义接口
public:

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addAssignInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("employee.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AddAssignInfoJsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/add-assign", addAssignInfo, BODY_DTO(AddAssignInfoDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddAssignInfo(dto));
	}

private:
	// 3.3 演示新增数据
	AddAssignInfoJsonVO::Wrapper execAddAssignInfo(const AddAssignInfoDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _Add_Assign_CONTROLLER_