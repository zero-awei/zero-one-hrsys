#ifndef __ContractController__
#define __ContractController__

#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "../../Macros.h"
#include "domain/query/ContractQuery/ContractQuery_.h"
#include "../../domain/dto/ContractDTO/ContractDTO_.h"
#include "../../domain/vo/ContractVO/ContractVO_.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;


//��ѯ��ͬ�������
#define QUERYCONTRACTINFO \
info->queryParams.add<String>("infoid").description = ZH_WORDS_GETTER("contract.filed.infoid");\
info->queryParams["infoid"].addExample("default", String("2632DB4D-6440-4699-8584-5F944BABAA40"))


using namespace oatpp;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ContractController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ContractController);

public:
	// 3.1.1 �ӿ�����:�鿴ָ����ͬ
	ENDPOINT_INFO(queryContract) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contract.check");
		// ���Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractJsonVO_);
		// ���������ѯ����
		QUERYCONTRACTINFO;
	}
	// 3.1.2 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/contract-management/query-contract-info", queryContract, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, ContractQuery_, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryContract(query));
	}

	//3.2.1 �ӿ�����:�޸�ָ����ͬ
	ENDPOINT_INFO(updateContract) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contract.update");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// ���������ѯ����
		//UPDATECONTRACTINFO;
	}

	// 3.2.2 ����ӿڶ˵�
	ENDPOINT(API_M_PUT, "/contract-management/update-contract-info", updateContract, BODY_DTO(ContractDTO_::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execUpdateContract(dto));
	}

	//3.3.1 �ӿ�����:�����ͬ
	ENDPOINT_INFO(uploadContract) {
		info->summary = ZH_WORDS_GETTER("contract.upload");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("user.file.suffix");
		info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));
	}
	// 3.3.2 ����ӿڶ˵�
	// �����ļ��ϴ��˵㴦��
	ENDPOINT(API_M_POST, "/contract-management/upload-contract-info", uploadContract, BODY_STRING(String, body), QUERY(String, suffix)) {
		// ִ���ļ������߼�
		API_HANDLER_RESP_VO(execUploadContract(body, suffix));
	}

	//3.4.1 �ӿ�����:������ͬ
	ENDPOINT_INFO(downloadContract) {
		info->summary = ZH_WORDS_GETTER("contract.download");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ���������ѯ����
		info->queryParams.add<UInt8>("rows").description = ZH_WORDS_GETTER("contract.export.rows");
		info->queryParams["rows"].addExample("default", UInt64(1));
		info->queryParams["rows"].required = true;
		info->queryParams.add<String>("sequence").description = ZH_WORDS_GETTER("contract.export.sequence");
		info->queryParams["sequence"].addExample("default", String("ASC"));
		info->queryParams["sequence"].required = true;
	}
	// 3.4.2 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/contract-management/download-contract-info", downloadContract, QUERIES(QueryParams, qps)) {
		API_HANDLER_QUERY_PARAM(query, ContractDownloadQuery, qps);
		API_HANDLER_RESP_VO(execDownloadContract(query));
	}



private:
	//��ͬ��ѯ
	ContractJsonVO_::Wrapper execQueryContract(const ContractQuery_::Wrapper& query);
	//�޸ĺ�ͬ
	Uint64JsonVO::Wrapper execUpdateContract(const ContractDTO_::Wrapper& dto);
	//�����ͬ
	StringJsonVO::Wrapper execUploadContract(const String& fileBody, const String& suffix);

	/*
	* ������Ŀ��ǩ�����5000����
	* ����DAO��ѯ���ݿ⣬���غ��װ��Excel�ļ������浽FastDFS�ļ�������
	* ����ֵ���ļ�������ƴ����������
	* �����ˣ�akie
	*/
	StringJsonVO::Wrapper execDownloadContract(const ContractDownloadQuery::Wrapper& query);
};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif 
