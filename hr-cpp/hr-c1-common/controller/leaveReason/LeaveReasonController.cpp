
#include "stdafx.h"
#include "LeaveReasonController.h"
#include "service/leaveReason/LeaveReasonService.h"
#include "uselib/pullListRedis/UseLibRedis.h"

PullListVO::Wrapper LeaveReasonController::execQueryLeaveReason()
{
	// 定义返回数据对象
	auto jvo = PullListVO::createShared();
	auto dto = PullListDTO::createShared();
	std::string tableName = "leave-reason-pull-list";
	std::unordered_map<std::string, std::string> leaveReasonList;
	UseLibRedis redisExm;
	std::unordered_map<std::string, std::string> redisResult = redisExm.queryRedis(tableName);
	if (redisResult.empty()) { // 缓存为空
		// 定义一个Service
		LeaveReasonService service;
		// 执行查询
		dto = service.listAll();
		for (auto subptr = dto->pullList->begin(); subptr != dto->pullList->end(); subptr++) {
			leaveReasonList.insert(std::make_pair(std::to_string(*subptr->get()->key), *subptr->get()->val));
		}
		if (!leaveReasonList.empty()) {
			redisExm.updateRedis(tableName, leaveReasonList);
		}
	}
	else // 缓存有数据
	{
		leaveReasonList = redisExm.queryRedis(tableName);
		for (auto sub : leaveReasonList) {
			dto->pullList->push_back(ItemDTO::createShared(std::stoi(sub.first), sub.second));
		}
	}

	// 构建成功消息
	jvo->success(dto);
	return jvo;
}
