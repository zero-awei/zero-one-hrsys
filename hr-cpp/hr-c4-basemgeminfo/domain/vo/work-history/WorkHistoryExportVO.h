#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/17 8:58:44

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
#ifndef _WORKHISTORYEXPORTVO_H_
#define _WORKHISTORYEXPORTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/work-history/WorkHistoryExportDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


//响应导出数据JsonVO
class WorkHistoryExportJsonVO : public JsonVO<WorkHistoryExportPageDTO::Wrapper>
{
	DTO_INIT(WorkHistoryExportJsonVO, JsonVO<WorkHistoryExportPageDTO::Wrapper>);
	
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WORKHISTORYEXPORTVO_H_