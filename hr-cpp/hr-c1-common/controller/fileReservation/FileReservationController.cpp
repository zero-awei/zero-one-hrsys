
#include "stdafx.h"
#include "FileReservationController.h"
#include "domain/vo/pullList/PullListVO.h"
#include "uselib/pullListRedis/UseLibRedis.h"

PullListVO::Wrapper FileReservationController::execQueryFileReservation()
{
	auto dto = PullListDTO::createShared();
	UseLibRedis redisExm;
	std::string tableName = "file-reservation-pull-list";
	std::unordered_map<std::string, std::string> fileReservationList;
	std::unordered_map<std::string, std::string> redisResult = redisExm.queryRedis(tableName);
	if (redisResult.empty()) {
		// 列表数据
		auto localbase = ItemDTO::createShared(10, ZH_WORDS_GETTER("fileReservation.localbase"));
		auto enterbase = ItemDTO::createShared(20, ZH_WORDS_GETTER("fileReservation.enterbase"));
		auto other = ItemDTO::createShared(30, ZH_WORDS_GETTER("fileReservation.other"));
		dto->pullList->push_back(localbase);
		dto->pullList->push_back(enterbase);
		dto->pullList->push_back(other);
		
		// 加入缓存
		for (auto subptr = dto->pullList->begin(); subptr != dto->pullList->end(); subptr++) {
			fileReservationList.insert(std::make_pair(std::to_string(*subptr->get()->key), *subptr->get()->val));
		}
		redisExm.updateRedis(tableName, fileReservationList);
	}
	else // 缓存有数据
	{
		fileReservationList = redisExm.queryRedis(tableName);
		for (auto sub : fileReservationList) {
			dto->pullList->push_back(ItemDTO::createShared(std::stoi(sub.first), sub.second));
		}
	}
	
	auto vo = PullListVO::createShared();
	vo->success(dto);
	return vo;
}



