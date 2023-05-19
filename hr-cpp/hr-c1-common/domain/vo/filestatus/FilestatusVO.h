#pragma once
#ifndef _FILESTATUS_VO_
#define _FILESTATUS_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/pullList/PullListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 档案状态下拉列表显示JsonVO，用于响应给客户端的Json对象
 * 负责人：远翔
 */
class FilestatusJsonVO : public JsonVO<PullListDTO::Wrapper> {
	DTO_INIT(FilestatusJsonVO, JsonVO<PullListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FILESTATUS_VO_