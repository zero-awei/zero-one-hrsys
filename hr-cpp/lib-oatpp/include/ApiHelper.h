#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/30 16:07:52

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
#ifndef _API_HELPER_
#define _API_HELPER_

#include <string>
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"
#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "domain/vo/JsonVO.h"
#include "domain/dto/PageDTO.h"
#include "CustomerAuthorizeHandler.h"
#include "URIUtil.h"
using namespace std;
using namespace oatpp::web::protocol::http;

/**
 * 绑定控制器
 * @param __DOC__: doc端点对象指针
 * @param __ROUTER__: router对象指针
 * @param __CLASS__: controller类名称
 */
#define BIND_CONTROLLER(__DOC__, __ROUTER__, __CLASS__) \
__DOC__->append(__ROUTER__->addController(__CLASS__::createShared())->getEndpoints())

/**
* 控制器类访问定义，用于绑定授权处理器和类创建入口函数
* @param __CLASS__: controller类名称
*/
#define API_ACCESS_DECLARE(__CLASS__) \
public: \
__CLASS__(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper) { \
	setDefaultAuthorizationHandler(std::make_shared<CustomerAuthorizeHandler>()); \
} \
static std::shared_ptr<__CLASS__> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) { \
	return std::make_shared<__CLASS__>(objectMapper); \
}

// 获取数据请求
#define API_M_GET  "GET";
// 新增数据请求
#define API_M_POST "POST";
// 修改数据请求
#define API_M_PUT  "PUT";
// 删除数据请求
#define API_M_DEL  "DELETE";

////////////////////////////////////////////////////////////////////////// 

// API描述添加安全验证
#define API_DEF_ADD_AUTH() info->addSecurityRequirement("bearer_auth")

/**
 * API描述添加响应数据
 * @param __RESP_TYPE__: 响应数据类型，如：oatpp::Object<JsonVO<X>>
 */
#define API_DEF_ADD_RSP_JSON(__RESP_TYPE__) info->addResponse<__RESP_TYPE__>(Status::CODE_200, "application/json")

/**
* API描述添加响应数据，用oatpp::Object包装泛型
* @param __RESP_TYPE__: 响应数据类型，如：JsonVO<X>
*/
#define API_DEF_ADD_RSP_JSON_WRAPPER(__RESP_TYPE__) API_DEF_ADD_RSP_JSON(oatpp::Object<__RESP_TYPE__>)

// 处理跨平台描述信息中文乱码问题
#ifndef LINUX
#define API_PAGE_INDEX_DESC u8"查询页码"
#define API_PAGE_SIZE_DESC u8"查询条数"
#else
#define API_PAGE_INDEX_DESC "page index"
#define API_PAGE_SIZE_DESC "page size"
#endif
// API描述添加分页参数说明
#define API_DEF_ADD_PAGE_PARAMS() \
info->queryParams.add<UInt64>("pageIndex").description = API_PAGE_INDEX_DESC;\
info->queryParams["pageIndex"].addExample("default", oatpp::UInt64(1)); \
info->queryParams.add<UInt64>("pageSize").description = API_PAGE_SIZE_DESC; \
info->queryParams["pageSize"].addExample("default", oatpp::UInt64(10));

/**
 * API描述定义
 * @param __API_FUN_NAME__: Api端点名称
 * @param __RESP_TYPE__: 响应数据类型如：oatpp::Object<JsonVO<X>>
 * @param __TITLE__: Api描述标题
 */
#define API_DEF_DESCRIPTION(__API_FUN_NAME__,__TITLE__,__RESP_TYPE__) \
ENDPOINT_INFO(__API_FUN_NAME__) { \
	info->summary = __TITLE__; \
	API_DEF_ADD_AUTH(); \
	API_DEF_ADD_RSP_JSON(__RESP_TYPE__); \
}

//////////////////////////////////////////////////////////////////////////

// 接口处理器分页参数获取定义
#define API_HANDLER_PAGE_PARAME \
QUERY(UInt64, pageIndex), \
QUERY(UInt64, pageSize)

// 接口处理器授权参数获取定义
#define API_HANDLER_AUTH_PARAME \
AUTHORIZATION(std::shared_ptr<CustomerAuthorizeObject>, authObject)

 /**
  * 接口处理器解析查询参数到查询数据对象
  * @param __VAR__: 转换后的变量名称，如query
  * @param __TYPE__: 查询数据对象类型，如XxxQuery
  * @param __PARAMS__: QueryParams的变量名称，如：QUERIES(QueryParams, queryParams),则传入queryParams
  */
#define API_HANDLER_QUERY_PARAM(__VAR__, __TYPE__, __PARAMS__) \
auto __VAR__ = __TYPE__::createShared(); \
for (auto& param : __PARAMS__.getAll()) { \
	auto data = param.second.getMemoryHandle().get(); \
	auto typeval = __VAR__[param.first.toString()].getValueType(); \
	if (typeval == oatpp::data::mapping::type::__class::String::getType())\
		__VAR__[param.first.toString()] = oatpp::String(URIUtil::urlDecode(data->c_str())); \
	else if (typeval == oatpp::data::mapping::type::__class::Int32::getType())\
		__VAR__[param.first.toString()] = oatpp::Int32(stoi(*data)); \
	else if (typeval == oatpp::data::mapping::type::__class::UInt32::getType())\
		__VAR__[param.first.toString()] = oatpp::UInt32(stoi(*data)); \
	else if (typeval == oatpp::data::mapping::type::__class::Int64::getType())\
		__VAR__[param.first.toString()] = oatpp::Int64(stoll(*data)); \
	else if (typeval == oatpp::data::mapping::type::__class::UInt64::getType())\
		__VAR__[param.first.toString()] = oatpp::UInt64(stoull(*data)); \
	else if (typeval == oatpp::data::mapping::type::__class::Float32::getType())\
		__VAR__[param.first.toString()] = oatpp::Float32(stof(*data)); \
	else if (typeval == oatpp::data::mapping::type::__class::Float64::getType())\
		__VAR__[param.first.toString()] = oatpp::Float64(stod(*data)); \
	else if (typeval == oatpp::data::mapping::type::__class::Boolean::getType())\
		__VAR__[param.first.toString()] = oatpp::Boolean(*data == "true" || stoi(*data) == 1); \
}

/**
 * 接口处理器响应VO数据
 * @param __VO__: 响应数据对象
 */
#define API_HANDLER_RESP_VO(__VO__) return createDtoResponse(Status::CODE_200, __VO__)

/**
* 接口处理器响应VO数据，用oatpp::Object包装泛型
* @param __VO__: 响应数据对象
*/
#define API_HANDLER_RESP_VO_WRAPPER(__VO__) API_HANDLER_RESP_VO(oatpp::Object<__VO__>)

#endif // !_API_HELPER_