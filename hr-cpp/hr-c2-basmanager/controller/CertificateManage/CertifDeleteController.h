#pragma once
/*
（证书管理-证书信息-删除证书（支持批量删除））--洛洛
*/
#ifndef _CERTIFIDELETE_CONTROLLER_
#define _CERTIFIDELETE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "domain/dto/CertificateManage/RemoveCertifDTO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class CertifDeleteController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(CertifDeleteController);
	// 定义接口
public:

	// 定义删除接口描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("certif.delete.summary"), removeCertif, StringJsonVO);
	// 定义删除接口处理
	ENDPOINT(API_M_DEL, "/bas/remove-certif", removeCertif, BODY_DTO(RemoveCertifDTO::Wrapper, dto)) {
	 // 响应结果
	 API_HANDLER_RESP_VO(execRemoveCertif(dto));
	}
private:
	// 演示删除数据
	StringJsonVO::Wrapper execRemoveCertif(const RemoveCertifDTO::Wrapper& dto);
};

// 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _CERTIFIDELETE_CONTROLLER_