#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/08 21:23:08

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
#ifndef _TESTCONTROLLER_H_
#define _TESTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * ���Կ�����
 */
class TestController : public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(TestController);
public: // ����ӿ�
	// 3 ����ӿ�����
	ENDPOINT_INFO(queryTest) {
		// ����ӿڱ���
		info->summary = "test query";
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	// 4 ����ӿڶ˵�
	ENDPOINT(API_M_GET,"/test", queryTest,QUERIES(QueryParams,qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, PageQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryTest(query));
	}
private: // ����ӿ�ִ�к���
	// 5 ����ӿڵ�ִ�к���
	StringJsonVO::Wrapper execQueryTest(const PageQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_TESTCONTROLLER_H_