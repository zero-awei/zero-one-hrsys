#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/22 8:32:17

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
#ifndef _CERTIFICATECONTROLLER_H_
#define _CERTIFICATECONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/Certificate/CertificateDTO.h"
#include "domain/query/Certificate/CertificateQuery.h"
#include "domain/vo/Certificate/CertificateVO.h"
#include OATPP_CODEGEN_BEGIN(ApiController) 

class CertificateController :public oatpp::web::server::api::ApiController
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(CertificateController);
public://定义接口
	// 3 定义接口描述
	ENDPOINT_INFO(queryCertificate)
	{
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("certificate.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(CertificateJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("certificate.field.certificateName");
		info->queryParams["name"].addExample("default", String("shi gong yuan"));
		info->queryParams["name"].required = false;
	}
	ENDPOINT(API_M_GET, "/Certificate/query", queryCertificate, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, CertificateQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryCertificate(query));
	}
	// 定义新增证书类型
	ENDPOINT_INFO(addCertificate) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("certificate.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		
	}
	// 定义新增接口处理
	ENDPOINT(API_M_POST, "/Certificate/add", addCertificate, BODY_DTO(CertificateDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddCertificate(dto));
	}
	ENDPOINT_INFO(delCertificate) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("certificate.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		
	}
	// 定义批量删除接口处理
	ENDPOINT(API_M_DEL, "/Certificate/delete", delCertificate, BODY_DTO(CertificateDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execDelCertificate(dto));
	}
	//修改指定证书类型(单条修改)
	ENDPOINT_INFO(modifyCertificate) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("certificate.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		
	}
	ENDPOINT(API_M_PUT, "/Certificate/modify", modifyCertificate, BODY_DTO(CertificateDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyCertificate(dto));
	}
private:
	// 5 定义接口的执行函数
	CertificatePageJsonVO::Wrapper execQueryCertificate(const CertificateQuery::Wrapper& query); //分页查询
	Uint64JsonVO::Wrapper execAddCertificate(const CertificateDTO::Wrapper& dto); //新增岗位证书类型
	Uint64JsonVO::Wrapper execDelCertificate(const CertificateDTO::Wrapper& dto); //删除岗位证书类型
	Uint64JsonVO::Wrapper execModifyCertificate(const CertificateDTO::Wrapper& dto); //修改岗位证书类型
};
#include OATPP_CODEGEN_END(ApiController)
#endif // !_CERTIFICATECONTROLLER_H_