
#include "stdafx.h"
#include "LeaveReasonService.h"
#include "uselib/pullListRedis/UseLibRedis.h"
#include "dao/leaveReason/LeaveReasonDAO.h"
PullListDTO::Wrapper LeaveReasonService::listAll()
{
	auto ret = PullListDTO::createShared();
	std::string tableName = "leave-reason-pull-list";
	std::unordered_map<std::string, std::string> leaveReasonList;
	UseLibRedis redisExm;
	std::unordered_map<std::string, std::string> redisResult = redisExm.queryRedis(tableName);
	if (redisResult.empty()) { // 缓存为空
		LeaveReasonDAO dao;
		auto result = dao.selectLeaveReasonList();
		for (LeaveReasonDO sub : result)
		{
			auto dto = ItemDTO::createShared();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, val, Leavereason, key, Code);
			ret->pullList->push_back(dto);
		}
		for (auto subptr = ret->pullList->begin(); subptr != ret->pullList->end(); subptr++) {
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
			ret->pullList->push_back(ItemDTO::createShared(std::stoi(sub.first), sub.second));
		}
	}
	return ret;
}
