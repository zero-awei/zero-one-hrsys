#pragma once
#ifndef _DELETEPROJTAGDTO_H_
#define _DELETEPROJTAGDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DeleteProjTagDTO : public oatpp::DTO
{
	DTO_INIT(DeleteProjTagDTO, DTO);
	DTO_FIELD(String, tagId);
	DTO_FIELD_INFO(tagId) {
		info->description = ZH_WORDS_GETTER("projTag.tagId");
	}
};

/**
 * 删除多条岗位信息传输对象
 */
class DeleteProjTagBatchDTO : public oatpp::DTO
{
	DTO_INIT(DeleteProjTagBatchDTO, DTO);
	// 岗位集标识集
	DTO_FIELD(oatpp::List<String>, tagIds);
	DTO_FIELD_INFO(tagIds) {
		info->description = ZH_WORDS_GETTER("projTag.tagIds");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_DELETEPROJTAGDTO_H_