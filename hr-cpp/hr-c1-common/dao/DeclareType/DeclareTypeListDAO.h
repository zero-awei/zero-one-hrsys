//2023年5月27日
//作者：狗皮电耗子
//申报列表的DAO
#pragma once
#ifndef _DECLARE_TYPE_LIST_DAO_
#define _DECLARE_TYPE_LIST_DAO_

#include "BaseDAO.h"
#include "../../domain/do/declareType/DeclareTypeDO.h"

class DeclareTypeListDAO : public BaseDAO
{
public:
	//创建申报下拉列表
	std::list<DeclareTypeDO> getDeclareTypeList();

};

#endif // !_DECLARE_TYPE_LIST_DAO_


