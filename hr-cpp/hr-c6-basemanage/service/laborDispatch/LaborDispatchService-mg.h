
/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/20 0:00:36

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
#pragma once
#ifndef _LD_M_SERVICE_
#define _LD_M_SERVICE_
#include "domain/dto/LaborDispatch/LaborDispatchDTO.h"
#include "domain/dto/LaborDispatch/LaborDispatchDTO-mg.h"
#include "domain/query/LaborDispatch/LaborDispatchQuery-mg.h"

class LaborDispatchMService
{
public:
	// 分页查询所有数据
	LaborDispatchPageMDTO::Wrapper ListAll(const LaborDispatchMQuery::Wrapper& query);
	//LaborDispatchMDTO::Wrapper ListData(const LaborDispatchMQuery::Wrapper& query);

	bool updateData(const LaborDispatchUpdateDTO::Wrapper& dto);
protected:
private:
};
#endif
