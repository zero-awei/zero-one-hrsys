#pragma once
/*
证书管理-分页查询证书列表--pine
*/
#ifndef  _CHECK_CER_LIST_MAPPER_
#define  _CHECK_CER_LIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/CertificateManage/CertificateDO.h"

class ChechCerListMapper : public Mapper<CertificateDO>
{
public:
	CertificateDO mapper(ResultSet* resultSet) const override
	{
		CertificateDO data;
		data.setYgbh(resultSet->getString(1));//this
		data.setPimperSonName(resultSet->getString(2));//this
		data.setYgzt(resultSet->getString(3));
		data.setZZ(resultSet->getString(4));
		data.setZGZSBH(resultSet->getString(5));//证书编号
		data.setBcardNumber(resultSet->getString(6));
		data.setPimVocationalName(resultSet->getString(7));//this		
		data.setZslx(resultSet->getString(8));
		data.setZghqrq(resultSet->getString(9));
		data.setZgsydw(resultSet->getString(10));
		data.setZcdw(resultSet->getString(11));
		data.setSxrq(resultSet->getString(12));
		data.setFzyxq(resultSet->getString(13));

		data.setPIMPERSONID(resultSet->getString(14));
		data.setREGISNUMBER(resultSet->getString(15));
		data.setSOCSECPAYUNIT(resultSet->getString(16));
		data.setCSZCSJ(resultSet->getString(17));
		data.setXZCSJ(resultSet->getString(18));
		data.setPimvocationalid(resultSet->getString(19));//证书唯一标识
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