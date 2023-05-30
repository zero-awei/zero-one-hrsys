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


//查询合同所需参数
#define QUERYCONTRACTINFO \
info->queryParams.add<String>("infoid").description = ZH_WORDS_GETTER("contract.filed.infoid");\
info->queryParams["infoid"].addExample("default", String("2632DB4D-6440-4699-8584-5F944BABAA40"))


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
	ENDPOINT(API_M_GET, "/contract-management/query-contract-info", queryContract, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
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
		//UPDATECONTRACTINFO;
	}

	// 3.2.2 定义接口端点
	ENDPOINT(API_M_PUT, "/contract-management/update-contract-info", updateContract, BODY_DTO(ContractDTO_::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execUpdateContract(dto));
	}

	//3.3.1 接口描述:导入合同
	ENDPOINT_INFO(uploadContract) {
		info->summary = ZH_WORDS_GETTER("contract.upload");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("user.file.suffix");
		info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));
	}
	// 3.3.2 定义接口端点
	// 定义文件上传端点处理
	ENDPOINT(API_M_POST, "/contract-management/upload-contract-info", uploadContract, BODY_STRING(String, body), QUERY(String, suffix)) {
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
		info->queryParams["rows"].addExample("default", UInt64(1));
		info->queryParams["rows"].required = true;
		info->queryParams.add<String>("sequence").description = ZH_WORDS_GETTER("contract.export.sequence");
		info->queryParams["sequence"].addExample("default", String("ASC"));
		info->queryParams["sequence"].required = true;
	}
	// 3.4.2 定义接口端点
	ENDPOINT(API_M_GET, "/contract-management/download-contract-info", downloadContract, QUERIES(QueryParams, qps)) {
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

	/*
	* 导出项目标签（最大5000条）
	* 调用DAO查询数据库，返回后包装进Excel文件并保存到FastDFS文件服务器
	* 返回值：文件服务器拼接下载链接
	* 负责人：akie
	*/
	StringJsonVO::Wrapper execDownloadContract(const ContractDownloadQuery::Wrapper& query);
};
// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif 
