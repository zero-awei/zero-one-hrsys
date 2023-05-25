
#include "stdafx.h"
#include "FileStatusController.h"
#include "uselib/pullListRedis/UseLibRedis.h"

PullListVO::Wrapper FileStatusController::execQueryFileStatus()
{
	auto dto = PullListDTO::createShared();
	UseLibRedis redisExm;
	std::string tableName = "file-status-pull-list";
	std::unordered_map<std::string, std::string> fileStatusList;
	std::unordered_map<std::string, std::string> redisResult = redisExm.queryRedis(tableName);
	if (redisResult.empty()) {
		// 列表数据
		auto borrowing = ItemDTO::createShared(10, ZH_WORDS_GETTER("fileStatus.borrowing"));
		auto returned = ItemDTO::createShared(20, ZH_WORDS_GETTER("fileStatus.returned"));
		dto->pullList->push_back(borrowing);
		dto->pullList->push_back(returned);

		// 加入缓存
		for (auto subptr = dto->pullList->begin(); subptr != dto->pullList->end(); subptr++) {
			fileStatusList.insert(std::make_pair(std::to_string(*subptr->get()->key), *subptr->get()->val));
		}
		// 加入缓存
		redisExm.updateRedis(tableName, fileStatusList);
	}
	else { // 缓存有数据
		fileStatusList = redisExm.queryRedis(tableName);
		for (auto sub : fileStatusList) {
			dto->pullList->push_back(ItemDTO::createShared(std::stoi(sub.first), sub.second));
		}
	}
	auto vo = PullListVO::createShared();
	vo->success(dto);
	return vo;
}
