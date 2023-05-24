//2023年5月21日
//导出岗位信息
//作者：狗屁电耗子
#pragma once
#ifndef _JOB_DOWNLOAD_VO_
#define _JOB_DOWNLOAD_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/jobDownload/JobDownloadDTO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(DTO)

class JobDownloadJsonVO : public JsonVO<UInt32> {
	DTO_INIT(JobDownloadJsonVO, JsonVO<UInt32>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_JOB_DOWNLOAD_VO_
