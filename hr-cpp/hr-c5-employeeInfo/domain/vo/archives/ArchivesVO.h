#pragma once

#ifndef _ARCHIVES_VO_H_
#define _ARCHIVES_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/archives/ArchivesDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class ArchivesJsonVO : public JsonVO<ArchivesDTO::Wrapper> {
	DTO_INIT(ArchivesJsonVO, JsonVO<ArchivesDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class ArchivesPageJsonVO : public JsonVO<ArchivesPageDTO::Wrapper> {
	DTO_INIT(ArchivesPageJsonVO, JsonVO<ArchivesPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ARCHIVES_VO_H_