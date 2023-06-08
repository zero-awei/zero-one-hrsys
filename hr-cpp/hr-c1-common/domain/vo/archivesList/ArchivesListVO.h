//2023年5月21日
//档案室层级下拉列表
//作者：狗皮电耗子
#pragma once
#ifndef _ARCHIVES_LIST_VO_
#define _ARCHIVES_LIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/archivesLevels/ArchivesLevelsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ArchivesListVO : public JsonVO<ArchivesLevelsListDTO::Wrapper>
{
	DTO_INIT(ArchivesListVO, JsonVO<ArchivesLevelsListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ARCHIVES_LIST_VO_
