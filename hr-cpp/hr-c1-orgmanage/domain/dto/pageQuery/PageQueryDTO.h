#pragma once
#ifndef _PAGEQUERYDTO_H_
#define _PAGEQUERYDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PageQueryDTO : public oatpp::DTO
{
	DTO_INIT(PageQueryDTO, DTO);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PAGEQUERYDTO_H_