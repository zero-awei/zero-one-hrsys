#pragma once
#ifndef _JOB_DOWNLOAD_VO_
#define _JOB_DOWNLOAD_VO_

#include "../../../GlobalInclude.h"
#include "../../hr-c1-orgmanage/domain/dto/jobSet/jobDownload/JobDownloadDTO.h"

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(DTO)

class JobDownloadJsonVO : public JsonVO<UInt32> {
	DTO_INIT(JobDownloadJsonVO, JsonVO<UInt32>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_JOB_DOWNLOAD_VO_
