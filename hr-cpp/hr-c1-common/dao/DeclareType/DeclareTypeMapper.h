//2023年5月27日
//作者：狗皮电耗子
//申报类型下拉列表的数据库匹配映射
#pragma once
#ifndef _DECLARE_TYPE_MAPPER_
#define _DECLARE_TYPE_MAPPER_

#include "Mapper.h"
#include "domain/do/declareType/DeclareTypeDO.h"

class DeclareTypeMapper : public Mapper<DeclareTypeDO>
{
public:
	DeclareTypeDO mapper(ResultSet* result) const override
	{
		DeclareTypeDO declareTypeData;
		declareTypeData.setDeclareType(result->getString(1));
		return declareTypeData;
	}
};

#endif // !_DECLARE_TYPE_MAPPER_
