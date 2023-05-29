
/**
 *  证书管理 —— 证书信息 —— 查询、更新指定证书 —— 楚孟献
 */
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "stdafx.h"
#include "UpdateCertificateController.h"
#include "../../service/CertificateManage/SpercificCertificateService.h"

StringJsonVO::Wrapper UpdateCertificateController::execUpdateSpercificCertificate(const SpercificCertificateDTO::Wrapper& dto)
{
	{
		// 定义返回数据对象
		auto jvo = StringJsonVO::createShared();
		// 参数校验
		if (dto->PIMVOCATIONALID.getValue("").empty())
		{
			jvo->init(String("PIMVOCATIONALID must be not null"), RS_PARAMS_INVALID);
			return jvo;
		}
		// 定义一个Service
		SpercificCertificateService service;
		// 执行数据修
		if (service.updateData(dto)) {
			jvo->success(dto->PIMVOCATIONALID);
		}
		else
		{
			jvo->fail(dto->PIMVOCATIONALID);
		}
		// 响应结果
		return jvo;
	}
}

SpercificCertificateJsonVO::Wrapper UpdateCertificateController::execGetSpercificCertificate(const SpercificCertificateQuery::Wrapper& query)
{
	// 定义一个JsonVO对象
	auto vo = SpercificCertificateJsonVO::createShared();
	// 定义一个分页对象
	SpercificCertificateService service;
	auto result = service.querySpercificCertificate(query);

	vo->success(result);
	// 响应结果
	return vo;
}