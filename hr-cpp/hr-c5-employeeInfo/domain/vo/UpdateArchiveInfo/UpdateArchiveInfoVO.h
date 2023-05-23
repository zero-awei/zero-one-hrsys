#pragma once
#pragma once

#ifndef _UPDATE_ARCHIVE_INFO_VO_
#define _UPDATE_ARCHIVE_INFO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/UpdateArchiveInfo/UpdateArchiveInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示JsonVO，用于响应给客户端的Json对象
 */
class UpdateArchiveInfoVO : public JsonVO<UpdateArchiveInfoDTO::Wrapper> {
	DTO_INIT(UpdateArchiveInfoVO, JsonVO<UpdateArchiveInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UPDATE_ARCHIVE_INFO_VO_