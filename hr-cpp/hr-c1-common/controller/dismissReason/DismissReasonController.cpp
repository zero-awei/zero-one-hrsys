
#include "stdafx.h"
#include "DismissReasonController.h"
#include "uselib/pullListRedis/UseLibRedis.h"

PullListVO::Wrapper DismissReasonController::execQueryDismissReason()
{
	// 定义返回数据对象
	auto jvo = PullListVO::createShared();
	auto dto = PullListDTO::createShared();
	std::string tableName = "dismiss-reason-pull-list";
	std::unordered_map<std::string, std::string> dismissReasonList;
	UseLibRedis redisExm;
	std::unordered_map<std::string, std::string> redisResult = redisExm.queryRedis(tableName);
	if (redisResult.empty()) { // 缓存为空
		// 定义一个Service
		DismissReasonService service;
		// 执行查询
		dto = service.listAll();
		// 加入缓存
		for (auto subptr = dto->pullList->begin(); subptr != dto->pullList->end(); subptr++) {
			dismissReasonList.insert(std::make_pair(std::to_string(*subptr->get()->key), *subptr->get()->val));
		}
		redisExm.updateRedisWithTable(dismissReasonList, tableName);
	}
	else // 缓存有数据
	{
		dismissReasonList = redisExm.queryRedis(tableName);
		for (auto sub : dismissReasonList) {
			dto->pullList->push_back(ItemDTO::createShared(std::stoi(sub.first), sub.second));
		}
	}

	// 构建成功消息
	jvo->success(dto);
	return jvo;
}
