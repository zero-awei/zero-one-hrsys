#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Marvin
 @Date: 2023/05/18 19:52:51

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
#ifndef _FAMILYSITUATIONCONTROLLER_H_
#define _FAMILYSITUATIONCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/familysituation/FamilysituationQuery.h"
#include "domain/dto/familysituation/FamilysituationDTO.h"
#include "domain/vo/familysituation/FamilysituationVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 家庭情况控制器
 **/
class FamilysituationController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(FamilysituationController);
public: // 定义接口
	// 定义查询描述
	ENDPOINT_INFO(queryFamilysituation)
	{
		//定义标题
		info->summary = ZH_WORDS_GETTER("familysituation.get.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(FamilySituationPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("frelationship").description = ZH_WORDS_GETTER("familysituation.field.relationship");
		info->queryParams["frelationship"].addExample("default", String(ZH_WORDS_GETTER("familysituation.description.dadson")));
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("familysituation.field.name");
		info->queryParams["name"].addExample("default", String("Marvin"));
		// 待补充
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/query-by-Familysituation", queryFamilysituation, QUERIES(QueryParams, queryParams))
	{
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(familysituationQuery, FamilysituationQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryByFamilysituation(familysituationQuery));
	}
	// 定义添加家庭情况接口描述
	ENDPOINT_INFO(addFamilysituation)
	{
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("familysituation.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 定义添加接口处理
	ENDPOINT(API_M_POST, "/add-by-Familysituation", addFamilysituation, BODY_DTO(FamilysituationDTO::Wrapper, dto))
	{
		// 响应结果
		API_HANDLER_RESP_VO(execAddFamilysituation(dto));
	}
	// 定义修改接口描述
	ENDPOINT_INFO(modifyFamilysituation)
	{
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("familysituation.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义修改接口处理
	ENDPOINT(API_M_PUT, "/modify-by-Familysituation", modifyFamilysituation, BODY_DTO(FamilysituationDTO::Wrapper, dto))
	{
		// 响应结果
		API_HANDLER_RESP_VO(execModifyFamilysituation(dto));
	}
	// 定义删除接口描述
	ENDPOINT_INFO(deleteFamilysituation)
	{
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("familysituation.del.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义删除接口处理
	ENDPOINT(API_M_PUT, "/delete-by-Familysituation", deleteFamilysituation, BODY_DTO(FamilysituationDTO::Wrapper, dto))
	{
		// 响应结果
		API_HANDLER_RESP_VO(execDeleteFamilysituation(dto));
	}

private: // 定义接口执行函数
	// 查询数据响应
	FamilySituationPageJsonVO::Wrapper execQueryByFamilysituation(const FamilysituationQuery::Wrapper& query);
	// 添加数据响应
	StringJsonVO::Wrapper execAddFamilysituation(const FamilysituationDTO::Wrapper& dto);
	// 修改数据响应
	StringJsonVO::Wrapper execModifyFamilysituation(const FamilysituationDTO::Wrapper& dto);
	// 删除数据响应
	StringJsonVO::Wrapper execDeleteFamilysituation(const FamilysituationDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FAMILYSITUATIONCONTROLLER_H_