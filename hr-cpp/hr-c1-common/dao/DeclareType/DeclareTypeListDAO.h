//2023年5月27日
//作者：狗皮电耗子
//申报列表的DAO（写死了，新建的时候主键还没输进数据库里，查不了）
#pragma once
#ifndef _DECLARE_TYPE_LIST_DAO_
#define _DECLARE_TYPE_LIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/declareType/DeclareTypeDO.h"

class DeclareTypeListDAO
{
public:
	list<DeclareTypeDO> getDeclareTypeList();
};

#endif // !_DECLARE_TYPE_LIST_DAO_


