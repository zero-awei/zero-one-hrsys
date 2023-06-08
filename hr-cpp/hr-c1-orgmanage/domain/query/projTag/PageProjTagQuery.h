#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2023/05/24 18:22:04

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
#ifndef _PAGEPROJTAGQUERY_H_
#define _PAGEPROJTAGQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页查询项目标签Query领域模型
 * 负责人：咫尺之书
 */
class PageProjTagQuery : public PageQuery
{
	DTO_INIT(PageProjTagQuery, PageQuery);
	// 项目标签名
	DTO_FIELD_INFO(tagName) {
		info->description = ZH_WORDS_GETTER("projTag.pageQuery.tagName");
	}
	DTO_FIELD(String, tagName);
	// 查询排序
	DTO_FIELD_INFO(order) {
		info->description = ZH_WORDS_GETTER("projTag.pageQuery.order");
	}
	DTO_FIELD(String, order);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PAGEPROJTAGQUERY_H_