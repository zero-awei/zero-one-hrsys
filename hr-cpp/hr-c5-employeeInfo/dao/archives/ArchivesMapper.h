#pragma once
#ifndef _ARCHIVES_MAPPER_
#define _ARCHIVES_MAPPER_
#include "Mapper.h"
#include "../../domain/do/archives/archivesinfoDO.h"
#include "../../domain/do/archivesCenter/archivesCenterDO.h"
#include "../../domain/do/archives/t_pimarchivesDO.h"
/**
 * 档案信息详情页
 */
class ArchivesMapper : public Mapper<archivesinfoDO>
{
public:
	archivesinfoDO mapper(ResultSet* resultSet) const override
	{
		archivesinfoDO data;
		data.setPIMARCHIVESID(resultSet->getString(1));
		data.setDABH(resultSet->getString(2));
		data.setORGNAME(resultSet->getString(3));
		data.setSFXJD(resultSet->getString(4));
		data.setARCHIVESCENTERNAME(resultSet->getString(5));
		data.setDAZT(resultSet->getString(6));
		data.setYGBH(resultSet->getString(7));
		data.setPIMPERSONNAME(resultSet->getString(8));
		data.setORMORGNAME(resultSet->getString(9));
		data.setEDUCATION(resultSet->getString(10));
		data.setDATEOFBIRTH(resultSet->getString(11));
		data.setJOINPARTYDATE(resultSet->getString(12));
		data.setSTARTWORKDATAE(resultSet->getString(13));
		data.setDAZT(resultSet->getString(14));
		data.setBZ(resultSet->getString(15));
		data.setFJ(resultSet->getString(16));
		return data;
	}
};

/**
 * 档案信息详情页
 */
class ArchivesCenterMapper : public Mapper<archivesCenterDO>
{
public:
	archivesCenterDO mapper(ResultSet* resultSet) const override
	{
		archivesCenterDO data;
		data.setSERIALNO(resultSet->getUInt64(1));
		data.setARCHIVESCENTERNAME(resultSet->getString(2));
		data.setCABINETNO(resultSet->getString(3));
		data.setLAYERNO(resultSet->getString(4));
		data.setBNUMBER(resultSet->getString(5));
		return data;
	}
};
// 分页查询的mapper
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
