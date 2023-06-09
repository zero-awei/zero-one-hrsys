#pragma once
#ifndef _ARCHIVES_CENTER_VO_H_
#define _ARCHIVES_CENTER_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/archivesCenter/ArchivesCenterDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ArchivesCenterJsonVO : public JsonVO<ArchivesCenterDTO::Wrapper> {
	DTO_INIT(ArchivesCenterJsonVO, JsonVO<ArchivesCenterDTO::Wrapper>);
};

class ArchivesCenterPageJsonVO : public JsonVO<ArchivesCenterPageDTO::Wrapper> {
	DTO_INIT(ArchivesCenterPageJsonVO, JsonVO<ArchivesCenterPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ARCHIVES_CENTER_VO_H_
