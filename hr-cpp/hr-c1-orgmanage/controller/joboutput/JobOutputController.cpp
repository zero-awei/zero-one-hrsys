#include "stdafx.h"
#include "JobOutputController.h"

JobDownloadJsonVO::Wrapper JobOutputController::execDownloadJobinfo() {
	auto dto = JobDownloadDTO::createShared();
	auto vo = JobDownloadJsonVO::createShared();

	//vo->success(dto);
	return vo;
}