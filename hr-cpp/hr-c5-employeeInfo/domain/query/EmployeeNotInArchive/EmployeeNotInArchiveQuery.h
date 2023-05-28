#pragma once
#ifndef _EMPLOYEE_NOT_IN_AECHIVE_QUERY_
#define _EMPLOYEE_NOT_IN_AECHIVE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҳ��ѯԱ�����ڵ�������
 */
class EmployeeNotInArchiveQuery : public PageQuery
{
	DTO_INIT(EmployeeNotInArchiveQuery, PageQuery);

	// Ա������
	DTO_FIELD(String, PimPersonName);
	DTO_FIELD_INFO(PimPersonName) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.PimPersonName");
	}
	// Ա��id
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.pimpersonid");
	}

};
class ArchiveOutQuery : public PageQuery
{
	DTO_INIT(ArchiveOutQuery, PageQuery);

	// �鵵�ر����¼
	DTO_FIELD(String, ArchiveOut);
	DTO_FIELD_INFO(ArchiveOut) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.ArchiveOut");
	}

};


#include OATPP_CODEGEN_END(DTO)
#endif