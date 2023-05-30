
#include "stdafx.h"
#include "DismissReasonService.h"
#include "dao/dismissReason/DismissReasonDAO.h"
#include "uselib/pullListRedis/UseLibRedis.h"
PullListDTO::Wrapper DismissReasonService::listAll()
{
	auto ret = PullListDTO::createShared();
	std::string tableName = "dismiss-reason-pull-list";
	std::unordered_map<std::string, std::string> dismissReasonList;
	UseLibRedis redisExm;
	std::unordered_map<std::string, std::string> redisResult = redisExm.queryRedis(tableName);
	if (redisResult.empty()) { // 缓存为空
		DismissReasonDAO dao;
		auto result = dao.selectDismissReasonList();
		for (DismissReasonDO sub : result)
		{
			auto dto = ItemDTO::createShared();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, val, Dismissreason, key, Code);
			ret->pullList->push_back(dto);
		}
		// 加入缓存
		for (auto subptr = ret->pullList->begin(); subptr != ret->pullList->end(); subptr++) {
			dismissReasonList.insert(std::make_pair(std::to_string(*subptr->get()->key), *subptr->get()->val));
		}
		if (!dismissReasonList.empty()) {
			redisExm.updateRedis(tableName, dismissReasonList);
		}
	}
	else // 缓存有数据
	{
		dismissReasonList = redisExm.queryRedis(tableName);
		for (auto sub : dismissReasonList) {
			ret->pullList->push_back(ItemDTO::createShared(std::stoi(sub.first), sub.second));
		}
	}
	return ret;
}
