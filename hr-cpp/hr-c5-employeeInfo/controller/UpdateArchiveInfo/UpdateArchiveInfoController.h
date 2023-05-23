#pragma once
#pragma once
#ifndef _UPDATE_ARCHIVE_INFO_CONTROLLER_
#define _UPDATE_ARCHIVE_INFO_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/UpdateArchiveInfo/UpdateArchiveInfoDTO.h"
#include "domain/vo/UpdateArchiveInfo/UpdateArchiveInfoVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
	更新指定档案控制器
*/
class UpdateArchiveInfoController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(UpdateArchiveInfoController);
	// 3 定义接口
public:
	// 3.1 定义修改接口描述
	ENDPOINT_INFO(updateArchiveInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("archive.update.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/update-archive-info", updateArchiveInfo, BODY_DTO(UpdateArchiveInfoDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execUpdateArchiveInfo(dto));
	}

private:
	// 3.3 修改数据
	Uint64JsonVO::Wrapper execUpdateArchiveInfo(const UpdateArchiveInfoDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_UPDATE_ARCHIVE_INFO_CONTROLLER__