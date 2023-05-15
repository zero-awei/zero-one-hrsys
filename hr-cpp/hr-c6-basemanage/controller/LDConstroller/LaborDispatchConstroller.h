#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: mengHuan
 @Date: 2023/05/15 15:25:13

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
#ifndef _MHCONSTROLLER_H_
#define _MHCONSTROLLER_H_

#include "ApiHelper.h"
#include "domain/query/PageQuery.h"
#include "domain/vo/BaseJsonVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)

// 1 �̳п�����
class LaborDispatchConstroller : public oatpp::web::server::api::ApiController
{
	// 2 ����������������
	API_ACCESS_DECLARE(LaborDispatchConstroller);
public: 
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryCorlist) {
		// ����ӿڱ���
		info->summary = "query corporation lists";

		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//�����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("PIMLABOURCAMPANYNAME").description = "����˾";
		info->queryParams["PIMLABOURCAMPANYNAME"].addExample("default", String("moumouyouxiangongsi"));
		info->queryParams["PIMLABOURCAMPANYNAME"].required = false;
	}
	// 4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/query", queryCorlist, QUERIES(QueryParams, qcl)) {
		//������ѯ����
		API_HANDLER_QUERY_PARAM(query, PageQuery, qcl);
		//��Ӧ���
		API_HANDLER_RESP_VO(executeQueryAll(query));
	}
private: 
	// 5 ����ӿ�ִ�к���
	StringJsonVO::Wrapper executeQueryAll(const PageQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_MHCONSTROLLER_H_