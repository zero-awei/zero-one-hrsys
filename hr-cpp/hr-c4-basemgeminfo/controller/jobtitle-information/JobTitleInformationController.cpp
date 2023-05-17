#include "stdafx.h"
#include "JobTitleInformationController.h"
#include "../../service/certificate-information/jobtitle-information/JobTitleInformationService.h"
JobTitleInformationPageJsonVO::Wrapper JobTitleInformationController::execQueryJobTitleInformation(const JobTitleInformationPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	JobTitleInformationService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = JobTitleInformationPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}




