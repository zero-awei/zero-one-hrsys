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
#include "../../service/RosterOfPer/FormerEmployeesService.h"

CertificateInfoPageJsonVO::Wrapper UpdateCertificateController::execUpdateCertificateInfo(const updateCertificateQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个JsonVO对象
	auto vo = CertificateInfoPageJsonVO::createShared();
	// 定义一个分页对象
	auto pageDTO = CertificateInfoPageDTO::createShared();
	//pageDTO->addData(CertificateInfoPageDTO::createShared("1", "zs"));
	//pageDTO->addData(CertificateInfoPageDTO::createShared("2", "ls"));
	// 响应结果
	vo->success(pageDTO);
	return vo;
}

CertificateInfoPageJsonVO::Wrapper UpdateCertificateController::execGetCertificateInfo(const updateCertificateQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个JsonVO对象
	auto vo = CertificateInfoPageJsonVO::createShared();
	// 定义一个分页对象
	auto pageDTO = CertificateInfoPageDTO::createShared();
	//pageDTO->addData(CertificateInfoPageDTO::createShared("1", "zs"));
	//pageDTO->addData(CertificateInfoPageDTO::createShared("2", "ls"));
	// 响应结果
	vo->success(pageDTO);
	return vo;
}