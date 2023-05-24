#pragma once
#ifndef _JOB_UPDATE_VO_
#define _JOB_UPDATE_VO_

#include "../../../GlobalInclude.h"
#include "../../hr-c1-orgmanage/domain/dto/jobSet/jobDownloadDto/JobDownloadDTO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(DTO)

class JobUpdateJsonVO : public JsonVO<UInt32> {
	DTO_INIT(JobUpdateJsonVO, JsonVO<UInt32>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_JOB_UPDATE_VO_
