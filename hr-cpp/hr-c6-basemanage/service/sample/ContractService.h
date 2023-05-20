#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _Contract_SERVICE_
#define _Contract_SERVICE_
#include <list>
#include "domain/vo/contract/ContractVO.h"
#include "domain/query/contract/ContractQuery.h"
#include "domain/dto/contract/ContractDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ContractService
{
public:
	// ��ҳ��ѯ��������
	ContractPageDTO::Wrapper listAll(const ContractQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const ContractDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const ContractDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_