/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/08 21:19:56

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
#include "stdafx.h"
#include "TestController.h"

TestPageJsonVO::Wrapper TestController::execQueryTest(const TestQuery::Wrapper& query)
{
	// 创建响应对象
	auto vo = TestPageJsonVO::createShared();
	// 创建分页对象
	auto pdto = TestPageDTO::createShared();
	pdto->addData(TestDTO::createShared(1, "zs"));
	pdto->addData(TestDTO::createShared(2, "ls"));
	// 响应结果
	vo->success(pdto);
	return vo;
}
