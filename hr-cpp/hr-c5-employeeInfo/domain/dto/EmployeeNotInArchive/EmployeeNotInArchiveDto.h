#pragma once

#ifndef _EMPLOYEE_NOT_IN_AECHIVE_DTO_
#define _EMPLOYEE_NOT_IN_AECHIVE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class EmployeeNotInArchiveDto : public oatpp::DTO
{
	DTO_INIT(EmployeeNotInArchiveDto, DTO);
	// �������
	DTO_FIELD(String, nummber);
	DTO_FIELD_INFO(nummber) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.nummber");
	}
	// ����λ
	DTO_FIELD(String, gunits);
	DTO_FIELD_INFO(gunits) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field. gunits");
	}
	// �������ܵ�
	DTO_FIELD(String, pos);
	DTO_FIELD_INFO(pos) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.pos");
	}
	// ������
	DTO_FIELD(String, office);
	DTO_FIELD_INFO(office) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.office");
	}
	// ����״̬
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.status");
	}
	// Ա�����
	DTO_FIELD(String, emloyeenumber);
	DTO_FIELD_INFO(emloyeenumber) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.emloyeenumber");
	}
	// Ա������
	DTO_FIELD(String, PimPersonName);
	DTO_FIELD_INFO(PimPersonName) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.PimPersonName");
	}
	// ������λ
	DTO_FIELD(String, unit);
	DTO_FIELD_INFO(unit) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.unit");
	}
	// Ա��״̬
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.state");
	}
	// ������
	DTO_FIELD(String, use);
	DTO_FIELD_INFO(use) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.use");
	}
};


class ArchiveOutDto : public oatpp::DTO
{
	DTO_INIT(ArchiveOutDto, DTO);
	// Ա�����
	DTO_FIELD(String, emloyeenumber);
	DTO_FIELD_INFO(emloyeenumber) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.emloyeenumber");
	}
	// Ա������
	DTO_FIELD(String, PimPersonName);
	DTO_FIELD_INFO(PimPersonName) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.PimPersonName");
	}
	// ������λ
	DTO_FIELD(String, outunit);
	DTO_FIELD_INFO(outunit) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.outunit");
	}
	// ���뵥λ
	DTO_FIELD(String, inunit);
	DTO_FIELD_INFO(inunit) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.inunit");
	}
	// ����ʱ��
	DTO_FIELD(String, time);
	DTO_FIELD_INFO(time) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.time");
	}
};
/**
 * ʾ����ҳ�������
 */
class EmployeeNotInArchivePageDTO : public PageDTO<EmployeeNotInArchiveDto::Wrapper>
{
	DTO_INIT(EmployeeNotInArchivePageDTO, PageDTO<EmployeeNotInArchiveDto::Wrapper>);
};

class ArchiveOutPageDTO : public PageDTO<ArchiveOutDto::Wrapper>
{
	DTO_INIT(ArchiveOutPageDTO, PageDTO<ArchiveOutDto::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_