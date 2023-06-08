#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ahao
 @Date: 2023/5/22 14:58:43

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
#ifndef _ASSIGN_CONTROLLER_
#define _ASSIGN_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/assignInfo/AssignInfoQueryDTO.h"
#include "domain/vo/assignInfo/AssignInfoQueryVO.h"
#include "domain/dto/assignInfo/AssignInfoCommonDTO.h"
#include "domain/dto/assignInfo/AssignInfoDeleteDTO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/query/assignInfo/AssignInfoQuery.h"
#include "domain/query/PageQuery.h"
#include "domain/query/assignInfo/AssignInfoQueryDetail.h"
#include "domain/query/assignInfo/AssignExportQuery.h"
#include "SimpleDateTimeFormat.h"
#include "CommonMacros.h"
#include "domain/vo/assignInfo/ImportAssignInfoVO.h"
#include "CharsetConvertHepler.h"
#include "domain/dto/assignInfo/ImportAssignInfoDTO.h"
#include <iostream>
#include "domain/dto/assignInfo/MulDeleteAssignInfoDTO.h"
#include "domain/vo/assignInfo/MulDeleteAssignInfoVO.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;



// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 控制器，供员工分配信息使用
 */
class AssignInfoController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(AssignInfoController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(assignQuery) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("employee.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AssignInfoPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("assignId").description = ZH_WORDS_GETTER("employee.t_pimperson.assignId");
		info->queryParams["assignId"].addExample("default", String(""));
		info->queryParams["assignId"].required = false;
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("employee.t_pimperson.id");
		info->queryParams["id"].addExample("default", String("F943C793-520E-46FA-8F6F-5EF08AC1F770"));
		info->queryParams["id"].required = false;
		info->queryParams.add<String>("startTime").description = ZH_WORDS_GETTER("employee.t_pimperson.startTime");
		info->queryParams["startTime"].addExample("default", String(""));
		info->queryParams["startTime"].required = false;
		info->queryParams.add<String>("endTime").description = ZH_WORDS_GETTER("employee.t_pimperson.endTime");
		info->queryParams["endTime"].addExample("default", String(""));
		info->queryParams["endTime"].required = false;
	}
	ENDPOINT(API_M_GET, "/c3-assign-info/query", assignQuery, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, AssignInfoQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execAssignQuery(userQuery, authObject->getPayload()));
	}
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addAssignInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("employee.post.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/c3-assign-info/add", addAssignInfo, API_HANDLER_AUTH_PARAME, BODY_DTO(AssignInfoCommonDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddAssignInfo(dto,authObject->getPayload()));
	}
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(deleteAssignInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("employee.delete.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		//API_DEF_ADD_QUERY_PARAMS(String, "assignId", ZH_WORDS_GETTER("employee.t_pimperson.assignId"), "", true);
	}
	// 3.2 定义删除接口处理
	ENDPOINT(API_M_DEL, "/c3-assign-info/delete", deleteAssignInfo, API_HANDLER_AUTH_PARAME, BODY_DTO(AssignInfoDeleteDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execDeleteAssignInfo(dto));
	}
	// 3.1 定义修改接口描述
	ENDPOINT_INFO(modifyAssignInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("employee.put.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/c3-assign-info/modify", modifyAssignInfo, API_HANDLER_AUTH_PARAME,BODY_DTO(AssignInfoCommonDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyAssignInfo(dto,authObject->getPayload()));
	}
	//定义导入员工信息接口端点描述	
	ENDPOINT_INFO(importAssignInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("importInfo.import.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ImportAssignJsonVO);
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
	//定义导入员工分配信息接口端点处理
	ENDPOINT(API_M_POST, "/c3-assign-info/import", importAssignInfo, API_HANDLER_AUTH_PARAME, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
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

		auto dto = ImportAssignInfoDTO::createShared(String(fileType), String(sheetName), filePath);
		// 响应结果
		API_HANDLER_RESP_VO(execImportAssignInfo(dto, authObject->getPayload()));
	}

	// 3.1 定义查询接口描述
	ENDPOINT_INFO(assignQueryDetail) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("employee.get.detail");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AssignInfoQueryJsonVO);
		//详细查询分配信息不需要分页
		// 定义分页参数描述
		//API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("assignId").description = ZH_WORDS_GETTER("employee.t_pimperson.assignId");
		info->queryParams["assignId"].addExample("default", String("E3D4260E-D2D6-4884-A6BE-FF6547BDF229"));
		info->queryParams["assignId"].required = true;
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/c3-assign-info/query-detail", assignQueryDetail, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, AssignInfoQueryDetail, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execAssignQueryDetail(userQuery, authObject->getPayload()));
	}
	// 删除多条数据
	ENDPOINT_INFO(deleteMultipleByAssignId) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("employee.delete.multiple");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(MulDeleteAssignInfoVO);
	}
	ENDPOINT(API_M_DEL, "/c3-assign-info/multiple-delete", deleteMultipleByAssignId, API_HANDLER_AUTH_PARAME, BODY_DTO(MulDeleteAssignInfoDTO::Wrapper, dto)) {
		API_HANDLER_RESP_VO(execMulDeleteAssignInfoById(dto, authObject->getPayload()));
	}

	ENDPOINT_INFO(exportAssignInfo) {
		info->summary = ZH_WORDS_GETTER("export.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("employee.field.id");
		info->queryParams["id"].addExample("default", String("0000001"));
		info->queryParams["id"].required = true;
	}
	ENDPOINT(API_M_GET, "/export-assign-info", exportAssignInfo, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		API_HANDLER_QUERY_PARAM(query, AssignExportQuery, qps);
		API_HANDLER_RESP_VO(execExportAssign(query));
	}

private:
	StringJsonVO::Wrapper execAddAssignInfo(const AssignInfoCommonDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execDeleteAssignInfo(const AssignInfoDeleteDTO::Wrapper& dto);
	//导入员工信息
	ImportAssignJsonVO::Wrapper execImportAssignInfo(const ImportAssignInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	AssignInfoPageJsonVO::Wrapper execAssignQuery(const AssignInfoQuery::Wrapper& query, const PayloadDTO& payload);
	AssignInfoQueryJsonVO::Wrapper execAssignQueryDetail(const AssignInfoQueryDetail::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execModifyAssignInfo(const AssignInfoCommonDTO::Wrapper& dto, const PayloadDTO& payload);
	MulDeleteAssignInfoVO::Wrapper execMulDeleteAssignInfoById(const MulDeleteAssignInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execExportAssign(const AssignExportQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _ASSIGN_CONTROLLER_