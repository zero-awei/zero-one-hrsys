
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: tml
 @Date: 2022/10/25 0:27:04

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
#ifndef _PIMPAPER_CONTROLLER_
#define _PIMPAPER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/pimpaper/PimpaperQuery.h"
#include "domain/dto/pimpaper/PimpaperDTO.h"
#include "domain/vo/pimpaper/PimpaperVO.h"
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
class PimpaperController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(PimpaperController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(pimpaperQuery) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("pimpaper.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PimpaperPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		//员工姓名
		info->queryParams.add<String>("pimpersonname").description = ZH_WORDS_GETTER("pimpaper.field.pimpersonname");
		info->queryParams["pimpersonname"].addExample("default", String("LiHua"));
		//员工编号
		info->queryParams.add<String>("ygbh").description = ZH_WORDS_GETTER("pimpaper.field.ygbh");
		info->queryParams["ygbh"].addExample("default", String("1234"));
		//证件号码
		info->queryParams.add<String>("zjhm").description = ZH_WORDS_GETTER("pimpaper.field.zjhm");
		info->queryParams["zjhm"].addExample("default", String("12345"));
		info->queryParams["zjhm"].required = false;
		//组织
		info->queryParams.add<String>("zzdzs").description = ZH_WORDS_GETTER("pimpaper.field.zzdzs");
		info->queryParams["zzdzs"].addExample("default", String("HuaWeiZhongBu"));
		info->queryParams["zzdzs"].required = false;
		//部门
		info->queryParams.add<String>("ormorgsectorname").description = ZH_WORDS_GETTER("pimpaper.field.ormorgsectorname");
		info->queryParams["ormorgsectorname"].addExample("default", String("Development department"));
		info->queryParams["ormorgsectorname"].required = false;
		//员工状态
		info->queryParams.add<String>("ygzt").description = ZH_WORDS_GETTER("pimpaper.field.ygzt");
		info->queryParams["ygzt"].addExample("default", String("working"));
		info->queryParams["ygzt"].required = false;
		//在岗状态
		info->queryParams.add<String>("zgzt").description = ZH_WORDS_GETTER("pimpaper.field.zgzt");
		info->queryParams["zgzt"].addExample("default", String("yes"));
		info->queryParams["zgzt"].required = false;
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/employee-info/pimpaper", pimpaperQuery, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(query, PimpaperQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryPimpaper(query));
	}

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addPimpaper) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("pimpaper.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/employee-info/add-pimpaper", addPimpaper, BODY_DTO(PimpaperDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddPimpaper(dto));
	}

	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removePimpaper) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("pimpaper.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义删除接口处理
	ENDPOINT(API_M_DEL, "/employee-info/remove-pimpaper", removePimpaper, BODY_DTO(PimpaperDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemovePimpaper(dto));
	}
private:
	// 3.3 演示分页查询数据
	PimpaperPageJsonVO::Wrapper execQueryPimpaper(const PimpaperQuery::Wrapper& query);
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddPimpaper(const PimpaperDTO::Wrapper& dto);
	// 3.3 演示删除数据
	Uint64JsonVO::Wrapper execRemovePimpaper(const PimpaperDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PIMPAPER_CONTROLLER_