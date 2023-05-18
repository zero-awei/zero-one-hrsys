#pragma once
#ifndef _ARCHIVEVO_H_
#define _ARCHIVEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/archive/archiveDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个档案室信息显示JsonVO对象，用于响应给客户端
 */
class archiveJsonVO : public JsonVO<archiveDTO::Wrapper>
{
	DTO_INIT(archiveJsonVO, JsonVO<archiveDTO::Wrapper>);
};

/**
 * 定义一个档案室信息分页显示JsonVO对象，用于响应给客户端
 */
class archivePageJsonVO : public JsonVO<archivePageDTO::Wrapper>
{
	DTO_INIT(archivePageJsonVO, JsonVO<archivePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif