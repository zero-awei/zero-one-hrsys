#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: jun
 @Date: 2023/05/24 20:04:52

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
#ifndef _IMPORTLANGUAGECONTROLLER_H_
#define _IMPORTLANGUAGECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "SimpleDateTimeFormat.h"
#include "CharsetConvertHepler.h"
#include "domain/dto/importLanguage/ImportLanguageDTO.h"

// 文件上传
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)
/**
 * 语言能力控制器 - 导入语言
 * 接收前端请求解析数据表名、文件格式、表格文件并保存到主机
 * 使用表格文件中的数据执行批量新增操作
 * 负责人：君
 */
class ImportLanguageController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ImportLanguageController);
public: // 定义接口
	//定义一个单文件上传接口描述
	ENDPOINT_INFO(importLanguage)
	{
		//定义接口标题
		info->summary = ZH_WORDS_GETTER("language.post.file");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		//API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义其他表单参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "fireType", ZH_WORDS_GETTER("language.post.fileType"), "xlsx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "sheetName", ZH_WORDS_GETTER("language.post.sheetName"), "Sheet1", true);
		API_DEF_ADD_QUERY_PARAMS(String, "file", ZH_WORDS_GETTER("language.post.path"), "", true);
		API_DEF_ADD_QUERY_PARAMS(String, "personID", ZH_WORDS_GETTER("sample.field.id"), "66958E87-91A4-4DA8-8124-060E93B47EBE", false);
	};
	//定义一个单文件上传接口处理
	ENDPOINT(API_M_POST, "/c3-language-info/upload-language", importLanguage, /*API_HANDLER_AUTH_PARAME,*/ REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		/* 创建multipart容器 */
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		/* 创建multipart读取器 */
		multipart::Reader multipartReader(multipartContainer.get());
		/* 配置读取器读取表单字段 */
		multipartReader.setPartReader("fileType", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("sheetName", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		/* 配置读取器读取文件到文件 */
		String filePath = "public/static/file";
		filePath->append(SimpleDateTimeFormat::format("%Y-%m-%d_%H-%M-%S_"));
		filePath->append("LanguageSet.xlsx");
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
		auto sheet = multipartContainer->getNamedPart("SheetName");
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
		
		auto dto = ImportLanguageDTO::createShared();
		/* 响应OK */
		API_HANDLER_RESP_VO(execImportLanguage(dto/*, authObject->getPayload()*/));
	}
private: // 定义接口执行函数
	//定义修改接口执行函数
	//Uint64JsonVO::Wrapper execUpdateLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execImportLanguage(const ImportLanguageDTO::Wrapper & dto/*, const PayloadDTO & payload*/);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_IMPORTLANGUAGECONTROLLER_H_