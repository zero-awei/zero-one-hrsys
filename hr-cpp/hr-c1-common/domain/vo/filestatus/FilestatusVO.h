#pragma once
#ifndef _FILESTATUS_VO_
#define _FILESTATUS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/sample/SampleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 档案状态显示JsonVO，用于响应给客户端的Json对象
 */
class FilestatusJsonVO : public JsonVO<SampleDTO::Wrapper> {
	DTO_INIT(FilestatusJsonVO, JsonVO<SampleDTO::Wrapper>);
};

/**
 * 档案状态分页显示JsonVO，用于响应给客户端的Json对象
 */
class FilestatusPageJsonVO : public JsonVO<SamplePageDTO::Wrapper> {
	DTO_INIT(FilestatusPageJsonVO, JsonVO<SamplePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FILESTATUS_VO_