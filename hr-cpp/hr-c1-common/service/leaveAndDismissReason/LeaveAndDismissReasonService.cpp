
#include "stdafx.h"
#include "LeaveAndDismissReasonService.h"
#include "uselib/pullListRedis/UseLibRedis.h"
#include "domain/do/leaveAndDismissReason/LeaveAndDismissReasonDO.h"
#include "dao/leaveAndDismissReason/LeaveAndDismissReasonDAO.h"
PullListDTO::Wrapper LeaveAndDismissReasonService::listAll()
{
	auto ret = PullListDTO::createShared();
	std::string tableName = "reason-pull-list";
	std::unordered_map<std::string, std::string> reasonList;
	UseLibRedis redisExm;
	std::unordered_map<std::string, std::string> redisResult = redisExm.queryRedis(tableName);
	if (redisResult.empty()) { // 缓存为空
		LeaveAndDismissReasonDAO dao;
		auto result = dao.selectReasonList();
		for (LeaveAndDismissReasonDO sub : result)
		{
			auto dto = ItemDTO::createShared();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, val, Reason, key, Code);
			ret->pullList->push_back(dto);
		}
		for (auto subptr = ret->pullList->begin(); subptr != ret->pullList->end(); subptr++) {
			reasonList.insert(std::make_pair(std::to_string(*subptr->get()->key), *subptr->get()->val));
		}
		if (!reasonList.empty()) {
			redisExm.updateRedis(tableName, reasonList);
		}
	}
	else // 缓存有数据
	{
		reasonList = redisExm.queryRedis(tableName);
		for (auto sub : reasonList) {
			ret->pullList->push_back(ItemDTO::createShared(std::stoi(sub.first), sub.second));
		}
	}
	return ret;
}
