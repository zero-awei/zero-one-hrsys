#ifndef __ContractController__
#define __ContractController__

#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "../../Macros.h"
#include "domain/query/ContractQuery/ContractQuery_.h"
#include "../../domain/dto/ContractDTO/ContractDTO_.h"
#include "../../domain/vo/ContractVO/ContractVO_.h"

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
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractJsonVO_);
		// 添加其他查询参数
		QUERYCONTRACTINFO;
	}
	// 3.1.2 定义接口端点
	ENDPOINT(API_M_GET, "/queryContract", queryContract, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, ContractQuery_, qps);
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
	ENDPOINT(API_M_PUT, "/updateContract", updateContract, BODY_DTO(ContractDTO_::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execUpdateContract(dto));
	}

	//3.3.1 接口描述:导入合同
	ENDPOINT_INFO(uploadContract) {
		info->summary = ZH_WORDS_GETTER("contract.upload");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("user.file.suffix");
		info->queryParams["suffix"].addExample("png", String(".png"));
		info->queryParams["suffix"].addExample("jpg", String(".jpg"));
		info->queryParams["suffix"].addExample("txt", String(".txt"));
	}
	// 3.3.2 定义接口端点
	// 定义文件上传端点处理
	ENDPOINT(API_M_POST, "/uploadContract", uploadContract, BODY_STRING(String, body), QUERY(String, suffix)) {
		// 执行文件保存逻辑
		API_HANDLER_RESP_VO(execUploadContract(body, suffix));
	}

	//3.4.1 接口描述:导出合同
	ENDPOINT_INFO(downloadContract) {
		info->summary = ZH_WORDS_GETTER("contract.download");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 添加其他查询参数
		info->queryParams.add<UInt8>("rows").description = ZH_WORDS_GETTER("contract.export.rows");
		info->queryParams["rows"].addExample("default", UInt8(1));
		info->queryParams["rows"].required = true;
		info->queryParams.add<String>("sequence").description = ZH_WORDS_GETTER("contract.export.sequence");
		info->queryParams["sequence"].addExample("default", String("ASC"));
		info->queryParams["sequence"].required = true;
	}
	// 3.4.2 定义接口端点
	ENDPOINT(API_M_GET, "/downloadContract", downloadContract, QUERIES(QueryParams, qps)) {
		API_HANDLER_QUERY_PARAM(query, ContractDownloadQuery, qps);
		API_HANDLER_RESP_VO(execDownloadContract(query));
	}




private:
	//合同查询
	ContractJsonVO_::Wrapper execQueryContract(const ContractQuery_::Wrapper& query);
	//修改合同
	Uint64JsonVO::Wrapper execUpdateContract(const ContractDTO_::Wrapper& dto);
	//导入合同
	StringJsonVO::Wrapper execUploadContract(const String& fileBody, const String& suffix);
	//导出合同
	StringJsonVO::Wrapper execDownloadContract(const ContractDownloadQuery::Wrapper& query);
};
// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif 
