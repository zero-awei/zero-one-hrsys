#pragma once
#ifndef _Person_QUERY_
#define _Person_QUERY_
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include "../lib-oatpp/include/ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class PersonQuery : public oatpp::DTO
{
	// ��ʼ������
	DTO_INIT(PersonQuery, DTO);
	// ��ѯ����
	DTO_FIELD(String, PersonName) = API_PERSON_defalut_DESC;
	DTO_FIELD_INFO(PersonName)
	{
#ifndef LINUX
		info->description = u8"Ա������";
#else
		info->description = "curr person name";
#endif
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PAGE_QUERY_