#include "stdafx.h"
#include "JobOutputController.h"

StringJsonVO::Wrapper JobOutputController::execDownloadJobinfo(const PostDetailQuery::Wrapper& query) {
	auto dto = JobDownloadDTO::createShared();
	auto vo = JobDownloadJsonVO::createShared();

	vo->success("url/download");
	return vo;
}