#ifndef __ContractController__
#define __ContractController__

#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "../../Macros.h"
#include "domain/query/ContractQuery/ContractQuery.h"
#include "../../domain/dto/ContractDTO/ContractDTO.h"
#include "../../domain/vo/ContractVO/ContractVO.h"

//修改合同所需参数
#define UPDATECONTRACTINFO \
info->queryParams.add<String>("PIMCONTRACTID").description = ZH_WORDS_GETTER("contract.PIMCONTRACTID");\
info->queryParams["PIMCONTRACTID"].addExample("default", String("(:3[___]"));\
info->queryParams.add<String>("CREATEMAN").description = ZH_WORDS_GETTER("contract.CREATEMAN");\
info->queryParams["CREATEMAN"].addExample("default", String("(:3[___]"));\
info->queryParams["CREATEMAN"].required = false;\
info->queryParams.add<String>("CREATEDATE").description = ZH_WORDS_GETTER("contract.CREATEDATE");\
info->queryParams["CREATEDATE"].addExample("default", String("(:3[___]"));\
info->queryParams["CREATEDATE"].required = false;\
info->queryParams.add<String>("UPDATEDATE").description = ZH_WORDS_GETTER("contract.UPDATEDATE");\
info->queryParams["UPDATEDATE"].addExample("default", String("((:3[___]"));\
info->queryParams["UPDATEDATE"].required = false;\
info->queryParams.add<String>("PIMCONTRACTNAME").description = ZH_WORDS_GETTER("contract.PIMCONTRACTNAME");\
info->queryParams["PIMCONTRACTNAME"].addExample("default", String("(:3[___]"));\
info->queryParams["PIMCONTRACTNAME"].required = false 

//查询合同所需参数
#define QUERYCONTRACTINFO \
info->queryParams.add<String>("PIMCONTRACTID").description = ZH_WORDS_GETTER("contract.PIMCONTRACTID");\
info->queryParams["PIMCONTRACTID"].addExample("default", String("(:3[___]"))


using namespace oatpp;

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ContractController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ContractController);

public:
	// 3.1.1 接口描述:查看指定合同
	ENDPOINT_INFO(queryContract) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("contract.check");
		// 添加默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractJsonVO);
		// 添加其他查询参数
		QUERYCONTRACTINFO;
	}
	// 3.1.2 定义接口端点
	ENDPOINT(API_M_GET, "/queryContract", queryContract, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, ContractQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryContract(query));
	}

	//3.2.1 接口描述:修改指定合同
	ENDPOINT_INFO(updateContract) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("contract.update");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// 添加其他查询参数
		UPDATECONTRACTINFO;
	}

	// 3.2.2 定义接口端点
	ENDPOINT(API_M_PUT, "/updateContract", updateContract, BODY_DTO(ContractDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execUpdateContract(dto));
	}

	//3.3.1 接口描述:导入合同
	ENDPOINT_INFO(uploadContract) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("contract.upload");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// 添加其他查询参数
		info->queryParams.add<String>("UploadPath").description = ZH_WORDS_GETTER("contract.uploadpath"); 
		info->queryParams["UploadPath"].addExample("default", String("(:3[___]")); 
	}

	// 3.3.2 定义接口端点
	ENDPOINT(API_M_PUT, "/uploadContract", uploadContract, BODY_DTO(PathDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execUploadContract(dto));
	}


	//3.4.1 接口描述:导出合同
	ENDPOINT_INFO(downloadContract) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("contract.download");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PathJsonVO);
		// 添加其他查询参数
		info->queryParams.add<String>("DownloadPath").description = ZH_WORDS_GETTER("contract.downloadpath");
		info->queryParams["DownloadPath"].addExample("default", String("(:3[___]"));
	}

	// 3.4.2 定义接口端点
	ENDPOINT(API_M_PUT, "/downloadContract", downloadContract, BODY_DTO(PathDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execDownloadContract(dto));
	}

private:
	//合同查询
	ContractJsonVO::Wrapper execQueryContract(const ContractQuery::Wrapper& query);
	//修改合同
	Uint64JsonVO::Wrapper execUpdateContract(const ContractDTO::Wrapper& dto);
	//导入合同
	Uint64JsonVO::Wrapper execUploadContract(const PathDTO::Wrapper& dto);
	//导出合同
	PathJsonVO::Wrapper execDownloadContract(const PathDTO::Wrapper& dto);

};
// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif 
