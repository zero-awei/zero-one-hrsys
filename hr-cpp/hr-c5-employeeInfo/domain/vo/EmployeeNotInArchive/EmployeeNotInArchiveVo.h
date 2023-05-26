#pragma once

#ifndef _EMPLOYEE_NOT_IN_AECHIVE_VO_
#define _EMPLOYEE_NOT_IN_AECHIVE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/EmployeeNotInArchive/EmployeeNotInArchiveDto.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class EmployeeNotInArchiveJsonVO : public JsonVO<EmployeeNotInArchiveDto::Wrapper> {
	DTO_INIT(EmployeeNotInArchiveJsonVO, JsonVO<EmployeeNotInArchiveDto::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class EmployeeNotInArchivePageJsonVO : public JsonVO <String>
{
	DTO_INIT(EmployeeNotInArchivePageJsonVO, JsonVO<String>);
};

class ArchiveOutPageJsonVO : public JsonVO<String> {
	DTO_INIT(ArchiveOutPageJsonVO, JsonVO<String>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_ARCHIVES_VO_