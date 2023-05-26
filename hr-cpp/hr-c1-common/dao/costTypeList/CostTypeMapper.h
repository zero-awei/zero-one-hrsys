#pragma once
#ifndef _COSTTYPEMAPPER_H_
#define _COSTTYPEMAPPER_H_

#include "Mapper.h"
#include "domain/do/costTypeList/CostType.h"

/**
 * 费用类别下拉列表数据库字段匹配映射
 * 负责人：咫尺之书
 */
class CostTypeMapper : public Mapper<CostTypeDO>
{
public:
	CostTypeDO mapper(ResultSet* result) const override
	{
		CostTypeDO data;
		data.setCostType(result->getString(1));
		return data;
	}
};

#endif // !_COSTTYPEMAPPER_H_