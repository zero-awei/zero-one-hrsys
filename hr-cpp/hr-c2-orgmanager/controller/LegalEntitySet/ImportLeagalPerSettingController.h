#pragma once
/*
 (法人主体设置-导入法人设置)--洛洛
*/
#ifndef _IMPORTLEAGALPERSETTING_CONTROLLER_
#define _IMPORTLEAGALPERSETTING_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "domain/dto/LegalEntitySet/ImportLeagalPerSettingDTO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class ImportLeagalPerSettingController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ImportLeagalPerSettingController);
	// 3 定义接口
public:
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addLeagalPerSetting) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.import.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/org-import/legalEntitySet", addLeagalPerSetting, BODY_DTO(ImportLeagalPerSettingDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddLeagalPerSetting(dto));
	}
	/*
	// [其他] 定义一个单文件上传接口
	ENDPOINT(API_M_POST, "/upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		// 创建multipart容器
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		// 创建multipart读取器
		multipart::Reader multipartReader(multipartContainer.get());
		// 配置读取器读取表单字段3
		multipartReader.setPartReader("nickname", multipart::createInMemoryPartReader(-1 ));// max-data-size
		multipartReader.setPartReader("age", multipart::createInMemoryPartReader(-1));// max-data-size
		// 配置读取器读取文件到文件
		multipartReader.setPartReader("file", multipart::createFilePartReader("public/static/file/test.png"));
		// 读取请求体中的数据
		request->transferBody(&multipartReader);
		// 打印part数量
		OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
		// 获取表单数据
		auto nickname = multipartContainer->getNamedPart("nickname");
		auto age = multipartContainer->getNamedPart("age");
		// 断言表单数据是否正确
		OATPP_ASSERT_HTTP(nickname, Status::CODE_400, "nickname is null");
		OATPP_ASSERT_HTTP(age, Status::CODE_400, "age is null");
		// 打印应表单数据
		OATPP_LOGD("Multipart", "nickname='%s'", nickname->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "age='%s'", age->getPayload()->getInMemoryData()->c_str());
		// 获取文件部分
		auto filePart = multipartContainer->getNamedPart("file");
		// 断言文件是否获取到
		OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file is null");
		// 打印文件名称
		OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());
		// 响应OK
		return createResponse(Status::CODE_200, "OK");
	}
	*/
	/*
	// [其他] 定义一个多文件上传接口
	ENDPOINT(API_M_POST, "/upload-more", uploadFileMore, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		//创建multipart容器
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		// 创建multipart读取器
		multipart::Reader multipartReader(multipartContainer.get());
		// 配置读取器读取文件到文件
		multipartReader.setPartReader("file0", multipart::createFilePartReader("public/static/file/test1.png"));
		multipartReader.setPartReader("file1", multipart::createFilePartReader("public/static/file/test2.png"));
		// 读取请求体中的数据
		request->transferBody(&multipartReader);
		// 获取文件部分
		auto file0 = multipartContainer->getNamedPart("file0");
		auto file1 = multipartContainer->getNamedPart("file1");
		// 断言文件是否获取到
		OATPP_ASSERT_HTTP(file0, Status::CODE_400, "file0 is null");
		OATPP_ASSERT_HTTP(file1, Status::CODE_400, "file1 is null");
		// 响应OK
		return createResponse(Status::CODE_200, "OK");
	*/

private:
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddLeagalPerSetting(const ImportLeagalPerSettingDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _IMPORTLEAGALPERSETTING_CONTROLLER_