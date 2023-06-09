#pragma once
#ifndef _ARCHIVES_MAPPER_
#define _ARCHIVES_MAPPER_

#include "Mapper.h"
#include "../../domain/do/archives/t_pimarchivesDO.h"

/**
 * 示例表字段匹配映射
 */
// 分页查询的mapper
// asd
class ArchivesMapper : public Mapper<t_pimarchivesDO>
{
public:
	t_pimarchivesDO mapper(ResultSet* resultSet) const override
	{
		t_pimarchivesDO data;
		data.setPimArchivesId(resultSet->getString(1));
		data.setDabh(resultSet->getString(2));
		data.setOrgName(resultSet->getString(3));
		data.setDabgd(resultSet->getString(4));
		data.setArchivesCenterName(resultSet->getString(5));
		data.setDazt(resultSet->getString(6));
		data.setYgbh(resultSet->getString(7));
		data.setPimPersonName(resultSet->getString(8));
		data.setYgzt(resultSet->getString(9));
		data.setOrmOrgName(resultSet->getString(10));
		data.setZt(resultSet->getString(11));
		//data.setEducation(resultSet->getString(12));
		//data.setDateOfBirth(resultSet->getString(13));
		//data.setJoinPartyDate(resultSet->getString(14));
		//data.setStartWorkDatae(resultSet->getString(15));
		return data;
	}
};

// 查询详细信息使用的mapper表
class ArchivesMapperDetail : public Mapper<t_pimarchivesDO>
{
public:
	t_pimarchivesDO mapper(ResultSet* resultSet) const override
	{
		t_pimarchivesDO data;
		data.setPimArchivesId(resultSet->getString(1));
		data.setDabh(resultSet->getString(2));
		data.setOrgName(resultSet->getString(3));
		data.setDabgd(resultSet->getString(4));
		data.setArchivesCenterName(resultSet->getString(5));
		data.setDazt(resultSet->getString(6));
		data.setYgbh(resultSet->getString(7));
		data.setPimPersonName(resultSet->getString(8));
		data.setYgzt(resultSet->getString(9));
		data.setOrmOrgName(resultSet->getString(10));
		data.setZt(resultSet->getString(11));
		data.setEducation(resultSet->getString(12));
		data.setDateOfBirth(resultSet->getString(13));
		data.setJoinPartyDate(resultSet->getString(14));
		data.setStartWorkDatae(resultSet->getString(15));
		return data;
	}
};
#endif // !_ARCHIVES_MAPPER_