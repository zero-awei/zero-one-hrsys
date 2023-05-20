#pragma once

#ifndef _TESTCONTROLLER_H_
#define _TESTCONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include"ApiHelper.h"
#include "domain/query/PageQuery.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen 0

//���Կ�����
class TestController : public oatpp::web::server::api::ApiController//1
{
	//���������������� 2
	API_ACCESS_DECLARE(TestController);
public://����ӿ�
	//����ӿ����� 3
	ENDPOINT_INFO(qurryTest)
	{
		//����ӿڱ���
		info->summary = "test qurry";
		//������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//�����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	//����ӿڶ˵� 4
	ENDPOINT(API_M_GET, "/test", qurryTest, QUERIES(QueryParams, qps))
	{
		//������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, PageQuery, qps);
		//��Ӧ���
		API_HANDLER_RESP_VO(execQueryTest(query));
	}
private://����ӿ�ִ�к��� 5
	StringJsonVO::Wrapper execQueryTest(const PageQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_