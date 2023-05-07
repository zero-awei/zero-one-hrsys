#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/24 15:36:33

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
#ifndef _SWAGGERCOMPONENT_HPP_
#define _SWAGGERCOMPONENT_HPP_

#include "oatpp-swagger/Model.hpp"
#include "oatpp-swagger/Resources.hpp"
#include "oatpp/core/macro/component.hpp"

//定义Swagger-UI资源路径
#ifndef OATPP_SWAGGER_RES_PATH
#define OATPP_SWAGGER_RES_PATH "../lib-oatpp/include/oatpp-swagger/res"
#endif

//定义服务名称
#ifndef OATPP_SWAGGER_SERVICE_NAME
#define OATPP_SWAGGER_SERVICE_NAME "arch demo for windows"
#endif

/**
 * 定义一个Swagger组件
 * 组件访问地址：http://host:port/swagger/ui
 */
class SwaggerComponent
{
	/*
	 * 通用API文档信息
	 */
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::DocumentInfo>, swaggerDocumentInfo)([] {
		auto ss = oatpp::swagger::SecurityScheme::createShared();
		ss->description = "Default HTTP Bearer Authorization";
		ss->name = "Authorization";
		ss->in = "header";
		ss->type = "http";
		ss->scheme = "bearer";
		ss->bearerFormat = "JWT";
		oatpp::swagger::DocumentInfo::Builder builder;
		builder
			.setTitle(OATPP_SWAGGER_SERVICE_NAME " API interface service")
			.setDescription("Provide a set of API documents for describing the front-end and back-end interactions of the " OATPP_SWAGGER_SERVICE_NAME)
			.setVersion("1.0.0")
			.setContactName("01 Star")
			.setContactUrl("https://space.bilibili.com/1653229811/?spm_id_from=333.999.0.0")
			.setContactEmail("01xq@mail.com")
			.setLicenseName("Apache License, Version 2.0")
			.setLicenseUrl("https://www.apache.org/licenses/LICENSE-2.0")
			.addSecurityScheme("bearer_auth", ss);
		return builder.build();
		}());

	/*
	 * Swagger-Ui资源路径
	 * 确保指定oatpp-swagger/res文件夹的正确完整路径
	 */
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::Resources>, swaggerResources)([] {
		return oatpp::swagger::Resources::loadResources(OATPP_SWAGGER_RES_PATH);
		}());
};

#endif // !_SWAGGERCOMPONENT_HPP_