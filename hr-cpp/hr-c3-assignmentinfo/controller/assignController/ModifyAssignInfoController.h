#ifndef _Modify_Assign_Info_CONTROLLER_
#define _Modify_Assign_Info_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/assignInfo/ModifyAssignInfoDTO.h"
#include "domain/vo/assignInfo/ModifyAssignInfoVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) // 0


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class ModifyAssignInfoController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ModifyAssignInfoController);
	// 3 定义接口
public:
	// 3.1 定义修改接口描述
	ENDPOINT_INFO(modifyAssignInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("employee.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/modify-assignInfo", modifyAssignInfo, BODY_DTO(ModifyAssignInfoDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyAssignInfo(dto));
	}

private:
	//// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyAssignInfo(const ModifyAssignInfoDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_Modify_Assign_Info_CONTROLLER_