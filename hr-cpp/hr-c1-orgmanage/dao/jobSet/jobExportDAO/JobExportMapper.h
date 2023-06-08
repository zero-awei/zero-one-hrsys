//2023年5月28日
//作者：狗皮电耗子
//岗位导出的mapper
#pragma once
#ifndef _JOB_EXPORT_MAPPER_
#define _JOB_EXPORT_MAPPER_

#include "Mapper.h"
#include "domain/do/postSet/PostDetailDO.h"

class JobExportMapper : public Mapper<PostDetailDO> 
{
public:
	PostDetailDO mapper(ResultSet* resultSet) const override 
	{
		PostDetailDO data;

		data.setOrmPostId(resultSet->getString(1));
		data.setOrmPostName(resultSet->getString(2));
		data.setIsKeyPostion(resultSet->getString(3));
		data.setCreateMan(resultSet->getString(4));
		data.setUpdateMan(resultSet->getString(5));
		data.setCreateDate(resultSet->getString(6));
		data.setUpdateDate(resultSet->getString(7));
		data.setOrmOrgId(resultSet->getString(8));
		data.setGwType(resultSet->getString(9));
		data.setGwfl(resultSet->getString(10));
		data.setIsConfidential(resultSet->getString(11));
		data.setIsTemp(resultSet->getString(12));
		data.setPostNature(resultSet->getString(13));
		data.setStartStopSign(resultSet->getString(14));
		data.setIsTemp(resultSet->getString(15));
		data.setNx(resultSet->getUInt(16));
		data.setBxjlnx(resultSet->getUInt(17));
		data.setXh(resultSet->getUInt(18));

		return data;
	}
};


#endif // !_JOB_EXPORT_MAPPER_
