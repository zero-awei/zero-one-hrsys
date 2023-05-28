/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#include "ImportJobController.h"
#include "ExcelComponent.h"
#include "service/jobSet/JobSetService.h"

ImportJobJsonVO::Wrapper ImportJobController::execImportJob(const ImportJobDTO::Wrapper& dto, const PayloadDTO & payload)
{
	// 构建返回VO
	auto vo = ImportJobJsonVO::createShared();
	// 参数校验
	if (dto->filePath->empty()) {
		vo->init({}, RS_PARAMS_INVALID);
		return vo;
	}

	// 构建返回样例
	/*String str1 = "123abc";
	String str2 = "456def";
	String str3 = "789ghi";
	auto ij = ImportJobVO::createShared();
	ij->newId->push_back("123abc");
	ij->newId->push_back("456def");
	ij->newId->push_back("789ghi");
	vo->init(ij, RS_SUCCESS);*/

	// TODO: 调用service
	std::list<std::string> result;
	JobSetService service;
	auto res = service.addMultiJob(dto, payload);

	if (res->newId->size()) 
		vo->init(res, RS_SUCCESS);
	else 
		vo->init(res, RS_FAIL);

	return vo;
}
