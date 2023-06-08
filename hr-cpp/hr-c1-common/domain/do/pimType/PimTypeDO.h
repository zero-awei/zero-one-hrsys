//2023年5月23日
//合同类别下拉列表的DO
//作者：狗皮电耗子
#pragma once
#ifndef _PRIM_TYPE_DO_
#define _PRIM_TYPE_DO_
#include "../DoInclude.h"

class PimTypeDO 
{
	CC_SYNTHESIZE(string, createDate, CreateDate);
	CC_SYNTHESIZE(string, pimcontractID, PimContractIdentity);
	CC_SYNTHESIZE(string, pimcontractName, PimContractName);
	CC_SYNTHESIZE(string, createrName, CreaterName);
	CC_SYNTHESIZE(string, updaterName, UpdaterName);
	CC_SYNTHESIZE(string, updateDate, UpdateDate);
	CC_SYNTHESIZE(string, typeCode, TypeCode);
	CC_SYNTHESIZE(string, type, pimType);
	CC_SYNTHESIZE(string, ormorgID, OrmorgID);
public:
	PimTypeDO() {
		createDate = "建立时间";
		pimcontractID = "合同类型标识";
		pimcontractName = "合同类型名称";
		createrName = "建立人";
		updaterName = "更新人";
		updateDate = "更新时间";
		typeCode = "合同类型代码";
		type = "类型";
		ormorgID = "组织标识";
	}
};


#endif // !_PRIM_TYPE_DO_
