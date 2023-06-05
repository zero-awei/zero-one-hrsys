#pragma once
/*
组织管理 ——数据设置 —— 法人主体设置  -- cpt

法人主体名称下拉列表 `LegalEntitySetPullDownList`

更新指定法人设置信息  `UpdateLegalerSettingMessage`

导出法人设置 `LegalEntitySet`

新增法人设置（支持批量新增）** `LegalEntitySet`
*/
#ifndef _LEGALENTITYSET_MAPPER_
#define _LEGALENTITYSET_MAPPER_
#include "Mapper.h"
#include "../../domain/do/LegalEntitySet/LegalEntitySetDO.h"
/**
 * 示例表字段匹配映射
 */
class LegalEntitySetMapper : public Mapper<LegalEntitySetDO>
{
public:
	LegalEntitySetDO mapper(ResultSet* resultSet) const override
	{
		LegalEntitySetDO data;
		data.setCONTRACTSIGNORGID(resultSet->getString(1));
		data.setCONTRACTSIGNORGNAME(resultSet->getString(2));
		data.setORMSIGNORGID(resultSet->getString(3));
		data.setORMORGID(resultSet->getString(4));
		data.setISDEFAULTSIGNORG(resultSet->getString(5));
		return data;
	}
};
// 下拉列表字段匹配映射
class LegalEntitySetPullDownListMapper : public Mapper<LegalEntitySetDO>
{
public:
	LegalEntitySetDO mapper(ResultSet* resultSet) const override
	{
		LegalEntitySetDO data;
		data.setORMSIGNORGID(resultSet->getString(1));
		return data;
	}
};
/*
LegalEntitySetMapper类的作用是将ResultSet对象中的数据映射到LegalEntitySetDO对象中。ResultSet通常用于表示从数据库中检索到的结果集。
mapper方法接受一个ResultSet*参数，即指向ResultSet对象的指针，并返回一个LegalEntitySetDO对象。
在mapper方法中，首先创建一个LegalEntitySetDO对象data。然后通过调用resultSet对象的各种方法，如getUInt64、getString和getInt，
获取结果集中的具体数据，并使用data对象的相应setter方法，如setId、setName、setSex和setAge，将数据设置到LegalEntitySetDO对象中。
最后，将填充好的LegalEntitySetDO对象返回。
这段代码展示了一种常见的数据映射模式，用于将数据库查询结果映射到自定义的数据对象中。
*/
#endif // !_LEGALENTITYSET_MAPPER_