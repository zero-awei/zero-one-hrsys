#pragma once
#ifndef _UPDATELEGALERSETINGMESSAGE_CONTROLLER_
#define _UPDATELEGALERSETINGMESSAGE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/do/LegalEntitySet/UpdateLegalerSetingMessageDO.h"
#include "domain/dto/LegalEntitySet/UpdateLegalerSetingMessageDTO.h"
#include "domain/vo/LegalEntitySet/UpdateLegalerSetingMessageVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "ApiHelper.h"
using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

class UpdateLegalerSetingMessageController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(UpdateLegalerSetingMessageController); // 2 定义控制器访问入口
public:
	// 3.1 定义修改接口描述
	ENDPOINT_INFO(modifyUpdateLegalerSetingMessage) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("EmpInfo.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/org/update-LegalEntitySet", modifyUpdateLegalerSetingMessage, BODY_DTO(UpdateLegalerSetingMessageDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyUpdateLegalerSetingMessage(dto));
	}
private:
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyUpdateLegalerSetingMessage(const UpdateLegalerSetingMessageDTO::Wrapper& dto);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _UPDATELEGALERSETINGMESSAGE_CONTROLLER_