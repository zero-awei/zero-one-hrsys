#pragma once
#ifndef _ARCHIVESMAPPER_H_
#define _ARCHIVESMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/archives/ArchivesDO.h"

class ArchivesMapper : public Mapper<ArchivesDO> {
public:
	ArchivesDO mapper(ResultSet* resultSet) const {
		ArchivesDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setDabh(resultSet->getString(3));
		data.setOrmorgid3(resultSet->getString(4));
		data.setDabgd(resultSet->getString(5));
		data.setArchivescenterid(resultSet->getString(6));
		data.setEducation(resultSet->getString(7));
		data.setDateofbirth(resultSet->getString(8));
		data.setJoinpartydate(resultSet->getString(9));
		data.setStartworkdatae(resultSet->getString(10));
		data.setStartworkdatae(resultSet->getString(11));
		return data;
	}
};

#endif // !_ARCHIVESMAPPER_H_