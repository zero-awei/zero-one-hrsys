#pragma once

#ifndef _IMPORT_QUERY_
#define _IMPORT_QUERY_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ImportQuery : public oatpp::DTO {
    DTO_INIT(ImportQuery , DTO);

    // 文件的二进制
	DTO_FIELD(String, file);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_IMPORT_QUERY_