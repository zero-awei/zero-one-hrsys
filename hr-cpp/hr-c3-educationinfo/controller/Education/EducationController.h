/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/18 9:45:52
*/
#ifndef _EDUCATIOCONTROLLER_H_
#define _EDUCATIONCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/EducationPage/EducationPageQuery.h"
#include "domain/query/EducationSingle/EducationSingleQuery.h"
#include "domain/dto/Education/EducationDTO.h"
#include "charsetconvertHepler.h"

//文件上传
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;
#include OATPP_CODEGEN_BEGIN(ApiController)

class EducationController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(EducationController);
public: // 接口
	// 功能1 分页查询指定姓名员工的教育信息：接口描述
	ENDPOINT_INFO(gueryEducationPage) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("gueryEducationPage");//中文字典zh-dict.yaml
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		//API_DEF_ADD_RSP_JSON_WRAPPER(EducationPageJsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述：根据员工姓名查询
		info->queryParams.add<String>("pimpersonname").description = ZH_WORDS_GETTER("gueryEducationPage");
		info->queryParams["pimpersonname"].addExample("default", String("Chen Jun"));
		info->queryParams["pimpersonname"].required = false;
	}
	// 功能1 分页查询指定姓名员工的教育信息：接口处理
	ENDPOINT(API_M_GET, "/education/guery-Education-Page", gueryEducationPage, API_HANDLER_AUTH_PARAME,  QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(educationQuery, EducationPageQuery, queryParams);//将queryParams转换为GetEducationPageQuery 命名为educationQuery
		// 响应结果
		API_HANDLER_RESP_VO(execQueryEducationPage(educationQuery, authObject->getPayload()));
	}
	// 功能2 单独查询指定姓名员工的教育信息：接口描述
	ENDPOINT_INFO(queryEducationSingle) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("queryEducationSingle");//中文字典zh-dict.yaml
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		//API_DEF_ADD_RSP_JSON_WRAPPER(EducationPageJsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义其他表单参数描述：根据员工姓名查询
		info->queryParams.add<String>("pimpersonname").description = ZH_WORDS_GETTER("getEducationPageQuery");
		info->queryParams["pimpersonname"].addExample("default", String("Chen Jun"));
	}
	// 功能2 单独查询指定姓名员工的教育信息：接口处理
	ENDPOINT(API_M_GET, "/education/query-Education-Single", queryEducationSingle, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(educationSingle, EducationSingleQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryEducationSingle(educationSingle, authObject->getPayload()));
	}
	// 功能3 单条新增指定姓名员工的教育信息：接口描述
	ENDPOINT_INFO(addEducationSingle) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("addEducationSingle");
		// 定义响应参数格式
		//API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 功能3 单条新增指定姓名员工的教育信息：接口处理
	ENDPOINT(API_M_POST, "/education/add-Education-Single", addEducationSingle, BODY_DTO(EducationDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddEducationSingle(dto));
	}

	// 功能4 单条修改指定姓名员工的教育信息：接口描述
	ENDPOINT_INFO(modifyEducationSingle) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("modifyEducationSingle");
		// 定义响应参数格式
		//API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 功能4 修改指定姓名员工的教育信息：接口处理
	ENDPOINT(API_M_PUT, "/education/modify-Education-Single", modifyEducationSingle, BODY_DTO(EducationDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyEducationSingle(dto));
	}
	// 功能5 删除指定姓名员工的教育信息：接口描述
	ENDPOINT_INFO(removeEducation) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("removeEducation");
		// 定义响应参数格式
		//API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 功能5 删除指定姓名员工的教育信息：接口处理
	ENDPOINT(API_M_DEL, "/education/remove-Education", removeEducation, BODY_DTO(EducationDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemoveEducation(dto));
	}

	// 功能6 单个文件上传教育信息：接口描述
		//* 接收前端请求解析数据表名、文件格式、表格文件并保存到主机
		//* 使用表格文件中的数据执行批量新增操作，并返回装载新增id的List信息

	ENDPOINT_INFO(importEducation) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("jobSet.import.summary");
		// 定义默认授权参数
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		//API_DEF_ADD_RSP_JSON_WRAPPER(ImportJobJsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义分页参数描述
		info->queryParams.add<String>("/Education/file-type").description = ZH_WORDS_GETTER("importEducation.fileType");
		info->queryParams["fileType"].addExample("default", String("xlsx"));
		info->queryParams["fileType"].required = false;
		info->queryParams.add<String>("/Education/sheet-name").description = ZH_WORDS_GETTER("importEducation.sheetName");
		info->queryParams["sheetName"].addExample("default", String("Sheet1"));
		info->queryParams["sheetName"].required = true;
		info->queryParams.add<String>("/Education/file").description = ZH_WORDS_GETTER("importEducation.file");
		info->queryParams["file"].required = true;
	}
	// 功能6 单个文件上传教育信息：接口处理
	ENDPOINT(API_M_POST, "/education/upload-Education", importEducation,REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		///* 创建multipart容器 */
		//auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		///* 创建multipart读取器 */
		//multipart::Reader multipartReader(multipartContainer.get());
		///* 配置读取器读取表单字段 */
		//multipartReader.setPartReader("fileType", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		//multipartReader.setPartReader("sheetName", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		///* 配置读取器读取文件到文件 */
		//String filePath = "public/static/file/";
		//filePath->append(SimpleDateTimeFormat::format("%Y-%m-%d_%H-%M-%S_"));
		//filePath->append("JobSet.xlsx");
		//multipartReader.setPartReader("file", multipart::createFilePartReader(filePath));

		///* 读取请求体中的数据 */
		//request->transferBody(&multipartReader);
		//if (multipartContainer->count() != 3)
		//{
		//	/* 打印part数量 */
		//	OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
		//	return createResponse(Status::CODE_400, "error in params");
		//}

		///* 获取表单数据 */
		//auto type = multipartContainer->getNamedPart("fileType");
		//auto sheet = multipartContainer->getNamedPart("sheetName");
		///* 断言表单数据是否正确 */
		//OATPP_ASSERT_HTTP(type, Status::CODE_400, "fileType is null");
		//OATPP_ASSERT_HTTP(sheet, Status::CODE_400, "sheetName is null");

		//string fileType = CharsetConvertHepler::utf8ToAnsi(type->getPayload()->getInMemoryData()->c_str());
		//string sheetName = CharsetConvertHepler::utf8ToAnsi(sheet->getPayload()->getInMemoryData()->c_str());
		//if (fileType != "csv" && fileType != "xls" && fileType != "xlsx" && sheetName != "")
		//{
		//	return createResponse(Status::CODE_400, "error in params");
		//}

		///* 获取文件部分 */
		//auto filePart = multipartContainer->getNamedPart("file");
		///* 断言文件是否获取到 */
		//OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file upload error");
		///* 打印文件名称 */
		//OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());
		//auto dto = ImportJobDTO::createShared(String(fileType), String(sheetName), filePath);
		auto dto = EducationDTO::createShared();
		// 响应结果
		API_HANDLER_RESP_VO(execImportEducation(dto));
	}

private: // 接口执行函数
	// 功能1 分页查询指定姓名员工的教育信息：接口执行函数
	StringJsonVO::Wrapper execQueryEducationPage(const EducationPageQuery::Wrapper& query, const PayloadDTO& payload);
	// 功能2 单条查询指定姓名员工的教育信息：接口执行函数
	StringJsonVO::Wrapper execQueryEducationSingle(const EducationSingleQuery::Wrapper& query, const PayloadDTO& payload);
	// 功能3 单条新增指定姓名员工的教育信息：接口执行函数
	StringJsonVO::Wrapper execAddEducationSingle(const EducationDTO::Wrapper& dto);
	// 功能4 修改指定姓名员工的教育信息：接口执行函数
	StringJsonVO::Wrapper execModifyEducationSingle(const EducationDTO::Wrapper& dto);
	// 功能5 删除指定姓名员工的教育信息：接口执行函数
	StringJsonVO::Wrapper execRemoveEducation(const EducationDTO::Wrapper& dto);
	// 功能6 单个文件上传教育信息：接口处理
	StringJsonVO::Wrapper execImportEducation(const EducationDTO::Wrapper& dto);


};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_GETEDUCATIONPAGECONTROLLER_H_#pragma once
#include "CharsetConvertHepler.h"
#include "domain/query/EducationSingle/EducationSingleQuery.h"
