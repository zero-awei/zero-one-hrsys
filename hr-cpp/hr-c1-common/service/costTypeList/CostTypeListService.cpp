#include "stdafx.h"
#include "Macros.h"
#include "CostTypeListService.h"
#include "uselib/pullListRedis/UseLibRedis.h"
#include "dao/costTypeList/CostTypeListDAO.h"

PullListDTO::Wrapper CostTypeListService::listAll()
{
	// 构建返回对象
	auto res = PullListDTO::createShared();

	// TODO: 查询缓存
	// 从缓存中获取费用类别列表
	auto hash = UseLibRedis::queryRedis("cost-type");

	auto dto = PullListDTO::createShared();
	// 如果为空则调用dao查询数据库
	if (hash.empty())
	{
		// TODO: 调用dao查询数据库
		CostTypeListDAO dao;
		auto res = dao.listAll();

		// 组装成DTO返回
		for (auto item : res)
		{
			string code = item.getCode();
			dto->pullList->push_back(ItemDTO::createShared(atoi(code.c_str()), item.getCostType()));
		}

		// TODO: 将获取的数据更新到Redis缓存
		UseLibRedis::updateRedis("cost-type", dao.getMapList());
	}
	// 否则组装缓存数据到DTO
	else
	{
		for (auto item : hash)
		{
			int code = atoi(item.first.c_str());
			dto->pullList->push_back(ItemDTO::createShared(code, item.second));
		}
	}
	return dto;
}
