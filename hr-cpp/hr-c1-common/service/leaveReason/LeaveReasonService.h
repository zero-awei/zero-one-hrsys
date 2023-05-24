#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/23 15:58:35

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
#ifndef _LEAVEREASONSERVICE_H_
#define _LEAVEREASONSERVICE_H_
#include "domain/dto/pullList/PullListDTO.h"
/**
 * 离职原因下拉列表Service
 * 负责人：远翔
 */
class LeaveReasonService
{
public:
	PullListDTO::Wrapper listAll();
};

#endif // !_LEAVEREASONSERVICE_H_