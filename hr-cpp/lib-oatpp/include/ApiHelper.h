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
 * �󶨿�����
 * @param __DOC__: doc�˵����ָ��
 * @param __ROUTER__: router����ָ��
 * @param __CLASS__: controller������
 */
#define BIND_CONTROLLER(__DOC__, __ROUTER__, __CLASS__) \
__DOC__->append(__ROUTER__->addController(__CLASS__::createShared())->getEndpoints())

 /**
 * ����������ʶ��壬���ڰ���Ȩ���������ഴ����ں���
 * @param __CLASS__: controller������
 */
#define API_ACCESS_DECLARE(__CLASS__) \
public: \
__CLASS__(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper) { \
	setDefaultAuthorizationHandler(std::make_shared<CustomerAuthorizeHandler>()); \
} \
static std::shared_ptr<__CLASS__> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) { \
	return std::make_shared<__CLASS__>(objectMapper); \
}

 // ��ȡ��������
#define API_M_GET  "GET";
// ������������
#define API_M_POST "POST";
// �޸���������
#define API_M_PUT  "PUT";
// ɾ����������
#define API_M_DEL  "DELETE";

//////////////////////////////////////////////////////////////////////////

// API�������ӱ���
#define API_DEF_ADD_TITLE(_TITLE_) info->summary = _TITLE_

// API�������Ӱ�ȫ��֤
#define API_DEF_ADD_AUTH() info->addSecurityRequirement("bearer_auth")

/**
 * API����������Ӧ����
 * @param __RESP_TYPE__: ��Ӧ�������ͣ��磺oatpp::Object<JsonVO<X>>
 */
#define API_DEF_ADD_RSP_JSON(__RESP_TYPE__) info->addResponse<__RESP_TYPE__>(Status::CODE_200, "application/json")

 /**
 * API����������Ӧ���ݣ���oatpp::Object��װ����
 * @param __RESP_TYPE__: ��Ӧ�������ͣ��磺JsonVO<X>
 */
#define API_DEF_ADD_RSP_JSON_WRAPPER(__RESP_TYPE__) API_DEF_ADD_RSP_JSON(oatpp::Object<__RESP_TYPE__>)

 /**
  * API��������ͨ�ò�������
  * @param _TITLE_: �ӿڱ���
  * @param __RESP_TYPE__: �ӿ���Ӧ�������͡��磺"UserPageJsonVO"��"StringJsonVO"
  */
#define API_DEF_ADD_COMMON(_TITLE_, __RESP_TYPE__) \
API_DEF_ADD_TITLE(_TITLE_); \
API_DEF_ADD_RSP_JSON(__RESP_TYPE__::Wrapper)

  /**
  * API��������ͨ�ò������壬�����ʱ��ᶨ����Ȩ����
  * @param _TITLE_: �ӿڱ���
  * @param __RESP_TYPE__: �ӿ���Ӧ�������͡��磺"UserPageJsonVO"��"StringJsonVO"
  */
#define API_DEF_ADD_COMMON_AUTH(_TITLE_, __RESP_TYPE__) \
API_DEF_ADD_TITLE(_TITLE_); \
API_DEF_ADD_AUTH(); \
API_DEF_ADD_RSP_JSON(__RESP_TYPE__::Wrapper)

  // ������ƽ̨������Ϣ������������
#ifndef LINUX
#define API_PAGE_INDEX_DESC u8"��ѯҳ��"
#define API_PAGE_SIZE_DESC u8"��ѯ����"
#else
#define API_PAGE_INDEX_DESC "page index"
#define API_PAGE_SIZE_DESC "page size"
#endif
// API�������ӷ�ҳ����˵��
#define API_DEF_ADD_PAGE_PARAMS() \
info->queryParams.add<UInt64>("pageIndex").description = API_PAGE_INDEX_DESC;\
info->queryParams["pageIndex"].addExample("default", oatpp::UInt64(1)); \
info->queryParams.add<UInt64>("pageSize").description = API_PAGE_SIZE_DESC; \
info->queryParams["pageSize"].addExample("default", oatpp::UInt64(10))

/**
 * API�������Ӳ�ѯ����˵��
 * @param _TYPE_: �ֶ��������͡��磺String��UInt32��
 * @param _FIELD_NAME_: �ֶ����ơ��磺"age"��"sex"
 * @param _DESCRIPTION_: �ֶ�������
 * @param _EXAMPLE_VAL_: ʾ��ֵ���磺"li si"��123
 * @param _REQUIRE_: �Ƿ�ش�������boolֵ���磺true��false
 */
#define API_DEF_ADD_QUERY_PARAMS(_TYPE_, _FIELD_NAME_, _DESCRIPTION_, _EXAMPLE_VAL_, _REQUIRE_) \
info->queryParams.add<_TYPE_>(_FIELD_NAME_).description = _DESCRIPTION_; \
info->queryParams[_FIELD_NAME_].addExample("default", _TYPE_(_EXAMPLE_VAL_)); \
info->queryParams[_FIELD_NAME_].required = _REQUIRE_

 /**
  * API��������
  * @param __TITLE__: Api��������
  * @param __ENDPOINT_FUN_NAME__: Api�˵㺯������
  * @param __RESP_TYPE__: ��Ӧ���������磺XxxJsonVO
  */
#define API_DEF_ENDPOINT_INFO(__TITLE__, __ENDPOINT_FUN_NAME__, __RESP_TYPE__) \
ENDPOINT_INFO(__ENDPOINT_FUN_NAME__) { \
	info->summary = __TITLE__; \
	API_DEF_ADD_RSP_JSON_WRAPPER(__RESP_TYPE__); \
}

  /**
  * API�������壬�����ʱ��������Ȩ����
  * @param __TITLE__: Api��������
  * @param __ENDPOINT_FUN_NAME__: Api�˵㺯������
  * @param __RESP_TYPE__: ��Ӧ���������磺XxxJsonVO
  */
#define API_DEF_ENDPOINT_INFO_AUTH(__TITLE__, __ENDPOINT_FUN_NAME__, __RESP_TYPE__) \
ENDPOINT_INFO(__ENDPOINT_FUN_NAME__) { \
	info->summary = __TITLE__; \
	API_DEF_ADD_AUTH(); \
	API_DEF_ADD_RSP_JSON_WRAPPER(__RESP_TYPE__); \
}

  //////////////////////////////////////////////////////////////////////////

  // �ӿڴ�������ҳ������ȡ����
#define API_HANDLER_PAGE_PARAME \
QUERY(UInt64, pageIndex), \
QUERY(UInt64, pageSize)

// �ӿڴ�������Ȩ������ȡ����
#define API_HANDLER_AUTH_PARAME \
AUTHORIZATION(std::shared_ptr<CustomerAuthorizeObject>, authObject)

/**
* �ӿڴ�����������ѯ��������ѯ���ݶ���
* @param __VAR__: ת����ı������ƣ���query
* @param __TYPE__: ��ѯ���ݶ������ͣ���XxxQuery
* @param __PARAMS__: QueryParams�ı������ƣ��磺QUERIES(QueryParams, queryParams),����queryParams
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
 * �ӿڴ�������ӦVO����
 * @param __VO__: ��Ӧ���ݶ���
 */
#define API_HANDLER_RESP_VO(__VO__) return createDtoResponse(Status::CODE_200, __VO__)

 /**
 * �ӿڴ�������ӦVO���ݣ���oatpp::Object��װ����
 * @param __VO__: ��Ӧ���ݶ���
 */
#define API_HANDLER_RESP_VO_WRAPPER(__VO__) API_HANDLER_RESP_VO(oatpp::Object<__VO__>)

 /**
  * API�˵㶨��
  * @param _METHOD_: ����ʽ���磺API_M_GET
  * @param _PATH_: �˵���ʵ�ַ���磺/user/query-by-name
  * @param __ENDPOINT_FUN_NAME__: Api�˵㺯������
  * @param _PARAM_MACRO_: ָ��һ���������������ꡣ�磺BODY_DTO(SampleDTO::Wrapper, dto)
  * @param _EXECUTE_: �����߼�������execXXX�������磺execModifySample(dto)
  */
#define API_HANDLER_ENDPOINT(_METHOD_, _PATH_, __ENDPOINT_FUN_NAME__, _PARAM_MACRO_, _EXECUTE_) \
ENDPOINT(_METHOD_, _PATH_, __ENDPOINT_FUN_NAME__, _PARAM_MACRO_) { \
	API_HANDLER_RESP_VO(_EXECUTE_); \
}

  /**
  * API�˵㶨�壬�����ʱ��������Ȩ����
  * @param _METHOD_: ����ʽ���磺API_M_GET
  * @param _PATH_: �˵���ʵ�ַ���磺/user/query-by-name
  * @param __ENDPOINT_FUN_NAME__: Api�˵㺯������
  * @param _PARAM_MACRO_: ָ��һ���������������ꡣ�磺BODY_DTO(SampleDTO::Wrapper, dto)
  * @param _EXECUTE_: �����߼�������execXXX�������磺execModifySample(dto)
  */
#define API_HANDLER_ENDPOINT_AUTH(_METHOD_, _PATH_, __ENDPOINT_FUN_NAME__, _PARAM_MACRO_, _EXECUTE_) \
ENDPOINT(_METHOD_, _PATH_, __ENDPOINT_FUN_NAME__, _PARAM_MACRO_, API_HANDLER_AUTH_PARAME) { \
	API_HANDLER_RESP_VO(_EXECUTE_); \
}

  /**
   * API�˵㶨�壬�������������
   * @param _METHOD_: ����ʽ���磺API_M_GET
   * @param _PATH_: �˵���ʵ�ַ���磺/user/query-by-name
   * @param __ENDPOINT_FUN_NAME__: Api�˵㺯������
   * @param _EXECUTE_: �����߼�������execXXX�������磺execModifySample(dto)
   */
#define API_HANDLER_ENDPOINT_NOPARAM(_METHOD_, _PATH_, __ENDPOINT_FUN_NAME__, _EXECUTE_) \
ENDPOINT(_METHOD_, _PATH_, __ENDPOINT_FUN_NAME__) { \
	API_HANDLER_RESP_VO(_EXECUTE_); \
}

   /**
   * API�˵㶨�壬��������������������ʱ��������Ȩ����
   * @param _METHOD_: ����ʽ���磺API_M_GET
   * @param _PATH_: �˵���ʵ�ַ���磺/user/query-by-name
   * @param __ENDPOINT_FUN_NAME__: Api�˵㺯������
   * @param _EXECUTE_: �����߼�������execXXX�������磺execModifySample(dto)
   */
#define API_HANDLER_ENDPOINT_NOPARAM_AUTH(_METHOD_, _PATH_, __ENDPOINT_FUN_NAME__, _EXECUTE_) \
ENDPOINT(_METHOD_, _PATH_, __ENDPOINT_FUN_NAME__, API_HANDLER_AUTH_PARAME) { \
	API_HANDLER_RESP_VO(_EXECUTE_); \
}

   /**
   * API�˵㶨�壬���ڴ��������ѯ���������󣬲�ѯ����������ı�����Ϊquery
   * @param _METHOD_: ����ʽ���磺API_M_GET
   * @param _PATH_: �˵���ʵ�ַ���磺/user/query-by-name
   * @param __ENDPOINT_FUN_NAME__: Api�˵㺯������
   * @param _QUERY_TYPE_: ��ѯ�������͡��磺SampleQuery
   * @param _EXECUTE_: �����߼�������execXXX�������磺execQuerySample(query)
   */
#define API_HANDLER_ENDPOINT_QUERY(_METHOD_, _PATH_, __ENDPOINT_FUN_NAME__, _QUERY_TYPE_, _EXECUTE_) \
ENDPOINT(_METHOD_, _PATH_, __ENDPOINT_FUN_NAME__, QUERIES(QueryParams, queryParams)) { \
	API_HANDLER_QUERY_PARAM(query, _QUERY_TYPE_, queryParams);\
	API_HANDLER_RESP_VO(_EXECUTE_); \
}

   /**
   * API�˵㶨�壬���ڴ��������ѯ���������󣬲�ѯ����������ı�����Ϊquery�������ʱ��������Ȩ����
   * @param _METHOD_: ����ʽ���磺API_M_GET
   * @param _PATH_: �˵���ʵ�ַ���磺/user/query-by-name
   * @param __ENDPOINT_FUN_NAME__: Api�˵㺯������
   * @param _QUERY_TYPE_: ��ѯ�������͡��磺SampleQuery
   * @param _EXECUTE_: �����߼�������execXXX�������磺execQuerySample(query, authObject->getPayload())
   */
#define API_HANDLER_ENDPOINT_QUERY_AUTH(_METHOD_, _PATH_, __ENDPOINT_FUN_NAME__, _QUERY_TYPE_, _EXECUTE_) \
ENDPOINT(_METHOD_, _PATH_, __ENDPOINT_FUN_NAME__, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) { \
	API_HANDLER_QUERY_PARAM(query, _QUERY_TYPE_, queryParams);\
	API_HANDLER_RESP_VO(_EXECUTE_); \
}

   //////////////////////////////////////////////////////////////////////////

   /**
   * DTO�ֶζ����
   * @param _TYPE_: �ֶ����͡��磺String��Int32��List<Int32>��List<SampleQuery::Wrapper>
   * @param _NAME_: �ֶ����ơ��磺name��sex
   * @param _DESCRIPTION_: �ֶ�����
   * @param _REQUIRE_: �Ƿ�ش��������磺true��false
   * @param _DEFAULT_: �ֶ�Ĭ��ֵ��ע���������Ĭ��ֵ��������ֶ�ֵû�б����Ǿͻᱣ��ֵΪĬ��ֵ���磺"zhangsan" ��123
   */
#define API_DTO_FIELD(_TYPE_, _NAME_, _DESCRIPTION_, _REQUIRE_, _DEFAULT_) \
DTO_FIELD(_TYPE_, _NAME_) = _DEFAULT_; \
DTO_FIELD_INFO(_NAME_) { \
	info->description = _DESCRIPTION_; \
	info->required = _REQUIRE_; \
}

   /**
   * DTO�ֶζ���꣬�󲿷����Ա���ϵͳĬ��
   * @param _TYPE_: �ֶ����͡��磺String��Int32��List<Int32>��List<SampleQuery::Wrapper>
   * @param _NAME_: �ֶ����ơ��磺name��sex
   * @param _DESCRIPTION_: �ֶ�����
   */
#define API_DTO_FIELD_DEFAULT(_TYPE_, _NAME_, _DESCRIPTION_) \
DTO_FIELD(_TYPE_, _NAME_); \
DTO_FIELD_INFO(_NAME_) { \
	info->description = _DESCRIPTION_; \
}

#endif // !_API_HELPER_