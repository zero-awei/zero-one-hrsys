#pragma once
/*
* 法人主体设置--删除法人设置(支持批量删除)--pine
*/
#ifndef _DELETE_LEGAL_ENTITY_CONTROLLER_
#define _DELETE_LEGAL_ENTITY_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "domain/dto/LegalEntitySet/DeleteLegalEntityDTO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) 

class DeleteLegalEntityController : public oatpp::web::server::api::ApiController // 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(DeleteLegalEntityController);
	// 定义接口
public:

	// 定义删除接口描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("LegalEntitySet.delete.summary"), removeLES, StringJsonVO);
	// 定义删除接口处理
	ENDPOINT(API_M_DEL, "/org/remove-LES", removeLES, BODY_DTO(DeleteLegalEntityDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execDeleteLegalEntity(dto));
	}
private:
	// 演示删除数据
	StringJsonVO::Wrapper execDeleteLegalEntity(const DeleteLegalEntityDTO::Wrapper& dto);
};

// 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) 
#endif // _CERTIFIDELETE_CONTROLLER_