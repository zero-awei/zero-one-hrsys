#pragma once
#ifndef _PAGEQUERYEMPLOYEELIST_CONTROLLER_
#define _PAGEQUERYEMPLOYEELIST_CONTROLLER_

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

class PageQueryEmployeeListController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(PageQueryEmployeeListController); // 2 定义控制器访问入口
private:
	// 3.3 演示分页查询数据
	//PageQueryEmployeeListPageJsonVO::Wrapper execQuerySample(const PageQueryEmployeeListQuery::Wrapper& query, const PayloadDTO& payload);
	//// 3.3 演示新增数据
	//Uint64JsonVO::Wrapper execAddSample(const PageQueryEmployeeListDTO::Wrapper& dto);
	//// 3.3 演示修改数据
	//Uint64JsonVO::Wrapper execModifySample(const PageQueryEmployeeListDTO::Wrapper& dto);
	// //3.3 演示删除数据
	//Uint64JsonVO::Wrapper execRemoveSample(const PageQueryEmployeeListDTO::Wrapper& dto);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_