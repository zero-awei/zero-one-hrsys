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
	PostDetailDO mapper(ResultSet* resultSet) const override 
	{
		PostDetailDO data;

		data.setXh(resultSet->getUInt64(1));
		data.setGwfl(resultSet->getString(2));
		data.setIsConfidential(resultSet->getString(3));
		data.setOrmPostName(resultSet->getString(4));
		data.setNx(resultSet->getUInt64(5));
		data.setBxjlnx(resultSet->getUInt64(6));
		data.setIsKeyPostion(resultSet->getString(7));
		data.setPostNature(resultSet->getString(8));
		data.setStartStopSign(resultSet->getString(9));
		data.setOrmPostId(resultSet->getString(10));
		data.setCreateMan(resultSet->getString(11));
		data.setUpdateDate(resultSet->getString(12));
		data.setUpdateMan(resultSet->getString(13));
		data.setCreateDate(resultSet->getString(14));
		data.setOrgId(resultSet->getString(15));
		data.setGwType(resultSet->getString(16));
		data.setIsTemp(resultSet->getString(17));
		data.setOrmOrgId(resultSet->getString(18));
		data.setOrmOrgName(resultSet->getString(19));

		return data;
	}
};


#endif // !_JOB_EXPORT_MAPPER_
