#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: arui
 @Date: 2023/05/22 15:35:55

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
#ifndef _REWARDANDPUNISHMENTINFORMATIONCONTROLLER_H_
#define _REWARDANDPUNISHMENTINFORMATIONCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "./Macros.h"
#include"domain/query/rewardandpunishmentinformation/RewardAndPunishmentInformationPageQuery.h"
#include "domain/vo/rewardandpunishmentinformation/RewardAndPunishmentInformationVO.h"
#include"domain/dto/rewardandpunishmentinformation/AddRewardAndPunishmentInformationDTO.h"
#include"domain/dto/rewardandpunishmentinformation/DelRewardAndPunishmentInformationDTO.h"
#include"domain/dto/rewardandpunishmentinformation/RewardAndPunishmentInformationDTO.h"
#include"domain/dto/rewardandpunishmentinformation/RewardAndPunishmentInformationIntoDTO.h"
#include <oatpp-swagger/Types.hpp>
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "oatpp-swagger/Model.hpp"


using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)//0

//奖惩信息控制器

class RewardAndPunishmentInformationController : public oatpp::web::server::api::ApiController //1
{
	// 2定义控制器访问入口
	API_ACCESS_DECLARE(RewardAndPunishmentInformationController);
public: // 定义接口
		//3.定义接口描述
		ENDPOINT_INFO(Information) {
			// 定义接口标题
			info->summary = ZH_WORDS_GETTER("rewardandpunishmentinformation.get.summary");
			// 定义响应参数类型
			API_DEF_ADD_RSP_JSON_WRAPPER(RewardAndPunishmentInformationJsonVO);
			// 定义分页查询参数描述
			API_DEF_ADD_PAGE_PARAMS();
			// 添加其他查询参数
			info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.pimpersonid");
			info->queryParams["pimpersonid"].addExample("default", String("1002"));
			info->queryParams["pimpersonid"].required = false;
		}
		//4.定义端点接口
		ENDPOINT(API_M_GET, "/rewardandpunishmentinformation/select", Information, QUERIES(QueryParams, qps)) {
			// 解析查询参数（解析成领域模型对象）
			API_HANDLER_QUERY_PARAM(query, RewardAndPunishmentInformationPageQuery, qps);
			// 响应结果
			API_HANDLER_RESP_VO(execQueryRewardAndPunishmentInformation(query));
		}

		//新增指定员工奖惩信息（单条新增）
		ENDPOINT_INFO(AddRewardAndPunishmentInformation)
		{
			// 定义接口标题
			info->summary = ZH_WORDS_GETTER("rewardandpunishmentinformation.post.summary");
			API_DEF_ADD_AUTH();
			// 定义响应参数格式
			API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		}
		//定义新增接口处理
		ENDPOINT(API_M_POST, "/rewardandpunishmentinformation/add", AddRewardAndPunishmentInformation,API_HANDLER_AUTH_PARAME, BODY_DTO(AddRewardAndPunishmentInformationDTO::Wrapper, dto,))
		{
			//响应结果
			API_HANDLER_RESP_VO(execAddRewardAndPunishmentInformation(dto, authObject->getPayload()));
		}

		//删除员工奖惩信息(支持批量删除)
		ENDPOINT_INFO(DelRewardAndPunishmentInformation)
		{
			//定义接口标题
			info->summary = ZH_WORDS_GETTER("rewardandpunishmentinformation.delete.summary");
			// 定义响应参数格式
			API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		}
		// 定义批量删除接口处理
		ENDPOINT(API_M_POST, "/rewardandpunishmentinformation/del", DelRewardAndPunishmentInformation, BODY_DTO(DelRewardAndPunishmentInformationDTO::Wrapper, dto))
		{
			// 响应结果
			API_HANDLER_RESP_VO(execDelRewardAndPunishmentInformation(dto));
		}

		//导入指定员工奖惩信息
		ENDPOINT_INFO(postFile)
		{
			info->summary = ZH_WORDS_GETTER("rewardandpunishmentinformation.file.summary");
			API_DEF_ADD_AUTH();
			info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
			API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
			info->queryParams["suffix"].description = ZH_WORDS_GETTER("rewardandpunishmentinformation.file.suffix");
			info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));

			// 定义其他表单参数描述
			info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("rewardandpunishmentinformation.file.pimpersionid");
			info->queryParams["pimpersonid"].addExample("default", String("0002CC75-F8EB-45B3-A359-0310EC7F6D5B"));
			//info->queryParams["pimpersonid"].required = true;
		}
		// 定义文件上传端点处理
		ENDPOINT(API_M_POST, "/rewardandpunishmentinformation/file", postFile, API_HANDLER_AUTH_PARAME, BODY_STRING(String, body), QUERY(String, suffix), QUERY(String, pimpersonid))
		{
			// 执行文件保存逻辑
			API_HANDLER_RESP_VO(execRewardAndPunishmentInformationInto(body, suffix, pimpersonid, authObject->getPayload()));
		}

private: //定义接口执行函数
		//定义接口的执行函数
	//定义查询执行函数
	RewardAndPunishmentInformationPageJsonVO::Wrapper execQueryRewardAndPunishmentInformation(const RewardAndPunishmentInformationPageQuery::Wrapper& query);
	//定义新增执行函数
	Uint64JsonVO::Wrapper execAddRewardAndPunishmentInformation(const AddRewardAndPunishmentInformationDTO::Wrapper& dto, const PayloadDTO& payload);
	//定义删除执行函数
	Uint64JsonVO::Wrapper execDelRewardAndPunishmentInformation(const DelRewardAndPunishmentInformationDTO::Wrapper& dto);
	//定义导入执行函数
	StringJsonVO::Wrapper execRewardAndPunishmentInformationInto(const String& body, const String& suffix, const String& pimpersonid, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)//0

#endif // !_REWARDANDPUNISHMENTINFORMATIONCONTROLLER_H_