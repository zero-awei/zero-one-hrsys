#pragma once

#ifndef _BLACKLIST_CONTROLLER_H_
#define _BLACKLIST_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/Blacklist/BlacklistQuery.h"
#include "domain/vo/Blacklist/BlacklistVO.h"
#include "domain/dto/Blacklist/BlacklistDTO.h"

using namespace oatpp;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class BlacklistController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(BlacklistController);
public: // ����ӿ�
	// 3 ����ӿ�����
	ENDPOINT_INFO(queryBlacklist) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("blacklist.get.summary");
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(BlacklistPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	// 4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/blacklist/query-blacklist", queryBlacklist, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, BlacklistQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryBlacklist(query));
	}
private: // ����ӿ�ִ�к���
	// 5 ����ӿڵ�ִ�к���
	BlacklistPageJsonVO::Wrapper execQueryBlacklist(const BlacklistQuery::Wrapper& query);
};



#include OATPP_CODEGEN_END(ApiController) // 0

#endif 