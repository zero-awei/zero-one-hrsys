
#include "stdafx.h"
#include "FileStatusService.h"
#include "uselib/pullListRedis/UseLibRedis.h"
#include "dao/fileStatus/FileStatusDAO.h"
#include "domain/do/fileStatus/FileStatusDO.h"
PullListDTO::Wrapper FileStatusService::listAll()
{
	auto ret = PullListDTO::createShared();
	UseLibRedis redisExm;
	std::string tableName = "file-status-pull-list";
	std::unordered_map<std::string, std::string> fileStatusList;
	std::unordered_map<std::string, std::string> redisResult = redisExm.queryRedis(tableName);
	if (redisResult.empty()) {
		FileStatusDAO dao;
		auto result = dao.selectFileStatusList();
		for (FileStatusDO sub : result)
		{
			auto dto = ItemDTO::createShared();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, val, FileStatus, key, Code);
			ret->pullList->push_back(dto);
		}

		// 加入缓存
		for (auto subptr = ret->pullList->begin(); subptr != ret->pullList->end(); subptr++) {
			fileStatusList.insert(std::make_pair(std::to_string(*subptr->get()->key), *subptr->get()->val));
		}
		if (result.size()) {
			redisExm.updateRedis(tableName, fileStatusList);
		}
	}
	else // 缓存有数据
	{
		fileStatusList = redisExm.queryRedis(tableName);
		for (auto sub : fileStatusList) {
			ret->pullList->push_back(ItemDTO::createShared(std::stoi(sub.first), sub.second));
		}
	}
	return ret;
}
