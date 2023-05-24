#pragma once
#ifndef _LEGALERNAMEPULLDOWNLIST_CONTROLLER_
#define _LEGALERNAMEPULLDOWNLIST_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/do/LegalEntitySet/LegalerNamePullDownListDO.h"
#include "domain/dto/LegalEntitySet/LegalerNamePullDownListDTO.h"
#include "domain/vo/LegalEntitySet/LegalerNamePullDownListVO.h"
#include "domain/query/LegalEntitySet/LegalerNamePullDownListQuery.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "ApiHelper.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class LegalerNamePullDownListController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(LegalerNamePullDownListController); // 2 定义控制器访问入口
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
#endif // _LEGALERNAMEPULLDOWNLIST_CONTROLLER_

