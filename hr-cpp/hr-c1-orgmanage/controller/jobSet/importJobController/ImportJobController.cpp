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

ImportJobJsonVO::Wrapper ImportJobController::execImportJob(const ImportJobDTO::Wrapper& dto/*, const PayloadDTO & payload*/)
{
	auto vo = ImportJobJsonVO::createShared();
	// 参数校验
	if (dto->filePath->empty()) {
		vo->init({}, RS_PARAMS_INVALID);
	}

	// 构建样例返回
	/*String str1 = "123abc";
	String str2 = "456def";
	String str3 = "789ghi";
	auto ij = ImportJobVO::createShared();
	ij->newId->push_back("123abc");
	ij->newId->push_back("456def");
	ij->newId->push_back("789ghi");
	vo->init(ij, RS_SUCCESS);*/

	// TODO: 调用service


	return vo;
}
