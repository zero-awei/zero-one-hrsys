#pragma once
#ifndef _EXPORTEMPLOYEE_CONTROLLER_
#define _EXPORTEMPLOYEE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/do/RosterOfPer/ExportEmployeeDO.h"
#include "domain/dto/RosterOfPer/ExportEmployeeDTO.h"
#include "domain/vo/RosterOfPer/ExportEmployeeVO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
//#include "ApiHelper.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ExportEmployeeController : public oatpp::web::server::api::ApiController {
	
API_ACCESS_DECLARE(ExportEmployeeController); // 2 定义控制器访问入口
public:
	// 3.1 定义查询接口描述
	//ENDPOINT_INFO(queryExportEmployee) {
	//	// 定义接口标题
	//	info->summary = ZH_WORDS_GETTER("ExportEmployee.get.summary");
	//	// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
	//	API_DEF_ADD_AUTH();
	//	// 定义响应参数格式
	//	API_DEF_ADD_RSP_JSON_WRAPPER(ExportEmployeePageJsonVO);
	//	// 定义分页参数描述
	//	API_DEF_ADD_PAGE_PARAMS();
	//	// 定义其他表单参数描述
	//	info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("ExportEmployee.field.name");
	//	info->queryParams["name"].addExample("default", String("li ming"));
	//	info->queryParams["name"].required = false;
	//	info->queryParams.add<String>("sex").description = ZH_WORDS_GETTER("ExportEmployee.field.sex");
	//	info->queryParams["sex"].addExample("default", String("N"));
	//	info->queryParams["sex"].required = false;
	//}
	//// 3.2 定义查询接口处理
	//ENDPOINT(API_M_GET, "/ExportEmployee", queryExportEmployee, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
	//	// 解析查询参数
	//	API_HANDLER_QUERY_PARAM(userQuery, ExportEmployeeQuery, queryParams);
	//	// 响应结果
	//	API_HANDLER_RESP_VO(execQueryExportEmployee(userQuery, authObject->getPayload()));
	//}
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addExportEmployee) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("ExportEmployee.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/ExportEmployee", addExportEmployee, BODY_DTO(ExportEmployeeDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddExportEmployee(dto));
	}
	// 3.1 定义修改接口描述
	ENDPOINT_INFO(modifyExportEmployee) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("ExportEmployee.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/ExportEmployee", modifyExportEmployee, BODY_DTO(ExportEmployeeDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyExportEmployee(dto));
	}
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeExportEmployee) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("ExportEmployee.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义删除接口处理
	ENDPOINT(API_M_DEL, "/ExportEmployee", removeExportEmployee, BODY_DTO(ExportEmployeeDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemoveExportEmployee(dto));
	}

	// [其他] 定义一个单文件上传接口
	ENDPOINT(API_M_POST, "/upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		/* 创建multipart容器 */
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		/* 创建multipart读取器 */
		multipart::Reader multipartReader(multipartContainer.get());
		/* 配置读取器读取表单字段3*/
		multipartReader.setPartReader("nickname", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("age", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		/* 配置读取器读取文件到文件 */
		multipartReader.setPartReader("file", multipart::createFilePartReader("public/static/file/test.png"));
		/* 读取请求体中的数据 */
		request->transferBody(&multipartReader);
		/* 打印part数量 */
		OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
		/* 获取表单数据 */
		auto nickname = multipartContainer->getNamedPart("nickname");
		auto age = multipartContainer->getNamedPart("age");
		/* 断言表单数据是否正确 */
		OATPP_ASSERT_HTTP(nickname, Status::CODE_400, "nickname is null");
		OATPP_ASSERT_HTTP(age, Status::CODE_400, "age is null");
		/* 打印应表单数据 */
		OATPP_LOGD("Multipart", "nickname='%s'", nickname->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "age='%s'", age->getPayload()->getInMemoryData()->c_str());
		/* 获取文件部分 */
		auto filePart = multipartContainer->getNamedPart("file");
		/* 断言文件是否获取到 */
		OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file is null");
		/* 打印文件名称 */
	  	OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());
		/* 响应OK */
		return createResponse(Status::CODE_200, "OK");
	}

	// [其他] 定义一个多文件上传接口
	ENDPOINT(API_M_POST, "/upload-more", uploadFileMore, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		/* 创建multipart容器 */
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		/* 创建multipart读取器 */
		multipart::Reader multipartReader(multipartContainer.get());
		/* 配置读取器读取文件到文件 */
		multipartReader.setPartReader("file0", multipart::createFilePartReader("public/static/file/test1.png"));
		multipartReader.setPartReader("file1", multipart::createFilePartReader("public/static/file/test2.png"));
		/* 读取请求体中的数据 */
		request->transferBody(&multipartReader);
		/* 获取文件部分 */
		auto file0 = multipartContainer->getNamedPart("file0");
		auto file1 = multipartContainer->getNamedPart("file1");
		/* 断言文件是否获取到 */
		OATPP_ASSERT_HTTP(file0, Status::CODE_400, "file0 is null");
		OATPP_ASSERT_HTTP(file1, Status::CODE_400, "file1 is null");
		/* 响应OK */
		return createResponse(Status::CODE_200, "OK");
	}
private: 
	//// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddExportEmployee(const ExportEmployeeDTO::Wrapper& dto);
	//// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyExportEmployee(const ExportEmployeeDTO::Wrapper& dto);
	// //3.3 演示删除数据
	Uint64JsonVO::Wrapper execRemoveExportEmployee(const ExportEmployeeDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _EXPORTEMPLOYEE_CONTROLLER_