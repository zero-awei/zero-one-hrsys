#pragma once

#ifndef _Import_Query_
#define _Import_Query_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ImportQuery : public oatpp::DTO {
    DTO_INIT(ImportQuery , DTO);

    // 文件的二进制
	DTO_FIELD(String, file);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_Import_Query_