#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/13 19:52:05

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

/**
 * 合同查询传输数据类型
 */
class ContractDTO : public oatpp::DTO
{
public:
	DTO_INIT(ContractDTO, DTO);

	// 人员信息标识
	DTO_FIELD(String, PIMPERSONID);
	DTO_FIELD_INFO(PIMPERSONID) {
		info->description = ZH_WORDS_GETTER("contract.PIMPERSONID");
	}
	// 合同编号
	DTO_FIELD(String, HTBH);
	DTO_FIELD_INFO(HTBH) {
		info->description = ZH_WORDS_GETTER("contract.HTBH");
	}
	// 合同类别
	DTO_FIELD(String, HTLX);
	DTO_FIELD_INFO(HTLX) {
		info->description = ZH_WORDS_GETTER("contract.HTLX");
	}
	// 合同类型
	DTO_FIELD(String, CONTRACTTYPE);
	DTO_FIELD_INFO(CONTRACTTYPE) {
		info->description = ZH_WORDS_GETTER("contract.CONTRACTTYPE");
	}
	// 起始日期
	DTO_FIELD(String, QSRQ);
	DTO_FIELD_INFO(QSRQ) {
		info->description = ZH_WORDS_GETTER("contract.QSRQ");
	}
	// 结束日期
	DTO_FIELD(String, JSRQ);
	DTO_FIELD_INFO(JSRQ) {
		info->description = ZH_WORDS_GETTER("contract.JSRQ");
	}
	// 合同状态
	DTO_FIELD(String, HTZT);
	DTO_FIELD_INFO(HTZT) {
		info->description = ZH_WORDS_GETTER("contract.HTZT");
	}
	// 试用到期时间
	DTO_FIELD(String, SYDQSJ);
	DTO_FIELD_INFO(SYDQSJ) {
		info->description = ZH_WORDS_GETTER("contract.SYDQSJ");
	}
};

/**
 * 合同查询分页传输数据类型
 */
class ContractPageDTO : public PageDTO<ContractDTO::Wrapper>
{
	DTO_INIT(ContractPageDTO, PageDTO<ContractDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTRACTDTO_H_