/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/18 9:45:52
*/
#ifndef _EDUCATIOCONTROLLER_H_
#define _EDUCATIONCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "SimpleDateTimeFormat.h"
#include "domain/query/educationPage/EducationPageQuery.h"
#include "domain/query/educationSingle/EducationSingleQuery.h"
#include "domain/query/educationExport/EducationExportQuery.h"
#include "domain/dto/education/EducationDTO.h"
#include "domain/dto/educationDelete/EducationDeleteDTO.h"
#include "domain/dto/educationImport/EducationImportDTO.h"
#include "domain/vo/education/EducationJsonVO.h"
#include "domain/vo/educationImport/EducationImportVO.h"
#include "CharsetConvertHepler.h"
#include "domain/dto/educationAdd/EducationAddDTO.h"


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
	// 功能1 分页查询指定员工的教育信息：接口描述
	ENDPOINT_INFO(gueryEducationPage) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("gueryEducationPage");//中文字典zh-dict.yaml
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(EducationPageJsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义分页参数描述//分页列表+分页编号 + 员工编号 pimpersonid
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述：根据员工id查询
		info->queryParams.add<String>("PIMPERSONID").description = ZH_WORDS_GETTER("education.PIMPERSONID");
		info->queryParams["PIMPERSONID"].addExample("default", String("5F8310F7-6E69-4D28-901F-97FFAB32E721"));
		info->queryParams["PIMPERSONID"].required = false;
		/*info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("education.id");
		info->queryParams["pimpersonid"].addExample("default", String("02A0F00B-506C-4F02-B4A1-9524F4043CF9"));
		info->queryParams["pimpersonid"].required = false;
		info->queryParams.add<String>("pimpersonname").description = ZH_WORDS_GETTER("gueryEducationPage");
		info->queryParams["pimpersonname"].addExample("default", String(""));
		info->queryParams["pimpersonname"].required = false;
		info->queryParams.add<String>("sort").description = ZH_WORDS_GETTER("t_pimperson.sort");
		info->queryParams["sort"].addExample("default", String("asc"));
		info->queryParams["sort"].required = false;*/
	}
	// 功能1 分页查询指定员工的教育信息：接口处理
	ENDPOINT(API_M_GET, "/c3-education-info/guery-education-page", gueryEducationPage, API_HANDLER_AUTH_PARAME,  QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(educationQuery, EducationPageQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryEducationPage(educationQuery, authObject->getPayload()));
	}
	
	// 功能2 单独查询指定员工的教育信息：接口描述
	ENDPOINT_INFO(queryEducationSingle) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("queryEducationSingle");//中文字典zh-dict.yaml
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(EducationSingleJsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义其他表单参数描述：根据教育标识查询
		info->queryParams.add<String>("PIMPERSONID").description = ZH_WORDS_GETTER("education.PIMPERSONID");
		info->queryParams["PIMPERSONID"].addExample("default", String("5F8310F7-6E69-4D28-901F-97FFAB32E721"));
		info->queryParams["PIMPERSONID"].required = false;
		//info->queryParams.add<String>("pimpersonname").description = ZH_WORDS_GETTER("getEducationPageQuery");
		//info->queryParams["pimpersonname"].addExample("default", String("ChenJun"));
	}
	// 功能2 单独查询指定员工的教育信息：接口处理
	ENDPOINT(API_M_GET, "/c3-education-info/query-education-single", queryEducationSingle, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(educationSingle, EducationSingleQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryEducationSingle(educationSingle, authObject->getPayload()));
	}
	
	// 功能3 单条新增指定员工的教育信息：接口描述
	ENDPOINT_INFO(addEducationSingle) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("addEducationSingle");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//// 教育信息标识 （必填）
		//info->queryParams.add<String>("PIMEDUCATIONID").description = ZH_WORDS_GETTER("education.PIMEDUCATIONID");
		//info->queryParams["PIMEDUCATIONID"].addExample("default", String("114514114514"));
		//info->queryParams["PIMEDUCATIONID"].required = false;
		//// 学历
		//info->queryParams.add<String>("XL").description = ZH_WORDS_GETTER("education.XL");
		//info->queryParams["XL"].addExample("default", String(u8"带专"));
		//info->queryParams["XL"].required = false;
		//// 入学时间
		//info->queryParams.add<UInt64>("QSSJ").description = ZH_WORDS_GETTER("education.QSSJ");
		//info->queryParams["QSSJ"].addExample("default", UInt64(19210606));
		//info->queryParams["QSSJ"].required = false;
		//// 毕业时间
		//info->queryParams.add<UInt64>("JSSJ").description = ZH_WORDS_GETTER("education.JSSJ");
		//info->queryParams["JSSJ"].addExample("default", UInt64(19780606));
		//info->queryParams["JSSJ"].required = false;
		//// 毕业院校
		//info->queryParams.add<String>("BYYX").description = ZH_WORDS_GETTER("education.BYYX");
		//info->queryParams["BYYX"].addExample("default", String(u8"黑龙江科技大学"));
		//info->queryParams["BYYX"].required = false;
		//// 一级学科
		//info->queryParams.add<String>("XKML").description = ZH_WORDS_GETTER("education.XKML");
		//info->queryParams["XKML"].addExample("default", String(u8"生物学"));
		//info->queryParams["XKML"].required = false;
		//// 所学专业
		//info->queryParams.add<String>("SXZY").description = ZH_WORDS_GETTER("education.SXZY");
		//info->queryParams["SXZY"].addExample("default", String(u8"母猪的产后护理"));
		//info->queryParams["SXZY"].required = false;
		//// 学习形式
		//info->queryParams.add<String>("XLLX").description = ZH_WORDS_GETTER("education.XLLX");
		//info->queryParams["XLLX"].addExample("default", String(u8"全日制"));
		//info->queryParams["XLLX"].required = false;
		//// 学校性质
		//info->queryParams.add<String>("XXXZ").description = ZH_WORDS_GETTER("education.XXXZ");
		//info->queryParams["XXXZ"].addExample("default", String(u8"双非"));
		//info->queryParams["XXXZ"].required = false;
		//// 是否第一学历
		//info->queryParams.add<Int16>("SFDYXL").description = ZH_WORDS_GETTER("education.SFDYXL");
		//info->queryParams["SFDYXL"].addExample("default", Int16(1));
		//info->queryParams["SFDYXL"].required = false;
		////是否最高学历
		//info->queryParams.add<Int16>("SFZGXL").description = ZH_WORDS_GETTER("education.SFZGXL");
		//info->queryParams["SFZGXL"].addExample("default", Int16(1));
		//info->queryParams["SFZGXL"].required = false;
		//// 毕业证
		//info->queryParams.add<String>("BTZ").description = ZH_WORDS_GETTER("education.BTZ");
		//info->queryParams["BTZ"].addExample("default", String(u8"文件"));
		//info->queryParams["BTZ"].required = false;
		//// 学位证
		//info->queryParams.add<String>("XWZ").description = ZH_WORDS_GETTER("education.XWZ");
		//info->queryParams["XWZ"].addExample("default", String(u8"文件"));
		//info->queryParams["XWZ"].required = false;
		//// 学历验证
		//info->queryParams.add<String>("XLCX").description = ZH_WORDS_GETTER("education.XLCX");
		//info->queryParams["XLCX"].addExample("default", String(u8"文件"));
		//info->queryParams["XLCX"].required = false;
		//// 其他附件
		//info->queryParams.add<String>("FJ").description = ZH_WORDS_GETTER("education.FJ");
		//info->queryParams["FJ"].addExample("default", String(u8"文件"));
		//info->queryParams["FJ"].required = false;
	}
	// 功能3 单条新增指定员工的教育信息：接口处理
	ENDPOINT(API_M_POST, "/c3-education-info/add-education-single", addEducationSingle, API_HANDLER_AUTH_PARAME, BODY_DTO(EducationAddDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddEducationSingle(dto, authObject->getPayload()));
	}

	// 功能4 单条修改指定员工的教育信息：接口描述
	ENDPOINT_INFO(modifyEducationSingle) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("modifyEducationSingle");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//		// 教育信息标识 （必填）
		//info->queryParams.add<String>("PIMEDUCATIONID").description = ZH_WORDS_GETTER("education.PIMEDUCATIONID");
		//info->queryParams["PIMEDUCATIONID"].addExample("default", String("114514114514"));
		//info->queryParams["PIMEDUCATIONID"].required = false;
		//// 学历
		//info->queryParams.add<String>("XL").description = ZH_WORDS_GETTER("education.XL");
		//info->queryParams["XL"].addExample("default", String(u8"带专"));
		//info->queryParams["XL"].required = false;
		//// 入学时间
		//info->queryParams.add<UInt64>("QSSJ").description = ZH_WORDS_GETTER("education.QSSJ");
		//info->queryParams["QSSJ"].addExample("default", UInt64(19210606));
		//info->queryParams["QSSJ"].required = false;
		//// 毕业时间
		//info->queryParams.add<UInt64>("JSSJ").description = ZH_WORDS_GETTER("education.JSSJ");
		//info->queryParams["JSSJ"].addExample("default", UInt64(19780606));
		//info->queryParams["JSSJ"].required = false;
		//// 毕业院校
		//info->queryParams.add<String>("BYYX").description = ZH_WORDS_GETTER("education.BYYX");
		//info->queryParams["BYYX"].addExample("default", String(u8"黑龙江科技大学"));
		//info->queryParams["BYYX"].required = false;
		//// 一级学科
		//info->queryParams.add<String>("XKML").description = ZH_WORDS_GETTER("education.XKML");
		//info->queryParams["XKML"].addExample("default", String(u8"生物学"));
		//info->queryParams["XKML"].required = false;
		//// 所学专业
		//info->queryParams.add<String>("SXZY").description = ZH_WORDS_GETTER("education.SXZY");
		//info->queryParams["SXZY"].addExample("default", String(u8"母猪的产后护理"));
		//info->queryParams["SXZY"].required = false;
		//// 学习形式
		//info->queryParams.add<String>("XLLX").description = ZH_WORDS_GETTER("education.XLLX");
		//info->queryParams["XLLX"].addExample("default", String(u8"全日制"));
		//info->queryParams["XLLX"].required = false;
		//// 学校性质
		//info->queryParams.add<String>("XXXZ").description = ZH_WORDS_GETTER("education.XXXZ");
		//info->queryParams["XXXZ"].addExample("default", String(u8"双非"));
		//info->queryParams["XXXZ"].required = false;
		//// 是否第一学历
		//info->queryParams.add<Int16>("SFDYXL").description = ZH_WORDS_GETTER("education.SFDYXL");
		//info->queryParams["SFDYXL"].addExample("default", Int16(1));
		//info->queryParams["SFDYXL"].required = false;
		////是否最高学历
		//info->queryParams.add<Int16>("SFZGXL").description = ZH_WORDS_GETTER("education.SFZGXL");
		//info->queryParams["SFZGXL"].addExample("default", Int16(1));
		//info->queryParams["SFZGXL"].required = false;
		//// 毕业证
		//info->queryParams.add<String>("BTZ").description = ZH_WORDS_GETTER("education.BTZ");
		//info->queryParams["BTZ"].addExample("default", String(u8"文件"));
		//info->queryParams["BTZ"].required = false;
		//// 学位证
		//info->queryParams.add<String>("XWZ").description = ZH_WORDS_GETTER("education.XWZ");
		//info->queryParams["XWZ"].addExample("default", String(u8"文件"));
		//info->queryParams["XWZ"].required = false;
		//// 学历验证
		//info->queryParams.add<String>("XLCX").description = ZH_WORDS_GETTER("education.XLCX");
		//info->queryParams["XLCX"].addExample("default", String(u8"文件"));
		//info->queryParams["XLCX"].required = false;
		//// 其他附件
		//info->queryParams.add<String>("FJ").description = ZH_WORDS_GETTER("education.FJ");
		//info->queryParams["FJ"].addExample("default", String(u8"文件"));
		//info->queryParams["FJ"].required = false;
	}
	// 功能4 单条修改指定员工的教育信息：接口处理
	ENDPOINT(API_M_PUT, "/c3-education-info/modify-education-single", modifyEducationSingle, API_HANDLER_AUTH_PARAME, BODY_DTO(EducationAddDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyEducationSingle(dto, authObject->getPayload()));
	}
	

	
	// 功能5 删除指定员工的教育信息：接口描述
	ENDPOINT_INFO(removeEducation) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("removeEducation");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		

	}
	// 功能5 删除指定员工的教育信息：接口处理
	//ENDPOINT(API_M_DEL, "/education/remove-Education-Single", removeEducation, API_HANDLER_AUTH_PARAME,PATH(String, deleteId)) {
	ENDPOINT(API_M_DEL, "/c3-education-info/remove-education-single", removeEducation, API_HANDLER_AUTH_PARAME,BODY_DTO(EducationDeleteSingleDTO::Wrapper, dto)) {
		//auto dto = EducationDeleteSingleDTO::createShared();
		//dto->deleteId = deleteId;
		//// 响应结果
		//API_HANDLER_RESP_VO(execRemoveEducation(dto, authObject->getPayload()));
		API_HANDLER_RESP_VO(execRemoveEducation(dto, authObject->getPayload()));
	}


	//// 功能6 批量删除姓名员工的教育信息：接口描述
	//ENDPOINT_INFO(removeEducationNotSingle) {
	//	// 定义接口标题
	//	info->summary = ZH_WORDS_GETTER("removeEducationNotSingle");
	//	// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
	//	API_DEF_ADD_AUTH();
	//	// 定义响应参数格式
	//	API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	//	//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	//}
	//// 功能6 批量删除姓名员工的教育信息：接口处理
	////ENDPOINT(API_M_DEL, "/education/remove-Education-Not-Single", removeEducationNotSingle, API_HANDLER_AUTH_PARAME, BODY_STRING(String, jsonPayload)) {
	//ENDPOINT(API_M_DEL, "/employee-info/remove-education-not-single", removeEducationNotSingle, API_HANDLER_AUTH_PARAME, BODY_DTO(EducationDeleteNotSingleDTO::Wrapper, dto)) {
	//	//const std::shared_ptr<ObjectMapper>& objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
	//	// 解析查询参数
	//	//auto dto = EducationDeleteNotSingleDTO::createShared();
	//	//dto->deleteIds = objectMapper->readFromString<oatpp::List<String>>(jsonPayload);
	//	////测试
	//	//for (const auto& item : *dto->deleteIds) {
	//	//	/*OATPP_LOGD("testEndpoint", "Item: %s", item->c_str());*/
	//	//	cout << item->c_str() << endl;
	//	//}
	//	// 响应结果
	//	API_HANDLER_RESP_VO(execRemoveEducationNotSingle(dto, authObject->getPayload()));
	//}

	// 功能7 单个文件上传教育信息：接口描述
		//* 接收前端请求解析数据表名、文件格式、表格文件并保存到主机
		//* 使用表格文件中的数据执行批量新增操作，并返回装载新增id的List信息
	ENDPOINT_INFO(importEducation) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("importEducation.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(EudacationImportJsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义分页参数描述
		info->queryParams.add<String>("/Education/file-type").description = ZH_WORDS_GETTER("importEducation.fileType");
		info->queryParams["fileType"].addExample("default", String("xlsx"));
		info->queryParams["fileType"].required = false;
		info->queryParams.add<String>("/Education/sheet-name").description = ZH_WORDS_GETTER("importEducation.sheetName");
		info->queryParams["sheetName"].addExample("default", String("Sheet1"));
		info->queryParams["sheetName"].required = false;
		info->queryParams.add<String>("/Education/file").description = ZH_WORDS_GETTER("importEducation.file");
		info->queryParams["file"].required = true;
	}
	// 功能7 单个文件上传教育信息：接口处理
	ENDPOINT(API_M_POST, "/c3-education-info/upload-education", importEducation, API_HANDLER_AUTH_PARAME,REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		/* 创建multipart容器 */
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		/* 创建multipart读取器 */
		multipart::Reader multipartReader(multipartContainer.get());
		/* 配置读取器读取表单字段 */
		multipartReader.setPartReader("fileType", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("sheetName", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		/* 配置读取器读取文件到文件 */
		String filePath = "public/static/file/";
		filePath->append(SimpleDateTimeFormat::format("%Y-%m-%d_%H-%M-%S_"));
		filePath->append("EducationSet.xlsx");
		multipartReader.setPartReader("file", multipart::createFilePartReader(filePath));

		/* 读取请求体中的数据 */
		request->transferBody(&multipartReader);
		if (multipartContainer->count() != 3)
		{
			/* 打印part数量 */
			OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
			return createResponse(Status::CODE_400, "error in params");
		}

		/* 获取表单数据 */
		auto type = multipartContainer->getNamedPart("fileType");
		auto sheet = multipartContainer->getNamedPart("sheetName");
		/* 断言表单数据是否正确 */
		OATPP_ASSERT_HTTP(type, Status::CODE_400, "fileType is null");
		OATPP_ASSERT_HTTP(sheet, Status::CODE_400, "sheetName is null");

		string fileType = CharsetConvertHepler::utf8ToAnsi(type->getPayload()->getInMemoryData()->c_str());
		string sheetName = CharsetConvertHepler::utf8ToAnsi(sheet->getPayload()->getInMemoryData()->c_str());
		if (fileType != "csv" && fileType != "xls" && fileType != "xlsx")
		{
			return createResponse(Status::CODE_400, "error in params");
		}

		/* 获取文件部分 */
		auto filePart = multipartContainer->getNamedPart("file");
		/* 断言文件是否获取到 */
		OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file upload error");
		/* 打印文件名称 */
		OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());

		auto dto = EducationImportDTO::createShared(String(fileType), String(sheetName), filePath);
		//atuo dto = EducationImportDTO::createShared();
		//
		//// 响应结果
		API_HANDLER_RESP_VO(execImportEducation(dto, authObject->getPayload()));

	}


	//功能8 导出教育信息文件
		/* 接收前端请求并解析请求字段，进行数据查询（最大5000条）
		* 对查询出的数据封装成表格文件并上传fastdfs文件服务器
		* 返回值：StringJsonVO - 返回一个下载url字符串
		* 负责人：Andrew
		*/
	//功能8 导出教育信息文件 接口描述
	ENDPOINT_INFO(exportEducation) {
		info->summary = ZH_WORDS_GETTER("sample.field.id");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("employee.field.id");
		info->queryParams["id"].addExample("default", String("0000001"));
		info->queryParams["id"].required = true;
	}
	//功能8 导出教育信息文件 接口处理
	ENDPOINT(API_M_GET, "/c3-education-info/export-eudaction", exportEducation, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		API_HANDLER_QUERY_PARAM(query, EducationExportQuery, qps);
		API_HANDLER_RESP_VO(execExportEducation(query));
	}


private: // 接口执行函数
// 功能1 分页查询指定员工的教育信息：接口执行函数
	EducationPageJsonVO::Wrapper execQueryEducationPage(const EducationPageQuery::Wrapper& query, const PayloadDTO& payload);
	//StringJsonVO::Wrapper execQueryEducationPage(const EducationPageQuery::Wrapper& query, const PayloadDTO& payload);
// 功能2 单条查询指定员工的教育信息：接口执行函数
	EducationSingleJsonVO::Wrapper execQueryEducationSingle(const EducationSingleQuery::Wrapper& query, const PayloadDTO& payload);
	//StringJsonVO::Wrapper execQueryEducationSingle(const EducationSingleQuery::Wrapper& query, const PayloadDTO& payload);
// 功能3 单条新增指定员工的教育信息：接口执行函数
	//StringJsonVO::Wrapper execAddEducationSingle(const EducationSingleDTO::Wrapper& dto, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execAddEducationSingle(const EducationAddDTO::Wrapper& dto, const PayloadDTO& payload);
// 功能4 修改指定员工的教育信息：接口执行函数
	//StringJsonVO::Wrapper execModifyEducationSingle(const EducationSingleDTO::Wrapper& dto, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execModifyEducationSingle(const EducationAddDTO::Wrapper& dto, const PayloadDTO& payload);
// 功能5 删除指定员工的教育信息：接口执行函数
	//Uint64JsonVO::Wrapper execRemoveEducation(const EducationDeleteSingleDTO::Wrapper& dto, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execRemoveEducation(const EducationDeleteSingleDTO::Wrapper& dto, const PayloadDTO& payload);
// 功能6 批量删除指定员工的教育信息：接口执行函数
	//EducationDeleteNotSingleJsonVO::Wrapper execRemoveEducationNotSingle(const EducationDeleteNotSingleDTO::Wrapper& dto, const PayloadDTO& payload);
	//Uint64JsonVO::Wrapper execRemoveEducationNotSingle(const EducationDeleteNotSingleDTO::Wrapper& dto, const PayloadDTO& payload);
	//StringJsonVO::Wrapper execRemoveEducationNotSingle(const EducationDeleteNotSingleDTO::Wrapper& dto, const PayloadDTO& payload);
// 功能7 单个文件上传教育信息：接口执行函数
	EudacationImportJsonVO::Wrapper execImportEducation(const EducationImportDTO::Wrapper& dto, const PayloadDTO& payload);
	//StringJsonVO::Wrapper execImportEducation(const EducationImportDTO::Wrapper& dto, const PayloadDTO& payload);
//功能8 导出教育信息文件:  接口执行函数
	StringJsonVO::Wrapper execExportEducation(const EducationExportQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_GETEDUCATIONPAGECONTROLLER_H_


