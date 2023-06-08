#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/30 0:29:03

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
#ifndef _FILESTATUSDAO_H_
#define _FILESTATUSDAO_H_
#include "BaseDAO.h"
#include "domain/do/fileStatus/FileStatusDO.h"
/**
 * 文档借阅状态DAO
 * 负责人：远翔
 */
class FileStatusDAO : public BaseDAO
{
public:
	// 查询列表
	std::list<FileStatusDO> selectFileStatusList();
};

#endif // !_FILESTATUSDAO_H_