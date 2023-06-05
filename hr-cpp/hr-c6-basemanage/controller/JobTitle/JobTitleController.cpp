#include "stdafx.h"
#include "JobTitleController.h"
#include "service/JobTitle/JobTitleService.h"
#include "FastDfsClient.h"
#include <iostream>

JTQueryPageJsonVO::Wrapper JobTitleController::execQueryPage(const JobTitleQuery::Wrapper& query)
{
	// 定义Service
	JobTitleService service;
	auto result = service.listAll(query);
	auto jvo = JTQueryPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

JTQueryPageJsonVO::Wrapper JobTitleController::execQueryPageSB(const JobTitleQuery::Wrapper& query)
{
	JobTitleService service;
	// 定义返回参数
	auto result = JobTitlePageDTO::createShared();
	// 参数校验
	// 有参数的情况，即prama不为空
	if (query->param) {
		result = service.listByParams(query); // 有参的时候，调用模糊查询获取数据
	}
	else {
		// 无参数情况,调用全部查询获取数据
		result = service.listAll(query);
	}
	auto jvo = JTQueryPageJsonVO::createShared();
	// 响应结果
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper JobTitleController::execRemoveJobTitle(const JobTitleDeleteDTO::Wrapper& dto)
{
	cout << "执行删除" << endl;
	//auto
	auto jvo = Uint64JsonVO::createShared();
	// 进行数据校验-- 非空校验
	if (!dto->list_jobtitle_id) {
		cout << "传入的id列表为空" << endl;
	}
	if (dto->list_jobtitle_id->empty()) {
		cout << "传入的id列表无效" << endl;
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	}
	JobTitleService service;
	UInt64 count = service.removeData(dto);
	if (count <= 0) {
		jvo->fail(UInt64(count));
	}
	else {
		jvo->success(UInt64(count));
	}
	return jvo;
}

// 添加职称信息
StringJsonVO::Wrapper JobTitleController::execAddJobTitle(const JobTitleAddDTO::Wrapper& dto)
{
	auto jvo = StringJsonVO::createShared();
	//cout << "id: " << dto->employee_id << endl;
	//cout << "employee_name:" << dto->employee_name << endl;
	// 判断数据是否合法
	// 非空判断--有一个为空，则返回false
	if (!dto->employee_id || !dto->employee_name || !dto->jobtitle_name || !dto->get_time) {
		jvo->init(String(-1), RS_PARAMS_INVALID);
	}
	// 有效值检验--有一个无效则返回false
	if (dto->employee_id->empty() || dto->employee_name->empty() || dto->employee_name->empty() || dto->get_time->empty()) {
		jvo->init(String(-1), RS_PARAMS_INVALID);
	}
	//cout << "接收id为：" << dto->employee_id << endl;
	// 值有效，进入添加
	// 创建server
	JobTitleService service;
	// 添加成功
	if (service.addData(dto)) {
		jvo->success(String(dto->employee_id));
	}
	else {
		jvo->fail(String(-1));
	}
	return jvo;
}

StringJsonVO::Wrapper JobTitleController::execJobTitlePostFile(const String& fileBody, const String& suffix)
{
	auto vo = StringJsonVO::createShared();
	//cout << "文件体" << string(fileBody) << endl;
	// 查看是否有文件，如果没有则返回空
	if (fileBody->empty() || suffix->empty()) {
		vo->fail(String("上传失败"));
		return vo;
	}
	JobTitleService  service;
	auto ss = service.postFile(fileBody, suffix);
	vo->success(ss);
	return vo;
}
