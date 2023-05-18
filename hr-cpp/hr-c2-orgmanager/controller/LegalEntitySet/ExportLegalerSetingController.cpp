#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_
#include "ExportLegalerSetingController.h"
#include "stdafx.h"

// 包含 dto vo jsonvo  query   以及oatpp 接口
#include "domain/vo/BaseJsonVO.h"
//#include "domain/query/sample/SampleQuery.h"
//#include "domain/dto/sample/SampleDTO.h"
//#include "domain/vo/sample/SampleVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class xxController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(SampleController); // 2 定义控制器访问入口
private: DTO

	// 3.3 演示分页查询数据
	SamplePageJsonVO::Wrapper execQuerySample(const SampleQuery::Wrapper& query, const PayloadDTO& payload);
	   // 3.3 演示新增数据
	   Uint64JsonVO::Wrapper execAddSample(const SampleDTO::Wrapper& dto);
	   // 3.3 演示修改数据
	   Uint64JsonVO::Wrapper execModifySample(const SampleDTO::Wrapper& dto);
	   // 3.3 演示删除数据
	   Uint64JsonVO::Wrapper execRemoveSample(const SampleDTO::Wrapper& dto);
}

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_

