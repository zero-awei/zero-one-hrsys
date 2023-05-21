#include "stdafx.h"
#include "MilitaryController.h"
#include "../../service/military/MilitaryService.h"

MilitaryJsonVO::Wrapper MilitaryController::execQueryMilitary(const MilitaryDetailQuery::Wrapper& query) {
	// 响应结果
	auto jvo = MilitaryJsonVO::createShared();
	// 定义一个Service
	MilitaryService service;
	// 查询数据
	auto result = service.listDetail(query);
	if (result->PIMARMYCADRESID.getValue("").empty()) {
		cout << "No details were found" << endl;
		jvo->fail(result);
	}
	else {
		jvo->success(result);
	}
	return jvo;
}

StringJsonVO::Wrapper MilitaryController::execModifyMilitary(const MilitaryDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (dto->PIMARMYCADRESID.getValue("").empty())
	{
		jvo->init(String("PIMARMYCADRESID must be not null"), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	MilitaryService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->PIMARMYCADRESID);
	}        
	else
	{
		cout << "The primary key is not found or the data is consistent before and after the modification!" << endl;
		jvo->fail(dto->PIMARMYCADRESID);
	}
	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper MilitaryController::execDownloadMilitary(const MilitaryDownloadQuery::Wrapper& query)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	string filedName = MilitaryService().download(query);
	// 响应结果
	if (filedName.empty()) {
		jvo->fail("download failed!");
	}
	else {
		jvo->success(filedName);
	}
	return jvo;
}
