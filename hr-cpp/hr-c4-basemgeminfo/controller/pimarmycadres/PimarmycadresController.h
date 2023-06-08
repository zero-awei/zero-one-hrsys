#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/20 11:40:01

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _PIMARMYCADRESCONTROLLER_H_
#define _PIMARMYCADRESCONTROLLER_H_


#include "domain/vo/BaseJsonVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/query/pimarmycadres/PimarmycadresPageQuery.h"
#include "domain/vo/pimarmycadres/PimarmycadresVO.h"
#include "domain/dto/pimarmycadres/AddPimarmycadresDTO.h"
#include "domain/dto/pimarmycadres/DelPimarmycadresDTO.h"
#include "oatpp-swagger/Model.hpp"
#include "oatpp-swagger/Types.hpp"
#include <openssl/md5.h>
#include <boost/throw_exception.hpp>
#include <boost/throw_exception.hpp>

#include "ServerInfo.h"

#include "domain/query/pimarmycadres/PimarmycadresQuery.h"
//#include "domain/dto/Pimarmycadres/ModPimarmycadresDTO.h"
//#include "domain/vo/Pimarmycadres/ModPimarmycadresVO.h"
#include "domain/vo/pimarmycadres/PimarmycadresVO.h"
#include "domain/dto/pimarmycadres/PimarmycadresIntoDTO.h"


using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

class PimarmycadresController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(PimarmycadresController);
public: // 定义接口
	//  定义查询接口描述
	ENDPOINT_INFO(queryPimarmycadres) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("pimarmycadres.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PimarmycadresFindVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("pimid").description = ZH_WORDS_GETTER("pimarmycadres.field.pimid");
		info->queryParams["pimid"].addExample("default", String("6611212223"));
		info->queryParams["pimid"].required = false;
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/pimarmycadres/select", queryPimarmycadres, QUERIES(QueryParams, qps)) {
		//解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, PimarmycadresPageQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryPimarmycadres(query));
		
		
		//PimarmycadresFindVO::Wrapper execQueryPimarmycadres(const PimarmycadresPageQuery::Wrapper & query);
	}

	// 定义新增接口描述
	ENDPOINT_INFO(addPimarmycadres) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("pimarmycadres.post.summary");
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义新增接口处理
	ENDPOINT(API_M_POST, "/pimarmycadres/add", addPimarmycadres, API_HANDLER_AUTH_PARAME, BODY_DTO(AddPimarmycadresDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddPimarmycadres(dto, authObject->getPayload()));
	}

	// 定义批量删除接口描述
	ENDPOINT_INFO(delPimarmycadres) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("pimarmycadres.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义批量删除接口处理
	ENDPOINT(API_M_POST, "/pimarmycadres/delete", delPimarmycadres, BODY_DTO(DelPimarmycadresDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execDelPimarmycadres(dto));
	}

	// 定义一个单文件导入接口
	ENDPOINT_INFO(postFile) {
		API_DEF_ADD_AUTH();
		info->summary = ZH_WORDS_GETTER("pimarmycadres.file.summary");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("pimarmycadres.field.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("1002"));
		/*info->queryParams["suffix"].description = ZH_WORDS_GETTER("pimarmycadres.file.suffix");
		info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));*/
	}
	// 定义文件上传端点处理
	ENDPOINT(API_M_POST, "/pimarmycadres/file", postFile, API_HANDLER_AUTH_PARAME, BODY_STRING(String, body), QUERY(String, suffix), QUERY(String, pimpersonid)) {
		// 执行文件保存逻辑
		API_HANDLER_RESP_VO(execIntoPimarmycadres(body, suffix,pimpersonid,authObject->getPayload()));
	}

private:

	// 定义分页查询执行函数
	PimarmycadresFindVO::Wrapper execQueryPimarmycadres(const PimarmycadresPageQuery::Wrapper& query);

	//定义增加执行函数
	Uint64JsonVO::Wrapper execAddPimarmycadres(const AddPimarmycadresDTO::Wrapper& dto, const PayloadDTO& payload);

	//定义删除执行函数
	Uint64JsonVO::Wrapper execDelPimarmycadres(const DelPimarmycadresDTO::Wrapper& dto);

	//定义导入执行函数
	StringJsonVO::Wrapper execIntoPimarmycadres(const String& body, const String& suffix,const String& pimpersonid, const PayloadDTO& payload);


};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_PIMARMYCADRESCONTROLLER_H_