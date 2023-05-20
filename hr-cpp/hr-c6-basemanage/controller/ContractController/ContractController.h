#ifndef __ContractController__
#define __ContractController__

#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "../../Macros.h"
#include "domain/query/ContractQuery/ContractQuery_.h"
#include "../../domain/dto/ContractDTO/ContractDTO_.h"
#include "../../domain/vo/ContractVO/ContractVO_.h"

//�޸ĺ�ͬ�������
#define UPDATECONTRACTINFO \
info->queryParams.add<String>("PIMCONTRACTID").description = ZH_WORDS_GETTER("Contract.PIMCONTRACTID");\
info->queryParams["PIMCONTRACTID"].addExample("default", String("(:3[___]"));\
info->queryParams.add<String>("CREATEMAN").description = ZH_WORDS_GETTER("Contract.CREATEMAN");\
info->queryParams["CREATEMAN"].addExample("default", String("(:3[___]"));\
info->queryParams["CREATEMAN"].required = false;\
info->queryParams.add<String>("CREATEDATE").description = ZH_WORDS_GETTER("Contract.CREATEDATE");\
info->queryParams["CREATEDATE"].addExample("default", String("(:3[___]"));\
info->queryParams["CREATEDATE"].required = false;\
info->queryParams.add<String>("UPDATEDATE").description = ZH_WORDS_GETTER("Contract.UPDATEDATE");\
info->queryParams["UPDATEDATE"].addExample("default", String("((:3[___]"));\
info->queryParams["UPDATEDATE"].required = false;\
info->queryParams.add<String>("PIMCONTRACTNAME").description = ZH_WORDS_GETTER("Contract.PIMCONTRACTNAME");\
info->queryParams["PIMCONTRACTNAME"].addExample("default", String("(:3[___]"));\
info->queryParams["PIMCONTRACTNAME"].required = false 

//��ѯ��ͬ�������
#define QUERYCONTRACTINFO \
info->queryParams.add<String>("PIMCONTRACTID").description = ZH_WORDS_GETTER("Contract.PIMCONTRACTID");\
info->queryParams["PIMCONTRACTID"].addExample("default", String("(:3[___]"))


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
		info->summary = ZH_WORDS_GETTER("Contract.check");
		// ���Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractJsonVO_);
		// ���������ѯ����
		QUERYCONTRACTINFO;
	}
	// 3.1.2 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/queryContract", queryContract, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, ContractQuery_, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryContract(query));
	}

	//3.2.1 �ӿ�����:�޸�ָ����ͬ
	ENDPOINT_INFO(updateContract) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("Contract.update");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// ���������ѯ����
		UPDATECONTRACTINFO;
	}

	// 3.2.2 ����ӿڶ˵�
	ENDPOINT(API_M_PUT, "/updateContract", updateContract, BODY_DTO(ContractDTO_::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execUpdateContract(dto));
	}

	//3.3.1 �ӿ�����:�����ͬ
	ENDPOINT_INFO(uploadContract) {
		info->summary = ZH_WORDS_GETTER("Contract.upload");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("user.file.suffix");
		info->queryParams["suffix"].addExample("png", String(".png"));
		info->queryParams["suffix"].addExample("jpg", String(".jpg"));
		info->queryParams["suffix"].addExample("txt", String(".txt"));
	}
	// 3.3.2 ����ӿڶ˵�
	// �����ļ��ϴ��˵㴦��
	ENDPOINT(API_M_POST, "/uploadContract", uploadContract, BODY_STRING(String, body), QUERY(String, suffix)) {
		// ִ���ļ������߼�
		API_HANDLER_RESP_VO(execUploadContract(body, suffix));
	}

	//3.4.1 �ӿ�����:������ͬ
	ENDPOINT_INFO(downloadContract) {
		info->summary = ZH_WORDS_GETTER("Contract.download");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ���������ѯ����
		info->queryParams.add<UInt8>("rows").description = ZH_WORDS_GETTER("Contract.export.rows");
		info->queryParams["rows"].addExample("default", UInt8(1));
		info->queryParams["rows"].required = true;
		info->queryParams.add<String>("sequence").description = ZH_WORDS_GETTER("Contract.export.sequence");
		info->queryParams["sequence"].addExample("default", String("ASC"));
		info->queryParams["sequence"].required = true;
	}
	// 3.4.2 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/downloadContract", downloadContract, QUERIES(QueryParams, qps)) {
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
	//������ͬ
	StringJsonVO::Wrapper execDownloadContract(const ContractDownloadQuery::Wrapper& query);
};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif 
