#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/18 17:23:11

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
#ifndef _EXPORTPROJTAGQUERY_H_
#define _EXPORTPROJTAGQUERY_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 导出项目标签Query领域模型
 * 负责人：Andrew
 */
class ExportProjTagQuery : public oatpp::DTO
{
	DTO_INIT(ExportProjTagQuery, DTO);
	// 导出行数
	DTO_FIELD(UInt32, line);
	DTO_FIELD_INFO(line) {
		info->description = ZH_WORDS_GETTER("projTag.export.line");
	}
	// 顺序
	DTO_FIELD(String, order);
	DTO_FIELD_INFO(order) {
		info->description = ZH_WORDS_GETTER("projTag.export.order");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPORTPROJTAGQUERY_H_