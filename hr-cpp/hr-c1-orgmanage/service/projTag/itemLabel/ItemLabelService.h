#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanchen
 @Date: 2023/05/31 20:58:49

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
#ifndef _ITEMLABELSERVICE_H_
#define _ITEMLABELSERVICE_H_
#include "domain/dto/itemLabel/ItemLabelDTO.h"
#include "domain/query/itemlabel/ItemlabelQuery.h"
#include <list>
#include "domain/vo/itemLabel/ItemLabelVO.h"

/**
 * 项目标签-查询指定项目标签
 * 负责人：缘尘
 */
class ItemLabeService
{
public:
	ItemLabelPageDTO::Wrapper listItemLabel(const ItemLabelQuery::Wrapper& query);
};

#endif // !_ITEMLABELSERVICE_H_