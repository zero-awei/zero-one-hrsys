#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/27 10:29:17

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
#ifndef _JOBSETDAO_H_
#define _JOBSETDAO_H_
#include "BaseDAO.h"
#include "domain/do/postSet/PostDetailDO.h"
/**
 * 岗位设置DAO
 */
class JobSetDAO : public BaseDAO
{
public:
	/**
	 * 插入多条数据
	 * 返回自增id列表
	 * 负责人：远翔
	 */
	list<string> insertMultiData(const list<PostDetailDO>& dataList);
};

#endif // !_JOBSETDAO_H_