#pragma once
#ifndef _ARCHIVEVO_H_
#define _ARCHIVEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/archive/ArchiveDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个档案室信息显示JsonVO对象，用于响应给客户端
 */
class ArchiveJsonVO : public JsonVO<ArchiveDTO::Wrapper>
{
	DTO_INIT(ArchiveJsonVO, JsonVO<ArchiveDTO::Wrapper>);
};

/**
 * 定义一个档案室信息分页显示JsonVO对象，用于响应给客户端
 */
class ArchivePageJsonVO : public JsonVO<ArchivePageDTO::Wrapper>
{
	DTO_INIT(ArchivePageJsonVO, JsonVO<ArchivePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif