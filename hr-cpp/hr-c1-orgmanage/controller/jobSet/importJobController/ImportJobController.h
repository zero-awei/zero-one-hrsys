#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/16 18:28:33

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
#ifndef _IMPORTJOBCONTROLLER_H_
#define _IMPORTJOBCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "SimpleDateTimeFormat.h"
#include "ServerInfo.h"
#include "Macros.h"
#include "domain/dto/jobSet/ImportJobDTO.h"
#include "CharsetConvertHepler.h"
#include "domain/vo/jobSet/ImportJobVO.h"
#include "../lib-common/include/CommonMacros.h"
#include <iostream>

// 文件上传
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"


using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 岗位设置 - 导入岗位
 * 接收前端请求解析数据表名、文件格式、表格文件并保存到主机
 * 使用表格文件中的数据执行批量新增操作，并返回装载新增id的List信息
 * 负责人：Andrew
 */
class ImportJobController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ImportJobController);
public: // 定义接口
	ENDPOINT_INFO(importJob) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("jobSet.import.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ImportJobJsonVO);
		// 定义参数描述
		info->queryParams.add<String>("fileType").description = ZH_WORDS_GETTER("jobSet.import.fileType");
		info->queryParams["fileType"].addExample("default", String("xlsx"));
		info->queryParams["fileType"].required = false;
		info->queryParams.add<String>("sheetName").description = ZH_WORDS_GETTER("jobSet.import.sheetName");
		info->queryParams["sheetName"].addExample("default", String("Sheet1"));
		info->queryParams["sheetName"].required = true;
		info->queryParams.add<String>("file").description = ZH_WORDS_GETTER("jobSet.import.file");
		info->queryParams["file"].required = true;
	}

	ENDPOINT(API_M_POST, PATH_TO_JOBSET("/import-job"), importJob, API_HANDLER_AUTH_PARAME, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
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

		auto dto = ImportJobDTO::createShared(String(fileType), String(sheetName), filePath);
		// 响应结果
		API_HANDLER_RESP_VO(execImportJob(dto, authObject->getPayload()));
	}
private: // 定义接口执行函数
	ImportJobJsonVO::Wrapper execImportJob(const ImportJobDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_IMPORTJOBCONTROLLER_H_