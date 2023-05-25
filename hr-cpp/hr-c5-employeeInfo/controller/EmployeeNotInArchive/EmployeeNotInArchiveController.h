#pragma once
#ifndef _EMPLOYEE_NOT_IN_AECHIVE_CONTROLLER_
#define _EMPLOYEE_NOT_IN_AECHIVE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/EmployeeNotInArchive/EmployeeNotInArchiveVo.h"
#include "domain/query/EmployeeNotInArchive/EmployeeNotInArchiveQuery.h"
#include "domain/dto/EmployeeNotInArchive/EmployeeNotInArchiveDto.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * ���Կ�����
 */
class EmployeeNotInArchiveController : public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(EmployeeNotInArchiveController);
public: // ����ӿ�
	// 3 ����ӿ�����
	ENDPOINT_INFO(EmployeeNotInArchive) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("EmployeeNotInArchive.get.summary");
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(EmployeeNotInArchivePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		//Ա������
		info->queryParams.add<String>("PimPersonName").description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.PimPersonName");
		info->queryParams["PimPersonName"].addExample("default", String("Name"));
	}
	// 4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/employeenotInarchive", EmployeeNotInArchive, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, EmployeeNotInArchiveQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryTest(query));
	}
private: // ����ӿ�ִ�к���
	// 5 ����ӿڵ�ִ�к���
	EmployeeNotInArchivePageJsonVO::Wrapper execQueryTest(const EmployeeNotInArchiveQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_ARCHIVSE_CONTEOLLER_