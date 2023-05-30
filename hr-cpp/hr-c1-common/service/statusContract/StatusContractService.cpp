
#include "stdafx.h"
#include "StatusContractService.h"
#include "uselib/pullListRedis/UseLibRedis.h"
#include "dao/statusContract/StatusContractDAO.h"
#include "domain/do/constractStatus/ConstractStatusDO.h"
PullListDTO::Wrapper StatusContractService::listAll()
{
	auto ret = PullListDTO::createShared();
	std::string tableName = "constract-status-pull-list";
	std::unordered_map<std::string, std::string> statusContractList;
	UseLibRedis redisExm;
	std::unordered_map<std::string, std::string> redisResult = redisExm.queryRedis(tableName);
	if (redisResult.empty()) { // 缓存为空
		StatusContractDAO dao;
		auto result = dao.selectConstractStatusList();
		for (ConstractStatusDO sub : result)
		{
			auto dto = ItemDTO::createShared();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, val, ConstractStatus, key, Code);
			ret->pullList->push_back(dto);
		}
		for (auto subptr = ret->pullList->begin(); subptr != ret->pullList->end(); subptr++) {
			statusContractList.insert(std::make_pair(std::to_string(*subptr->get()->key), *subptr->get()->val));
		}
		if (!statusContractList.empty()) {
			redisExm.updateRedis(tableName, statusContractList);
		}
	}
	else // 缓存有数据
	{
		statusContractList = redisExm.queryRedis(tableName);
		for (auto sub : statusContractList) {
			ret->pullList->push_back(ItemDTO::createShared(std::stoi(sub.first), sub.second));
		}
	}
	return ret;
}

