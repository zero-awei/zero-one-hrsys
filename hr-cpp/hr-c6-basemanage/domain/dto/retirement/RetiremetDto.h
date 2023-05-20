#pragma once
#ifndef _RETIREMETDTO_H_
#define _RETIREMETDTO_H_

#include "stdafx.h"
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class RetirementDTO : public oatpp::DTO
{
	//��ʼ��
	DTO_INIT(RetirementDTO, DTO);
	// Ա������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("My.field.name");
	}
	// Ա�����
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("My.field.id");
	}
	//�Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("My.field.sex");
	}
	// ����
	DTO_FIELD(UInt64, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("My.field.age");
	}
};

/**
 * ʾ����ҳ�������
 */
class ContractPageDTO : public PageDTO<RetirementDTO::Wrapper>
{
	DTO_INIT(ContractPageDTO, PageDTO<RetirementDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RETIREMETDTO_H_
