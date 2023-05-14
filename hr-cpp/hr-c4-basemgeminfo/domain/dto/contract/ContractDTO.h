#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/14 21:51:11

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
#ifndef _CONTRACTDTO_H_
#define _CONTRACTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 定义单个合同信息传输对象
*/
class ContractDTO : public oatpp::DTO
{
	DTO_INIT(ContractDTO, DTO);
	// 员工编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// 员工姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// 员工所属单位
	DTO_FIELD(String, unit);
	DTO_FIELD_INFO(unit) {
		info->description = ZH_WORDS_GETTER("contract.unit");
	}
	// 员工状态
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("contract.state");
	}
	// 员工到本单位时间
	DTO_FIELD(String, unitTime);
	DTO_FIELD_INFO(unitTime) {
		info->description = ZH_WORDS_GETTER("contract.unitTime");
	}
	// 合同编号
	DTO_FIELD(String, contractID);
	DTO_FIELD_INFO(contractID) {
		info->description = ZH_WORDS_GETTER("contract.contractID");
	}
	// 合同签订单位
	DTO_FIELD(String, contractUnit);
	DTO_FIELD_INFO(contractUnit) {
		info->description = ZH_WORDS_GETTER("contract.contractUnit");
	}
	// 合同类别
	DTO_FIELD(String, contractCategory);
	DTO_FIELD_INFO(contractCategory) {
		info->description = ZH_WORDS_GETTER("contract.contractCategory");
	}
	// 合同类型
	DTO_FIELD(String, contractType);
	DTO_FIELD_INFO(contractType) {
		info->description = ZH_WORDS_GETTER("contract.contractType");
	}
	// 合同起始日期
	DTO_FIELD(String, startDate);
	DTO_FIELD_INFO(startDate) {
		info->description = ZH_WORDS_GETTER("contract.startDate");
	}
	// 合同结束日期
	DTO_FIELD(String, endDate);
	DTO_FIELD_INFO(endDate) {
		info->description = ZH_WORDS_GETTER("contract.endDate");
	}
	// 合同状态
	DTO_FIELD(String, contractStatus);
	DTO_FIELD_INFO(contractStatus) {
		info->description = ZH_WORDS_GETTER("contract.contractStatus");
	}
	// 合同剩余天数
	DTO_FIELD(String, remaining);
	DTO_FIELD_INFO(remaining) {
		info->description = ZH_WORDS_GETTER("contract.remaining");
	}
	// 合同试用到期时间
	DTO_FIELD(String, trialExpiration);
	DTO_FIELD_INFO(trialExpiration) {
		info->description = ZH_WORDS_GETTER("contract.trialExpiration");
	}
};

/**
 * 定义分页合同信息传输对象
 */
class ContractPageDTO : public PageDTO<ContractDTO::Wrapper>
{
	DTO_INIT(ContractPageDTO, PageDTO<ContractDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTRACTDTO_H_