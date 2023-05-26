#pragma once

#ifndef _PATENTINFOCONTROLLER_H_
#define _PATENTINFOCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/patentinfo/PatentinfoQuery.h"
#include "domain/vo/patentinfo/PatentinfoVO.h"
#include "domain/dto/patentinfo/PatentinfoDTO.h"
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
class PatentinfoController : public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(PatentinfoController);
public: // ����ӿ�







	// 3 ����ӿ�����
	ENDPOINT_INFO(queryPatentinfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("patentInformation.select.summary");
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(PatentinfoJsonVO);
		// �����ҳ��ѯ��������
		//API_DEF_ADD_PAGE_PARAMS();
		// ���������ѯ����
		//info->queryParams.add<String>("ZLH").description = ZH_WORDS_GETTER("patentInformation.field.ZLH");
		//info->queryParams["ZLH"].addExample("default", String("patentInformation"));

		//Ա�����
		info->queryParams.add<String>("PIMPATENTID").description = ZH_WORDS_GETTER("patentInformation.pimpatent.PIMPATENTID");
		info->queryParams["PIMPATENTID"].addExample("default", String("1234"));
		info->queryParams["PIMPATENTID"].required = true;
	}
	// 4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/employee-info/patentinfo", queryPatentinfo, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, PatentinfoQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryPatentinfo(query));
	}

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(patentinfoQuery) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("patentInformation.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PatentinfoPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		// ר����
		info->queryParams.add<String>("ZLH").description = ZH_WORDS_GETTER("patentInformation.field.ZLH");
		info->queryParams["ZLH"].addExample("default", String("123456789"));
		//// ר������
		//info->queryParams.add<String>("PIMPATENTNAME").description = ZH_WORDS_GETTER("patentInformation.field.PIMPATENTNAME");
		//info->queryParams["PIMPATENTNAME"].addExample("default", String("zxxx-xxxx"));
		//// ר����ȡʱ��
		//info->queryParams.add<String>("ZLHQSJ").description = ZH_WORDS_GETTER("patentInformation.field.ZLHQSJ");
		//info->queryParams["ZLHQSJ"].addExample("default", String("zxxx-xxxx-xxxx-xxxx"));
		//// ר����׼����
		//info->queryParams.add<String>("ZLPZGB").description = ZH_WORDS_GETTER("patentInformation.field.ZLPZGB");
		//info->queryParams["ZLPZGB"].addExample("default", String("2000-01-01"));
		//// ����
		//info->queryParams.add<String>("ENCLOLURE").description = ZH_WORDS_GETTER("patentInformation.field.ENCLOLURE");
		//info->queryParams["ENCLOLURE"].addExample("default", String("fj-name"));
		//// ר����Ϣ����
		//info->queryParams.add<String>("PIMPATENTID").description = ZH_WORDS_GETTER("patentInformation.field.PIMPATENTID");
		//info->queryParams["PIMPATENTID"].addExample("default", String("1234-xxxx-xxxx-1234"));
		//// ��Ա��Ϣ��ʶ
		//info->queryParams.add<String>("PIMPERSONID").description = ZH_WORDS_GETTER("patentInformation.field.PIMPERSONID");
		//info->queryParams["PIMPERSONID"].addExample("default", String("1234-1234-1234-1234"));
	}

	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/employee-info/Page-patentinfo", patentinfoQuery, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(query, PatentinfoQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryPagePatent(query));
	}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addPatent) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("patentInformation.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/employee-info/add-patentinfo", addPatent, BODY_DTO(PatentinfoDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddPatent(dto));
	}

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removePatent) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("patentInformation.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/employee-info/remove-patentinfo", removePatent, BODY_DTO(PatentinfoDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemovePatent(dto));
	}

	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(modifySample) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("patentInformation.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/employee-info/modify-patentinfo", modifySample, BODY_DTO(PatentinfoDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyPatentinfo(dto));
	}


private: // ����ӿ�ִ�к���
	//��ҳ�鿴ָ��Ա��ר����Ϣ����ҳ��ѯ�б�
	PatentinfoPageJsonVO::Wrapper execQueryPagePatent(const PatentinfoQuery::Wrapper& query);

	//����ָ��Ա��ר����Ϣ������������
	Uint64JsonVO::Wrapper execAddPatent(const PatentinfoDTO::Wrapper& dto);

	//ɾ��ָ��Ա��ר����Ϣ��֧������ɾ����
	Uint64JsonVO::Wrapper execRemovePatent(const PatentinfoDTO::Wrapper& dto);

	//�鿴ָ��Ա��ר����Ϣ��ָ��ר����Ϣ���飩
	PatentinfoPageJsonVO::Wrapper execQueryPagePatentinfo(const PatentinfoQuery::Wrapper& query);

	// 5 ����ӿڵ�ִ�к���
	PatentinfoJsonVO::Wrapper execQueryPatentinfo(const PatentinfoQuery::Wrapper& query);

	//�޸�ָ��Ա��ר����Ϣ�������޸ģ�
	Uint64JsonVO::Wrapper execModifyPatentinfo(const PatentinfoDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_TESTCONTROLLER_H_