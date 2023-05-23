#pragma once
#ifndef _IMPORTTAG_VO_
#define _IMPORTTAG_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/projTag/ImportTagDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 返回装载在数据库序号字段的list
 * 负责人：远翔
 */
class ImportTagVO : public oatpp::DTO
{
	DTO_INIT(ImportTagVO, DTO);
	DTO_FIELD(List<String>, newId) = {};
	DTO_FIELD_INFO(newId) {
		info->description = ZH_WORDS_GETTER("projTag.import.summary");
	}
};

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class ImportProjTagJsonVO : public JsonVO<ImportTagVO::Wrapper> {
	DTO_INIT(ImportProjTagJsonVO, JsonVO<ImportTagVO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class ImportProjTagPageJsonVO : public JsonVO<ImportTagPageDTO::Wrapper> {
	DTO_INIT(ImportProjTagPageJsonVO, JsonVO<ImportTagPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_IMPORTTAG_VO_