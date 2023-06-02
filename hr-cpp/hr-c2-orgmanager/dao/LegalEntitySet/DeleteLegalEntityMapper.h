#pragma once
/*
* 法人主体设置--删除法人设置(支持批量删除)--pine
*/
#ifndef  _DELETE_LEGAL_ENTITY_MAPPER_
#define  _DELETE_LEGAL_ENTITY_MAPPER_

#include "Mapper.h"
#include "../../domain/do/LegalEntitySet/LegalEntitySetDO.h"

/**
 * 示例表字段匹配映射
 */
class DeleteLegalEntityMapper : public Mapper<LegalEntitySetDO>
{
public:
	LegalEntitySetDO mapper(ResultSet* resultSet) const override
	{
		LegalEntitySetDO data;
		data.setORMSIGNORGNAME(resultSet->getString(1));//this
		data.setCONTRACTSIGNORGNAME(resultSet->getString(2));//要连表查询//this
		data.setISDEFAULTSIGNORG(resultSet->getUInt64(3));//this

		//data.setYgzt(resultSet->getString(3));
		//data.setOrganizationName(resultSet->getString(3));
		//data.setZgzsbh(resultSet->getString(5));
		//data.setBcardNumber(resultSet->getString(6));	
		//data.setZslx(resultSet->getString(8));
		//data.setZghqrq(resultSet->getString(9));
		//data.setZcdw(resultSet->getString(10));
		//data.setZgsydw(resultSet->getString(11));
		//data.setFzyxq(resultSet->getString(12));
		//data.setSxrq(resultSet->getString(13));
		return data;
	}
};
/*
*get里面是查到的符合条件的表的列数,要与实际的列数相对应才行，里面只找了要查的三个量
*/


/*
SampleMapper类的作用是将ResultSet对象中的数据映射到SampleDO对象中。ResultSet通常用于表示从数据库中检索到的结果集。
mapper方法接受一个ResultSet*参数，即指向ResultSet对象的指针，并返回一个SampleDO对象。
在mapper方法中，首先创建一个SampleDO对象data。然后通过调用resultSet对象的各种方法，如getUInt64、getString和getInt，
获取结果集中的具体数据，并使用data对象的相应setter方法，如setId、setName、setSex和setAge，将数据设置到SampleDO对象中。
最后，将填充好的SampleDO对象返回。
这段代码展示了一种常见的数据映射模式，用于将数据库查询结果映射到自定义的数据对象中。
*/
#endif // !_SAMPLE_MAPPER_