#pragma once
#ifndef _CONTRACTCATEGORY_IMPORT_DTO_
#define _CONTRACTCATEGORY_IMPORT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 用于批量导入的合同类型传输对象
 */
class ContractCategoryImportDTO : public oatpp::DTO
{
    DTO_INIT(ContractCategoryImportDTO, DTO);

    // 合同类型名
    DTO_FIELD(String, categoryName);
    DTO_FIELD_INFO(categoryName) {
        info->description = ZH_WORDS_GETTER("contractCategory.field.categoryName");
    }

    // 合同类型描述
    DTO_FIELD(String, categoryDescription);
    DTO_FIELD_INFO(categoryDescription) {
        info->description = ZH_WORDS_GETTER("contractCategory.field.categoryDescription");
    }
};

/**
 * 用于批量导入的合同类型列表传输对象
 */
class ContractCategorysImportDTO : public oatpp::DTO
{
    DTO_INIT(ContractCategorysImportDTO, DTO);

    // 合同类型列表
    DTO_FIELD(List<Object<ContractCategoryImportDTO>>, categorys);
    DTO_FIELD_INFO(categorys) {
        info->description = ZH_WORDS_GETTER("contractCategory.field.categorys");
    }
};

#include OATPP_CODEGEN_END(DTO)
#endif // !