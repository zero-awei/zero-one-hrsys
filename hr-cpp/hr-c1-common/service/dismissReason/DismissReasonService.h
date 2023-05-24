#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/23 11:03:40

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
#ifndef _DISMISSREASONSERVICE_H_
#define _DISMISSREASONSERVICE_H_
#include "domain/do/dismissReason/DismissReasonDO.h"
#include "domain/dto/pullList/PullListDTO.h"

/**
 * 解聘原因下拉列表Service
 * 负责人：远翔
 */
class DismissReasonService
{
public:
	// 查询下拉列表数据
	PullListDTO::Wrapper listAll();
};

#endif // !_DISMISSREASONSERVICE_H_