#pragma once
/*
证书管理-分页查询证书列表--pine
*/
#ifndef  _CHECH_CER_LIST_MAPPER_
#define  _CHECH_CER_LIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/CertificateManage/CertificateDO.h"

/**
 * 示例表字段匹配映射
 */
class CertificateMapper : public Mapper<CertificateDO>
{
public:
	CertificateDO mapper(ResultSet* resultSet) const override
	{
		CertificateDO data;
		//data.setId(resultSet->getUInt64(1));
		//data.setName(resultSet->getString(2));
		//data.setSex(resultSet->getString(3));
		//data.setAge(resultSet->getString(4));
		//data.setOrganization(resultSet->getString(5));
		//data.setDepartment(resultSet->getString(6));
		//data.setRank(resultSet->getString(7));
		//data.setMail_address(resultSet->getString(8));
		//data.setFamily_contact(resultSet->getString(9));
		//data.setFamily_contact_nuimber(resultSet->getString(10));
		return data;
	}
};

/*
SampleMapper类的作用是将ResultSet对象中的数据映射到SampleDO对象中。ResultSet通常用于表示从数据库中检索到的结果集。
mapper方法接受一个ResultSet*参数，即指向ResultSet对象的指针，并返回一个SampleDO对象。
在mapper方法中，首先创建一个SampleDO对象data。然后通过调用resultSet对象的各种方法，如getUInt64、getString和getInt，
获取结果集中的具体数据，并使用data对象的相应setter方法，如setId、setName、setSex和setAge，将数据设置到SampleDO对象中。
最后，将填充好的SampleDO对象返回。
这段代码展示了一种常见的数据映射模式，用于将数据库查询结果映射到自定义的数据对象中。
*/
#endif // !_SAMPLE_MAPPER_