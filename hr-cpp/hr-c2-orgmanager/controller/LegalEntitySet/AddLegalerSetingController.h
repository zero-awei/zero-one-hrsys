#pragma once

/*
*（	数据设置——法人主体设置——导出法人主体设置 (导出页面在前端完成) --cpt
*/

#ifndef _ADDTLEGALERSETING_CONTROLLER_
#define _ADDTLEGALERSETING_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/do/LegalEntitySet/AddLegalerSetingDO.h"
#include "domain/dto/LegalEntitySet/AddLegalerSetingDTO.h"
#include "domain/vo/LegalEntitySet/AddLegalerSetingVO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "ApiHelper.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class AddLegalerSetingController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(AddLegalerSetingController); // 2 定义控制器访问入口
public:

	ENDPOINT_INFO(addAddLegalerSeting) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/org/add-LegalerSeting", addAddLegalerSeting, BODY_DTO(AddLegalerSetingDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddAddLegalerSeting(dto));
	}
private:
	Uint64JsonVO::Wrapper execAddAddLegalerSeting(const AddLegalerSetingDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _ADDLEGALERSETING_CONTROLLER_

