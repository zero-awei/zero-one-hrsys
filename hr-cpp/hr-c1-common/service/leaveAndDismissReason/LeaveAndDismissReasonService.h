#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/30 23:26:22

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
#ifndef _LEAVEANDDISMISSREASONSERVICE_H_
#define _LEAVEANDDISMISSREASONSERVICE_H_
#include "domain/dto/pullList/PullListDTO.h"
/**
 * 离职/解聘原因Service
 * 负责人：远翔
 */
class LeaveAndDismissReasonService
{
public:
	PullListDTO::Wrapper listAll();
};

#endif // !_LEAVEANDDISMISSREASONSERVICE_H_