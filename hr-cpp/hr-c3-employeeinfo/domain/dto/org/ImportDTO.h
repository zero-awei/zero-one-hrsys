#pragma once
#ifndef _IMPORTDTO_
#define _IMPORTDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class ImportDTO : public oatpp::DTO
{
	DTO_INIT(ImportDTO , DTO);

    // 导入是否成功
	DTO_FIELD(String, success);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_org_DTO_