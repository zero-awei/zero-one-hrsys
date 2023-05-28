#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: Andrew211vibe
 @Date: 2023/05/27 8:24:55
>>>>>>> fd9c62c9f45a44f72160877d460eb61f63de0604

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
 * 岗位设置DAO数据持久化层
 */
class JobSetDAO : public BaseDAO
{
public:
	/**
	 * 导入岗位设置（批量新增岗位设置）
	 * 负责人：Andrew
	 */
	std::list<std::string> insertMultiJob(const std::list<PostDetailDO> &data);
	/**
	 * 新增岗位设置
	 * 负责人：Andrew
	 */
	bool insertJob(const PostDetailDO& data);
};

#endif // !_JOBSETDAO_H_