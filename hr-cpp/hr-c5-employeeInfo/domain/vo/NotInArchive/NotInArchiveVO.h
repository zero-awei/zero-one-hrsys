#pragma once

#ifndef _NOT_IN_ARCHIVE_VO_
#define _NOT_IN_ARCHIVE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/NotInArchive/NotInArchiveDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示JsonVO，用于响应给客户端的Json对象
 */
class NotInArchiveVO : public JsonVO<NotInArchiveDTO::Wrapper> {
	DTO_INIT(NotInArchiveVO, JsonVO<NotInArchiveDTO::Wrapper>);
};

/**
 * 分页显示JsonVO，用于响应给客户端的Json对象
 */
class NotInArchivePageJsonVO : public JsonVO<NotInArchivePageDTO::Wrapper> {
	DTO_INIT(NotInArchivePageJsonVO, JsonVO<NotInArchivePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_NOT_IN_ARCHIVE_