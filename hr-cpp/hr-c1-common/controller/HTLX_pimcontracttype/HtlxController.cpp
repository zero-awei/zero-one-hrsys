#include "stdafx.h"
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/19 21:31:12

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
#include "HtlxController.h"

//还有些注释没补

Uint64JsonVO::Wrapper HtlxController::execModifyHtlx(const HtlxDTO::Wrapper& dto)
{
	// 定义一个JsonVO对象
	auto jvo = Uint64JsonVO::createShared();
	
	return jvo;
}
