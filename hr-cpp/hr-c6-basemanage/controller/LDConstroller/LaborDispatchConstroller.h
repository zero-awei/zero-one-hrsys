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
#include "domain/vo/LaborDispatchVO.h"
#include "domain/query/LaborDispatchQuery.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)

// 1 �̳п�����
class LaborDispatchConstroller : public oatpp::web::server::api::ApiController
{
	// 2 ����������������
	API_ACCESS_DECLARE(LaborDispatchConstroller);
public: 
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryLDCorlist) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("ldcompany.get.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(LaborDispatchPageJsonVO);
		//�����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("PIMLABOURCAMPANYNAME").description = ZH_WORDS_GETTER("ldcompany.field.PIMLABOURCAMPANYNAME");
		info->queryParams["PIMLABOURCAMPANYNAME"].required = false;
		info->queryParams.add<String>("PIMLABOURCAMPANYID").description = ZH_WORDS_GETTER("ldcompany.field.PIMLABOURCAMPANYID");
		info->queryParams["PIMLABOURCAMPANYID"].required = false;

	}
	// 3.2 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/query", queryLDCorlist, QUERIES(QueryParams, qcl)) {
		//������ѯ����
		API_HANDLER_QUERY_PARAM(query, PageQuery, qcl);
		//��Ӧ���
		API_HANDLER_RESP_VO(executeQueryAll(query));
	}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addLDCor) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("ldcompany.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/add", addLDCor, BODY_DTO(LaborDispatchDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddLaborDispatch(dto));
	}

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeCor) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("ldcompany.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/remove", removeCor, BODY_DTO(LaborDispatchDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveLaborDispatch(dto));
	}

	// 3.1 ���嵼���ӿ�����
	ENDPOINT_INFO(exportCor) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("ldcompany.export.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_PUT, "/export",exportCor, QUERIES(QueryParams, qcl)) {
		//������ѯ����
		API_HANDLER_QUERY_PARAM(query, PageQuery, qcl);
		//��Ӧ���
		API_HANDLER_RESP_VO(executeQueryAll(query));
	}


private: //  ����ӿ�ִ�к���
	// 3.3 ��ҳ��ѯ����
	StringJsonVO::Wrapper executeQueryAll(const PageQuery::Wrapper& query);
	// 3.3 ��������
	Uint64JsonVO::Wrapper execAddLaborDispatch(const LaborDispatchDTO::Wrapper& dto);
	//3.3 ɾ������
	Uint64JsonVO::Wrapper execRemoveLaborDispatch(const LaborDispatchDTO::Wrapper& dto);
	//3.3 ��������
	StringJsonVO::Wrapper execExportLaborDispatch(const PageQuery::Wrapper& query);
	/*LaborDispatchPageJsonVO::Wrapper executeQueryAll(const PageQuery::Wrapper& query);*/
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_MHCONSTROLLER_H_