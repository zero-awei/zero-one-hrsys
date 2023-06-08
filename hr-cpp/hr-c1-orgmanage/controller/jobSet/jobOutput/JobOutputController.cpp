#include "stdafx.h"
#include "JobOutputController.h"

StringJsonVO::Wrapper JobOutputController::execDownloadJobinfo(const PostDetailQuery::Wrapper& query) {
	auto vo = StringJsonVO::createShared();
	
	JobOutputService service;
	string url = service.exportJobInfomation(query);

	if (url.empty())
		vo->fail(url);
	else
		vo->success(url);
	return vo;
}