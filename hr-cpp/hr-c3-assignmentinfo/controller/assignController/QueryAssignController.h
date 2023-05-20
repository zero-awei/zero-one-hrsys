#ifndef _Query_Assign_CONTROLLER_
#define _Query_Assign_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/query/assignInfo/AssignInfoQuery.h"
#include "domain/query/PageQuery.h"
#include "domain/vo/assignInfo/AssignInfoQueryVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) // 0

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class QueryAssignController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(QueryAssignController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(assignQuery) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("employee.get.sumary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AssignInfoQueryJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("employee.field.id");
		info->queryParams["id"].addExample("default", String("114514"));
		info->queryParams["id"].required = false;
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/sample", assignQuery, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, AssignInfoQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execAssignQuery(userQuery, authObject->getPayload()));
	}
	//// 3.1 定义新增接口描述
	//ENDPOINT_INFO(addSample) {
	//	// 定义接口标题
	//	info->summary = ZH_WORDS_GETTER("sample.post.summary");
	//	// 定义响应参数格式
	//	API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	//}
	//// 3.2 定义新增接口处理
	//ENDPOINT(API_M_POST, "/sample", addSample, BODY_DTO(SampleDTO::Wrapper, dto)) {
	//	// 响应结果
	//	API_HANDLER_RESP_VO(execAddSample(dto));
	//}
	//// 3.1 定义修改接口描述
	//ENDPOINT_INFO(modifySample) {
	//	// 定义接口标题
	//	info->summary = ZH_WORDS_GETTER("sample.put.summary");
	//	// 定义响应参数格式
	//	API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	//}
	//// 3.2 定义修改接口处理
	//ENDPOINT(API_M_PUT, "/sample", modifySample, BODY_DTO(SampleDTO::Wrapper, dto)) {
	//	// 响应结果
	//	API_HANDLER_RESP_VO(execModifySample(dto));
	//}
	//// 3.1 定义删除接口描述
	//ENDPOINT_INFO(removeSample) {
	//	// 定义接口标题
	//	info->summary = ZH_WORDS_GETTER("sample.delete.summary");
	//	// 定义响应参数格式
	//	API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	//}
	//// 3.2 定义删除接口处理
	//ENDPOINT(API_M_DEL, "/sample", removeSample, BODY_DTO(SampleDTO::Wrapper, dto)) {
	//	// 响应结果
	//	API_HANDLER_RESP_VO(execRemoveSample(dto));
	//}

	//// [其他] 定义一个单文件上传接口
	//ENDPOINT(API_M_POST, "/upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
	//	/* 创建multipart容器 */
	//	auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
	//	/* 创建multipart读取器 */
	//	multipart::Reader multipartReader(multipartContainer.get());
	//	/* 配置读取器读取表单字段 */
	//	multipartReader.setPartReader("nickname", multipart::createInMemoryPartReader(-1 /* max-data-size */));
	//	multipartReader.setPartReader("age", multipart::createInMemoryPartReader(-1 /* max-data-size */));
	//	/* 配置读取器读取文件到文件 */
	//	multipartReader.setPartReader("file", multipart::createFilePartReader("public/static/file/test.png"));
	//	/* 读取请求体中的数据 */
	//	request->transferBody(&multipartReader);
	//	/* 打印part数量 */
	//	OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
	//	/* 获取表单数据 */
	//	auto nickname = multipartContainer->getNamedPart("nickname");
	//	auto age = multipartContainer->getNamedPart("age");
	//	/* 断言表单数据是否正确 */
	//	OATPP_ASSERT_HTTP(nickname, Status::CODE_400, "nickname is null");
	//	OATPP_ASSERT_HTTP(age, Status::CODE_400, "age is null");
	//	/* 打印应表单数据 */
	//	OATPP_LOGD("Multipart", "nickname='%s'", nickname->getPayload()->getInMemoryData()->c_str());
	//	OATPP_LOGD("Multipart", "age='%s'", age->getPayload()->getInMemoryData()->c_str());
	//	/* 获取文件部分 */
	//	auto filePart = multipartContainer->getNamedPart("file");
	//	/* 断言文件是否获取到 */
	//	OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file is null");
	//	/* 打印文件名称 */
	//	OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());
	//	/* 响应OK */
	//	return createResponse(Status::CODE_200, "OK");
	//}
	//// [其他] 定义一个多文件上传接口
	//ENDPOINT(API_M_POST, "/upload-more", uploadFileMore, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
	//	/* 创建multipart容器 */
	//	auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
	//	/* 创建multipart读取器 */
	//	multipart::Reader multipartReader(multipartContainer.get());
	//	/* 配置读取器读取文件到文件 */
	//	multipartReader.setPartReader("file0", multipart::createFilePartReader("public/static/file/test1.png"));
	//	multipartReader.setPartReader("file1", multipart::createFilePartReader("public/static/file/test2.png"));
	//	/* 读取请求体中的数据 */
	//	request->transferBody(&multipartReader);
	//	/* 获取文件部分 */
	//	auto file0 = multipartContainer->getNamedPart("file0");
	//	auto file1 = multipartContainer->getNamedPart("file1");
	//	/* 断言文件是否获取到 */
	//	OATPP_ASSERT_HTTP(file0, Status::CODE_400, "file0 is null");
	//	OATPP_ASSERT_HTTP(file1, Status::CODE_400, "file1 is null");
	//	/* 响应OK */
	//	return createResponse(Status::CODE_200, "OK");
	//}
private:
	// 3.3 演示分页查询数据
	AssignInfoQueryJsonVO::Wrapper execAssignQuery(const AssignInfoQuery::Wrapper& query, const PayloadDTO& payload);
	//// 3.3 演示新增数据
	//Uint64JsonVO::Wrapper execAddSample(const SampleDTO::Wrapper& dto);
	//// 3.3 演示修改数据
	//Uint64JsonVO::Wrapper execModifySample(const SampleDTO::Wrapper& dto);
	//// 3.3 演示删除数据
	//Uint64JsonVO::Wrapper execRemoveSample(const SampleDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_