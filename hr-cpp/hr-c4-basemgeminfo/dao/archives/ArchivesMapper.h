#pragma once
#ifndef _ARCHIVESMAPPER_H_
#define _ARCHIVESMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/archives/ArchivesDO.h"

class ArchivesMapper : public Mapper<ArchivesDO> {
public:
	ArchivesDO mapper(ResultSet* resultSet) const {
		ArchivesDO data;
		//data.setId(resultSet->getString(1));
		//data.setName(resultSet->getString(2));
		data.setDabh(resultSet->getString(1));
		data.setOrmorgid3(resultSet->getString(2));
		data.setDabgd(resultSet->getString(3));
		data.setArchivescentername(resultSet->getString(4));
		data.setEducation(resultSet->getString(5));
		data.setDateofbirth(resultSet->getString(6));
		data.setJoinpartydate(resultSet->getString(7));
		data.setStartworkdatae(resultSet->getString(8));
		data.setDazt(resultSet->getString(9));
		return data;
	}
};

#endif // !_ARCHIVESMAPPER_H_