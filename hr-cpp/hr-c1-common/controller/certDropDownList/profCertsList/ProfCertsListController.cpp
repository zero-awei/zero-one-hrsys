/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 8:30:04

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
#include "profCertsListController.h"
//#include "../../service/sample/SampleService.h"

ProfCertsListJsonVO::Wrapper ProfCertsListController::execQueryProfCertsList(const ProfCertsQuery::Wrapper& query)
{	
	auto dto = ProfCertsListDTO::createShared();
	auto vo = ProfCertsListJsonVO::createShared();
	vo->success(dto);
	return vo;
}