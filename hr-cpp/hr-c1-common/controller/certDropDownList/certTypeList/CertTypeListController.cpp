/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 15:55:09

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
#include "CertTypeListController.h"
#include "../../../service/certs/certTypeService/CertTypeService.h"

CertTypeListJsonVO::Wrapper CertTypeListController::execQueryCertTypeList()
{
	auto vo = CertTypeListJsonVO::createShared();
	CertTypeService certTypeService;
	auto dto = certTypeService.listAll();
	if (dto->rows->size() <= 1){
		vo->fail(dto);
	}
	else {
		vo->success(dto);
	}
	return vo;
}
