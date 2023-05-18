#pragma once
#ifndef _EXPORTLEGALERSETTING_CONTROLLER_
#define _EXPORTLEGALERSETTING_CONTROLLER_

// 包含 dto vo jsonvo  query   以及oatpp 接口
#include "domain/vo/BaseJsonVO.h"
//#include "domain/query/sample/SampleQuery.h"
//#include "domain/dto/sample/SampleDTO.h"
//#include "domain/vo/sample/SampleVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "ApiHelper.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ExportLegalerSetingController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(ExportLegalerSetingController); // 2 定义控制器访问入口
public:

private:
	//// 3.3 演示新增数据
	//Uint64JsonVO::Wrapper execAddSample(const ExportEmployeeDTO::Wrapper& dto);
	//// 3.3 演示修改数据
	//Uint64JsonVO::Wrapper execModifySample(const ExportEmployeeDTO::Wrapper& dto);
	// //3.3 演示删除数据
	//Uint64JsonVO::Wrapper execRemoveSample(const ExportEmployeeDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _EXPORTLEGALERSETTING_CONTROLLER_

