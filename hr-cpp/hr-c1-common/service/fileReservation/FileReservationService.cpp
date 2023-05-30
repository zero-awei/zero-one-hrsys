
#include "stdafx.h"
#include "FileReservationService.h"
#include "dao/fileReservation/FileReservationDAO.h"
PullListDTO::Wrapper FileReservationService::listAll()
{
	auto ret = PullListDTO::createShared();
	UseLibRedis redisExm;
	std::string tableName = "file-reservation-pull-list";
	std::unordered_map<std::string, std::string> fileReservationList;
	std::unordered_map<std::string, std::string> redisResult = redisExm.queryRedis(tableName);
	if (redisResult.empty()) {
		FileReservationDAO dao;
		auto result = dao.selectFileReservationList();
		for (FileReservationDO sub : result)
		{
			auto dto = ItemDTO::createShared();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, val, FileReservation, key, Code);
			ret->pullList->push_back(dto);
		}

		// 加入缓存
		for (auto subptr = ret->pullList->begin(); subptr != ret->pullList->end(); subptr++) {
			fileReservationList.insert(std::make_pair(std::to_string(*subptr->get()->key), *subptr->get()->val));
		}
		if (result.size()) {
			redisExm.updateRedis(tableName, fileReservationList);
		}
	}
	else // 缓存有数据
	{
		fileReservationList = redisExm.queryRedis(tableName);
		for (auto sub : fileReservationList) {
			ret->pullList->push_back(ItemDTO::createShared(std::stoi(sub.first), sub.second));
		}
	}
	return ret;
}
