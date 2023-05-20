#pragma once
#ifndef _CONTRACTTYPE_IMPORT_DTO_
#define _CONTRACTTYPE_IMPORT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 用于批量导入的合同类型传输对象
 */
class ContractTypeImportDTO : public oatpp::DTO
{
    DTO_INIT(ContractTypeImportDTO, DTO);

    // 合同类型名
    DTO_FIELD(String, typeName);
    DTO_FIELD_INFO(typeName) {
        info->description = ZH_WORDS_GETTER("contractType.field.typeName");
    }

    // 合同类型描述
    DTO_FIELD(String, typeDescription);
    DTO_FIELD_INFO(typeDescription) {
        info->description = ZH_WORDS_GETTER("contractType.field.typeDescription");
    }
};

/**
 * 用于批量导入的合同类型列表传输对象
 */
class ContractTypesImportDTO : public oatpp::DTO
{
    DTO_INIT(ContractTypesImportDTO, DTO);

    // 合同类型列表
    DTO_FIELD(List<Object<ContractTypeImportDTO>>, types);
    DTO_FIELD_INFO(types) {
        info->description = ZH_WORDS_GETTER("contractType.field.types");
    }
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CONTRACTTYPE_IMPORT_DTO_