#pragma once

/**
* jsonVO类型，将DIO数据封装到JSONVO中返回给前端
*/


#include "stdafx.h"
#include "../../GlobalInclude.h"
#include "domain/dto/JobTitle/JobTitleDTO.h"

#ifndef _JOBTITLE_VO_
#define _JOBTITLE_VO_


#include OATPP_CODEGEN_BEGIN(DTO)
// 查询返回的JsonVO，里面包含的数据为JobTitleDTO类型的数据
class JTQueryJsonVO :public JsonVO<JobTitleDTO::Wrapper> {
	//DTI_INIT对DTO对象进行性初始化操作
	DTO_INIT(JTQueryJsonVO, JsonVO<JobTitleDTO::Wrapper>);
};
// 分页查询返回的JsonVO
class JTQueryPageJsonVO :public JsonVO<JobTitlePageDTO::Wrapper> {
	DTO_INIT(JTQueryPageJsonVO, JsonVO<JobTitlePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_JOBTITLE_VO_