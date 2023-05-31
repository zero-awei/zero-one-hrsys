//2023年5月21日
//岗位更新信息
//作者：狗皮电耗子
#pragma once
#ifndef _JOB_UPDATE_VO_
#define _JOB_UPDATE_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/jobSet/jobUpdateDto/JobUpdateDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class JobUpdateJsonVO : public JsonVO<JobUpdateDTO::Wrapper> {
	DTO_INIT(JobUpdateJsonVO, JsonVO<JobUpdateDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_JOB_UPDATE_VO_
