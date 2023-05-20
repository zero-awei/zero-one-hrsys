#pragma once
#ifndef _CONTRACTTYPE_EXPORT_VO_
#define _CONTRACTTYPE_EXPORT_VO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 合同类型导出结果显示对象，用于响应给客户端的Json对象
 */
class ContractTypeExportVO : public oatpp::DTO {
    DTO_INIT(ContractTypeExportVO, DTO);

    // 导出文件的URL
    DTO_FIELD(String, fileUrl);
    DTO_FIELD_INFO(fileUrl) {
        info->description = ZH_WORDS_GETTER("contractType.field.fileUrl");
    }

    // 导出的合同类型数量
    DTO_FIELD(UInt32, exportedCount);
    DTO_FIELD_INFO(exportedCount) {
        info->description = ZH_WORDS_GETTER("contractType.field.exportedCount");
    }
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTRACTTYPE_EXPORT_VO_
