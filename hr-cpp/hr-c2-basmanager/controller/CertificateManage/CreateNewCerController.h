#pragma once
#ifndef _CREATE_NEW_CER_CONTROLLER_
#define _CREATE_NEW_CER_CONTROLLER_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/CertificateManage/CreateNewCerQuery.h"
#include "domain/dto/CertificateManage/CreateNewCerDTO.h"
#include "domain/vo/CertificateManage/CreateNewCerVO.h"
/*下述暂未用到*/
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;
// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
  新建证书--(证书管理-新建证书)--pine
 */
class CreateNewCerController : public oatpp::web::server::api::ApiController // 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(CreateNewCerController);

public: // 定义接口（定义接口描述与接口端点）
        // 定义新增接口描述
	ENDPOINT_INFO(addNewCer) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("cermanage.post.addcer");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	    // 定义新增接口处理
	ENDPOINT(API_M_POST, "/bas/add-CreateNewCer", addNewCer, BODY_DTO(CreateNewCerDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddNewCer(dto));
	}

private:// 定义执行函数
	// 执行新增数据
	Uint64JsonVO::Wrapper execAddNewCer(const CreateNewCerDTO::Wrapper& dto);

};

// 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController)
#endif // _CreateNewCer_CONTROLLER_