#pragma once
#ifndef _DELETEPROJTAGBATCHVO_H_
#define _DELETEPROJTAGBATCHVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/projTag/DeleteProjTagDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 批量删除项目标签信息
 * 负责人：咫尺之书
 */
class DeleteProjTagBatchVO : public JsonVO<DeleteProjTagBatchDTO::Wrapper> {
	DTO_INIT(DeleteProjTagBatchVO, JsonVO<DeleteProjTagBatchDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DELETEPROJTAGBATCHVO_H_