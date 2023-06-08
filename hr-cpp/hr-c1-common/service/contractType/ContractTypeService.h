#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/06/02 1:12:53

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
#ifndef _CONTRACTTYPESERVICE_H_
#define _CONTRACTTYPESERVICE_H_

#include "domain/dto/contractType/ContractTypeDTO.h"

/**
 * 合同类别下拉列表service实现
 * 负责人：Andrew
 */
class ContractTypeService
{
public:
	ContractTypeListDTO::Wrapper listAll();
};

#endif // !_CONTRACTTYPESERVICE_H_