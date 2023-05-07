#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/01 17:39:36

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
#ifndef _USERCONTROLLER_H_
#define _USERCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/user/UserQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/user/UserVO.h"
#include "domain/vo/user/MenuVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class UserController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(UserController);
public:
	// 定义查询所有用户信息接口端点描述
	ENDPOINT_INFO(queryAllUser) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("user.query-all.summary");
		// 添加默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON(UserPageJsonVO::Wrapper);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		info->queryParams.add<String>("nickname").description = ZH_WORDS_GETTER("user.query-all.nickname");
	}
	// 定义查询所有用户信息接口端点处理
	ENDPOINT(API_M_GET, "/user/query-all", queryAllUser, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, UserQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(executeQueryAll(userQuery));
	}
	// 定义文件上传端点描述
	ENDPOINT_INFO(postFile) {
		info->summary = ZH_WORDS_GETTER("user.file.summary");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("user.file.suffix");
		info->queryParams["suffix"].addExample("png", String(".png"));
		info->queryParams["suffix"].addExample("jpg", String(".jpg"));
		info->queryParams["suffix"].addExample("txt", String(".txt"));
	}
	// 定义文件上传端点处理
	ENDPOINT(API_M_POST, "/user/file", postFile, BODY_STRING(String, body), QUERY(String, suffix)) {
		// 执行文件保存逻辑
		API_HANDLER_RESP_VO(executePostFile(body, suffix));
	}
	// 定义查询用户菜单接口端点描述
	ENDPOINT_INFO(queryMenu) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("user.query-menu.summary");
		// 添加默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON(MenuJsonVO::Wrapper);
	}
	// 定义查询所有用户信息接口端点处理
	ENDPOINT(API_M_GET, "/user/query-menu", queryMenu, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 响应结果
		API_HANDLER_RESP_VO(executeQueryMenu(authObject->getPayload()));
	}
private:
	// 查询所有
	UserPageJsonVO::Wrapper executeQueryAll(const UserQuery::Wrapper& userQuery);
	// 保存文件
	StringJsonVO::Wrapper executePostFile(const String& fileBody, const String& suffix);
	// 测试菜单
	MenuJsonVO::Wrapper executeQueryMenu(const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_