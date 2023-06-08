#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/19 14:44:00

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _EMPLOYEE_INFOMATION_CONTROLLER
#define _EMPLOYEE_INFOMATION_CONTROLLER

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/EmployeeInformationPageQuery/EmployeeInformationPageQuery.h"
#include "domain/vo/EmployeeInformation/EmployeeInformationVO.h"
//#include "domain/dto/AddEmployeeAssignInfo/AddEmployeeAssignInfo.h"
#include "domain/dto/EmployeeInformationPageQuery/EmployeeInformationPageQueryDTO.h"
#include "CustomerAuthorizeHandler.h"
#include "../../../lib-oatpp/include/domain/dto/PayloadDTO.h"
#include "domain/dto/importInfo/ImportInfoDTO.h"
#include "domain/vo/importInfo/importInfoVO.h"
#include "iostream"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "SimpleDateTimeFormat.h"
#include "CommonMacros.h"
#include "CharsetConvertHepler.h"
#include "domain/query/postSet/PostDetailQuery.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

//定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController)
/*
员工信息控制器
*/
class EmployeeInformationController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(EmployeeInformationController);
public: // 定义接口

	//定义分页查询员工列表接口端点描述
	ENDPOINT_INFO(PageQueryInfo) {
		//定义接口标题
		info->summary = ZH_WORDS_GETTER("member.field.summarypage");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		//定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(EmployeeInformationPageJsonVO);
		//定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		//编号
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("employee.field.id");
		info->queryParams["id"].addExample("default", String("1921****"));
		info->queryParams["id"].required = false;
		//姓名
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("employee.field.name");
		info->queryParams["name"].addExample("default", String("李**"));
		info->queryParams["name"].required = false;
		//组织
		info->queryParams.add<String>("organize").description = ZH_WORDS_GETTER("employee.field.organize");
		info->queryParams["organize"].addExample("default", String("N"));
		info->queryParams["organize"].required = false;
		//部门
		info->queryParams.add<String>("depart").description = ZH_WORDS_GETTER("employee.field.depart");
		info->queryParams["depart"].addExample("default", String("N"));
		info->queryParams["depart"].required = false;
		//职务
		info->queryParams.add<String>("job").description = ZH_WORDS_GETTER("employee.field.job");
		info->queryParams["job"].addExample("default", String("N"));
		info->queryParams["job"].required = false;
		//岗位
		info->queryParams.add<String>("post").description = ZH_WORDS_GETTER("employee.field.post");
		info->queryParams["post"].addExample("default", String("N"));
		info->queryParams["post"].required = false;
		//证件号
		info->queryParams.add<String>("idMum").description = ZH_WORDS_GETTER("employee.field.idMum");
		info->queryParams["idMum"].addExample("default", String("2665643635********"));
		info->queryParams["idMum"].required = false;
		//出生日期
		info->queryParams.add<String>("birthday").description = ZH_WORDS_GETTER("employee.field.birthday");
		info->queryParams["birthday"].addExample("default", String("1992-10-18 00:00:00"));
		info->queryParams["birthday"].required = false;
		// 年龄
		info->queryParams.add<UInt32>("age").description = ZH_WORDS_GETTER("employee.field.age");
		info->queryParams["age"].addExample("default", UInt32(20));
		info->queryParams["age"].required = false;
		//手机号码
		info->queryParams.add<String>("phone").description = ZH_WORDS_GETTER("employee.field.phone");
		info->queryParams["phone"].addExample("default", String("159182*****"));
		info->queryParams["phone"].required = false;
		//员工状态
		info->queryParams.add<String>("state").description = ZH_WORDS_GETTER("employee.field.state");
		info->queryParams["state"].addExample("default", String("50"));
		info->queryParams["state"].required = false;

	}
	//定义分页查询员工列表接口端点处理
	ENDPOINT(API_M_GET, "/c3-employee-info/page-query", PageQueryInfo, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		//解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, EmployeeInformationPageQuery, queryParams);
		//响应结果
		API_HANDLER_RESP_VO(execEmployeeInformation(query, authObject->getPayload()));
	}

	//定义导入员工信息接口端点描述	
	ENDPOINT_INFO(importEmployeeInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("importInfo.import.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ImportJobJsonVO);
		// 定义参数描述
		info->queryParams.add<String>("fileType").description = ZH_WORDS_GETTER("importInfo.import.fileType");
		info->queryParams["fileType"].addExample("default", String("xlsx"));
		info->queryParams["fileType"].required = false;
		info->queryParams.add<String>("sheetName").description = ZH_WORDS_GETTER("importInfo.import.sheetName");
		info->queryParams["sheetName"].addExample("default", String("Sheet1"));
		info->queryParams["sheetName"].required = true;
		info->queryParams.add<String>("file").description = ZH_WORDS_GETTER("importInfo.import.file");
		info->queryParams["file"].required = true;
	}
	//定义导入员工信息接口端点处理
	ENDPOINT(API_M_POST, "/c3-employee-info/import-info", importEmployeeInfo, API_HANDLER_AUTH_PARAME, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
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
		filePath->append("JobSet.xlsx");
		multipartReader.setPartReader("file", multipart::createFilePartReader(filePath));

		//判断目录是否存在，不存在创建目录
		string fileName = std::string(filePath);
		auto dir = fileName.substr(0, fileName.find_last_of("/") + 1);
		const size_t dirLen = dir.length();
		if (dirLen > MAX_DIR_LEN)
		{
			std::cout << "ExcelComponent 135: excel save fail(file path too long)" << std::endl;
			return createResponse(Status::CODE_401, "");
		}
		char tmpDirPath[MAX_DIR_LEN] = { 0 };
		for (size_t i = 0; i < dirLen; i++)
		{
			tmpDirPath[i] = dir[i];
			if (tmpDirPath[i] == '/')
			{
				if (ACCESS(tmpDirPath, 0) != 0)
				{
					if (MKDIR(tmpDirPath) != 0)
					{
						std::cout << "ExcelComponent 148: excel save fail(create dir " << tmpDirPath << " fail)" << std::endl;
						return createResponse(Status::CODE_401, "");
					}
				}
			}
		}

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
		if (fileType != "csv" && fileType != "xls" && fileType != "xlsx" && sheetName != "")
		{
			return createResponse(Status::CODE_400, "error in params");
		}

		/* 获取文件部分 */
		auto filePart = multipartContainer->getNamedPart("file");
		/* 断言文件是否获取到 */
		OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file upload error");
		/* 打印文件名称 */
		OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());

		auto dto = ImportInfoDTO::createShared(String(fileType), String(sheetName), filePath);
		// 响应结果
		API_HANDLER_RESP_VO(execImportEmployeeInfo(dto, authObject->getPayload()));
	}

	//定义导出员工信息(导出本页在前端完成)接口端点描述	
	ENDPOINT_INFO(exportEmployeeInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("importInfo.export.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 添加默认授权参数
		API_DEF_ADD_AUTH();
	}
	//定义导出员工信息(导出本页在前端完成)接口端点处理
	ENDPOINT(API_M_GET, PATH_TO_STAFFING("/c3-employee-info/export-info"), exportEmployeeInfo, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(query, PostDetailQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execExportEmployeeInfo(query));
	}

	//定义新增员工信息接口端点描述
	ENDPOINT_INFO(addEmployee) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("orgsector.field.summary");
		// 添加默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//定义新增员工信息接口端点处理
	ENDPOINT(API_M_POST, "/c3-employee-info/add-new-info", addEmployee, API_HANDLER_AUTH_PARAME, BODY_DTO(EmployeeInformationDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddEmployee(dto, authObject->getPayload()));
	}
private:// 定义接口执行函数

	//分页查询员工列表
	EmployeeInformationPageJsonVO::Wrapper execEmployeeInformation(const EmployeeInformationPageQuery::Wrapper& query, const PayloadDTO& payload);
	//导入员工信息
	ImportJobJsonVO::Wrapper execImportEmployeeInfo(const ImportInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	//导出员工信息(导出本页在前端完成)
	StringJsonVO::Wrapper execExportEmployeeInfo(const PostDetailQuery::Wrapper& query);
	//新增员工信息
	Uint64JsonVO::Wrapper execAddEmployee(const EmployeeInformationDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EMPLOYEE_INFOMATION_CONTROLLER
