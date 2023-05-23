#pragma once
#ifndef _Delete_Assign_Info_CONTROLLER_
#define _Delete_Assign_Info_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/assignInfo/DeleteAssignInfoDTO.h"
#include "domain/vo/assignInfo/DeleteAssignInfoVO.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class DeleteAssignInfoController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(DeleteAssignInfoController);
	// 3 定义接口
public:
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(deleteAssignInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("employee.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义删除接口处理
	ENDPOINT(API_M_DEL, "/delete-assignInfo", deleteAssignInfo, BODY_DTO(DeleteAssignInfoDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execDeleteAssignInfo(dto));
	}
private:
	// 3.3 演示删除数据
	Uint64JsonVO::Wrapper execDeleteAssignInfo(const DeleteAssignInfoDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_Delete_Assign_Info_CONTROLLER_