#ifndef _Import_Assign_Info_CONTROLLER_
#define _Import_Assign_Info_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/dto/assignInfo/ImportAssignInfoDTO.h"
#include "domain/vo/assignInfo/ImportAssignInfoVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) // 0

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class ImportAssignInfoController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ImportAssignInfoController);
	// 3 定义接口
public:
	// [其他] 定义一个单文件上传接口
	ENDPOINT(API_M_POST, "/upload-assignInfo", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		/* 创建multipart容器 */
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		/* 创建multipart读取器 */
		multipart::Reader multipartReader(multipartContainer.get());
		/* 配置读取器读取表单字段 */
		multipartReader.setPartReader("id", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("assign", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("type", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("organize", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("depart", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("job", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("post", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("start-time", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("end-time", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		/* 配置读取器读取文件到文件 */
		multipartReader.setPartReader("file", multipart::createFilePartReader("public/static/file/test.png"));
		/* 读取请求体中的数据 */
		request->transferBody(&multipartReader);
		/* 打印part数量 */
		OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
		/* 获取表单数据 */
		auto id = multipartContainer->getNamedPart("id");
		auto assign = multipartContainer->getNamedPart("assign");
		auto Etype = multipartContainer->getNamedPart("Etype");
		auto organize = multipartContainer->getNamedPart("organize");
		auto depart = multipartContainer->getNamedPart("depart");
		auto job = multipartContainer->getNamedPart("job");
		auto post = multipartContainer->getNamedPart("post");
		auto startTime = multipartContainer->getNamedPart("startTime");
		auto endTime = multipartContainer->getNamedPart("endTime");
		/* 断言表单数据是否正确 */
		OATPP_ASSERT_HTTP(id, Status::CODE_400,  "id is null");
		OATPP_ASSERT_HTTP(assign, Status::CODE_400, "assign is null");
		OATPP_ASSERT_HTTP(Etype, Status::CODE_400, "Etype is null");
		OATPP_ASSERT_HTTP(organize, Status::CODE_400, "organize is null");
		OATPP_ASSERT_HTTP(depart, Status::CODE_400, "depart is null");
		OATPP_ASSERT_HTTP(job, Status::CODE_400, "job is null");
		OATPP_ASSERT_HTTP(post, Status::CODE_400, "post is null");
		OATPP_ASSERT_HTTP(startTime, Status::CODE_400, "startTime is null");
		OATPP_ASSERT_HTTP(endTime, Status::CODE_400, "endTime is null");
		/* 打印应表单数据 */
		OATPP_LOGD("Multipart", "id='%s'", id->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "assign='%s'", assign->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "Etype='%s'", Etype->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "organize='%s'", organize->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "depart='%s'", depart->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "job='%s'", job->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "post='%s'", post->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "startTime='%s'", startTime->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "endTime='%s'", endTime->getPayload()->getInMemoryData()->c_str());
		/* 获取文件部分 */
		auto filePart = multipartContainer->getNamedPart("file");
		/* 断言文件是否获取到 */
		OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file is null");
		/* 打印文件名称 */
		OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());
		/* 响应OK */
		return createResponse(Status::CODE_200, "OK");
	}
private:
	ImportAssignInfoJsonVO::Wrapper execImportAssignInfo(const ImportAssignInfoDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_Import_Assign_Info_CONTROLLER_