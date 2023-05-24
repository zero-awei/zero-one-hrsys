#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/24 15:58:56

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
#ifndef _POSTDELETE_SERVICE_
#define _POSTDELETE_SERVICE_
#include <list>
#include "domain/dto/postSet/PostDeleteDTO.h"

/**
 * 岗位设置 - 删除岗位Service
 * 负责人 : rice
 */
class PostDeleteService
{
public:
	bool removeData(string id);
	bool removeBatchData(const PostDeleteBatchDTO::Wrapper& postDeleteBatchDTO);
};

#endif // !_POSTDELETE_SERVICE_

