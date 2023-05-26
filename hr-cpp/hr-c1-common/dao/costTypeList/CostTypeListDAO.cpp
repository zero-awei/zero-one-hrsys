#include "stdafx.h"
#include "CostTypeListDAO.h"
#include "CostTypeMapper.h"

std::list<CostTypeDO> CostTypeListDAO::listAll()
{
	/*string str = "SELECT `LEVELTYPE` FROM `t_pimarmycadres` GROUP BY `LEVELTYPE`";
	ArmyLevelMapper mapper;
	return sqlSession->executeQuery<ArmyLevelTypeDO, ArmyLevelMapper>(str, mapper);*/

	list<CostTypeDO> res;
	for (auto item : costType)
	{
		CostTypeDO tmp(item.first, item.second);
		res.push_back(tmp);
	}
	return res;
}

unordered_map<string, string> CostTypeListDAO::getMapList()
{
	return costType;
}