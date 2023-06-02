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


//合同查询信息params
#define QUERYCONTRACTINFO \
info->queryParams.add<String>("infoid").description = ZH_WORDS_GETTER("contract.filed.infoid");\
info->queryParams["infoid"].addExample("default", String("2632DB4D-6440-4699-8584-5F944BABAA40"))

//合同导出params
#define DOWNLOADCONTRACTINFO \
info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("contract.filed.id");\
info->queryParams["id"].addExample("default", String("1921****"));\
info->queryParams["id"].required = false;\
info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("contract.filed.name");\
info->queryParams["name"].addExample("default", String(""));\
info->queryParams["name"].required = false;\
info->queryParams.add<String>("emp_condition").description = ZH_WORDS_GETTER("contract.filed.emp_condition");\
info->queryParams["emp_condition"].addExample("default", String(""));\
info->queryParams["emp_condition"].required = false;\
info->queryParams.add<String>("contract_num").description = ZH_WORDS_GETTER("contract.filed.contract_num");\
info->queryParams["contract_num"].addExample("default", String(""));\
info->queryParams["contract_num"].required = false;\
info->queryParams.add<String>("type").description = ZH_WORDS_GETTER("contract.filed.type");\
info->queryParams["type"].addExample("default", String(""));\
info->queryParams["type"].required = false;\
info->queryParams.add<String>("variety").description = ZH_WORDS_GETTER("contract.filed.variety");\
info->queryParams["variety"].addExample("default", String(""));\
info->queryParams["variety"].required = false;\
info->queryParams.add<String>("condition").description = ZH_WORDS_GETTER("contract.filed.condition");\
info->queryParams["condition"].addExample("default", String(""));\
info->queryParams["condition"].required = false;\
info->queryParams.add<String>("date").description = ZH_WORDS_GETTER("contract.filed.date(>=)");\
info->queryParams["date"].addExample("default", String(""));\
info->queryParams["date"].required = false;\
info->queryParams.add<String>("date_end").description = ZH_WORDS_GETTER("contract.filed.date_end(<=)");\
info->queryParams["date_end"].addExample("default", String(""));\
info->queryParams["date_end"].required = false

using namespace oatpp;

// 0 定义API控制器使用宏  (api控制器是处理传入请求，返回响应的)
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ContractController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ContractController);

public:
	// 3.1.1 查询合同接口描述
	ENDPOINT_INFO(queryContract) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("contract.check");
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractJsonVO_);
		// 合同查询信息params
		QUERYCONTRACTINFO;
	}
	// 3.1.2 查询合同接口处理
	ENDPOINT(API_M_GET, "/contract-management/query-contract-info", queryContract, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(query, ContractQuery_, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryContract(query));
	}

	//3.2.1 更新合同接口描述
	ENDPOINT_INFO(updateContract) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("contract.update");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);

		//UPDATECONTRACTINFO;
	}

	// 3.2.2 更新合同接口处理
	ENDPOINT(API_M_PUT, "/contract-management/update-contract-info", updateContract, BODY_DTO(ContractDTO_::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execUpdateContract(dto));
	}

	//3.3.1 导入合同接口描述
	ENDPOINT_INFO(uploadContract) {
		info->summary = ZH_WORDS_GETTER("contract.upload");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("user.file.suffix");
		info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));
	}
	// 3.3.2 导入合同接口处理
	ENDPOINT(API_M_POST, "/contract-management/upload-contract-info", uploadContract, BODY_STRING(String, body), QUERY(String, suffix)) {
		// ִ响应结果
		API_HANDLER_RESP_VO(execUploadContract(body, suffix));
	}

	//3.4.1 导出合同接口描述
	ENDPOINT_INFO(downloadContract) {
		info->summary = ZH_WORDS_GETTER("contract.download");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//合同导出params
		info->queryParams.add<UInt64>("rows").description = ZH_WORDS_GETTER("contract.export.rows");
		info->queryParams["rows"].addExample("default", UInt64(1000));
		info->queryParams["rows"].required = true;
		DOWNLOADCONTRACTINFO;
	}
	// 3.4.2 导出合同接口处理
	ENDPOINT(API_M_GET, "/contract-management/download-contract-info", downloadContract, QUERIES(QueryParams, qps)) {
		API_HANDLER_QUERY_PARAM(query, ContractDownloadQuery, qps);
		API_HANDLER_RESP_VO(execDownloadContract(query));
	}



private:
	//
	ContractJsonVO_::Wrapper execQueryContract(const ContractQuery_::Wrapper& query);
	//
	Uint64JsonVO::Wrapper execUpdateContract(const ContractDTO_::Wrapper& dto);
	//
	StringJsonVO::Wrapper execUploadContract(const String& fileBody, const String& suffix);
	//
	StringJsonVO::Wrapper execDownloadContract(const ContractDownloadQuery::Wrapper& query);
};
// 0 
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif 
